#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"
#define buffer_size 300
#include <math.h>

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array


// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

                    }




// Complete the main function
int main() {
    FITNESS_DATA data[200];
    int run = 0;
    char choice;
    FILE *file;
    char filename[200];
    int total = 0;
    char line[buffer_size];
    char date[200];
    char time[200];
    char steps[200];
    int min = 100, max = 0;
    float num = 0, N, sum = 0, mean;



    while (run == 0){
        printf("Menu Options:\nA: Specify the filename to be imported\nB: Display the total number of records in the file\nC: Find the date and time of the timeslot with the fewest steps\nD: Find the date and time of the timeslot with the largest number of steps\nE: Find the mean step count of all the records in the file\nF: Find the longest continuous period where the step count is above 500 steps\nQ: Quit\n");
        printf("Enter choice: ");
        scanf(" %c", &choice);
        
        switch(choice){
            case 'A': 
            case 'a':
                printf("Input filename: ");
                scanf("%s", filename);
                file = fopen(filename, "r");
                if (file == NULL)
                {
                    printf("Error: File could not be opened\n");
                    return 1;
                }
                while (fgets(line, buffer_size, file)){
                    // adds the individual items to the array
                    tokeniseRecord(line,",",date,time,steps);
                    strcpy(data[total].date, date);
                    strcpy(data[total].time, time);
                    data[total].steps = atoi(steps);
                    if (atoi(steps) < min){
                        min = atoi(steps);
                    }
                    if (atoi(steps) > max){
                        max = atoi(steps);
                    }
                    total++;
                }
            break;

            case 'B':
            case 'b':
                printf("Number of records in file: %d\n", total);
            break;

            case 'C':
            case 'c':
                printf("Fewest steps: %d\n", min);
            break;

            case 'D':
            case 'd':
                printf("Largest steps: %d\n", max);
            break;

            case 'Q':
            case 'q': run = 1;
            break;

            default: printf("Hello\n");
            break;
        }


        }
        return 0;
    }
