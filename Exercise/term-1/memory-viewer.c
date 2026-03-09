#include <stdio.h>

int main() {
    unsigned int addr, data;
    
    scanf("%u %u", &addr, &data);
    
    char hexData[9]; 
    sprintf(hexData, "%08x", data);
    
    printf("0x%08x: ", addr);
    for (int i = 0; i < 8; i += 2) {
        printf(" %c%c", hexData[i], hexData[i+1]);
    }
    printf("\n");
    
    return 0;
}