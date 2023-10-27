#include <stdio.h>
#include <string.h>

typedef unsigned long long int array_size_t;

int main(){
    array_size_t array_size = 256;
    char array [array_size];
    for (array_size_t i = 0; i < array_size - 1; i++)
        array[i] = i + 1;
    array[array_size - 1] = '\0';

    printf("%ld-characterlong string:\n%s\n", strlen(array), array);
    return 0;
}