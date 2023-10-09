#include <stdio.h>

int main(){
    int width, height, area;

    printf("Please enter rectangle height: ");
    scanf("%d", &height);
    printf("Please enter rectangle width: ");
    scanf("%d", &width);
    area = width * height;
    printf("The area of the rectangle is %d\n", area);
    return 0;
}