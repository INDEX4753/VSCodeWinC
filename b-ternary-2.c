#include <stdio.h>
#include <string.h>
#include <ctype.h>

char input_str[20];     // 存储输入字符串
char trad_ternary[100]; // 存储传统三进制
int num;                // 存储转换后的十进制数
int is_legal;           // 标记输入是否合法
int n;                  // 测试用例数量
int sign;               // 数字符号（1为正，-1为负）
int idx;                // 数组索引
int carry;              // 进位标志

int main()
{
    int safe = scanf("%d", &n);
    int ch = getchar();
    (void)ch, safe;

    while (n-- > 0)
    {

        memset(input_str, 0, sizeof(input_str));
        memset(trad_ternary, 0, sizeof(trad_ternary));
        num = 0;
        is_legal = 1;
        sign = 1;
        idx = 0;
        carry = 0;

        fgets(input_str, 20, stdin);
        for (int i = 0; i < 20; i++)
        {
            if (input_str[i] == '\n')
            {
                input_str[i] = '\0';
                break;
            }
        }

        int len = 0;
        while (input_str[len] != '\0')
        {
            len++;
        }
        if (len == 0)
        {
            is_legal = 0;
        }
        if (len == 2 && input_str[0] == '-' && input_str[1] == '0')
        {
            is_legal = 0;
        }
        for (int i = 0; i < len; i++)
        {
            if (i == 0 && input_str[i] == '-')
            {
                continue;
            }
            if (input_str[i] < '0' || input_str[i] > '9')
            {
                is_legal = 0;
                break;
            }
        }

        if (!is_legal)
        {
            printf("Radix Error\n");
            continue;
        }

        int start = 0;
        if (input_str[0] == '-')
        {
            sign = -1;
            start = 1;
        }
        for (int i = start; input_str[i] != '\0'; i++)
        {
            num = num * 10 + (input_str[i] - '0');
        }
        num *= sign;

        if (num == 0)
        {
            printf("0\n");
            continue;
        }

        int abs_num = (num < 0) ? -num : num;
        idx = 0;
        while (abs_num > 0)
        {
            trad_ternary[idx] = (abs_num % 3) + '0';
            abs_num = abs_num / 3;
            idx++;
        }
        trad_ternary[idx] = '\0';

        carry = 0;
        for (int i = 0; i < idx; i++)
        {
            int digit = (trad_ternary[i] - '0') + carry;
            carry = 0;
            if (digit == 0)
            {
                trad_ternary[i] = '0';
            }
            else if (digit == 1)
            {
                trad_ternary[i] = '1';
            }
            else if (digit == 2)
            {
                trad_ternary[i] = 'Z';
                carry = 1;
            }
            else if (digit == 3)
            {
                trad_ternary[i] = '0';
                carry = 1;
            }
        }

        if (carry)
        {
            trad_ternary[idx] = '1';
            idx++;
            trad_ternary[idx] = '\0';
        }

        for (int i = 0; i < idx / 2; i++)
        {
            char temp = trad_ternary[i];
            trad_ternary[i] = trad_ternary[idx - 1 - i];
            trad_ternary[idx - 1 - i] = temp;
        }

        if (num < 0)
        {
            for (int i = 0; i < idx; i++)
            {
                if (trad_ternary[i] == 'Z')
                {
                    trad_ternary[i] = '1';
                }
                else if (trad_ternary[i] == '1')
                {
                    trad_ternary[i] = 'Z';
                }
            }
        }

        printf("%s\n", trad_ternary);
    }
    return 0;
}