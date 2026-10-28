// Name: Tanishq Last Name: Parashar StudentID: 241ADB173
// Compile with: gcc -O2 -Wall -Wextra -std=c17 -o calc calc.c -lm
// Resources used: None yet.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    const char *input_file = NULL;
    const char *input_dir = NULL;
    const char *output_dir = NULL;

    FILE *input = NULL;

    if (argc == 1)
    {
        fprintf(stderr, "Error: no input specified.\n");
        return 1;
    }

    if (argc == 2)
    {
        input_file = argv[1];
    }
    else if (argc == 3)
    {
        if (strcmp(argv[1], "-d") == 0 || strcmp(argv[1], "--dir") == 0)
        {
            input_dir = argv[2];
        }
    }
    else if (argc == 4)
    {
        if (strcmp(argv[1], "-o") == 0 || strcmp(argv[1], "--output-dir") == 0)
        {
            output_dir = argv[2];
            input_file = argv[3];
        }
    }

    if (input_file != NULL)
    {
        input = fopen(input_file, "r");

        if (input == NULL)
        {
            fprintf(stderr, "Error: cannot open input file.\n");
            return 1;
        }

        printf("Input file opened successfully.\n");

        fclose(input);
    }

    if (input_dir != NULL)
    {
        printf("Input directory: %s\n", input_dir);
    }

    if (output_dir != NULL)
    {
        printf("Output directory: %s\n", output_dir);
    }

    return 0;
}