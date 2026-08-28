#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

double asknum(char, FILE*);
double check_input(FILE* );

//asks coefficients of quadratic equation
double asknum(char coeff, FILE* flog)///<function asknum() accepts char coefficient and ask it
{
    printf("Enter coefficient %c: ", coeff);

    return check_input(flog);
}

///function check_input() accepts log file to write there user's number, while he won't enter good input
//check input
double check_input(FILE* flog)
{
    while(true)
    {
        double number = 0;
        char ch = '0';
        int return_scanf = scanf("%lg", &number);
        if (return_scanf != 1 || (ch = getchar()) != '\n')
        {
            if (return_scanf == 1)
            {
                printf("\"%lg", number);
                putchar(ch);
                while((ch = getchar()) != '\n') putchar(ch);
                printf("\" - wrong input, enter a number: ");
                continue;
            }
            else
            {
                printf("\"");
                while((ch = getchar()) != '\n') putchar(ch);
                printf("\" - wrong input, enter a number: ");
                continue;
            }
        }
        #ifdef DEBUG
        write_log(flog, LOG_INFO, PR_VAR(number, d));
        #endif

        return number;
    }
}

#endif // INPUT_H_INCLUDED
