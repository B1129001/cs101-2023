#include <stdio.h>
int main() {
    char a[] = "81c8g8u168";
    char *roman[9] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    int i = 0, c = 0;
    
    while (a[i] != '\0') {  
        if (a[i] >= '1' && a[i] <= '9') { 
            c = a[i] - '0' - 1;
            printf("%s ", roman[c]);
        } else {
            printf("%c ", a[i]);
        }
        i++;
    }
    return 0;
}
