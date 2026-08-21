#ifndef TESTIK_H_INCLUDED
#define TESTIK_H_INCLUDED

#include "maths.h"

bool test(struct coeffs, struct ans);

//проверяет ответ
bool test(struct coeffs EQ, struct ans otvet)
{
    switch (otvet.id)
    {
        case 0:
            if (test_kvad0(EQ)) break;
            return false;
        case 1:
            if (test_kvad1(EQ, otvet.x1)) break;
            return false;
        case 2:
            if (test_kvad2(EQ, otvet.x1, otvet.x2)) break;
            return false;
        case 3:
            if (test_kvad3(EQ, otvet.x1)) break;
            return false;
        case 4:
            if (test_kvad4(EQ)) break;
            return false;
        case 5:
            if (test_kvad5(EQ)) break;
            return false;
    }
    return true;
}

#endif // TESTIK_H_INCLUDED
