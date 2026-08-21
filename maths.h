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

struct ans answer(struct coeffs EQ, int);
int num_sol(double, double, double);
double Discriminant(struct coeffs EQ);
bool isnull(double, double);
bool test_kvad1(struct coeffs, double);
bool test_kvad2(struct coeffs);
bool test_kvad3(struct coeffs);
double line(double, double);

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

//проверяет, является ли введенные значения корнями квадратного уравнения с заданными коэффициентами
bool test_kvad2(struct coeffs EQ, double x1, double x2)
{
    double D = Discriminant(EQ);
    if (OK(EQ, x1) && OK(EQ, x2) && !(isnull(x1, x2))) return true;
    else return false;
}

//проверяет, действительно ли уравнение имеет одно решение и верно ли оно
bool test_kvad1(struct coeffs EQ, double x)
{
    double D = Discriminant(EQ);
    if (isnull(D, 0) && OK(EQ, x)) return true;
    return false;
}

bool test_kvad3(struct coeffs EQ, double x)
{
    if (isnull(-EQ.c / EQ.b, x)) return true;
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
