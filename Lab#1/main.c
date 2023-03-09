#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* fp;
    int a[] = {1,2,3} ;
    int a_read[sizeof(a)/sizeof(a[0])];
    char b[] = "ABC" ;
    float c[] = {1.1, 1.2, 1.3} ;
    if ((fp = fopen("a.bin", "wb+")) == NULL) {
        printf("Cannot open the file...") ;
        exit(1);
    }
    if (fwrite(a, sizeof(a), 1,fp) != 1) {
        printf("File write error....\n");
    }
    fseek(fp, 0, SEEK_SET);

    if (fread(a_read,sizeof(a_read), 1, fp) != 1) {
        printf("File read error....\n") ;
    }
    for (int i = 0 ;i < (sizeof(a)/sizeof(a[0])) ;i++) {
        printf("%d",a_read[i]);
    }
    return 0 ;
}
