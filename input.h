#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

double asknum(char);

//запрашивает коэффициенты квадратного уравнения
double asknum(char coeff)
{
    double n = 0;
    printf("Введите коэффициент %c: ", coeff);
    char ch = '\0';
    bool notok = true;

    while(notok)
    {
        int cor = scanf("%lg", &n);
        if (cor != 1 || (ch = getchar()) != '\n')
        {
            while ((ch = getchar()) != '\n') continue;
            printf("Неправильный ввод, введите число: ");
        }
        else notok = false;
    }
    return n;
}


#endif // INPUT_H_INCLUDED
