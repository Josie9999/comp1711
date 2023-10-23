#include <stdio.h>

int main(){
    char filename [] = "squares.dat";
    FILE *file = fopen(filename, "w");
    if (file == NULL){
        perror("");
        return 1;
    }
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        fprintf(file, "%d\n", i * i);
    }
    float mean;
    for ()
    fclose(file);
    return 0;
}