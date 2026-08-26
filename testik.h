#ifndef TESTIK_H_INCLUDED
#define TESTIK_H_INCLUDED

void test(char* argv, FILE*);
FILE* test_init(char*, int*);

//функция тестировщика
void test(char* argv, FILE* flog)
{
    FILE* fp = NULL;
    int num_strs = 1;
    fp = test_init(argv, &num_strs);

    struct coeffs* cf = (struct coeffs*)calloc(num_strs, sizeof(struct coeffs));
    struct ans* answers = (struct ans*)calloc(num_strs, sizeof(struct ans));

    #ifdef DEBUG
    write_log(flog, LOG_INFO, "func calloc took %d numbers memory of struct ans\n", num_strs);
    write_log(flog, LOG_INFO, "func calloc took %d numbers memory of struct coeffs\n", num_strs);
    #endif

    for (unsigned int i = 0;i < num_strs; ++i)
    {
        MyAssert(0 <= i && i < num_strs);
        struct ans ans_ref = answers[i];
        struct coeffs coefficients = cf[i];
        fscanf(fp, "%lg %lg %lg %d %lg %lg",&coefficients.a, &coefficients.b, &coefficients.c, &ans_ref.id, &ans_ref.x1, &ans_ref.x2);
        struct ans ans_prog = answer(coefficients); //fixme
        if (ans_ref.id == ans_prog.id && (issame(ans_ref.x1, ans_prog.x1) && issame(ans_ref.x2, ans_prog.x2)) || (issame(ans_ref.x1, ans_prog.x2) && issame(ans_ref.x2, ans_prog.x1)))
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
    free(cf);
    free(answers);
    if (fclose(fp) != 0) printf("Ошибка закрытия файла\n");
    printf("\n");
}

//возвращает файл теста, подсчитывает количество строк в тестах,
FILE* test_init(char* argv, int* strs)
{
    FILE* fp = NULL;
    char ch = '0';
    if ((fp = fopen(argv, "r")) == NULL) printf("Ошибка открытия файла\n");
    while ((ch = getc(fp)) != EOF)
    {
        if (ch == '\n') (*strs)++;
    }
    rewind(fp);
    return fp;
}

#endif // TESTIK_H_INCLUDED
