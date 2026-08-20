#ifndef OUTPUT_H_INCLUDED
#define OUTPUT_H_INCLUDED

#include "maths.h"

void answer(double, double);
void answers(double, double, double);
void printans(double, double, double, double);
int menu();
//выводит единственное решение
void answer(double a, double b)
{
    double ans = -b / 2 / a;
    printf("1 решение: %.2lg\n", ans);
}

//выводит два решения
void answers(double a, double b, double D)
{
    double ans1 = (-b + sqrt(D)) / 2 / a;
    double ans2 = (-b - sqrt(D)) / 2 / a;
    printf("2 решения: %.2lg, %.2lg\n", ans1, ans2);
}

//выводит ответ
void printans(double a, double b, double c, double D)
{
    if (!isnull(a, 0))
    {
        if (D < 0) printf("Корней нет\n");
        else if (isnull(D, 0)) answer(a, b);
        else answers(a, b, D);
    }
    else
    {
        if (isnull(b, 0))
        {
            if (isnull(c, 0))
            {
                printf("Бесконечное количество корней\n");
            }
            else printf("Нет корней\n");
        }
        else
        {
            printf("Линейное уравнение, корень: %.2lg\n", -c / b);
        }
    }
}

//меню, которое запрашивает у пользователя запуск программы снова
int menu()
{
    char ch = '\0';
    bool notok = true;
    int n = 0;

    while(notok)
    {
        int cor = scanf("%d", &n);
        if (cor != 1 || (ch = getchar()) != '\n')
        {
            while ((ch = getchar()) != '\n') continue;
            printf("Неправильный ввод, введите 0 либо 1: ");
        }
        else
        {
            if (n != 1 && n != 0) printf("Неправильный ввод, введите 0 либо 1: ");
            else notok = false;
        }
    }

    return n;
}


#endif // OUTPUT_H_INCLUDED
