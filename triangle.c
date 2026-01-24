#include <stdio.h>

int main(){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (a + b > c && b + c > a && a + c > b)
    {
        if (a == b && b == c)
            printf("equilateral triangle\n");
        else if (a*a + b*b == c*c || a*a + c*c == b*b || b*b + c*c == a*a)
            printf("right triangle\n");
        else
        { 
            if (a*a + b*b < c*c || a*a + c*c < b*b || b*b + c*c < a*a)
            {
                printf("obtuse ");
                if (a == b || a == c || c == b)
                    printf("isosceles triangle\n");
                else
                    printf("triangle\n");
            }
            else
            {
                printf("acute ");
                if (a == b || a == c || c == b)
                    printf("isosceles triangle\n");
                else
                    printf("triangle\n");
            }    
        }

    }
    else
        printf("not triangle\n");

    return 0;
    
}