#include <stdio.h>
#include <string.h>

int main() {
    int row_num = 0, col_num = 0, size = 0, select = 0, cnt = 0;
    char text[64]={0,} , tmp_text[3][32]={0,}, c_text[64]={0,}, d_text[64]={0,};

    printf("1.Encryption / 2.Decryption :");
    scanf("%d", &select);

    if (select == 1) {
        printf("Type Plaintext :");
        scanf("%s", text);
        size = strlen(text);
    } else if (select == 2) {
        printf("Type Ciphertext :");
        scanf("%s", text);
        size = strlen(text);
    }

    if (select == 1) {
        for (col_num = 0; col_num < size; col_num++) {
            if (((text[col_num] >= 'a') && (text[col_num] <= 'z')) ||
                ((text[col_num] >= 'A') && (text[col_num] <= 'Z'))) {
                if (col_num % 3 == 0)
                    tmp_text[0][col_num / 3] = text[col_num];
                else if(col_num % 3 == 1)
                    tmp_text[1][col_num / 3] = text[col_num];
                else
                    tmp_text[2][col_num / 3] = text[col_num];
            }
        }
        if (size % 3 == 0) {
            for (col_num = 0; col_num < (size / 3); col_num++) {
                c_text[col_num] = tmp_text[0][col_num];
                c_text[col_num + (size / 3)] = tmp_text[1][col_num];
                c_text[col_num + (size / 3) *2] = tmp_text[2][col_num];
            }
        }
        else if(size % 3 == 1){
            for (col_num = 0; col_num < (size / 3); col_num++) {
                c_text[col_num] = tmp_text[0][col_num];
                c_text[col_num + (size / 3)+1] = tmp_text[1][col_num];
                c_text[col_num + ((size / 3)*2)+1] = tmp_text[2][col_num];
            }
            c_text[col_num] = tmp_text[0][col_num];
        }
        else {
            for (col_num = 0; col_num < (size / 3); col_num++) {
                c_text[col_num] = tmp_text[0][col_num];
                c_text[col_num + (size / 3) + 1] = tmp_text[1][col_num];
                c_text[col_num + ((size / 3) * 2) + 2] = tmp_text[2][col_num];
            }
            c_text[col_num] = tmp_text[0][col_num];
            c_text[col_num+(size/3)+1] = tmp_text[1][col_num];
        }

        printf("Encrypted Text : ");
        for (col_num = 0; col_num < size; col_num++) {
            printf("%c", c_text[col_num]);
        }
        printf("\n");
    }
    else if (select == 2) {
        if (((text[col_num] >= 'a') && (text[col_num] <= 'z')) ||
            ((text[col_num] >= 'A') && (text[col_num] <= 'Z'))) {
            if(size % 3 == 0) {
                for (col_num = 0; col_num < size; col_num++) {
                    if(col_num%3==0)
                        d_text[col_num] = text[col_num/3];
                    else if(col_num%3==1)
                        d_text[col_num] = text[(col_num/3) + (size / 3)];
                    else
                        d_text[col_num] = text[(col_num/3) + ((size / 3)*2)];
                }
            }
            else if(size%3 == 1){
                for (col_num = 0; col_num < size; col_num++) {
                    if(col_num%3==0)
                        d_text[col_num] = text[col_num/3];
                    else if(col_num%3==1)
                        d_text[col_num] = text[(col_num/3) + ((size / 3)+1)];
                    else
                        d_text[col_num] = text[(col_num/3) + (((size / 3)*2)+1)];
                }
            }
            else{
                for (col_num = 0; col_num < size; col_num++) {
                    if(col_num%3==0)
                        d_text[col_num] = text[col_num/3];
                    else if(col_num%3==1)
                        d_text[col_num] = text[(col_num/3) + ((size / 3)+1)];
                    else
                        d_text[col_num] = text[(col_num/3) + (((size / 3)*2)+2)];
                }
            }
        }
        printf("Decrypted Text : ");
        for (col_num = 0; col_num < size; col_num++) {
            printf("%c", d_text[col_num]);
        }
    }
    return 0;
}
