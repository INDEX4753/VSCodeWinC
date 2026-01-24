#include <stdio.h>
#include <math.h>

int main()
{
    double x1, y1, x2, y2, x, y, distance, angle;
    scanf("%lf %lf", &x1, &y1);
    scanf("%lf %lf", &x2, &y2);
    x = x2 - x1;
    y = y2 - y1;

    distance = hypot(x, y);
    angle = fmod(((atan2(y, x) * 180.0) / acos(-1.0)) + 360.0, 360.0);

    printf("%.4lf %.4lf", distance, fmod(450.0 - angle, 360.0));
    return 0;
}