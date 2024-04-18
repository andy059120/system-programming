#include <stdio.h>
#include <string.h>

const char rewds[][10] = { // 31
    "if", "do", "for", "int", "break", "default", "float",
    "double", "case", "else", "extern", "sizeof", "register",
    "while", "enum", "union", "goto", "auto", "char", "const",
    "static", "switch", "continue", "struct", "return", "long",
    "short", "signed", "unsigned", "typedef", "void"};

void start(FILE *fin, FILE *fout)
{
    int SLOC = 1;
    int index = 0;
    int i = 0;
    char c;
    char buffer[255];
    char token[10];
    int flagIDEN = 0;
    int flagREWD = 0;
    int flagINTE = 0;
    int flagFLOT = 0;
    int flagSC = 0;
    int flagPREP = 0;

    while (fscanf(fin, "%c", &buffer[index]) != EOF)
    {
        // PREP
        if (buffer[index] == 35)
        {
            flagPREP = 1;
            if (flagPREP == 1)
            {
                fprintf(fout, "%d ", SLOC);
                fprintf(fout, "%s ", "PREP");
                flagSC++;
            }
            else if (flagSC > 1)
            {
                fprintf(fout, "%s", buffer);
                fprintf(fout, "%c", '\n');
                flagPREP = 0;
                continue;
            }
        }

        // SC
        if (buffer[index] == 47)
        {
            if (flagSC == 1)
            {
                fprintf(fout, "%d ", SLOC);
                fprintf(fout, "%s ", "SC");
                fprintf(fout, "%s", "//");
                flagSC++;
            }
            else if (flagSC > 1)
            {
                fprintf(fout, "%c", buffer[index]);
                fprintf(fout, "%c", '\n');
                // flagSC = 0;
                continue;
            }
            else
            {
                flagSC = 0;
            }
            flagSC = 1;
        }

        // SPEC
        if (buffer[index] == 123 || buffer[index] == 125 || buffer[index] == 40 || buffer[index] == 41 || buffer[index] == 58 || buffer[index] == 59 || buffer[index] == 63)
        {
            fprintf(fout, "%d ", SLOC);
            fprintf(fout, "%s ", "SPEC");
            fprintf(fout, "%c", buffer[index]);
            fprintf(fout, "%c", '\n');
        }

        if (buffer[index] == '\n')
        {
            SLOC++;
        }

        index %= 255;

        // IDEN & REWD

        if ((buffer[index] == 95 || buffer[index] >= 65 && buffer[index] <= 90 || buffer[index] >= 97 && buffer[index] <= 122) && i < 10)
        {
            if ((buffer[index] == 69 || buffer[index] == 101) && flagFLOT)
            {
                token[i] = buffer[index];
                i++;
                flagINTE = 1;
                flagFLOT = 1;
                flagIDEN = 0;
                flagREWD = 0;
                continue;
            }
            token[i] = buffer[index];
            i++;
            flagREWD = 1;
            flagIDEN = 1;
            flagINTE = 0;
            flagFLOT = 0;
            continue;
        }

        // INTE & FLOT
        if (flagFLOT)
        {
            if ((buffer[index] == 43 || buffer[index] == 45 || buffer[index] == 46 || buffer[index] >= 48 && buffer[index] <= 57 || buffer[index] == 69 || buffer[index] == 101) && i < 10)
            {
                token[i] = buffer[index];
                i++;
                flagINTE = 1;
                flagFLOT = 1;
                flagIDEN = 0;
                flagREWD = 0;
                continue;
            }
        }
        else
        {
            if ((buffer[index] == 43 || buffer[index] == 45 || buffer[index] == 46 || buffer[index] >= 48 && buffer[index] <= 57) && i < 10)
            {
                token[i] = buffer[index];
                i++;
                flagINTE = 1;
                flagFLOT = 1;
                flagIDEN = 0;
                flagREWD = 0;
                continue;
            }
        }

        if (!flagFLOT)
        {
            // OPER
            if (buffer[index] == 33 || buffer[index] == 37 || buffer[index] == 38 || (buffer[index] >= 42 && buffer[index] <= 47) || (buffer[index] >= 60 && buffer[index] <= 62) || buffer[index] == 91 || buffer[index] == 93 || buffer[index] == 94)
            {
                fprintf(fout, "%d ", SLOC);
                fprintf(fout, "%s ", "OPER");
                fprintf(fout, "%c", buffer[index]);
                fprintf(fout, "%c", '\n');
            }
        }

        if (flagINTE)
        {
            if (i == 0)
                continue;
            for (int j = i; j < 10; j++)
            {
                token[i] = '\0';
            }
            for (int j = 0; j < i; j++)
            {
                if (token[j] == 46 || token[j] == 69 || token[j] == 101)
                {
                    flagINTE = 0;
                }
            }
            if (flagINTE)
            {
                fprintf(fout, "%d ", SLOC);
                fprintf(fout, "%s ", "INTE");
                for (int j = 0; j < i; j++)
                {
                    fprintf(fout, "%c", token[j]);
                }
                fprintf(fout, "%c", '\n');
                flagIDEN = 0;
                i = 0;
                continue;
            }
        }
        if (flagFLOT)
        {
            fprintf(fout, "%d ", SLOC);
            fprintf(fout, "%s ", "FLOT");
            for (int j = 0; j < i; j++)
            {
                fprintf(fout, "%c", token[j]);
            }
            fprintf(fout, "%c", '\n');
            flagFLOT = 0;
            i = 0;
            continue;
        }
        if (flagREWD)
        {
            for (int j = i; j < 10; j++)
            {
                token[i] = '\0';
            }
            for (int j = 0; j < 31; j++)
            {
                if (strcmp(token, rewds[j]) == 0)
                {
                    fprintf(fout, "%d ", SLOC);
                    fprintf(fout, "%s ", "REWD");
                    fprintf(fout, "%s", token);
                    fprintf(fout, "%c", '\n');
                    i = 0;
                    flagREWD = 0;
                    continue;
                }
            }
            flagREWD = 0;
        }
        if (flagIDEN)
        {
            if (i == 0)
                continue;

            fprintf(fout, "%d ", SLOC);
            fprintf(fout, "%s ", "IDEN");
            for (int j = 0; j < i; j++)
            {
                fprintf(fout, "%c", token[j]);
            }
            fprintf(fout, "%c", '\n');
            flagIDEN = 0;
            i = 0;
        }
    }
}

int main()
{
    FILE *inputFile = fopen("123.txt", "r");
    FILE *outputFile = fopen("output.txt", "w");
    if (inputFile == NULL)
    {
        printf("failed to open the file.\n");
        return 1; // EXIT_FAILURE
    }

    start(inputFile, outputFile);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}