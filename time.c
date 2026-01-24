#include <stdio.h>

int main(){
    char month[11];
    int day;
    int year;
    char weekday[11];
    int hour;
    int minute;
    int second;
    scanf("%s %d %d %s %d %d %d", month, &day, &year, weekday, &hour, &minute, &second);
    if (year<=9999 && year>=0 && day>=1 && day<=31 && hour>=0 && hour<=23 && minute>=0 && minute<=59 && second>=0 && second<=59){
        printf("%.3s %.3s %.2d %.2d:%.2d:%.2d %.4d",weekday, month, day, hour, minute, second, year);
        return 0;
    }
    else{
        return 1;
    }
    
}