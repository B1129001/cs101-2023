#include <stdio.h>

int main() {
    char a[] = "10001111";
    int decimal = 0;
    for (int i = 0; a[i] != '\0'; i++) {
        decimal = decimal << 1;  // 左移一位，
        if (a[i] == '1') {
            decimal = decimal | 1;  // 設最低位為1
        }
    }
    char hex_str[3];
    int high = decimal >> 4;  // 取高4位
    int low = decimal & 0x0F;  // 取低4位
    hex_str[0] = (high < 10) ? (high + '0') : (high - 10 + 'A');  // 轉換高4位
    hex_str[1] = (low < 10) ? (low + '0') : (low - 10 + 'A');  // 轉換低4位
    hex_str[2] = '\0';  
    
    printf("%s\n", hex_str);
    return 0;
}
