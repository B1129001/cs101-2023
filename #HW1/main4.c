#include <stdio.h>

int main() {
    char a[] = "ac-99bc";
    int i = 0, sign = 1, num = 0;
    
    while (a[i] != '\0') {
        if (a[i] == '-') {  // 檢查負號
            sign = -1;
        }
        i++;
    }    
    i=0;
    
    while (a[i] != '\0') {  
        if (a[i] >= '0' && a[i] <= '9') {  
            num = num * 10 + (a[i] - '0');  // 計算整數
        } 
        i++;
    }
    printf("%d\n", sign * num); 
    return 0;
}
