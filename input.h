#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

#include "log.h"

double asknum(char, FILE*);

//запрашивает коэффициенты квадратного уравнения
double asknum(char coeff, FILE* fp)
{
    time_t now = time(NULL);
    char* time_str = ctime(&now);
    time_str[strcspn(time_str, "\n")] = 0;
    double n = 0;
    printf("Введите коэффициент %c: ", coeff);
    char ch = '\0';
    bool notok = true;

    while(notok)
    {
        int cor = scanf("%lg", &n);
        if (cor != 1 || (ch = getchar()) != '\n')
        {
            while ((ch = getchar()) != '\n') continue;
            #ifdef DEBUG
            write_log(fp, time_str, LOG_INFO, "wrong users's input\n");
            #endif
            printf("Неправильный ввод, введите число: ");
        }
        else notok = false;
    }
    #ifdef DEBUG
    write_log(fp, time_str, LOG_INFO, "coefficient has been being inputted success\n");
    #endif
    return n;
}


#endif // INPUT_H_INCLUDED
