#include <stdio.h>
int main(){
    int var1, var2, temp1, temp2;
    printf("Enter a number: ");
    scanf("%d", &var1);
    printf("Enter a number: ");
    scanf("%d", &var2);
    temp1 = var1;
    temp2 = var2;
    var1 = temp2;
    var2 = temp1;

    printf("The swapped numbers are %d and %d\n", var1, var2);
    return 0;
}