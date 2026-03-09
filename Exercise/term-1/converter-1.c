#include <stdio.h>

int eNum(int a);
int eNum10(int a);
int eNum1x(int a);

int main()
{
    int n;
    scanf("%d", &n);

    int dig3 = n / 100,
        dig2 = n % 100 / 10,
        dig1 = n % 10;
    
    if (dig3 != 0)
    {
        eNum(dig3);
        printf(" hundred");
        if (dig2 || dig1)  
        {
            printf(" and ");
        }
    }

    if (dig2 >= 2)
    {
        eNum10(dig2);
        if (dig1 != 0)  
        {
            printf("-");
            eNum(dig1);
        }
    }
    else if (dig2 == 1)
    {
        eNum1x(dig1);  
    }
    else  
    {
        if (dig1 != 0) 
        {
            eNum(dig1);
        }
    }
    if (n == 0)
    {
        printf("zero");
    }
    printf("\n");
    return 0;
}

// 输出0-9的英文（0无输出，由主函数特殊处理）
int eNum(int a)
{
    switch (a)
    {
        case 1: printf("one"); break;
        case 2: printf("two"); break;
        case 3: printf("three"); break;
        case 4: printf("four"); break;
        case 5: printf("five"); break;
        case 6: printf("six"); break;
        case 7: printf("seven"); break;
        case 8: printf("eight"); break;
        case 9: printf("nine"); break;
        default: break;
    }
    return 0;
}

// 输出20-90的整十英文
int eNum10(int b)
{
    switch (b)
    {
        case 2: printf("twenty"); break;
        case 3: printf("thirty"); break;
        case 4: printf("forty"); break;
        case 5: printf("fifty"); break;
        case 6: printf("sixty"); break;
        case 7: printf("seventy"); break;
        case 8: printf("eighty"); break;
        case 9: printf("ninety"); break;
        default: break;
    }
    return 0;
}

// 输出10-19的英文
int eNum1x(int c)
{
    switch (c)
    {
        case 0: printf("ten"); break;
        case 1: printf("eleven"); break;
        case 2: printf("twelve"); break;
        case 3: printf("thirteen"); break;
        case 4: printf("fourteen"); break;
        case 5: printf("fifteen"); break;
        case 6: printf("sixteen"); break;
        case 7: printf("seventeen"); break;
        case 8: printf("eighteen"); break;
        case 9: printf("nineteen"); break;
        default: break;
    }

    getchar();
    return 0;
}