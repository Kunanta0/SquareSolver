#ifndef OUTPUT_H_INCLUDED
#define OUTPUT_H_INCLUDED

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"
#define BLUE "\033[34m"

#define THINKING "Thinking..."

const int ms_time = 2000;

#include "maths.h"

void printans(struct ans, FILE*);
int menu(FILE* );

//выводит ответ
void printans(struct ans otvet, FILE* fp)
{
    printf(THINKING);

    Sleep(ms_time);
    for (unsigned int i = 0; i < strlen(THINKING); ++i)
    {
        printf("\b");
    }
    switch (otvet.id)
    {
    case QUAD_0_ROOTS:
        printf(YELLOW "Quadratic equation doesn't have real roots, because discriminant is less than zero\n\n" RESET);
        #ifdef DEBUG
        write_log(fp, LOG_INFO, PR_VAR(otvet.id, d));
        #endif
        break;
    case QUAD_1_ROOTS:
        printf(YELLOW "1 root, because discriminant is zero: %lg\n\n" RESET, otvet.x1);
        #ifdef DEBUG
        write_log(fp, LOG_INFO, PR_VAR(otvet.id, d));
        write_log(fp, LOG_INFO, PR_VAR(otvet.x1, lg));
        #endif
        break;
    case QUAD_2_ROOTS:
        printf(YELLOW "2 roots, because discriminant is bigger than zero: %lg and %lg\n\n" RESET, otvet.x1, otvet.x2);
        #ifdef DEBUG
        write_log(fp, LOG_INFO, PR_VAR(otvet.id, d));
        write_log(fp, LOG_INFO, PR_VAR(otvet.x1, lg));
        write_log(fp, LOG_INFO, PR_VAR(otvet.x2, lg));
        #endif
        break;
    case LINE:
        printf(YELLOW "Linear equation, because coefficient a = 0, root: %lg\n\n" RESET, otvet.x1);
        #ifdef DEBUG
        write_log(fp, LOG_INFO, PR_VAR(otvet.id, d));
        write_log(fp, LOG_INFO, PR_VAR(otvet.x1, lg));
        #endif
        break;
    case ZERO_EQUALS_ZERO:
        printf(YELLOW "Infinity number if roots, because all the coefficients are zeros (0 = 0)\n\n" RESET);
        #ifdef DEBUG
        write_log(fp, LOG_INFO, PR_VAR(otvet.id, d));
        #endif
        break;
    case ZERO_EQUALS_NO_ZERO:
        printf(YELLOW "No roots, condratiction, because all the coefficients except c are zero, (c != 0)\n\n" RESET);
        #ifdef DEBUG
        write_log(fp, LOG_INFO, PR_VAR(otvet.id, d));
        #endif
        break;
    }
}

//меню, которое запрашивает у пользователя запуск программы снова
int menu(FILE* flog)
{
    double number = 0;
    while (true)
    {
        number = check_input(flog);
        if (!(issame(number, 0)) && !(issame(number, 1)) && !(issame(number, 2)))
        {
            printf("Error: you entered wrong number: %lg. Enter 0, or 1, or 2: ", number);
            continue;
        }
        else break;
    }
    return int(number);
}

#endif // OUTPUT_H_INCLUDED
