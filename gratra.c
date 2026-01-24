#include <stdio.h>
#include <string.h>
#define MAXN 100

void rotate90(char inPut[][MAXN], char outPut[][MAXN], int n);
void rotate180(char inPut[][MAXN], char outPut[][MAXN], int n);
void rotate270(char inPut[][MAXN], char outPut[][MAXN], int n);
void reflect(char inPut[][MAXN], char outPut[][MAXN], int n);
int isSame(char a[][MAXN], char b[][MAXN], int n);

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        char origin[MAXN][MAXN];
        char trans[MAXN][MAXN];
        for (int i = 0; i < n; i++) {
            scanf("%s", origin[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%s", trans[i]);
        }
        char r90[MAXN][MAXN], r180[MAXN][MAXN], r270[MAXN][MAXN];
        char ref[MAXN][MAXN];
        char ref_r90[MAXN][MAXN], ref_r180[MAXN][MAXN], ref_r270[MAXN][MAXN];
        rotate90(origin, r90, n);
        rotate180(origin, r180, n);
        rotate270(origin, r270, n);
        reflect(origin, ref, n);
        rotate90(ref, ref_r90, n);
        rotate180(ref, ref_r180, n);
        rotate270(ref, ref_r270, n);
        int result = 7;
        if (isSame(r90, trans, n)) {
            result = 1;
        } else if (isSame(r180, trans, n)) {
            result = 2;
        } else if (isSame(r270, trans, n)) {
            result = 3;
        } else if (isSame(ref, trans, n)) {
            result = 4;
        } else if (isSame(ref_r90, trans, n) || isSame(ref_r180, trans, n) || isSame(ref_r270, trans, n)) {
            result = 5;
        } else if (isSame(origin, trans, n)) {
            result = 6;
        }
        printf("%d\n", result);
    }

    return 0;
}


void rotate90(char inPut[][MAXN], char outPut[][MAXN], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            outPut[j][n - 1 - i] = inPut[i][j];
        }
    }
}

void rotate180(char inPut[][MAXN], char outPut[][MAXN], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            outPut[n - 1 - i][n - 1 - j] = inPut[i][j];
        }
    }
}

void rotate270(char inPut[][MAXN], char outPut[][MAXN], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            outPut[n - 1 - j][i] = inPut[i][j];
        }
    }
}

void reflect(char inPut[][MAXN], char outPut[][MAXN], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            outPut[i][n - 1 - j] = inPut[i][j];
        }
    }
}

int isSame(char a[][MAXN], char b[][MAXN], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] != b[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}