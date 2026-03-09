#include <stdio.h>
#include <string.h>
//-----------------------------------------------
int main() {
    int W;
    scanf("%d", &W);
    getchar();

    char idnum[51] = {0}, username[51] = {0}, email[51] = {0};

    for(int i = 0; i < 50; i++){
        scanf("%c", &idnum[i]);
        if(idnum[i] == ','){
            idnum[i] = '\0';
            break;
        }
    }
    for(int i = 0; i < 50; i++){
        scanf("%c", &username[i]);
        if(username[i] == ','){
            username[i] = '\0';
            break;
        }
    }
    for(int i = 0; i < 50; i++){
        scanf("%c", &email[i]);
        if(email[i] == '\n'){
            email[i] = '\0';
            break;
        }
    }

    if (strlen(idnum) > W) {
        idnum[W] = '\0';
    }
    if (strlen(username) > W) {
        username[W] = '\0';
    }
    if (strlen(email) > W) {
        email[W] = '\0';
    }

    printf("| ID       | %-*s |\n", W, idnum);
    printf("| Username | %-*s |\n", W, username);
    printf("| Email    | %-*s |\n", W, email);

    return 0;
}