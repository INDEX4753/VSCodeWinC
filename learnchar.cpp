#include <iostream>
#include <stdio.h>
#include <math.h>
#include <cmath>
#include <ctype.h>

float s(int a, int b, int c);

int main()
{
    char name[4] = "NJU";
    char addr[16] = "Jiangsu Nanjing"; // 字符长度为所有字符+“/0”（表示字符结束），汉字2倍
    char type = 'C';
    int types = type + 32;
    printf("%c", types); // 实现大小写字母的转化"A char is actually an int."

    int year = 1902;
    int month = 5;
    int day = 20;

    int score_of_edu = 100;
    int score_of_res = 99;
    int score_of_ifu = 86;

    float pingjunzhi = (score_of_edu + score_of_res + score_of_res) / 3.0f;
    float biaozhuncha = s(score_of_edu, score_of_res, score_of_res);
    int paiming = 5;

    printf("%s\t%s\n", name, addr);
    printf("%c\n", type);
    printf("%.2d-%.2d-%d\n", month, day, year);
    printf("%.4d\t%.4d\t%.4d\n", score_of_edu, score_of_res, score_of_res);
    printf("%f\t%f\t%d\n", pingjunzhi, biaozhuncha, paiming);
    /*********************************************************
        %d: int型变量占位符, 用来指明变量height的值显示的位置
        %c: char型变量占位符, 用来指明变量ch的值显示的位置
        %f: float型变量占位符, 用来指明变量profit的值显示的位置
        %lf: double型变量占位符, 用来指明变量pi的值显示的位置
    **********************************************************/

    system("pause");
    return 0;
}

float s(int a, int b, int c) ///< Ciallo~
{
    float adv = (a + b + c) / 3.0f;
    float s2 = (pow(a - adv, 2) + pow(b - adv, 2) + pow(c - adv, 2));
    return sqrt(s2);
    // sqrt()函数开方，默认double
    // pow( , )函数表示幂，默认double
}
