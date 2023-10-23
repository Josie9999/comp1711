#include <stdio.h>

float circleArea(float radius){
    float pi = 3.14;
    float area = pi * radius * radius;
    return area;
}

int main(){
    printf("%f\n",circleArea(5.87));
}