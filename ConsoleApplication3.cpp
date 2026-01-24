//-----------------------------------------------------------------
// 2038问题的求解程序
// 作者：ABYSSovo（刘泽豪）
//-----------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h> //声明 system 函数
#define YEAR0 1970
//-----------------------------------------------------------------
// 这里使用了计算年和月的两个自定义函数
long long countYears(int year);
long long countMonths(int year, int month);
//-----------------------------------------------------------------
int main()
{
	printf("请输入正确的时间（ 1970 年 1 月 1 日 00:00:00 UTC之后）：");
	int year, month, day, hour, minute, second;
	scanf("%d %d %d %d %d %d", &year, &month, &day, &hour, &minute, &second);

	long long totalSeconds;

	if (year < YEAR0 || year > 9999 || month < 1 || month > 12 || day < 1 || day > 31 ||
		hour < 0 || hour > 23 || minute < 0 || minute > 59 || second < 0 || second > 59) // 加入了对时间输入是否合法的判断
	{
		printf("输入的时间不合法！\n");
		return 1;
	}

	else
	{
		totalSeconds = countYears(year) + countMonths(year, month) +
					   (day - 1) * 24 * 3600 + hour * 3600 + minute * 60 + second; // 计算总秒数
		printf("%lld\n", totalSeconds);
		system("pause");
		return 0;
	}
}
//--------------------------------------------------------------------
long long countYears(int year)
{
	long long days = 0;
	for (int i = YEAR0; i < year; i++)
	{
		days = days + 365;
		if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) // 判断闰年
		{
			days++; // 闰年366天
		}
	}
	return days * 24 * 3600;
}
//---------------------------------------------------------------------
long long countMonths(int year, int month)
{
	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // 使用了数组来区分月份
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))		  // 判断闰年
	{
		daysInMonth[1] = 29; // 闰年2月29天
	}
	long long days = 0;
	for (int i = 0; i < month - 1; i++)
	{
		days = days + daysInMonth[i];
	}
	return days * 24 * 3600;
}