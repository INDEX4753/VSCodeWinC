#include <stdio.h>
#include <string.h>

int main(){
    char username[101];
    scanf("%100[^\n]", username);
    getchar();
    int len = strlen(username);
    printf("%d\n\"%.20s\"\n", len, username);
    return 0;
}