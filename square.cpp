#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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
    FILE* flog = NULL;
    #ifdef DEBUG
    flog = fopen("log.txt", "a");
    #endif
    while (true)
    {
        printf("Enter 0, to finish program, 1, to solve equation, 2, to start tests: ");

        int check = menu(flog);
        if (check == 0)
        {
            #ifdef DEBUG
            write_log(flog, LOG_INFO, PR_VAR(check, d));
            #endif
            break;
        }
        else if (check == 1)
        {
            #ifdef DEBUG
            write_log(flog, LOG_INFO, PR_VAR(check, d));
            #endif
            printf(YELLOW "Quadratic equation looks like ax^2 + bx + c = 0\n" RESET);

            struct coeffs EQ = init_eq(flog);
            struct ans ans_prog = answer(EQ);

            #ifdef DEBUG
            write_log(flog, LOG_INFO, PR_VAR(ans_prog.id, d));
            #endif
            printans(ans_prog, flog);
        }
        else
        {
            #ifdef DEBUG
            write_log(flog, LOG_INFO, PR_VAR(check, d));
            #endif
            test(argv[1], flog);
        }
    }
    printf(YELLOW "Bye!" RESET);
    #ifdef DEBUG
    if (fclose(flog) != 0) printf("Error of closing file\n");
    #endif
    return 0;
}
