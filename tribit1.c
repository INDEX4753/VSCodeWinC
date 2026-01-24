#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        char s[100];
        scanf("%s", s);
        int len = strlen(s);
        int is_valid = 1;

        for (int j = 0; j < len; j++) {
            if (s[j] != '0' && s[j] != '1' && s[j] != 'Z') {
                is_valid = 0;
                break;
            }
        }

        if (!is_valid) {
            printf("Radix Error\n");
            continue;
        }

        long long dec = 0;
        for (int j = 0; j < len; j++) {
            int dig;
            if (s[j] == 'Z') {
                dig = -1;
            } else {
                dig = s[j] - '0';
            }

            long long pow = 1;
            for (int k = 0; k < len - 1 - j; k++) {
                pow *= 3;
            }

            dec += dig * pow;
        }

        printf("%lld\n", dec);
    }

    return 0;
}