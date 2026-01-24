// ConsoleApplication8.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//-------------------------------------------------------------------------------

#include <stdio.h>
#include <math.h>

int main()
{
    int p, q;
    scanf("%d%d", &p, &q);
    double delta = pow(q / 2.0, 2) + pow(p / 3.0, 3);
    double x1 = cbrt(-q / 2.0 + sqrt(delta)) + cbrt(-q / 2.0 - sqrt(delta));
    printf("%.3f", x1);
    return 0;
}

