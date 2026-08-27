#ifndef MATHS_H_INCLUDED
#define MATHS_H_INCLUDED

enum Equation_id
{
    QUAD_0_ROOTS,
    QUAD_1_ROOTS,
    QUAD_2_ROOTS,
    LINE,
    ZERO_EQUALS_ZERO,
    ZERO_EQUALS_NO_ZERO
};

enum Choice_Menu
{
    FINISH,
    QUAD_SOLVER,
    TESTS
};

const double epsilon = 1e-7;

//структура ответа
struct ans
{
    int id;
    double x1;
    double x2;
};

//структура коэффициентов
struct coeffs
{
    double a;
    double b;
    double c;
};

//прототипы функций
struct ans answer(struct coeffs, int);
double Discriminant(struct coeffs);
bool issame(double, double);
struct coeffs init_eq(FILE*);
void linear_solver(struct coeffs EQ, struct ans* ans_prog);

//считает дискриминант
double Discriminant(struct coeffs EQ)
{
    return EQ.b * EQ.b - 4 * EQ.a * EQ.c;
}

//обрабатывает погрешность одинакового ввода дробных чисел
bool issame(double a, double b)
{
    return (abs(a - b) < epsilon);
}

//функция, которая возвращает структуру, которая выдает ответ
struct ans answer(struct coeffs EQ)
{
    double D = Discriminant(EQ);
    struct ans ans_prog = {};

    if(!(issame(EQ.a, 0)))
    {
        if (D < 0) ans_prog.id = QUAD_0_ROOTS;
        else if (issame(D, 0))
        {
            ans_prog.id = QUAD_1_ROOTS;
            ans_prog.x1 = -EQ.b / 2 / EQ.a;
        }
        else
        {
            ans_prog.id = QUAD_2_ROOTS;
            ans_prog.x1 = (-EQ.b + sqrt(D)) / 2 / EQ.a;
            ans_prog.x2 = (-EQ.b - sqrt(D)) / 2 / EQ.a;
        }
    }
    else linear_solver(EQ, &ans_prog);

    return ans_prog;
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

//решает линейное уравнение
void linear_solver(struct coeffs EQ, struct ans* ans_prog)
{
    if (issame(EQ.b, 0))
    {
        if (issame(EQ.c, 0)) (*ans_prog).id = ZERO_EQUALS_ZERO;
        else (*ans_prog).id = ZERO_EQUALS_NO_ZERO;
    }
    else
    {
        (*ans_prog).id = LINE;
        (*ans_prog).x1 = -EQ.c / EQ.b;
    }
}

#endif // MATHS_H_INCLUDED
