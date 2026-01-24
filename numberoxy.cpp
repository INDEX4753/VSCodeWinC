/*
 * ConsoleApplication6.cpp
 * 计算氧分子的个数
 * 2024-06-12
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
	const double MOL = 6.02E23;
	const int O2M = 32;
	printf("请输入氧气的质量：");
	float mO2;
	scanf("%f", &mO2);
	double result = mO2 / O2M * MOL;
	printf("氧分子的个数为：%.3e\n\t\t%.5g", result, result);
	system("pause");
	return 0;
}