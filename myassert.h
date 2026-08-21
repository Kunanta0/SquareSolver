#ifndef MYASSERT_H_INCLUDED
#define MYASSERT_H_INCLUDED

//свой assert()
#define MyAssert(exp)\
if (exp) exit(0);\
else\
{\
    fprintf(stderr, "Ошибка: %s в файле %s, в строке %d, в функции %s\n",#exp, __FILE__, __LINE__, __func__);\
    exit(1);\
}\

#endif // MYASSERT_H_INCLUDED
