#include <stdio.h>

int main() {
    
    char a[] = "AABBBCCCCddd";
    int len = 0;
    int count = 1;
    
    while (a[len] != '\0') {
        len++;
    }    
    
    for (int i = 0; i < len; i++) {
        if (a[i] == a[i+1]) {
            count++;
        } else {
            printf("%c%d", a[i], count);
            count = 1;
        }
    }
    return 0;
}
