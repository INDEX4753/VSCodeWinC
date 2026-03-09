#include <stdio.h>


int main() {
    int n = 1;
    const int key[18] = { 0, 0, 3, 0, 0, 0, 
                          0, 0, 0, 0, 0, 0,
                          0, 0, 15, 16, 0, 18};
    int x[18] = { 0 };
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }
    int ans1 = -1, 
        ans2 = 0, 
        ans3 = 0;

    if (n == 1) {
        printf("%d %d %d\n", key[x[0]-1], key[x[0]-1], key[x[0]-1]);
    }
    else {
        for (int i = 0; i < n;i++) {
            ans1 &= key[x[i]-1];    
        } 
        for (int i = 0; i < n;i++) {
            ans2 |= key[x[i]-1];    
        }
        for (int i = 0; i < n;i++) {
            ans3 ^= key[x[i]-1];    
        }
        printf("%d %d %d\n", ans1, ans2, ans3);         
    }
}