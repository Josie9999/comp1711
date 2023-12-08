# include <stdio.h>
#include <string.h>

int main(){
    typedef struct{
        char date[20];
        float bloodIron;
    } reading;

reading Today;
Today.bloodIron = 13;

reading Week[7];
Week[0].bloodIron = 5;

strcpy(Week[0].date, "Example");
}