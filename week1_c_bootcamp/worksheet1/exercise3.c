#include <stdio.h>
#include <limits.h>

void main(){
    printf("Range of signed int \n%d to %d", INT_MIN, INT_MAX);
    printf("\nRange of unsigned int \n0 to %u\n\n", UINT_MAX);
 
    printf("Range of signed char \n%d to %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("Range of unsigned char \n0 to %d\n\n", UCHAR_MAX);
 
    printf("Range of signed short int \n%d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("Range of unsigned short int \n0 to %d\n\n", USHRT_MAX);
 
    printf("Range of signed long int \n%ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("Range of unsigned long int \n0 to %lu\n\n", ULONG_MAX);
}