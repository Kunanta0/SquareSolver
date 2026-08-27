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
    #ifdef DEBUG
    fp = fopen("log.txt", "a");
    #endif
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
            struct ans ans_prog = answer(EQ);

            #ifdef DEBUG
            write_log(fp, LOG_INFO, PR_VAR(ans_prog.id, d));
            #endif
            printans(ans_prog, fp);
        }
        else
        {
            #ifdef DEBUG
            write_log(fp, LOG_INFO, PR_VAR(check, d));
            #endif
            test(argv[1], fp);
        }
    }
    printf(YELLOW "Пока!" RESET);
    #ifdef DEBUG
    if (fclose(fp) != 0) printf("Ошибка открытия файла\n");
    #endif
    return 0;
}
