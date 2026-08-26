#ifndef TESTIK_H_INCLUDED
#define TESTIK_H_INCLUDED

#include "log.h"

void test(int argc, char* argv[], FILE*);

//функция тестировщика
void test(int argc, char* argv[], FILE* flog)
{
    int num_cols = 0;

    time_t now = time(NULL);
    char* time_str = ctime(&now);
    time_str[strcspn(time_str, "\n")] = 0;
    FILE* fp = NULL;
    MyAssert((fp = fopen(argv[1], "r")) != NULL, flog, time_str);

    char ch = '0';

    while ((ch = getc(fp)) != EOF) if (ch == '\n') ++num_cols;
    num_cols += 1;


    fseek(fp, 0, SEEK_SET);

    struct coeffs* cf = (struct coeffs*)calloc(num_cols, sizeof(struct coeffs));
    struct ans* otvety = (struct ans*)calloc(num_cols, sizeof(struct ans));
    #ifdef DEBUG
    write_log(flog, time_str, LOG_INFO, "func calloc took %d numbers memory of struct coeffs", num_cols);
    write_log(flog, time_str, LOG_INFO, "func calloc took %d numbers memory of struct ans", num_cols);
    #endif

    for (int i = 0;i < num_cols; ++i)
    {
        fscanf(fp, "%lg %lg %lg %d %lg %lg",&(cf[i].a), &(cf[i].b), &(cf[i].c), &(otvety[i].id), &(otvety[i].x1), &(otvety[i].x2));
    }

    for (int i = 0;i < num_cols;++i)
    {
        double D = Discriminant(cf[i]);
        int id0 = num_sol(cf[i]);
        struct ans otvetik = answer(cf[i], id0);
        if (otvety[i].id != 2)
        {
            if ((otvety[i].id == otvetik.id) && (isnull(otvety[i].x1, otvetik.x1)) && (isnull(otvety[i].x2, otvetik.x2)))
            {
                printf(GREEN "Тест %d пройден\n" RESET, i + 1);
                write_log(flog, time_str, LOG_INFO, "Test %d succeed", i + 1);
            }
            else
            {
                printf(RED "Тест %d не пройден\n" RESET, i + 1);
                write_log(flog, time_str, LOG_WARNING, "Test %d unsucceed", i + 1);
            }
        }
        if (otvety[i].id == 2)
        {
            if (OK(cf[i], otvety[i].x1) && OK(cf[i], otvety[i].x2) && !(isnull(otvety[i].x1, otvety[i].x2)))
            {
                printf(GREEN "Тест %d пройден\n" RESET, i + 1);
                write_log(flog, time_str, LOG_INFO, "Test %d succeed", i + 1);
            }
            else
            {
                printf(RED "Тест %d не пройден\n" RESET, i + 1);
                write_log(flog, time_str, LOG_WARNING, "Test %d unsucceed", i + 1);
            }
        }
    }
    free(cf);
    free(otvety);
    MyAssert(fclose(fp) == 0, flog, time_str);
    printf("\n");
}

#endif // TESTIK_H_INCLUDED
