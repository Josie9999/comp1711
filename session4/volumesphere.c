#include <stdio.h>

float volumeSphere(float radius){
    float pi = 3.14;
    float volume = 4/3 * pi * radius * radius * radius;
    return volume;
}

int main(){
    printf("%f\n", volumeSphere(6.50));
}