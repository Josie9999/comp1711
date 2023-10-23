#include <stdio.h>
#include <stdlib.h>

int main(){
    char filename [] = "squares.dat";
    FILE *file = fopen(filename, "r");
    if (file == NULL){
        perror("");
        return 1;
    }

    int buffer_size = 100;
    float total = 0;
    float mean;
    int n = 0;
    char line_buffer[buffer_size];
    while (fgets(line_buffer, buffer_size, file) != NULL){
        printf("%s", line_buffer);
        total = total + atoi(line_buffer);
        n = n + 1;
    }
    mean = total / n;
    printf("The mean of the squares is %f\n", mean);

    fclose(file);
    return 0;
}