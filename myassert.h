#ifndef MYASSERT_H_INCLUDED
#define MYASSERT_H_INCLUDED

//свой assert()
#define MyAssert(exp)\
if (!(exp))\
{\
    fprintf(stderr, RED "Ошибка: %s в файле %s, в строке %d, в функции %s\n" RESET,#exp, __FILE__, __LINE__, __func__);\
    exit(1);\
}

#endif // MYASSERT_H_INCLUDED
