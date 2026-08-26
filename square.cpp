#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <math.h>
#include <windows.h>
#include "log.h"
#include "input.h"
#include "output.h"
#include "myassert.h"
#include "testik.h"

//0 - нет решения квадратного уравнения
//1 - 1 решение квадратного уравнения
//2 - 2 решения квадратного уравнения
//3 - 1 решение, линейное уравнение
//4 - бесконечное количество решений
//5 - нет решений, противоречие


int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Russian");
    FILE* fp = NULL;
    fp = fopen("log.txt", "a");
    while (true)
    {
        printf("Введите 0, чтобы завершить программу, 1, чтобы решать уравнение, 2, чтобы запустить тесты: ");
        int check = menu(fp);
        if (check == 0)
        {
            #ifdef DEBUG
            write_log(fp, LOG_INFO, PR_VAR(check, d));
            #endif
            break;
        }
        else if (check == 1)
        {
            #ifdef DEBUG
            write_log(fp, LOG_INFO, PR_VAR(check, d));
            #endif
            printf(YELLOW "Квадратное уравнение имеет вид ax^2 + bx + c = 0\n" RESET);

            struct coeffs EQ = init_eq(fp);

            #ifdef DEBUG
            write_log(fp, LOG_INFO, PR_VAR(id, d));
            #endif
            struct ans correct = answer(EQ);
            printans(correct, fp);
        }
        else
        {
            #ifdef DEBUG
            write_log(fp, LOG_INFO, PR_VAR(check, d));
            #endif
            test(argc, argv, fp);
        }
    }
    printf(YELLOW "Пока!" RESET);
    if (fclose(fp) != 0) printf("Ошибка открытия файла\n");
    return 0;
}
