#ifndef MATHS_H_INCLUDED
#define MATHS_H_INCLUDED

///this enum shows cases of quadratic equation
enum Equation_id
{
    QUAD_0_ROOTS,
    QUAD_1_ROOTS,
    QUAD_2_ROOTS,
    LINE,
    ZERO_EQUALS_ZERO,
    ZERO_EQUALS_NO_ZERO
};

const double epsilon = 1e-7;///<this constant uses to fix error of double numbers

//answer struct
struct ans
{
    int id;
    double x1;
    double x2;
};

//coefficient structure
struct coeffs
{
    double a;
    double b;
    double c;
};

//function prototypes
struct ans answer(struct coeffs, int);///<this function returns structure with answer
double Discriminant(struct coeffs);///<this function returns discriminant, accepts coefficients structure
bool issame(double, double);///<this function processes error of comparison double numbers
struct coeffs init_eq(FILE*);///<this function initialize coefficients structure
void linear_solver(struct coeffs EQ, struct ans* ans_prog);///<solve linear equation, accepts coefficient structure and pointer to answer structure

//counts discriminant
double Discriminant(struct coeffs EQ)
{
    return EQ.b * EQ.b - 4 * EQ.a * EQ.c;
}

//processing error of double numbers
bool issame(double a, double b)
{
    return (abs(a - b) < epsilon);
}

//function, which returns structure, which has the answer
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

//initialize struct
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

//solve linear equation
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
