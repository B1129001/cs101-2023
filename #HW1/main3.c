#include <stdio.h>

int main() {
    char a[] = "ABCabcABC";
    int shift = 4;
    printf("%s\n", a);
    printf("%d\n", shift);
    
    char temp[shift];
    int n = sizeof(a) / sizeof(char) - 1;

    for (int i = 0; i < shift; i++) {  // 前d個字母複製到臨時陣列
        temp[i] = a[i];
    }
    for (int i = 0; i < n - shift; i++) {  // 剩下字母左移d
        a[i] = a[i + shift];
    }
    for (int i = 0; i < shift; i++) {  // 臨時數列中的字母加回字串尾
        a[n - shift + i] = temp[i];
    }
    printf("%s", a);
    
    return 0;
}
