/**
*\file
*\brief file with main function
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <math.h>
#include <windows.h>
#include <getopt.h>
#include "log.h"
#include "input.h"
#include "output.h"
#include "myassert.h"
#include "testik.h"

//0 - no roots of quadratic equation
//1 - 1 root of quadratic equation
//2 - 2 roots of quadratic equation
//3 - 1 root of linear equation
//4 - infinity number of roots
//5 - no roots, contradiction "zero equals no zero"

int main(int argc, char* argv[])///<main function, accepts command line's arguments
{
    FILE* flog = NULL;
    #ifdef DEBUG
    flog = fopen("log.txt", "a");
    #endif

    struct option long_options[] = { {"solve", no_argument,       NULL, 's'},
                                     {"test",  required_argument, NULL, 't'},
                                     {0,       0,                 0,    0  } };

    int opt = 0;
    int options_index = 0;
    if ((opt = getopt_long(argc, argv, "s:t:", long_options, &options_index)) != -1)
    {
        switch(opt)
        {
            case 's':
                {
                    printf(YELLOW "Quadratic equation looks like ax^2 + bx + c = 0\n" RESET);

                    struct coeffs EQ = init_eq(flog);
                    struct ans ans_prog = answer(EQ);

                    printans(ans_prog, flog);
                    break;
                }
            case 't':
                {
                    test(argv[2], flog);
                    break;
                }
            default:
                exit(EXIT_FAILURE);
        }
    }
    printf(YELLOW "Bye!" RESET);
    #ifdef DEBUG
    if (fclose(flog) != 0) printf("Error of closing file\n");
    #endif
    return 0;
}
