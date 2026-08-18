#include <stdio.h>
#include <locale.h>
#include <math.h>
int asknum(char);
int Discriminant(int, int, int);
void answer(int, int);
void answers(int,int,int);

int main(void)
{
    setlocale(LC_ALL, "Russian");
    printf("Квадратное уравнение имеет вид ax^2+bx+c=0, a!=0\n");
    int a, b, c;
    a = asknum('a');
    b = asknum('b');
    c = asknum('c');
    int D=Discriminant(a,b,c);
    if (D<0) printf("Корней нет");
    else if (D==0) answer(a,b);
    else answers(a,b,D);
}
int asknum(char l)
{
    int n;
    printf("Введите коэффициент %c: ",l);
    char ch;
    while (scanf("%d", &n)!=1 || (l=='a' && n==0))
    {
        while ((ch=getchar())!='\n') continue;
        printf("Неправильный ввод, введите целое число: ");
    }
    return n;
}
int Discriminant(int a, int b, int c)
{
    return b*b-4*a*c;
}
void answer(int a, int b)
{
    float ans = -b/2/a;
    printf("1 решение: %.2f", ans);
}
void answers(int a, int b, int D)
{
    float ans1 = (-b+sqrt(D))/2/a;
    float ans2 = (-b-sqrt(D))/2/a;
    printf("2 решения: %.2f, %.2f", ans1, ans2);
}
