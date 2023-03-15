#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort(int *arr) {
    for (int k = 0; k < 6-1; k++) {    
        for (int j = 0; j < 6-k-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    } 
}
void generate_lottery_numbers (int *arr) {
    for (int i = 0; i < 7; i++) {
        if (i == 6) {
            arr[i] = rand() % 10 + 1;
        } else {
            arr[i] = rand() % 69 + 1;
        }
        for (int j = 0; j < i; j++) {
            if (i == 6 && arr[j] == arr[i]) {
                arr[i]= rand() % 10 + 1;
            } else if (i < 6 && arr[j] == arr[i]) {
                arr[i]= rand() % 69 + 1;
            }
        }
    }
}
int main() {
    int lottery_numbers[7], n;
    printf("歡迎光臨長庚樂透彩購買機臺\n請問您要買幾組樂透彩 (1 ~ 5): ");
    scanf("%d", &n);
    printf("以爲您購買的%d組樂透組合輸出至lotto.txt\n", n);
    FILE* fp = fopen("lotto.txt", "w+");
    
    srand((unsigned)time(NULL));
    putenv("TZ=Asia/Taipei");
    tzset();
    time_t curtime = time(NULL);
    asctime(localtime(&curtime));
    
    fprintf(fp, "======== lotto649 ========\n %s", asctime(localtime(&curtime)));
    for (int i = 1; i <= n; i++) {
        generate_lottery_numbers(lottery_numbers);
        sort(lottery_numbers);
        fprintf(fp, "[%d]: ", i);
        for (int i = 0; i < 7; i++) {
            if(lottery_numbers[i] <= 9) {
                fprintf(fp, "0%d ", lottery_numbers[i]);
            } else {
                fprintf(fp, "%d ", lottery_numbers[i]);
            }
        }
        fprintf(fp, "\n");
    }
    for (int i = n+1; i <= 5; i++) {
        fprintf(fp, "[%d]: -- -- -- -- -- -- --\n", i);
    }
    fprintf(fp, "======== csie@CGU ========\n");
    fclose(fp);
    return 0;
}
