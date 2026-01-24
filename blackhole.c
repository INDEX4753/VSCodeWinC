#include <stdio.h>

int max(int a, int b,int c);
int mid(int a, int b, int c);
int min(int a, int b, int c);

int main()
{
    int n0 = 123, sum = 0;
    scanf("%d", &n0);
    while(n0 != 495)
    {
        int dig3 = n0 / 100,
            dig2 = n0 % 100 / 10,
            dig1 = n0 % 10,
            maxNum = 100*max(dig1,dig2,dig3)+10*mid(dig1,dig2,dig3)+min(dig1,dig2,dig3),
            minNum = 100*min(dig1,dig2,dig3)+10*mid(dig1,dig2,dig3)+max(dig1,dig2,dig3),
            n1 = maxNum - minNum,
            delta = n0 - n1;
        if (delta > 0)
        {
            sum += delta;
            n0 = n1;
        }else
        {
            n0 = n1;
        }
    }

    printf("%d", sum);
}

int max(int a, int b, int c)
{
    if(a > b && a > c)
        return a;
    else if(b > c)
        return b;
    else
        return c;
}

int min(int a, int b, int c)
{
    if(a < b && a < c)
        return a;
    else if(b < c)
        return b;
    else
        return c;
}

int mid(int a, int b, int c)
{
    if(a < max(a,b,c) && a > min(a,b,c))
        return a;
    else if(b < max(a,b,c) && b > min(a,b,c))
        return b;
    else 
        return c;
}