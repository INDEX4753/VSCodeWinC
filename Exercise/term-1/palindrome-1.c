#include <stdio.h>

int main(){
    int len;
    scanf("%d", &len);
    getchar();
    
    char pali[len];
    for(int i = 0; i < len; i++){
        scanf("%c", &pali[i]);
    }

    for(int i = 0, j = len - 1; i < j; i++, j--){
        if(pali[i] == '?'){
            pali[i] = pali[j];
        }else if(pali[j] == '?'){
            pali[j] = pali[i];
        }
    }

    for(int i = 0; i < len; i++){
        printf("%c", pali[i]);
    }
}