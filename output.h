/**
*\file
*\brief Header with output functions
*/

#ifndef OUTPUT_H_INCLUDED
#define OUTPUT_H_INCLUDED

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"
#define BLUE "\033[34m"
#include "maths.h"

#define THINKING "Thinking..."

const int ms_time = 2000;///<time of thinking

/**
*this function prints answer from the structure, accepts log file to write information there
*\param[in,out] ans_prog prints answer, using structure
*/
void printans(struct ans, FILE*);

//print answer
void printans(struct ans ans_prog, FILE* flog)
{
    printf(THINKING);

    Sleep(ms_time);
    for (unsigned int i = 0; i < strlen(THINKING); ++i)
    {
        printf("\b");
    }
    switch (ans_prog.id)
    {
    case QUAD_0_ROOTS:
        printf(YELLOW "Quadratic equation doesn't have real roots, because discriminant is less than zero\n\n" RESET);
        #ifdef DEBUG
        write_log(flog, LOG_INFO, PR_VAR(ans_prog.id, d));
        #endif
        break;
    case QUAD_1_ROOTS:
        printf(YELLOW "1 root, because discriminant is zero: %lg\n\n" RESET, ans_prog.x1);
        #ifdef DEBUG
        write_log(flog, LOG_INFO, PR_VAR(ans_prog.id, d));
        write_log(flog, LOG_INFO, PR_VAR(ans_prog.x1, lg));
        #endif
        break;
    case QUAD_2_ROOTS:
        printf(YELLOW "2 roots, because discriminant is more than zero: %lg and %lg\n\n" RESET, ans_prog.x1, ans_prog.x2);
        #ifdef DEBUG
        write_log(flog, LOG_INFO, PR_VAR(ans_prog.id, d));
        write_log(flog, LOG_INFO, PR_VAR(ans_prog.x1, lg));
        write_log(flog, LOG_INFO, PR_VAR(ans_prog.x2, lg));
        #endif
        break;
    case LINE:
        printf(YELLOW "Linear equation, because coefficient a = 0, root: %lg\n\n" RESET, ans_prog.x1);
        #ifdef DEBUG
        write_log(flog, LOG_INFO, PR_VAR(ans_prog.id, d));
        write_log(flog, LOG_INFO, PR_VAR(ans_prog.x1, lg));
        #endif
        break;
    case ZERO_EQUALS_ZERO:
        printf(YELLOW "Infinity number if roots, because all the coefficients are zeros (0 = 0)\n\n" RESET);
        #ifdef DEBUG
        write_log(fp, LOG_INFO, PR_VAR(ans_prog.id, d));
        #endif
        break;
    case ZERO_EQUALS_NO_ZERO:
        printf(YELLOW "No roots, contradiction, because all the coefficients except c are zero, (c != 0)\n\n" RESET);
        #ifdef DEBUG
        write_log(flog, LOG_INFO, PR_VAR(ans_prog.id, d));
        #endif
        break;
    }
}

#endif // OUTPUT_H_INCLUDED
