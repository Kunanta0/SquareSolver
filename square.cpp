#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <math.h>
#include <windows.h>
#include "input.h"
#include "output.h"
#include "myassert.h"
#include "testik.h"
#include "log.h"


//0 - нет решения квадратного уравнения
//1 - 1 решение квадратного уравнения
//2 - 2 решения квадратного уравнения
//3 - 1 решение, линейное уравнение
//4 - бесконечное количество решений
//5 - нет решений, противоречие


int main(int argc, char* argv[])
{
    time_t now = time(NULL);
    char* time_str = ctime(&now);
    time_str[strcspn(time_str, "\n")] = 0;
    FILE* fp = NULL;
    fp = fopen("log.txt", "a");
    setlocale(LC_ALL, "Russian");

    while (true)
    {
        printf("Введите 0, чтобы завершить программу, 1, чтобы решать уравнение, 2, чтобы запустить тесты: ");
        int check = menu(fp);
        if (check == 0)
        {
            #ifdef DEBUG
            write_log(fp, time_str, LOG_INFO, PR_VAR(check, d));
            #endif
            break;
        }
        else if (check == 1)
        {
            #ifdef DEBUG
            write_log(fp, time_str, LOG_INFO, PR_VAR(check, d));
            #endif
            printf(YELLOW "Квадратное уравнение имеет вид ax^2 + bx + c = 0\n" RESET);

            struct coeffs EQ =
            {
                asknum('a', fp),
                asknum('b', fp),
                asknum('c', fp),
            };
            int id = num_sol(EQ);
            #ifdef DEBUG
            write_log(fp, time_str, LOG_INFO, PR_VAR(id, d));
            #endif
            struct ans otvet = answer(EQ, id);
            printans(otvet, fp);
        }
        else if (check == 2)
        {
            #ifdef DEBUG
            write_log(fp, time_str, LOG_INFO, PR_VAR(check, d));
            #endif
            test(argc, argv, fp);
        }
    }
    printf(YELLOW "Пока!" RESET);
    fclose(fp);
    return 0;
}
