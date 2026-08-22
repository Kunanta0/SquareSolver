#ifndef TESTIK_H_INCLUDED
#define TESTIK_H_INCLUDED

#define fscanning(file, StrCoeff, StrAns, index) fscanf(file, "%lg %lg %lg %d %lg %lg",\
&(StrCoeff[index].a), &(StrCoeff[index].b), &(StrCoeff[index].c), &(StrAns[index].id), &(StrAns[index].x1), &(StrAns[index].x2))

void test();

//проверяет ответ
void test()
{
    int num_cols = 0;

    FILE* fp = NULL;
    MyAssert((fp = fopen("test.txt", "r")) != NULL);

    char ch = '\0';

    while ((ch = getc(fp)) != EOF) if (ch == '\n') ++num_cols;
    num_cols += 1;

    rewind(fp);

    struct coeffs cf[num_cols];
    struct ans otvety[num_cols];
    for (int i = 0;i < num_cols; ++i)
    {
        fscanning(fp, cf, otvety, i);
    }

    for (int i = 0;i < sizeof(otvety) / sizeof(otvety[0]);++i)
    {
        double D = Discriminant(cf[i]);
        int id0 = num_sol(cf[i]);
        struct ans otvetik = answer(cf[i], id0);
        if (otvety[i].id != 2)
        {
            if ((otvety[i].id == otvetik.id) && (isnull(otvety[i].x1, otvetik.x1)) && (isnull(otvety[i].x2, otvetik.x2))) printf("Тест %d пройден\n", i + 1);
            else printf("Тест %d не пройден\n", i + 1);
        }
        if (otvety[i].id == 2)
        {
            if (OK(cf[i], otvety[i].x1) && OK(cf[i], otvety[i].x2) && !(isnull(otvety[i].x1, otvety[i].x2))) printf("Тест %d пройден\n", i + 1);
            else printf("Тест %d не пройден\n", i + 1);
        }
    }
    MyAssert(fclose(fp) == 0);
}

#endif // TESTIK_H_INCLUDED
