#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include "input.h"
#include "output.h"
#include "myassert.h"

//0 - нет решения квадратного уравнения
//1 - 1 решение квадратного уравнения
//2 - 2 решения квадратного уравнения
//3 - 1 решение, линейное уравнение
//4 - бесконечное количество решений
//5 - нет решений, противоречие

int main(void)
{
    setlocale(LC_ALL, "Russian");

    int check = 0;

    do
    {
        printf("Квадратное уравнение имеет вид ax^2 + bx + c = 0\n");

        double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;

        struct coeffs EQ =
        {
            asknum('a'),
            asknum('b'),
            asknum('c'),
        };

        int id = num_sol(EQ);

        struct ans otvet = answer(EQ, id);

        switch (otvet.id)
        {
            case 1:
                test_kvad1(EQ, otvet.x1);
                break;
            case 2:
                test_kvad2(EQ, otvet.x1, otvet.x2);
                break;
            case 3:
                test_kvad3(EQ, otvet.x1);
                break;
            default:
                break;
        }
        printans(otvet);

        printf("Введите 0, чтобы завершить программу, 1, чтобы решать уравнение снова: ");

        check = menu();
    } while (check == 1);

    printf("Пока!");
    return 0;
}
