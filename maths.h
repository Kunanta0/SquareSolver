#ifndef MATHS_H_INCLUDED
#define MATHS_H_INCLUDED

#define OK(str, x) isnull(x, (-str.b + sqrt(D)) / 2 / str.a) || isnull(x, (-str.b - sqrt(D)) / 2 / str.a)
#define ZERO 0

const double epsilon = 0.000000001;

//структура ответа
struct ans
{
    int id = ZERO;
    double x1 = ZERO;
    double x2 = ZERO;
};

//структура коэффициентов
struct coeffs
{
    double a = ZERO;
    double b = ZERO;
    double c = ZERO;
};

//прототипы функций, объявления структур
struct ans answer(struct coeffs, int);
int num_sol(struct coeffs);
double Discriminant(struct coeffs);
bool isnull(double, double);
bool test_kvad0(struct coeffs);
bool test_kvad1(struct coeffs, double);
bool test_kvad2(struct coeffs, double, double);
bool test_kvad3(struct coeffs, double);
bool test_kvad4(struct coeffs);
bool test_kvad5(struct coeffs);

//считает дискриминант
double Discriminant(struct coeffs EQ)
{
    return EQ.b * EQ.b - 4 * EQ.a * EQ.c;
}

//обрабатывает погрешность нулевого ввода
bool isnull(double a, double b)
{
    return (abs(a - b) < epsilon) ? true : false;
}

//проверяет случай 0
bool test_kvad0(struct coeffs EQ)
{
    if (Discriminant(EQ) < 0) return true;
    return false;
}
//проверяет случай 2
bool test_kvad2(struct coeffs EQ, double x1, double x2)
{
    double D = Discriminant(EQ);
    if (OK(EQ, x1) && OK(EQ, x2) && !(isnull(x1, x2))) return true;
    return false;
}
//проверяет случай 1
bool test_kvad1(struct coeffs EQ, double x)
{
    double D = Discriminant(EQ);
    if (isnull(D, 0) && OK(EQ, x)) return true;
    return false;
}
//проверяет случай 3
bool test_kvad3(struct coeffs EQ, double x)
{
    if (isnull(-EQ.c / EQ.b, x)) return true;
    return false;
}
//проверяет случай 4
bool test_kvad4(struct coeffs EQ)
{
    if (isnull(EQ.a, 0) && isnull(EQ.b, 0) && isnull(EQ.c, 0)) return true;
    return false;
}
//проверяет случай 5
bool test_kvad5(struct coeffs EQ)
{
    if (isnull(EQ.a, 0) && isnull(EQ.b, 0) && !isnull(EQ.c, 0)) return true;
    return false;
}

//выводит уникальный номер, показывающий, какой случай реализуется
int num_sol(struct coeffs EQ)
{
    double D = Discriminant(EQ);
    if (!isnull(EQ.a, 0))
    {
        if (D < 0) return 0;
        else if (isnull(D, 0)) return 1;
        else return 2;
    }
    else
    {
        if (isnull(EQ.b, 0))
        {
            if (isnull(EQ.c, 0))
            {
                return 4;
            }
            else return 5;
        }
        else
        {
            return 3;
        }
    }
}

//функция, которая возвращает структуру, которая выдает ответ
struct ans answer(struct coeffs EQ, int id)
{
    double D = Discriminant(EQ);
    struct ans otvet =
    {
        id,
        ZERO,
        ZERO
    };
    switch (id)
    {
        case 1:
            otvet.x1 = -EQ.b / 2 / EQ.a;
            break;
        case 2:
            otvet.x1 = (-EQ.b + sqrt(D)) / 2 / EQ.a;
            otvet.x2 = (-EQ.b - sqrt(D)) / 2 / EQ.a;
            break;
        case 3:
            otvet.x1 = -EQ.c / EQ.b;
            break;
        default:
            break;
    }
    return otvet;
}

#endif // MATHS_H_INCLUDED
