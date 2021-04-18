#include <stdio.h>
#include <string.h>
void Gronsfeld(int select, char *str, int str_size, char *key, int key_size)
{
    int i=0, j=0;

    for(i=0;i<str_size;i++){
        j = i%key_size; // 문자열이 아무리 길어도 key size만큼의 블록마다 암호화를 해야한다.

        if(select==1){
            if((str[i]>='A')&&(str[i]<='Z')){ // Affine Cipher과 마찬가지로 대, 소문자에 대한 검사
                str[i] -= 'A';
                key[j] -= '0'; // key를 받았는데, str과 마찬가지로 char로 이루어진 문자열이므로 ASCII CODE '0'을 빼주면 1부터 int로 저장될 것이다.
                if(str[i]+key[j]<0) // key를 더한 값이 음수라면, 그에 대응하는 알파벳 Z부터 매핑하기위해 +26.
                    str[i] += 26;
                str[i]=(str[i]+key[j])%26; // key를 더한 값이 25를 넘어가면, 그에 대응하는 알파벳에 다시 매핑하기 위해 mod 26 연산.
                str[i]+='A';
                key[i]+='0';
            }
            if((str[i]>='a')&&(str[i]<='z')){
                str[i] -= 'a';
                key[j] -= '0';
                if(str[i]+key[j]<0)
                    str[i] += 26;
                str[i] = (str[i]+key[j])%26;
                str[i] += 'a';
                key[i] += '0';
            }
        }
        if(select==2){
            if((str[i]>='A')&&(str[i]<='Z')){
                str[i] -= 'A';
                key[j] -= '0';
                if(str[i]-key[j]<0)
                    str[i] += 26;
                str[i]=(str[i]-key[j]);
                str[i]+='A';
                key[i]+='0';
            }
            if((str[i]>='a')&&(str[i]<='z')){
                str[i] -= 'a';
                key[j] -= '0';
                printf("%d",key[j]);
                if(str[i]-key[j]<0)
                    str[i] += 26;
                str[i] = (str[i]-key[j]);
                str[i] += 'a';
                key[i] += '0';
            }
        }
    }
}
int main()
{
    int key_size=0, str_size=0, select=1;
    char str[50]={0,}, key[16]={0,};

    printf("Please Type Plaintext or Ciphertext :");
    gets(str);
    printf("1. Encryption / 2. Decryption :");
    scanf("%d",&select);
    fflush(stdin);
    printf("Please Type Key Value :");
    gets(key);

    str_size = strlen(str);
    key_size = strlen(key);

    Gronsfeld(select, str, str_size, key, key_size);

    printf("\nEncrypted or Decrypted Text :");
    puts(str);

    return 0;
}