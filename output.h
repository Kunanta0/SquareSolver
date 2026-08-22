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
    case SQUARE_0:
        printf("Квадратное уравнение не имеет действительных корней\n\n");
        break;
    case SQUARE_1:
        printf("1 решение: %lg\n\n", otvet.x1);
        break;
    case SQUARE_2:
        printf("2 решения: %lg и %lg\n\n", otvet.x1, otvet.x2);
        break;
    case LINE:
        printf("Линейное уравнение, корень: %lg\n\n", otvet.x1);
        break;
    case ALWAYS_TRUE:
        printf("Бесконечное количество корней\n\n");
        break;
    case ALWAYS_FALSE:
        printf("Корней нет, противоречие\n\n");
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
            printf("Неправильный ввод, введите 0, либо 1, либо 2: ");
        }
        else
        {
            if (n != 0 && n != 1 && n != 2) printf("Неправильный ввод, введите 0, либо 1, либо 2: ");
            else notok = false;
        }
    }

    return n;
}

#endif // OUTPUT_H_INCLUDED
