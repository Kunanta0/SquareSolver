/**
*\file
*\brief Header with math functions
*/

#ifndef MATHS_H_INCLUDED
#define MATHS_H_INCLUDED

///this enum shows cases of quadratic equation
enum Equation_id
{
    QUAD_0_ROOTS,///<quadratic equation has no roots
    QUAD_1_ROOTS,///<quadratic equation has 1 root
    QUAD_2_ROOTS,///<quadratic equation has 2 roots
    LINE,///<linear equation (a = 0, b!= 0)
    ZERO_EQUALS_ZERO,///<case a = 0, b = 0, c = 0,
    ZERO_EQUALS_NO_ZERO///<case a = 0, b = 0, c !=  0
};

const double epsilon = 1e-7;///<this constant uses to fix error of double numbers

//answer structure
/**
*\brief structure of answer
*
*this structure contains parameters with roots and case
*/
struct ans
{
    int id;
    double x1;
    double x2;
};

//coefficient structure
/**
*\brief structure of coefficients
*
*this structure contains coefficients
*/
struct coeffs
{
    double a;
    double b;
    double c;
};

//function prototypes

/**
*this function returns structure with answer
*\param[in] EQ structure of coefficients
*\return structure of answer
*/
struct ans answer(struct coeffs);

/**
*this function returns discriminant, accepts coefficients structure
*\param[in] EQ structure of coefficients
*\return discriminant
*/
double Discriminant(struct coeffs);

/**
*this function processes error of comparison double numbers
*\param a,b comparing double numbers
*\return numbers are same or not
*/
bool issame(double, double);

/**
*this function initialize coefficients structure
*\param[out] flog log file
*\return structure of coefficients
*/
struct coeffs init_eq(FILE*);

/**
*solve linear equation, accepts coefficient structure and pointer to answer structure
*\param[in] EQ structure of coefficients
*\param[out] ans_prog structure of answer
*/
void linear_solver(struct coeffs, struct ans*);

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
struct coeffs init_eq(FILE* flog)
{
    struct coeffs EQ =
    {
        asknum('a', flog),
        asknum('b', flog),
        asknum('c', flog),
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
