#ifndef OUTPUT_H_INCLUDED
#define OUTPUT_H_INCLUDED

#include "maths.h"

void printans(struct ans);
int menu();

//выводит ответ
void printans(struct ans otvet)
{
    switch (otvet.id)
    {
    case 0:
        printf("Квадратное уравнение не имеет действительных корней\n");
        break;
    case 1:
        printf("1 решение: %lg\n", otvet.x1);
        break;
    case 2:
        printf("2 решения: %lg и %lg\n", otvet.x1, otvet.x2);
        break;
    case 3:
        printf("Линейное уравнение, корень: %lg\n", otvet.x1);
        break;
    case 4:
        printf("Бесконечное количество корней\n");
        break;
    case 5:
        printf("Корней нет, противоречие\n");
        break;
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
