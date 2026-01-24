#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int check = 0;
    int read;

    for(int i = 1; i <= 2*n - 1; i++){
        scanf("%d", &read);
        check ^= read;  //使用异或保留只出现一次的数
    }

    printf("%d", check);

    return 0;
}