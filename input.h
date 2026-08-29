/**
*\file
*\brief Header with input functions
*/

#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

/**
*accepts char coefficient and ask it
*\param[out] coeff char of coefficient
*\param[out] flog log file
*\return double number, which users entered
*/
double asknum(char, FILE*);

/**
*accepts log file to write there user's number, while he won't enter good input
*\param[out] flog log file
*\return number after checking
*/
double check_input(FILE* );

//asks coefficients of quadratic equation
double asknum(char coeff, FILE* flog)
{
    printf("Enter coefficient %c: ", coeff);

    return check_input(flog);
}

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
            printf("\"");
            if (return_scanf == 1) putchar(ch);
            while((ch = getchar()) != '\n') putchar(ch);
            printf("\" is not a number input, enter a number: ");
            continue;
        }

        if (isinf(number))
        {
            printf("Too big number, try again: ");
            continue;
        }
        #ifdef DEBUG
        write_log(flog, LOG_INFO, PR_VAR(number, lg));
        #endif

        return number;
    }
}

#endif // INPUT_H_INCLUDED
