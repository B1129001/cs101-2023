#include <stdio.h>

int main() {
    int a[] = {-9, 8, 7, 6, 5, -4, 3, -2, 1};
    int i = 4;
    
    int n = sizeof(a) / sizeof(int) - 1;      // 計算陣列的長度
    int k, j, temp;

    for (k = 0; k < n - 1; k++) {          // 使用泡沫排序法由大到小排序
        for (j = 0; j < n - k - 1; j++) {
            if (a[j] < a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    printf("%d\n", a[i-1]);

    return 0;
}
