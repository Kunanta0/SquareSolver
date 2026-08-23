#ifndef OUTPUT_H_INCLUDED
#define OUTPUT_H_INCLUDED

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"
#define BLUE "\033[34m"

#include "maths.h"

void printans(struct ans);
int menu();

//выводит ответ
void printans(struct ans otvet)
{
    switch (otvet.id)
    {
    case SQUARE_0:
        printf(YELLOW "Квадратное уравнение не имеет действительных корней\n\n" RESET);
        break;
    case SQUARE_1:
        printf(YELLOW "1 решение: %lg\n\n" RESET, otvet.x1);
        break;
    case SQUARE_2:
        printf(YELLOW "2 решения: %lg и %lg\n\n" RESET, otvet.x1, otvet.x2);
        break;
    case LINE:
        printf(YELLOW "Линейное уравнение, корень: %lg\n\n" RESET, otvet.x1);
        break;
    case ALWAYS_TRUE:
        printf(YELLOW "Бесконечное количество корней\n\n" RESET);
        break;
    case ALWAYS_FALSE:
        printf(YELLOW "Корней нет, противоречие\n\n" RESET);
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
