#include <stdio.h>
#include <stdlib.h>

#define BSIZE 256 // buffer size

int main()
{
    const char fileName[] = "phrases.txt"; // assumed same dir
    FILE *fp;
    char buffer[BSIZE]; // reading text from file
    char *r;

    fp = fopen(fileName, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Unable to open file: %s\nIt probably does not exist in the current directory.", fileName);
        exit(1);
    }

    while (!feof(fp)) // `feof(FILE *stream)` checks if end of file has been reached
    {
        r = fgets(buffer, BSIZE, fp);   // Parsing stops if a newline character is found
        if (r == NULL)
            break;
        printf("%s", buffer);
    }

    fclose(fp);
    return(0);
}