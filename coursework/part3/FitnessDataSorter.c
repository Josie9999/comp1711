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
char i, j;
FitnessData temp;


// Function to tokenize a record
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
int tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        
        strcpy(date, token);
    }
    else{
        return 1;
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    else{
        return 1;
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL && (token[0] > 47 && token[0] < 58)){
        strcpy(steps, token);
    }
    else{
        return 1;
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


    while (fgets(line, buffer_size, file)!=NULL){
        // adds the individual items to the array
        if (tokeniseRecord(line,",",date,time,steps) == 1){
            printf("Error: invalid file\n");
            return 1;
        }
        strcpy(data[total].date, date);
        if (data[i].date == ""){
            return 1;
        }
        strcpy(data[total].time, time);
        data[total].steps = atoi(steps);
        total++;
    }

    // orders the steps into decending order
    for (i = 0; i < total; ++i){
        for (j = i + 1; j < total; ++j){
            if (data[i].steps < data[j].steps){
                temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
    

    // gives the variable newFile the value of the filename and adds .tsv
    char *newFile;
    newFile = strcat(filename,".tsv");
    fclose(file);

    // opens the new file 
    FILE *fp;
    fp = fopen(newFile, "w+");
    // adds the value of the date, time ands 
    for (i = 0; i < total; ++i){
        fprintf(fp, "%s\t%s\t%d\n", data[i].date, data[i].time, data[i].steps);
    }
    printf("Data sorted and written to %s\n", newFile);
    fclose(fp);
    return 0;
}