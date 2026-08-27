#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

const int MAX_SIZE = 100;
double asknum(char, FILE*);
double check_input(FILE* );

//запрашивает коэффициенты квадратного уравнения
double asknum(char coeff, FILE* fp)
{
    printf("Enter coefficient %c: ", coeff);

    return check_input(fp);
}

//проверяет корректность ввода
double check_input(FILE* flog)
{
    char input[MAX_SIZE] = {};
    char* endptr = NULL;
    double number = 0;

    while(true)
    {
        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            printf("Input error\n");
            #ifdef DEBUG
            write_log(flog, LOG_INFO, "wrong users's input\n");
            #endif // DEBUG
            continue;
        }

        input[strcspn(input, "\n")] = 0;
        if (strlen(input) == 0)
        {
            printf("Error: empty input. Enter 0, or 1, or 2: ");
            #ifdef DEBUG
            write_log(flog, LOG_INFO, "wrong users's input\n");
            #endif // DEBUG
            continue;
        }

        number = strtod(input, &endptr);
        if (*endptr != '\0')
        {
            printf("Error: \"%s\" is not a number. Enter 0, or 1, or 2: ", input);
            #ifdef DEBUG
            write_log(flog, LOG_INFO, "wrong users's input\n");
            #endif // DEBUG
            continue;
        }
        return number;
    }
}

#endif // INPUT_H_INCLUDED
