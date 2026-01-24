#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    getchar(); // 吸收输入n后的换行符

    int s = 0, p = 0, q = 0;

    for (int i = 0; i < n; ++i) {
        char str[200];
        fgets(str, sizeof(str), stdin);
        str[strcspn(str, "\n")] = 0; // 去除换行符

        char title[100];
        int start = -1, end = -1;
        // 提取标题（找到第一个'{'和最后一个'}'的位置）
        for (int j = 0; str[j] != '\0'; ++j) {
            if (str[j] == '{') {
                start = j;
            } else if (str[j] == '}') {
                end = j;
            }
        }
        strncpy(title, str + start + 1, end - start - 1);
        title[end - start - 1] = '\0'; // 确保字符串结束

        // 优先判断最长的命令（subsubsection），再判断subsection，最后section
        if (strstr(str, "subsubsection")) {
            if (strstr(str, "subsubsection*")) {
                // 带*的subsubsection，直接输出标题
                printf("%s\n", title);
            } 
            else {
                // 不带*的subsubsection，q递增
                q++;
                printf("%d.%d.%d %s\n", s, p, q, title);
            }
        } 
        else if (strstr(str, "subsection")) {
            if (strstr(str, "subsection*")) {
                // 带*的subsection，直接输出标题
                printf("%s\n", title);
            } 
            else {
                // 不带*的subsection，p递增，q归零
                p++;
                q = 0;
                printf("%d.%d %s\n", s, p, title);
            }
        } 
        else if (strstr(str, "section")) {
            if (strstr(str, "section*")) {
                // 带*的section，直接输出标题
                printf("%s\n", title);
            } 
            else {
                // 不带*的section，s递增，p和q归零
                s++;
                p = 0;
                q = 0;
                printf("%d %s\n", s, title);
            }
        }
    }

    return 0;
}