#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"
#define buffer_size 300

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array
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
    int rounding;
    int total_value;
    int inrow = 0;
    int maxrow = 0;

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
    while (run == 0){
        // Prints menu and gets user input for menu option
        printf("Menu Options:\nA: Specify the filename to be imported\nB: Display the total number of records in the file\nC: Find the date and time of the timeslot with the fewest steps\nD: Find the date and time of the timeslot with the largest number of steps\nE: Find the mean step count of all the records in the file\nF: Find the longest continuous period where the step count is above 500 steps\nQ: Quit\n");
        printf("Enter choice: ");
        scanf(" %c", &choice);
        
        switch(choice){
            case 'A': 
            case 'a':
                // Opens the file given by the user
                printf("Input filename: ");
                scanf("%s", filename);
                file = fopen(filename, "r");
                if (file == NULL)
                {
                    printf("Error: File could not be opened\n");
                    return 1;
                }
                printf("File successfully loaded\n");
                while (fgets(line, buffer_size, file)){
                    // adds the individual items to the array
                    tokeniseRecord(line,",",date,time,steps);
                    strcpy(data[total].date, date);
                    strcpy(data[total].time, time);
                    data[total].steps = atoi(steps);

                    // Adds up the total amount of steps taken to calculate the mean
                    total_value += data[total].steps;
                    // Total increments every time the for loop runs to calculate the total amount of records
                    total++;
                }
                // Defines values which are created in the array
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
                printf("Total records: %d\n", total);
                file = fopen(filename, "r");
            break;

            case 'C':
            case 'c':
                for (counter = 0; counter < total; counter++){
                    // If the steps for the current value being passed is smaller than the current smallest value, min, a new min is set
                    if (data[counter].steps < min){
                        // Sets the new date and time for the smallest amount of steps
                        min = data[counter].steps;
                        min_date = data[counter].date;
                        min_time = data[counter].time;
                    }
                }

                printf("Fewest steps: %s %s\n", min_date, min_time);
                file = fopen(filename, "r");
            break;

            case 'D':
            case 'd':
                for (counter = 0; counter < total; counter++){
                    // If the steps for the current value being passed through the for loop is larger than the current largest value, max, a new max is set
                    if (data[counter].steps > max){
                        // Sets the new date and time for the largest amount of steps
                        max = data[counter].steps;
                        max_date = data[counter].date;
                        max_time = data[counter].time;
                    }
                }

                printf("Largest steps: %s %s\n", max_date, max_time);
                file = fopen(filename, "r");
            break;

            case 'E':
            case 'e':
                // Calculates the mean
                mean = total_value / total;
                rounding = total_value % total;
                if (rounding >= (total/2)){
                    mean++;
                }
                printf("Mean step count: %d\n", mean);
                file = fopen(filename, "r");
            break;

            case 'F':
            case 'f':
                for (counter = 0; counter < total; counter++){
                    // If steps exceeds 500 the steps inrow value is incremented
                    if (data[counter].steps > 500){
                        inrow += 1;
                    }
                    if (data[counter].steps <= 500){
                        // If steps stop exceeding 500 and the amount of steps exceeding 500 in a row is larger than the
                        // current highest value a new start date is set, of the current value - how many steps in a row have been counted
                        if (inrow >= maxrow){
                        start_date = data[counter - inrow].date;
                        start_time = data[counter - inrow].time;
                        }
                        // Sets the new end date of the element which exceeds 500 steps and sets maxrow to the new highest value of inrow
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
                file = fopen(filename, "r");
            break;

            case 'Q':
            case 'q': run = 1;
            break;

            default: printf("Invalid choice. Try again.\n");
            break;
        }


        }
        return 0;
    }
