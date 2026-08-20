#ifndef MATHS_H_INCLUDED
#define MATHS_H_INCLUDED

const double epsilon = 0.000000001;

double Discriminant(double, double, double);
bool isnull(double, double);

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


#endif // MATHS_H_INCLUDED
