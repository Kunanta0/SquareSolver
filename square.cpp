#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
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


int main(void)
{
    setlocale(LC_ALL, "Russian");

    while (true)
    {
        printf(YELLOW "Введите 0, чтобы завершить программу, 1, чтобы решать уравнение, 2, чтобы запустить тесты: ");
        int check = menu();
        if (check == 0) break;
        else if (check == 1)
        {
            printf(YELLOW "Квадратное уравнение имеет вид ax^2 + bx + c = 0\n");

            struct coeffs EQ =
            {
                asknum('a'),
                asknum('b'),
                asknum('c'),
            };
            int id = num_sol(EQ);
            struct ans otvet = answer(EQ, id);
            printans(otvet);
        }
        else if (check == 2) test();
    }
    printf(YELLOW "Пока!" RESET);
    return 0;
}
