#include <stdio.h>
#include <locale.h>
#include <math.h>
#include "input.h"
#include "output.h"
#include "myassert.h"

int main(void)
{

    setlocale(LC_ALL, "Russian");

    int check = 0;

    do
    {
        printf("Квадратное уравнение имеет вид ax^2 + bx + c = 0\n");

        double a = 0, b = 0, c = 0;
        a = asknum('a');
        b = asknum('b');
        c = asknum('c');
        double D = Discriminant(a, b, c);

        printans(a, b, c, D);

        printf("Введите 0, чтобы завершить программу, 1, чтобы решать уравнение снова: ");

        check = menu();
    }
    while (check == 1);

    printf("Пока!");
    return 0;
}
