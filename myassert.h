#ifndef MYASSERT_H_INCLUDED
#define MYASSERT_H_INCLUDED

#include "log.h"


//свой assert()
#define MyAssert(exp, fp, time_str)\
if (!(exp))\
{\
    fprintf(stderr, RED "Ошибка: %s в файле %s, в строке %d, в функции %s\n" RESET,#exp, __FILE__, __LINE__, __func__);\
    write_log(fp, time_str, LOG_ERROR, "ERROR: %s in file %s, in line %d, in function %s\n" RESET,#exp, __FILE__, __LINE__, __func__);\
    exit(1);\
}\
else\
{\
    write_log(fp, time_str, LOG_INFO, "Work with file has been successfully finished");\
}

#endif // MYASSERT_H_INCLUDED
