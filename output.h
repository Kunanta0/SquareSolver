#ifndef OUTPUT_H_INCLUDED
#define OUTPUT_H_INCLUDED

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"
#define BLUE "\033[34m"

#define THINKING "Думаю..."

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
        printf(YELLOW "Квадратное уравнение не имеет действительных корней, так как дискриминант меньше нуля\n\n" RESET);
        #ifdef DEBUG
        write_log(fp, LOG_INFO, PR_VAR(otvet.id, d));
        #endif
        break;
    case QUAD_1_ROOTS:
        printf(YELLOW "1 решение, так как дискриминант равен нулю: %lg\n\n" RESET, otvet.x1);
        #ifdef DEBUG
        write_log(fp, LOG_INFO, PR_VAR(otvet.id, d));
        write_log(fp, LOG_INFO, PR_VAR(otvet.x1, lg));
        #endif
        break;
    case QUAD_2_ROOTS:
        printf(YELLOW "2 решения, так как дискриминант больше нуля: %lg и %lg\n\n" RESET, otvet.x1, otvet.x2);
        #ifdef DEBUG
        write_log(fp, LOG_INFO, PR_VAR(otvet.id, d));
        write_log(fp, LOG_INFO, PR_VAR(otvet.x1, lg));
        write_log(fp, LOG_INFO, PR_VAR(otvet.x2, lg));
        #endif
        break;
    case LINE:
        printf(YELLOW "Линейное уравнение, так как коэффициент a = 0, корень: %lg\n\n" RESET, otvet.x1);
        #ifdef DEBUG
        write_log(fp, LOG_INFO, PR_VAR(otvet.id, d));
        write_log(fp, LOG_INFO, PR_VAR(otvet.x1, lg));
        #endif
        break;
    case ZERO_EQUALS_ZERO:
        printf(YELLOW "Бесконечное количество корней, так как все коэффициенты равны нулю (0 = 0)\n\n" RESET);
        #ifdef DEBUG
        write_log(fp, LOG_INFO, PR_VAR(otvet.id, d));
        #endif
        break;
    case ZERO_EQUALS_NO_ZERO:
        printf(YELLOW "Корней нет, противоречие, так как все коэффициенты кроме c равны нулю, (c != 0)\n\n" RESET);
        #ifdef DEBUG
        write_log(fp, LOG_INFO, PR_VAR(otvet.id, d));
        #endif
        break;
    }
}

//меню, которое запрашивает у пользователя запуск программы снова
int menu(FILE* fp)
{
    char ch = '\0';
    int n = 0;
    do
    {
        int coeff_entered = scanf("%d", &n);
        if (coeff_entered != 1 || (ch = getchar()) != '\n' || (n != 0 && n != 1 && n != 2))
        {
            printf("\"");
            if (coeff_entered == 1) printf("%d", n);
            putchar(ch);
            while ((ch = getchar()) != '\n') putchar(ch);
            printf("\" - неправильный ввод, введите 0, либо 1, либо 2: ");
            #ifdef DEBUG
            write_log(fp, LOG_INFO, "wrong users's input\n");
            #endif // DEBUG
        }
        else break;
    } while(true);
    #ifdef DEBUG
    write_log(fp, LOG_INFO, "in menu user entered "PR_VAR(n, d));
    #endif
    return n;
}

#endif // OUTPUT_H_INCLUDED
