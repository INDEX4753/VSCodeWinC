#include <stdio.h>

int main() {
    int n = 0;
    scanf("%d", &n);
    int size = 2 * n - 1;
    int a[size];
    
    for (int i = 0; i < size; i++) {
        scanf("%d", &a[i]);
    }
    
    for (int i = 0; i < size; i++) {
        if (a[i] == 0) continue;
        for (int j = i + 1; j < size; j++) {
            if (a[i] == a[j]) {
                a[i] = a[j] = 0; 
                break; 
            }
        }
    }
    
    for (int i = 0; i < size; i++) {
        if (a[i] != 0) {
            printf("%d ", a[i]);
        }
    }
    printf("\n"); 
    
    return 0;
}
