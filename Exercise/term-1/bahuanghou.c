#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    // 初始化棋盘，使用动态分配
    char **board = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++)
    {
        board[i] = (char *)malloc((n + 1) * sizeof(char)); // +1 用于存储字符串结束符
        for (int j = 0; j < n; j++)
        {
            board[i][j] = '.';
        }
        board[i][n] = '\0';
    }

    // 存储所有棋子的信息
    char *types = (char *)malloc(m * sizeof(char));
    int *x_coords = (int *)malloc(m * sizeof(int));
    int *y_coords = (int *)malloc(m * sizeof(int));

    // 读取棋子信息并在棋盘上标记
    for (int i = 0; i < m; i++)
    {
        scanf(" %c %d %d", &types[i], &x_coords[i], &y_coords[i]);
        // 转换为0-based索引
        int x = x_coords[i] - 1;
        int y = y_coords[i] - 1;
        board[x][y] = types[i];
    }

    // 处理每个棋子的攻击范围
    for (int i = 0; i < m; i++)
    {
        char type = types[i];
        int x = x_coords[i] - 1;
        int y = y_coords[i] - 1;

        if (type == 'N')
        { // 骑士
            // 骑士的8种可能移动
            int moves[8][2] = {
                {2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

            for (int j = 0; j < 8; j++)
            {
                int nx = x + moves[j][0];
                int ny = y + moves[j][1];
                // 检查是否在棋盘范围内
                if (nx >= 0 && nx < n && ny >= 0 && ny < n)
                {
                    // 如果该位置没有棋子，则标记为被攻击
                    if (board[nx][ny] == '.')
                    {
                        board[nx][ny] = 'X';
                    }
                }
            }
        }
        else if (type == 'R')
        { // 车
            // 同一行
            for (int j = 0; j < n; j++)
            {
                if (board[x][j] == '.')
                {
                    board[x][j] = 'X';
                }
            }
            // 同一列
            for (int j = 0; j < n; j++)
            {
                if (board[j][y] == '.')
                {
                    board[j][y] = 'X';
                }
            }
        }
        else if (type == 'Q')
        { // 皇后
            // 同一行
            for (int j = 0; j < n; j++)
            {
                if (board[x][j] == '.')
                {
                    board[x][j] = 'X';
                }
            }
            // 同一列
            for (int j = 0; j < n; j++)
            {
                if (board[j][y] == '.')
                {
                    board[j][y] = 'X';
                }
            }
            // 主对角线 (左上到右下)
            int dx = 1, dy = 1;
            while (x + dx < n && y + dy < n)
            {
                if (board[x + dx][y + dy] == '.')
                {
                    board[x + dx][y + dy] = 'X';
                }
                dx++;
                dy++;
            }
            dx = 1, dy = 1;
            while (x - dx >= 0 && y - dy >= 0)
            {
                if (board[x - dx][y - dy] == '.')
                {
                    board[x - dx][y - dy] = 'X';
                }
                dx++;
                dy++;
            }
            // 副对角线 (右上到左下)
            dx = 1, dy = 1;
            while (x + dx < n && y - dy >= 0)
            {
                if (board[x + dx][y - dy] == '.')
                {
                    board[x + dx][y - dy] = 'X';
                }
                dx++;
                dy++;
            }
            dx = 1, dy = 1;
            while (x - dx >= 0 && y + dy < n)
            {
                if (board[x - dx][y + dy] == '.')
                {
                    board[x - dx][y + dy] = 'X';
                }
                dx++;
                dy++;
            }
        }
    }

    // 输出棋盘
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", board[i]);
    }

    // 释放内存
    for (int i = 0; i < n; i++)
    {
        free(board[i]);
    }
    free(board);
    free(types);
    free(x_coords);
    free(y_coords);

    return 0;
}