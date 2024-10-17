#include <stdio.h>

int Mandel(double real, double imag){
    
    int limit = 100;
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
    
    int width = 100;
    int height = 100;
    
    double xLeft = -2.0;
    double xRight = 1.0;
    double yDown = -1.0;
    double yUp = 1.0;
    
    double dx = (xRight - xLeft) / (width - 1);
    double dy = (yUp - yDown) / (height - 1);
    
    for(int i = 0; i < height; ++i){
        for(int j = 0; j < width; ++j){
            
            double x = xLeft + j * dx;
            double y = yUp - i * dy;
            
            int val = Mandel(x,y);
            
            if(val == 100){
                
                printf(" ");
            }
            else{
                
                printf("@");
            }
        }
        printf("\n");
    }

    return 0;
}
