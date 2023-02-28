#include <stdio.h>

int main() {
    char a[] = "A3B2C4A9"; 
    char output[100];       // 放新字串的陣列
    int i = 0, j = 0;
    
    while (a[i] != '\0') {
        i++;
        int count = 0;
        while (a[i] >= '0' && a[i] <= '9') {
            count = a[i] - '0';
            for (int k = 0; k < count; k++) {
                output[j] = a[i-1];
                j++;
            }
            i++;
        }
    }
    output[j] = '\0'; 
    printf("%s", output);
    
    return 0;
}
