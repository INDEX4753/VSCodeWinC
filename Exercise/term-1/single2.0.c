#include <stdio.h>

int main() {
    int n;
    // 读取整数 n
    scanf("%d", &n);
    
    int result = 0;  // 初始化为 0，因为 0 和任意数异或不改变该数
    int num;
    
    // 读取 2n-1 个整数，依次异或
    for (int i = 0; i < 2 * n - 1; ++i) {
        scanf("%d", &num);
        result ^= num;  // 每次将当前数与结果异或
    }
    
    // 输出落单的整数
    printf("%d\n", result);
    
    return 0;
}