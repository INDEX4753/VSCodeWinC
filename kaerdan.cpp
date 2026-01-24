/*
    计算一元三次方程 x^3 + p*x + q = 0 的一个实根
    使用卡尔丹公式求解
*/
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
