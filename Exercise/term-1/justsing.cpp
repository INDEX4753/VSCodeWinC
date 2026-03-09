/*
阿伏伽德罗公式
*/
#include <stdio.h>

int main()
{
	double p, l, t;
	scanf("%lf %lf %lf", &p, &l, &t);
	double v = l * l * l;
	const float r = 8.314f;
	double n = (p * v) / (r * t);
	printf("%.4e\n", n);
	return 0;
}