#include <stdio.h>
#include <stdlib.h>

typedef struct Test{
    char s[30];// 30 byte 
    int i;     // 4
    float f;   //  
    double d;  // 8    
} Test_;

int main(){
    printf("sizeof(Test_) : %d" , sizeof(Test_));
}



