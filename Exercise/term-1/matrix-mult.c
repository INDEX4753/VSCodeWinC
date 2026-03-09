#include <stdio.h>
#define MAX_NUM 100
//--------------------------------
int main(){
    int m = 1, n = 1, p = 1;
    int a[MAX_NUM][MAX_NUM],
        b[MAX_NUM][MAX_NUM],
        c[MAX_NUM][MAX_NUM];
    scanf("%d %d %d", &m, &n, &p);
    getchar();//o

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &a[i][j]);
            getchar();
        }
    }//o

    for (int i = 0; i < n; i++){
        for (int j = 0; j < p; j++){
            scanf("%d", &b[i][j]);
            getchar();
        }
    }//o

    for (int i = 0; i < m; i++){
        for (int j = 0; j < p; j++){
            int sum = 0;
            for (int k = 0; k < n; k++){
                sum += a[i][k] * b[k][j];
            }
            c[i][j] = sum;
        }
    }
    for (int i = 0; i < m; i++){
        for (int j = 0; j < p; j++){
            printf("%d ", c[i][j]);
        }
        printf("\n"); 
    }   
}

