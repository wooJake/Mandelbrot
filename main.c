#include <stdio.h>

int limit = 100;

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
            
            if(val == limit){
                
                printf("@");
            }
            else if(val >= 0.9 * limit){
                
                printf("#");
            }
            else if(val >= 0.8 * limit){
                
                printf("+");
            }
            else if(val >= 0.7 * limit){
                
                printf("&");
            }
            else if(val >= 0.6 * limit){
                
                printf("?");
            }
            else if(val >= 0.5 * limit){
                
                printf("!");
            }
            else if(val >= 0.4 * limit){
                
                printf("^");
            }
            else if(val >= 0.3 * limit){
                
                printf("V");
            }
            else if(val >= 0.2 * limit){
                
                printf("*");
            }
            else if(val >= 0.1 * limit){
                
                printf("\'");
            }
            else{
                
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
