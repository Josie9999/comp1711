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
    char min_date, max_date, min_time, max_time;
    int counter = 0;
    int mean;
    int total_value;
    int inrow = 0;
    int maxrow = 0;


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

                    total_value += data[total].steps;
                    total++;
                }
                int min = data[0].steps;
                char *min_date = data[0].date;
                char *min_time = data[0].time;
                int max = data[0].steps;
                char *max_date = data[0].date;
                char *max_time = data[0].time;
                char *start_date = data[0].date;
                char *start_time = data[0].time;
                char *end_date = data[0].date;
                char *end_time = data[0].time;
            break;

            case 'B':
            case 'b':
                printf("Number of records in file: %d\n", total);
            break;

            case 'C':
            case 'c':
                for (counter = 0; counter < total; counter++){
                    if (data[counter].steps < min){
                        min = data[counter].steps;
                        min_date = data[counter].date;
                        min_time = data[counter].time;
                    }
                }

                printf("Fewest steps: %s %s\n", min_date, min_time);
            break;

            case 'D':
            case 'd':
                for (counter = 0; counter < total; counter++){
                    if (data[counter].steps > max){
                        max = data[counter].steps;
                        max_date = data[counter].date;
                        max_time = data[counter].time;
                    }
                }

                printf("Largest steps: %s %s\n", max_date, max_time);
            break;

            case 'E':
            case 'e':
                mean = total_value / total;
                printf("Mean step count: %d\n", mean);
            break;

            case 'F':
            case 'f':
                for (counter = 0; counter < total; counter++){
                    if (data[counter].steps >= 500){
                        inrow += 1;
                    }
                    if (data[counter].steps < 500){
                        if (inrow >= maxrow){
                        start_date = data[counter - inrow].date;
                        start_time = data[counter - inrow].time;
                        }
                        if (inrow > maxrow){
                            maxrow = inrow;
                            end_date = data[counter - 1].date;
                            end_time = data[counter - 1].time;
                        }
                        inrow = 0;
                    }
                }
                printf("Longest period start: %s %s\n", start_date, start_time);
                printf("Longest period end: %s %s\n", end_date, end_time);
            break;

            case 'Q':
            case 'q': run = 1;
            break;

            default: printf("Error\n");
            break;
        }


        }
        return 0;
    }
