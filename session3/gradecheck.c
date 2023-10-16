#include <stdio.h>
int main(){
    int mark;
    printf("Enter your mark: ");
    scanf("%d", &mark);
    if (mark < 50){
        printf("%d is a fail\n", mark);
    }
    else if (mark >= 50 && mark < 70){
        printf("%d is a pass\n", mark);
    }
    else{
        printf("%d is a distinction\n", mark);
    }
    return 0;
}