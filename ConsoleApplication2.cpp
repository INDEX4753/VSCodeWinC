/**************************************************************
 *	这是一个能够解简单的一元二次方程的程序
 *	用户需要输入方程的系数a、b、c（整数）
 *	其中a不能为0，否则将会报错
 *	程序会计算方程的根，并输出结果
 *	作者：ABYSSovo
 ***************************************************************/

#include <stdio.h>
#include <cmath>

int main()
{
	long a, b, c;
	printf("Enter coefficients a, b and c: ");
	scanf("%ld %ld %ld", &a, &b, &c);
	if (a == 0)
	{
		printf("Error: a cannot be 0.\n");
		return 1;
	}

	double delta = b * b - 4 * a * c;

	if (delta < 0)
	{
		printf("0\n");
	}
	else if (delta == 0)
	{
		double root0 = -b / (2.0f * a);
		printf("1\n");
		printf("%.3f\n", root0);
	}
	else
	{
		double root1 = (-b - sqrt(delta)) / (2.0f * a);
		double root2 = (-b + sqrt(delta)) / (2.0f * a);
		printf("2\n");
		printf("%.3f %.3f\n", root1, root2);
	}

	system("pause");

	return 0;
}
