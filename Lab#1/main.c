#include <stdio.h>
#include <stdlib.h>

int main() {
    int a[] = {1, 2, 3};
    //ar b[] = "ABC";
    //oat c[] = {1.1, 1.2, 1.3};
    FILE* fp;
    int arr_read[3];
    
    fp = fopen("a.bin", "wb+");
    fwrite (a, sizeof(a), 1 ,fp);
    fseek (fp, 0, SEEK_SET);
    fread (arr_read,sizeof(a),1,fp);
    
    for(int i =0;i<3;i++) {
        printf("%d",arr_read[i]);
    }
    fclose(fp);
    
    return 0;
}
