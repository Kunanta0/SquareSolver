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

    struct coeffs cf[6] =
    {
        {1, 5, 6},
        {1, -2, 1},
        {0, 0, 0},
        {0, 0, 4},
        {0, 6, 36},
        {100, 1, 100},
    } ;

    struct ans otvety[6] =
    {
        {2, -2, -3},
        {1, 1, ZERO},
        {4, ZERO, ZERO},
        {5, ZERO, ZERO},
        {3, -6, ZERO},
        {0, ZERO, ZERO},
    };

    for (int i = 0;i < 6;++i)
    {
        if (test(cf[i], otvety[i]) == 0) return 1;
    }

    int check = 0;

    do
    {
        printf("Квадратное уравнение имеет вид ax^2 + bx + c = 0\n");

        struct coeffs EQ =
        {
            asknum('a'),
            asknum('b'),
            asknum('c'),
        };
        int id = num_sol(EQ);
        struct ans otvet = answer(EQ, id);
        printans(otvet);

        printf("Введите 0, чтобы завершить программу, 1, чтобы решать уравнение снова: ");

        check = menu();
    } while (check == 1);

    printf("Пока!");
    return 0;
}
