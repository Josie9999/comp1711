#include <stdio.h>
int main(){
    int num;
    //printf("Enter a number: ");
    //scanf("%d", &num);
    while (num != -1){
        printf("Enter a number: ");
        scanf("%d", &num);
        if (num >= 0 && num <= 100){
            printf("%d is in range\n", num);
        }
        else if (num == -1){
            printf("Termination value used");
        }
        else{
            printf("Out of range\n");
        }
    }
    return 0;
}