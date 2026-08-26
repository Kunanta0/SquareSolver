#ifndef TESTIK_H_INCLUDED
#define TESTIK_H_INCLUDED

void test(int argc, char* argv[], FILE*);

//функция тестировщика
void test(int argc, char* argv[], FILE* flog)
{
    int num_strs = 0;
    char ch = '0';
    FILE* fp = NULL;

    if ((fp = fopen(argv[1], "r")) == NULL) printf("Ошибка открытия файла\n");
    while ((ch = getc(fp)) != EOF)
    {
        if (ch == '\n') ++num_strs;
    }
    num_strs += 1;

    fseek(fp, 0, SEEK_SET);

    struct coeffs* cf = (struct coeffs*)calloc(num_strs, sizeof(struct coeffs));
    struct ans* answers = (struct ans*)calloc(num_strs, sizeof(struct ans));

    #ifdef DEBUG
    write_log(flog, LOG_INFO, "func calloc took %d numbers memory of struct ans\n", num_cols);
    write_log(flog, LOG_INFO, "func calloc took %d numbers memory of struct coeffs\n", num_cols);
    #endif

    for (unsigned int i = 0;i < num_strs; ++i)
    {
        MyAssert(0 <= i && i < num_strs);
        struct ans ans_ref = answers[i];
        struct coeffs coefficients = cf[i];
        fscanf(fp, "%lg %lg %lg %d %lg %lg",&coefficients.a, &coefficients.b, &coefficients.c, &ans_ref.id, &ans_ref.x1, &ans_ref.x2);
        struct ans correct = answer(coefficients);
        if (ans_ref.id != 2)
        {
            if (ans_ref.id == correct.id && issame(ans_ref.x1, correct.x1) && issame(ans_ref.x2, correct.x2))
            {
                printf(GREEN "Тест %d пройден\n" RESET, i + 1);
                #ifdef DEBUG
                write_log(flog, LOG_INFO, "Test %d succeed\n", i + 1);
                #endif
            }
            else
            {
                printf(RED "Тест %d не пройден\n" RESET, i + 1);
                #ifdef DEBUG
                write_log(flog, LOG_WARNING, "Test %d unsucceed\n", i + 1);
                #endif
            }
        }
        if (ans_ref.id == 2)
        {
            if (ans_ref.id == correct.id)
            {
                if ((issame(ans_ref.x1, correct.x1) && issame(ans_ref.x2, correct.x2)) || (issame(ans_ref.x1, correct.x2) && issame(ans_ref.x2, correct.x1)))
                printf(GREEN "Тест %d пройден\n" RESET, i + 1);
                #ifdef DEBUG
                write_log(flog, LOG_INFO, "Test %d succeed\n", i + 1);
                #endif
            }
            else
            {
                printf(RED "Тест %d не пройден\n" RESET, i + 1);
                #ifdef DEBUG
                write_log(flog, LOG_WARNING, "Test %d unsucceed\n", i + 1);
                #endif
            }
        }
    }
    free(cf);
    free(answers);
    if (fclose(fp) != 0) printf("Ошибка закрытия файла\n");
    printf("\n");
}

#endif // TESTIK_H_INCLUDED
