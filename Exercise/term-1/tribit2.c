#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isLegal(char *s);
void decToBalanced(int n, char *buf);

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        char s[100];
        fgets(s, sizeof(s), stdin);
        s[strcspn(s, "\n")] = 0; 
        if (!isLegal(s)) {
            printf("Radix Error\n");
            continue;
        }
        int num = atoi(s);
        char buf[100];
        decToBalanced(num, buf);
        printf("%s\n", buf);
    }
    return 0;
}

int isLegal(char *s) {
    int len = strlen(s);
    if (len == 0) return 0;
    for (int i = 0; i < len; i++) {
        if (s[i] != '-' && !isdigit(s[i])) {
            return 0;
        }
    }
    if (s[0] == '-') {
        if (len == 1) return 0; 
        if (s[1] == '0' && len > 2) return 0; 
    } else {
        if (s[0] == '0' && len > 1) return 0; 
    }
    return 1;
}

void decToBalanced(int n, char *buf) {
    if (n == 0) {
        strcpy(buf, "0");
        return;
    }
    char temp[100] = {0};
    int index = 0;
    int isNegative = n < 0;
    if (isNegative) {
        n = -n; 
    }
    while (n != 0) {
        int r = n % 3;
        if (r == 2) {
            r = -1;
            n = (n + 1) / 3;
        } else if (r == 1) {
            n = n / 3;
        } else { 
            n = n / 3;
        }
        temp[index++] = (r == 1) ? '1' : (r == 0) ? '0' : 'Z';
    }
    if (isNegative) {
        for (int i = 0; i < index; i++) {
            if (temp[i] == '1') {
                temp[i] = 'Z';
            } else if (temp[i] == 'Z') {
                temp[i] = '1';
            }
        }
    }
    int j = 0;
    for (int i = index - 1; i >= 0; i--) {
        buf[j++] = temp[i];
    }
    buf[j] = '\0';
}