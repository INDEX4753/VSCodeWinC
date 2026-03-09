#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int h = n / 8;
    int w = m / 9;

    int matrix[n][m];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    int scaled[8][9];
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            int total = 0;
            int start_row = i * h;
            int end_row = (i + 1) * h;
            int start_col = j * w;
            int end_col = (j + 1) * w;
            for (int x = start_row; x < end_row; ++x)
            {
                for (int y = start_col; y < end_col; ++y)
                {
                    total += matrix[x][y];
                }
            }

            scaled[i][j] = total / (h * w);
        }
    }

    int binary[8][8];
    for (int i = 0; i < 8; ++i)
    {
        for (int k = 0; k < 8; ++k)
        {
            binary[i][k] =
                (scaled[i][k + 1] > scaled[i][k]) ? 1 : 0;
        }
    }

    uint64_t hash_val = 0;
    for (int i = 0; i < 8; ++i)
    {
        for (int k = 0; k < 8; ++k)
        {
            hash_val = (hash_val << 1) | binary[i][k];
        }
    }

    char hex_str[17];

    snprintf(hex_str, sizeof(hex_str), "%016" PRIX64, hash_val);
    puts(hex_str);
}