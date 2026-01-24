#include <stdio.h>
#define MAX_LEN 1000
int main() {
    int m;
    int a[MAX_LEN] = { 0 };
    scanf("%d", &m);
    for (int i = 0;  i < m; i++) {
        scanf("%d", &a[i]);
    }
    int vaild = 1;
    int d = a[1] - a[0];
    for (int i = 1; i < m - 1; i++) {
        if (a[i + 1] - a[i] <= d) {
            vaild = 0;
            break;
        }
        d = a[i + 1] - a[i];
    }
    for (int i = 0; i < m - 1; i++) {
        if (a[i] > a[i + 1]) {
            vaild = -1;
            break;
        }
    }
    printf("%d", vaild);
}

