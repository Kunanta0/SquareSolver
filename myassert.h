#ifndef MYASSERT_H_INCLUDED
#define MYASSERT_H_INCLUDED

void MyAssert(bool);


//свой assert()
void MyAssert(bool exp)
{
    if (exp) exit(0);
    else
    {
        printf("Ошибка в файле %s, в строке %d, в функции %s\n", __FILE__, __LINE__, __func__);
        exit(1);
    }
}


#endif // MYASSERT_H_INCLUDED
