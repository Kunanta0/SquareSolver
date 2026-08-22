#ifndef TESTIK_H_INCLUDED
#define TESTIK_H_INCLUDED

void test();

//проверяет ответ
void test()
{
    struct coeffs cf[] =
    {
        {1, 5, 6},
        {1, -2, 1},
        {0, 0, 0},
        {0, 0, 4},
        {0, 6, 36},
        {100, 1, 100},
    } ;

    struct ans otvety[] =
    {
        {2, -3, -2},
        {1, 1, ZERO},
        {4, ZERO, ZERO},
        {5, ZERO, ZERO},
        {3, -6, ZERO},
        {0, ZERO, ZERO},
    };

    for (int i = 0;i < 6;++i)
    {
        double D = Discriminant(cf[i]);
        int id0 = num_sol(cf[i]);
        struct ans otvetik = answer(cf[i], id0);
        if (otvety[i].id != 2)
        {
            if ((otvety[i].id == otvetik.id) && (otvety[i].x1 == otvetik.x1) && (otvety[i].x2 == otvetik.x2)) printf("Тест %d пройден\n", i + 1);
        }
        if (otvety[i].id == 2)
        {
            if (OK(cf[i], otvety[i].x1) && OK(cf[i], otvety[i].x2) && !(isnull(otvety[i].x1, otvety[i].x2))) printf("Тест %d пройден\n", i + 1);
            else printf("Тест %d не пройден ");
        }
    }
}

#endif // TESTIK_H_INCLUDED
