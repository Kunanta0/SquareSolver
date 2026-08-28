/**
*\file
*\brief Header with test function
*/

#ifndef TESTIK_H_INCLUDED
#define TESTIK_H_INCLUDED

/**
*this function runs tests
*\param[in] filename name of test file
*\param[out] flog log file
*/
void test(char*, FILE*);

/**
*this function initialize test file, returns number of its lines
*\param[in] filename name of test file
*\param[in,out] file_test test file
*\return number of lines
*/
int test_init(char*, FILE**);

//function for tests
void test(char* filename, FILE* flog)
{
    FILE* test_file = NULL;
    int num_strs = test_init(filename, &test_file);

    for (unsigned int i = 0;i < num_strs; ++i)
    {
        MyAssert(0 <= i && i < num_strs);
        struct ans ans_ref = {};
        struct coeffs coefficients = {};
        fscanf(test_file, "%lg %lg %lg %d %lg %lg", &coefficients.a, &coefficients.b, &coefficients.c, &ans_ref.id, &ans_ref.x1, &ans_ref.x2);
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
    if (fclose(test_file) != 0) printf("Error of closing file\n");
    printf("\n");
}

//returns number of lines in test, accepts pointer to file, which fills
int test_init(char* filename, FILE** file_test)
{
    int strs = 1;
    char ch = '0';
    if ((*file_test = fopen(filename, "r")) == NULL) printf("Error of opening file\n");
    while ((ch = getc(*file_test)) != EOF)
    {
        if (ch == '\n') ++strs;
    }
    rewind(*file_test);
    return strs;
}

#endif // TESTIK_H_INCLUDED
