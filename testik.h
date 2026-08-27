#ifndef TESTIK_H_INCLUDED
#define TESTIK_H_INCLUDED

void test(char* argv, FILE*);
int test_init(char*, FILE**);

//функция тестировщика
void test(char* argv, FILE* flog)
{
    FILE* test_file = NULL;
    int num_strs = 1;
    num_strs = test_init(argv, &test_file);

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
        fscanf(test_file, "%lg %lg %lg %d %lg %lg",&coefficients.a, &coefficients.b, &coefficients.c, &ans_ref.id, &ans_ref.x1, &ans_ref.x2);
        struct ans ans_prog = answer(coefficients); //fixme
        if (ans_ref.id == ans_prog.id && (issame(ans_ref.x1, ans_prog.x1) && issame(ans_ref.x2, ans_prog.x2)) || (issame(ans_ref.x1, ans_prog.x2) && issame(ans_ref.x2, ans_prog.x1)))
        {
            printf(GREEN "Test %d succeed\n" RESET, i + 1);
            #ifdef DEBUG
            write_log(flog, LOG_INFO, "Test %d succeed\n", i + 1);
            #endif
        }
        else
        {
            printf(RED "Test %d unsucceed\n" RESET, i + 1);
            #ifdef DEBUG
            write_log(flog, LOG_WARNING, "Test %d unsucceed\n", i + 1);
            #endif
        }
    }
    free(cf);
    free(answers);
    if (fclose(test_file) != 0) printf("Error of closing file\n");
    printf("\n");
}

//возвращает файл теста, подсчитывает количество строк в тестах,
int test_init(char* argv, FILE** file_test)
{
    int strs = 1;
    char ch = '0';
    if ((*file_test = fopen(argv, "r")) == NULL) printf("Error of closing file\n");
    while ((ch = getc(*file_test)) != EOF)
    {
        if (ch == '\n') ++strs;
    }
    rewind(*file_test);
    return strs;
}

#endif // TESTIK_H_INCLUDED
