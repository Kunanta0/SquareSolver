#ifndef MATHS_H_INCLUDED
#define MATHS_H_INCLUDED

#define OK(x) isnull(x, (-b + sqrt(D)) / 2 / a) || isnull(x, (-b - sqrt(D)) / 2 / a)

const double epsilon = 0.000000001;

double Discriminant(double, double, double);
bool isnull(double, double);
bool test_kvad(double, double, double, double, double);

//считает дискриминант
double Discriminant(double a, double b, double c)
{
    return b * b - 4 * a * c;
}

//обрабатывает погрешность нулевого ввода
bool isnull(double a, double b)
{
    return (abs(a - b) < epsilon) ? true : false;
}

//проверяет, является ли введенные значения корнями квадратного уравнения с заданными коэффициентами
bool test_kvad(double a, double b, double c, double x1, double x2)
{
    double D = Discriminant(a, b, c);
    if (OK(x1) && OK(x2)) return true;
    else return false;
}

#endif // MATHS_H_INCLUDED
