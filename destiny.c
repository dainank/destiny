#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BSIZE 256

int main()
{
    const char fileName[] = "phrases.txt"; // assumed same dir
    FILE *fp;
    char buffer[BSIZE]; // temporary line storage
    char *r, *entry;
    int itemCount, x = 0;
    char **list_base; // pointer->pointers[]->string

    fp = fopen(fileName, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Unable to open file: %s\nIt probably does not exist in the current directory.", fileName);
        exit(1);
    }
    list_base = (char **)malloc(sizeof(char *) * 100); // TODO: Get number of lines dynamically.
    if (list_base == NULL)
    {
        fprintf(stderr, "Unable to allocate memory for `list_base`.\n");
        exit(1);
    }

    while (!feof(fp)) // `feof(FILE *stream)` checks if end of file has been reached
    {
        r = fgets(buffer, BSIZE, fp); // Parsing stops if a newline character is found (or buffer size reached)
        if (r == NULL)
            break;

        entry = (char *)malloc(sizeof(char) * strlen(buffer) + 1); // dynamic memory on heap that gets converted to intended type char to hold curr line
        if (entry == NULL)
        {
            fprintf(stderr, "Unable to allocate memory for `buffer` (current line).\n");
            exit(1);
        }

        strcpy(entry, buffer);
        *(list_base + itemCount) = entry;   // array of pointers gets assigned
        itemCount++;    // move to next pointer in array
    }

    fclose(fp);
    for (x; x < itemCount; x++)
        printf("%s", *(list_base + x)); // dereference value at address
    return (0);
}