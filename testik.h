/**
*\file
*\brief Header with test function
*/

#ifndef TESTIK_H_INCLUDED
#define TESTIK_H_INCLUDED

/**
*this function runs tests
*\param[in] argv_i name of test file
*\param[out] flog log file
*/
void test(char*, FILE*);

/**
*this function initialize test file, returns number of its lines
*\param[in] argv_i name of test file
*\param[in,out] file_test test file
*\return number of lines
*/
int test_init(char*, FILE**);

//function for tests
void test(char* argv_i, FILE* flog)
{
    FILE* test_file = NULL;
    int num_strs = 1;
    num_strs = test_init(argv_i, &test_file);

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
        struct ans ans_prog = answer(coefficients);
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

//returns number of lines in test, accepts pointer to file, which fills
int test_init(char* argv_i, FILE** file_test)
{
    int strs = 1;
    char ch = '0';
    if ((*file_test = fopen(argv_i, "r")) == NULL) printf("Error of closing file\n");
    while ((ch = getc(*file_test)) != EOF)
    {
        if (ch == '\n') ++strs;
    }
    rewind(*file_test);
    return strs;
}

#endif // TESTIK_H_INCLUDED
