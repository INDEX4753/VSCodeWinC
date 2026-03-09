/*
	这是一个实现简单条件判断的C程序。
	程序从标准输入读取五个整数a, b, c, d, e。
	然后它检查以下条件：
	是否有3个数字相等，并且另外两个数字也相等。
*/

#include <stdio.h>

int main()
{
	int a, b, c, d, e;
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

	if ((a == b && d == e) && (c == b || c == d))
		printf("Yes\n");
	else
		printf("No\n");
}
