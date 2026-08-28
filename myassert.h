#ifndef MYASSERT_H_INCLUDED
#define MYASSERT_H_INCLUDED

///this is realization of my assert
//my assert()
#define MyAssert(exp)\
if (!(exp))\
{\
    fprintf(stderr, RED "Error: %s in file %s, in lines %d, in function %s\n" RESET,#exp, __FILE__, __LINE__, __func__);\
    exit(1);\
}

#endif // MYASSERT_H_INCLUDED
