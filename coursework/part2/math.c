#include <stdio.h>
#include <math.h>

int main(int argc, char*argv[])
{
    double average, num = 0, min = 0, max = 0, sum = 0, N, std_dev, sum_sqs = 0.0;

    if (argc <= 1)
    {
        fprintf(stderr, "Usage: %s file\n", argv[0]);
        return 1;
    }

    FILE *pFile = fopen(argv[1], "r");
    if (pFile == 0)
    {
        fprintf(stderr, "%s: failed to open file %s\n", argv[0], argv[1]);
        return 1;
    }
    if (fscanf(pFile, "%lf", &N) == 1)
    {
        for (int i = 0; i < N; i++)
        {
            if (fscanf(pFile, "%lF", &num) != 1)
            {
                fprintf(stderr, "%s: failed to read number\n", argv[0]);
                return 1;
            }

            if (num < min || i == 0)
                min = num;
            if (num > max || i == 0)
                max = num;
            sum += num;
            sum_sqs += (num*num);
        }
    }

    fclose(pFile);
    average = sum/N;

    printf("Smallest: %7.2lf\n", min);
    printf("Largest: %7.2lf\n", max);
    printf("Average: %7.2lf\n", average);
    return(0);
}