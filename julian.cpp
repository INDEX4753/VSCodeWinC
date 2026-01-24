#include <stdio.h>

int main()
{
	int y, m, d, a, JDN;
	scanf_s("%d %d %d", &y, &m, &d);
	a = (14 - m) / 12;
	y = y + 4800 - a;
	m = m + 12 * a - 3;
	JDN = d + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;
	printf("%d", JDN);
	return 0;
}