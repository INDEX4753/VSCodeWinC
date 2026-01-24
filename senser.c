#include <stdio.h>
#include <ctype.h>

int main()
{
    char name[21];
    long pre ;
    double frac ;
    double factor =1.0;
    char unit ;

    scanf("%s %ld %lf  %lf %c",&name,&pre,&frac,&factor,&unit);

    char new_unit = toupper(unit);

    char new_name[3] = {name[0], name[1], '\0'};

    printf("%s: %ld (%.5lf) | %.5E %.5lf %c\n",new_name,pre,frac,pre+frac,(pre*1.0+frac)*factor,new_unit);

    return 0;


}
