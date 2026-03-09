#include <stdio.h>
#include <math.h>

int main()
{
	double a = 236674 + 30303 * sqrt(61);
	double b = pow(5280, 3) * pow(a, 3);
	double c = log(b + 744);
	double pi1 = c / sqrt(427);

	double pi2 = (6 * atan(1.0 / 8) + 2 * atan(1.0 / 57) + atan(1.0 / 239)) * 4;
	
	printf("%.16g\n%.16g\n",pi1,pi2);

	return 0;
}