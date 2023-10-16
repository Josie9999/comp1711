#include <stdio.h>
int main(){
    int option;
    printf("Enter a menu option between 1 and 5: ");
    scanf("%d", &option);
    switch(option){
        case 1: printf("Option 1 has been selected\n");
        break;
        case 2: printf("Option 2 has been selected\n");
        break;
        case 3: printf("Option 3 has been selected\n");
        break;
        case 4: printf("Option 4 has been selected\n");
        break;
        case 5: printf("Option 5 has been selected\n");
        break;
        default: printf("Invalid choice selected\n");
    }
    }