#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include "input.h"
#include "output.h"
#include "myassert.h"

int main(void)
{
    const char* s = (test_kvad(1, -5, 6, 2, 3)) ? "true" : "false";
    printf("%s\n", s);

    setlocale(LC_ALL, "Russian");

    int check = 0;

    do
    {
        printf("Квадратное уравнение имеет вид ax^2 + bx + c = 0\n");

        double a, b, c = 0;
        a = asknum('a');
        b = asknum('b');
        c = asknum('c');
        double D = Discriminant(a, b, c);

        printans(a, b, c, D);

        printf("Введите 0, чтобы завершить программу, 1, чтобы решать уравнение снова: ");

        check = menu();
    }
    while (check == 1);

    MyAssert(check == 1);

    printf("Пока!");
    return 0;
}
