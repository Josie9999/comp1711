#include <stdio.h>
int main(){
    int temp;
    printf("Enter the temperature: ");
    scanf("%d", &temp);
    if (temp >= -10 && temp <= 40){
        printf("%d is within the range -10 mto 40 degrees celsius\n", temp);
    }
    else{
    printf("%d is not in range\n", temp);
    }
  return 0;
}
