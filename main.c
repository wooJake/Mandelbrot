#include <stdio.h>
#include <omp.h>

int limit = 100;
char chars[10] = {' ','\'','*','-','+','&','%','$','#','@'};

int Mandel(double real, double imag){
    
    double zReal = real;
    double zImag = imag;
    
    for(int i = 0; i < limit; ++i){
        
        double r_sq = zReal * zReal;
        double i_sq = zImag * zImag;
        
        if(r_sq + i_sq > 4){
            
            return i;
        }
        
        zImag = 2.0 * zReal * zImag + imag;
        zReal = r_sq - i_sq + real;
    }
    return limit;
}
int main(){
    
    int width = 167;
    int height = 100;
    
    //Setting bounds of map.
    double xLeft = -2.0;
    double xRight = 2.0;
    double yDown = -2.0;
    double yUp = 2.0;
    
    //Making variables to ensure set is fully visible.
    //Scaling width by difference of leftmost and rightmost then dividing by width, same with height but with upmost and downmost.

    //Variables to zoom in more (smaller value is more zoomed in).
    double zoom = 1.0;

    //Variables to shift set across the plane.
    double xShift = 0.0;
    double yShift = 0.0;
    
    //Using this to scrunch down the size of the coordinates to a managable size.
    double dx = (xRight - xLeft) / (width - 1);
    double dy = (yUp - yDown) / (height - 1);
    
    //Parallelizing main loop.
    #pragma omp parallel for
    for(int i = 0; i < height; ++i){
        for(int j = 0; j < width; ++j){
            
            //Starting from top left of map to scaled coordinate.
            //j is positive because we are counting up from the left of the map.
            //i is negative because we are counting down from the top of the map.
            double x = xShift + zoom * (xLeft + j * dx);
            double y = yShift + zoom * (yUp - i * dy);
            
            //Obtaining limit reached from Mandel function.
            int val = Mandel(x,y);

            //Looping through visual output.
            for(int k = 0; k < 10; ++k){

                //Checking if value is under a select amount before outputting specific characters.
                if(val <= (k / 10.0) * limit){

                    printf("%c", chars[k]);
                    break;
                }
                //If value is exactly the limit we color it with the @ symbol.
                if(val == limit){

                    printf("@");
                    break;
                }
            }
        }
        //Going to next line.
        printf("\n");
    }

    return 0;
}
