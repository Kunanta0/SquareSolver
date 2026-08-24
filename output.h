#ifndef OUTPUT_H_INCLUDED
#define OUTPUT_H_INCLUDED

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"
#define BLUE "\033[34m"

#define THINKING "Думаю..."

#include "maths.h"


void printans(struct ans, FILE*);
int menu(FILE* );

//выводит ответ
void printans(struct ans otvet, FILE* fp)
{
    time_t now = time(NULL);
    char* time_str = ctime(&now);
    time_str[strcspn(time_str, "\n")] = 0;
    printf(THINKING);
    Sleep(2000);
    for (int i = 0;i < strlen(THINKING); ++i) printf("\b");
    switch (otvet.id)
    {
    case SQUARE_0:
        printf(YELLOW "Квадратное уравнение не имеет действительных корней, так как дискриминант меньше нуля\n\n" RESET);
        #ifdef DEBUG
        write_log(fp, time_str, LOG_INFO, PR_VAR(otvet.id, d));
        #endif
        break;
    case SQUARE_1:
        printf(YELLOW "1 решение, так как дискриминант равен нулю: %lg\n\n" RESET, otvet.x1);
        #ifdef DEBUG
        write_log(fp, time_str, LOG_INFO, PR_VAR(otvet.id, d));
        write_log(fp, time_str, LOG_INFO, PR_VAR(otvet.x1, lg));
        #endif
        break;
    case SQUARE_2:
        printf(YELLOW "2 решения, так как дискриминант больше нуля: %lg и %lg\n\n" RESET, otvet.x1, otvet.x2);
        #ifdef DEBUG
        write_log(fp, time_str, LOG_INFO, PR_VAR(otvet.id, d));
        write_log(fp, time_str, LOG_INFO, PR_VAR(otvet.x1, lg));
        write_log(fp, time_str, LOG_INFO, PR_VAR(otvet.x2, lg));
        #endif
        break;
    case LINE:
        printf(YELLOW "Линейное уравнение, так как коэффициент a = 0, корень: %lg\n\n" RESET, otvet.x1);
        #ifdef DEBUG
        write_log(fp, time_str, LOG_INFO, PR_VAR(otvet.id, d));
        write_log(fp, time_str, LOG_INFO, PR_VAR(otvet.x1, lg));
        #endif
        break;
    case ALWAYS_TRUE:
        printf(YELLOW "Бесконечное количество корней, так как все коэффициенты равны нулю (0 = 0)\n\n" RESET);
        #ifdef DEBUG
        write_log(fp, time_str, LOG_INFO, PR_VAR(otvet.id, d));
        #endif
        break;
    case ALWAYS_FALSE:
        printf(YELLOW "Корней нет, противоречие, так как все коэффициенты кроме c равны нулю, (c != 0)\n\n" RESET);
        #ifdef DEBUG
        write_log(fp, time_str, LOG_INFO, PR_VAR(otvet.id, d));
        #endif
        break;
    }
}

//меню, которое запрашивает у пользователя запуск программы снова
int menu(FILE* fp)
{
    time_t now = time(NULL);
    char* time_str = ctime(&now);
    time_str[strcspn(time_str, "\n")] = 0;
    char ch = '\0';
    bool notok = true;
    int n = 0;

    while(notok)
    {
        int cor = scanf("%d", &n);
        if (cor != 1 || (ch = getchar()) != '\n')
        {
            while ((ch = getchar()) != '\n') continue;
            #ifdef DEBUG
            printf("Неправильный ввод, введите 0, либо 1, либо 2: ");
            write_log(fp, time_str, LOG_INFO, "wrong users's input\n");
            #endif // DEBUG
        }
        else
        {
            if (n != 0 && n != 1 && n != 2)
            {
                printf("Неправильный ввод, введите 0, либо 1, либо 2: ");
                #ifdef DEBUG
                write_log(fp, time_str, LOG_INFO, "wrong users's input\n");
                #endif
            }
            else notok = false;
        }
    }
    #ifdef DEBUG
    write_log(fp, time_str, LOG_INFO, "in menu user entered "PR_VAR(n, d));
    #endif
    return n;
}

#endif // OUTPUT_H_INCLUDED
