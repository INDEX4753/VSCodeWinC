#include <stdio.h>
#include <string.h>

int main() {
    char username[101];
    fgets(username, 101, stdin); 
    
    int len = strlen(username);
    if (username[len - 1] == '\n') {
        username[len - 1] = '\0';
        len--; 
    }
    
    printf("%d\n", len);
    
    if (len > 20) {
        username[20] = '\0';
    }
    

    printf("\"%s\"\n", username);
    
    return 0;
}