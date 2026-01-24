#include <stdio.h>
#include <stdbool.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    bool alive[n + 1]; // 编号为1~n，alive[i]为true表示i号还在圈中
    for (int i = 1; i <= n; ++i) {
        alive[i] = true;
    }

    int last = 1; // 第一轮离开的是1号
    alive[last] = false;
    int cnt = 1;  // 已离开的人数

    while (cnt < n - 1) {
        int step = a[last - 1]; // 上一轮离开的人的数字a_i
        int current = (last % n) + 1; // 从last的下一个位置开始数
        int count = 0;

        // 数step个存活的人
        while (count < step) {
            if (alive[current]) {
                ++count;
            }
            if (count < step) { // 未数到足够的人数，继续下一个位置
                current = (current % n) + 1;
            }
        }

        // 标记当前找到的人离开
        alive[current] = false;
        ++cnt;
        last = current; // 更新上一轮离开的人的位置
    }

    // 找到最后存活的人
    for (int i = 1; i <= n; ++i) {
        if (alive[i]) {
            printf("%d\n", i);
            break;
        }
    }

    return 0;
}