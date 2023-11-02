#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	char steps[1000];
} FITNESS_DATA;

// Define any additional variables here
    int total = 0;
    int i;
    int no_of_steps;


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
    // Creates an array with size 100
    FITNESS_DATA data[100];
    int buffer_size = 250;
    char line[buffer_size];
    int counter = 0;

    // Opens file FitnessData_2023.csv
    char filename [] = "FitnessData_2023.csv";
    FILE *file = fopen(filename, "r");
    // Returns 1 if file is empty
    if (file == NULL){
        perror("");
        return 1;
    }

    char date[200];
    char time[200];
    char steps[200];

    while (fgets(line, buffer_size, file))
    {   
        // adds the individual items to the array
        tokeniseRecord(line,",",date,time,steps);
        strcpy(data[total].date, date);
        strcpy(data[total].time, time);
        strcpy(data[total].steps, steps);
        // increments total by 1
        total++;

    }
    printf("Number of records in file: %d\n", total);
    
    // prints the first 3 lines 
    for(i=0; i < 3; i++){
        no_of_steps = atoi(data[i].steps);
        printf("%s/%s/%d\n", data[i].date, data[i].time, no_of_steps);
    }
}
