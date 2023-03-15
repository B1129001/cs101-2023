#include <stdio.h>

int main() {
    FILE *fp_read, *fp_write;
    char ch;
    fp_read = fopen("main2.c", "r");
    fp_write = fopen("main2.txt", "w");
    
    if (fp_write == NULL) {
        printf("Cannot open main2.txt\n");
        return 1;
    }
    if (fp_read == NULL) {
        printf("Cannot open main2.c \n");
        return 1;
    }
    while ((ch = fgetc(fp_read)) != EOF) {  
        fputc(ch, fp_write);    
    }
    fclose(fp_read);
    fclose(fp_write);
    printf("讀取 main2.c 檔案並將其內容寫入 main2.txt 檔案成功\n");
    return 0;
}    
