#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define buffer_size 300

// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

//Additional Variables
FitnessData data[200];
FILE *file;
char filename[200];
char line[buffer_size];
char date[200];
char time[200];
char steps[200];
int total = 0;
int i, j, temp;

// Function to tokenize a record
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


int main() {
    // Opens the file given by the user
    printf("Enter filename: ");
    scanf("%s", filename);
    file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error: invalid file\n");
        return 1;
    }
    printf("File successfully loaded\n");
    while (fgets(line, buffer_size, file)){
        // adds the individual items to the array
        tokeniseRecord(line,",",date,time,steps);
        strcpy(data[total].date, date);
        strcpy(data[total].time, time);
        data[total].steps = atoi(steps);
        total++;
    }

    for (i = 0; i < total; ++i){
        for (j = i + 1; j < total; ++j){
            if (data[i].steps < data[j].steps){
                temp = data[i].steps;
                data[i].steps = data[j].steps;
                data[j].steps = temp;
            }
        }
    }
    
    for (i = 0; i < total; ++i){
        printf("%d\n", data[i].steps);
    }
    fclose(file);

    FILE *fp;
    char newFile[200];
    strcat(newFile,".tsv");
    fp = fopen(newFile, "w");

    return 0;
}