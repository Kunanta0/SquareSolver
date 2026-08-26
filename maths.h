#ifndef MATHS_H_INCLUDED
#define MATHS_H_INCLUDED

#define ZERO 0

enum Equation_id
{
    QUAD_0_ROOTS,
    QUAD_1_ROOTS,
    QUAD_2_ROOTS,
    LINE,
    ZERO_EQUALS_ZERO,
    ZERO_EQUALS_NO_ZERO
};

const double epsilon = 1e-7;

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

//прототипы функций
int get_id(struct coeffs, double);
struct ans answer(struct coeffs, int);
double Discriminant(struct coeffs);
bool issame(double, double);
struct coeffs init_eq(FILE* );

//считает дискриминант
double Discriminant(struct coeffs EQ)
{
    return EQ.b * EQ.b - 4 * EQ.a * EQ.c;
}

//обрабатывает погрешность одинакового ввода
bool issame(double a, double b)
{
    return (abs(a - b) < epsilon);
}

//функция, которая возвращает структуру, которая выдает ответ
struct ans answer(struct coeffs EQ)
{
    double D = Discriminant(EQ);
    int id = get_id(EQ, D);
    struct ans correct =
    {
        id,
        ZERO,
        ZERO
    };
    switch (id)
    {
        case QUAD_1_ROOTS:
            correct.x1 = -EQ.b / 2 / EQ.a;
            break;
        case QUAD_2_ROOTS:
            correct.x1 = (-EQ.b + sqrt(D)) / 2 / EQ.a;
            correct.x2 = (-EQ.b - sqrt(D)) / 2 / EQ.a;
            break;
        case LINE:
            correct.x1 = -EQ.c / EQ.b;
            break;
        default:
            break;
    }
    return correct;
}

//возвращает то, какой случай реализуется
int get_id(struct coeffs EQ, double D) //enum
{
    int id = 0;
    if(!(issame(EQ.a, 0)))
    {
        if (D < 0) id = QUAD_0_ROOTS;
        else if (issame(D, 0)) id = QUAD_1_ROOTS;
        else id = QUAD_2_ROOTS;
    }
    else
    {
        if (issame(EQ.b, 0))
        {
            if (issame(EQ.c, 0)) id = ZERO_EQUALS_ZERO;
            else id = ZERO_EQUALS_NO_ZERO;
        }
        else
        {
            id = LINE;
        }
    }
    return id;
}

//инициализирует структуру
struct coeffs init_eq(FILE* fp)
{
    struct coeffs EQ =
    {
        asknum('a', fp),
        asknum('b', fp),
        asknum('c', fp),
    };
    return EQ;
}

#endif // MATHS_H_INCLUDED
