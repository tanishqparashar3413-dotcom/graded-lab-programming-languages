// Name: Tanishq Last Name: Parashar StudentID: 241ADB173
// Compile with: gcc -O2 -Wall -Wextra -std=c17 -o calc calc.c -lm
// Resources used: ChatGPT (parser structure and debugging assistance).

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static const char *p;

static void skip_spaces(void)
{
    while (*p == ' ' || *p == '\t')
    {
        p++;
    }
}

static long long parse_number(void)
{
    long long value = 0;

    while (isdigit((unsigned char)*p))
    {
        value = value * 10 + (*p - '0');
        p++;
    }

    return value;
}
static long long parse_expression(void);

static long long parse_term(void)
{
    skip_spaces();

    if (!isdigit((unsigned char)*p))
    {
        return 0;
    }

    return parse_number();
}

static long long parse_expression(void)
{
    long long value = parse_term();

    while (1)
    {
        skip_spaces();

        if (*p == '+')
        {
            p++;
            value += parse_term();
        }
        else if (*p == '-')
        {
            p++;
            value -= parse_term();
        }
        else
        {
            break;
        }
    }

    return value;
}
int main(int argc, char *argv[])
{
    const char *input_file = NULL;
    const char *input_dir = NULL;
    const char *output_dir = NULL;

    FILE *input = NULL;
    FILE *output = NULL;
    char line[1024];

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

        if (output_dir != NULL)
        {
            output = fopen("output.txt", "w");

            if (output == NULL)
            {
                fprintf(stderr, "Error: cannot create output file.\n");
                fclose(input);
                return 1;
            }

            while (fgets(line, sizeof(line), input) != NULL)
{
    p = line;

    long long result = parse_expression();

    skip_spaces();

    if (*p != '\0' && *p != '\n')
    {
        fprintf(output, "ERROR\n");
    }
    else
    {
        fprintf(output, "%lld\n", result);
    }
}

            fclose(output);
        }
        else
        {
            while (fgets(line, sizeof(line), input) != NULL)
{
    p = line;

    long long result = parse_expression();

    skip_spaces();

    if (*p != '\0' && *p != '\n')
    {
        printf("ERROR\n");
    }
    else
    {
        printf("%lld\n", result);
    }
}
        }

        fclose(input);
    }

    if (input_dir != NULL)
    {
        printf("Input directory: %s\n", input_dir);
    }

    return 0;
}