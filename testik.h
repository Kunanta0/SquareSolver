#ifndef TESTIK_H_INCLUDED
#define TESTIK_H_INCLUDED

bool test(struct coeffs, struct ans);

//проверяет ответ
bool test(struct coeffs EQ, struct ans otvet)
{
    int id0 = num_sol(EQ);
    struct ans otvetik = answer(EQ, id0);
    if ((otvet.id == otvetik.id) && (otvet.x1 == otvetik.x1) && (otvet.x2 == otvetik.x2)) return true;
    return false;
}

#endif // TESTIK_H_INCLUDED
