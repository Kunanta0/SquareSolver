#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

double asknum(char, FILE*);

//запрашивает коэффициенты квадратного уравнения
double asknum(char coeff, FILE* fp)
{
    double n = 0;
    char ch = '\0';
    bool bad_input = false;

    printf("Введите коэффициент %c: ", coeff);

    do
    {
        int coeff_entered = scanf("%lg", &n);
        if (coeff_entered != 1 || (ch = getchar()) != '\n')
        {
            printf("\"");
            if (coeff_entered == 1) printf("%lg", n);
            putchar(ch);
            while ((ch = getchar()) != '\n') putchar(ch);
            #ifdef DEBUG
            write_log(fp, LOG_INFO, "wrong users's input\n");
            #endif
            printf("\" не является числом, введите число: ");
            bad_input = true;
        }
        else bad_input = false;
    } while(bad_input);
    #ifdef DEBUG
    write_log(fp, LOG_INFO, "coefficient has been being inputted success\n");
    #endif
    return n;
}

#endif // INPUT_H_INCLUDED
