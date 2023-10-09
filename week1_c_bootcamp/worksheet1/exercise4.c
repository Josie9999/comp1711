#include <stdio.h>
int main(){
    float radius, area;

    printf("Enter circle radius: ");
    scanf("%f", &radius);
    area = radius * radius * 3.14;
    printf("The area of the circle is %.2f\n", area);
    return 0;
}