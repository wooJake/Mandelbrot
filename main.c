#include <stdio.h>

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
    
    double xLeft = -2.0;
    double xRight = 0.47;
    double yDown = -1.12;
    double yUp = 1.12;
    
    double dx = (xRight - xLeft) / (width - 1);
    double dy = (yUp - yDown) / (height - 1);
    
    #pragma omp parallel for
    for(int i = 0; i < height; ++i){
        for(int j = 0; j < width; ++j){
            
            double x = xLeft + j * dx;
            double y = yUp - i * dy;
            
            int val = Mandel(x,y);

            for(int k = 0; k < 10; ++k){

                if(val <= (k / 10.0) * limit){

                    printf("%c", chars[k]);
                    break;
                }
                if(val == limit){

                    printf("@");
                    break;
                }
            }
        }
        printf("\n");
    }

    return 0;
}
