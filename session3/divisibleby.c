#include <stdio.h>
int main(){
    int num = 21;
    if (num % 5 == 0 && num % 4 == 0){
        printf("%d is divisible by 4 and 5\n", num);
    }
    else{
        printf("%d is not divible by 4 and 5\n", num);
    }
    return 0;
}