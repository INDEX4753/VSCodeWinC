#include <stdio.h>

#define MAX_N 10001  // 最大人数为10^4

int prev[MAX_N];    // 存储每个节点的前驱
int next_[MAX_N];   // 存储每个节点的后继，避免与系统函数冲突
int a[MAX_N];       // 存储每个人手上的数字

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    // 初始化双向循环链表
    for (int i = 1; i <= n; i++) {
        prev[i] = i - 1;
        next_[i] = i + 1;
    }
    prev[1] = n;    // 1号的前驱是n号
    next_[n] = 1;   // n号的后继是1号

    // 第一轮：1号离开
    int last_deleted = 1;
    int p = prev[1];
    int nxt = next_[1];
    prev[nxt] = p;
    next_[p] = nxt;

    int remaining = n - 1;  // 剩余人数

    // 进行剩下的n-2轮
    for (int round = 2; round <= n - 1; round++) {
        // 从上个离开的人的下一个开始数
        int start = next_[last_deleted];
        // 获取步数（上一个离开的人手上的数字）
        int step = a[last_deleted];

        // 优化步数，取模运算减少循环次数
        step %= remaining;
        if (step == 0) {
            step = remaining;
        }

        // 找到要离开的人
        int current = start;
        for (int i = 1; i < step; i++) {
            current = next_[current];
        }

        // 更新最后离开的人
        last_deleted = current;

        // 从链表中删除当前离开的人
        p = prev[current];
        nxt = next_[current];
        prev[nxt] = p;
        next_[p] = nxt;

        remaining--;
    }

    // 最后剩下的人就是最后离开的人的下一个
    printf("%d\n", next_[last_deleted]);

    return 0;
}