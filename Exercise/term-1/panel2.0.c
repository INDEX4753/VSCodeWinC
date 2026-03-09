#include <stdio.h>
#include <string.h>

int main()
{
    int W;
    // 读取宽度参数 W
    scanf("%d", &W);
    getchar(); // 吸收 W 后的换行符

    char line[200];
    // 读取包含三个字段的整行（用户名可能含空格，用 fgets 确保完整读取）
    fgets(line, sizeof(line), stdin);
    // 移除行末尾的换行符
    line[strcspn(line, "\n")] = '\0';

    // 按逗号分割三个字段
    char *id = strtok(line, ",");
    char *username = strtok(NULL, ",");
    char *email = strtok(NULL, ",");

    // 截断超长字段（长度超过 W 时，保留前 W 个字符）
    if (strlen(id) > W)
    {
        id[W] = '\0';
    }
    if (strlen(username) > W)
    {
        username[W] = '\0';
    }
    if (strlen(email) > W)
    {
        email[W] = '\0';
    }

    // 格式化输出表格（左对齐，宽度为 W）
    printf("| ID       | %-*s |\n", W, id);
    printf("| Username | %-*s |\n", W, username);
    printf("| Email    | %-*s |\n", W, email);

    return 0;
}