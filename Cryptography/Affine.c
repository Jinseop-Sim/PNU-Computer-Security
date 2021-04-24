#include <stdio.h>
#include <string.h>

char AffineCipher(char *str, int str_size, int key1, int key2, int select)
{
    int i, j,sol, key_inv;
    if(select==1){
        for(i=0;i<str_size;i++)
        {
            if((str[i]>='A')&&(str[i]<='Z')) // 대문자에 대한 검사
            {
                str[i] -= 'A'; // str안의 문자에 대한 값을 0~25에 매핑.
                str[i] = (key1*str[i] + key2) % 26; // key1*문자 + key2 값이 25를 넘어가버리면 매핑할 문자가 없으므로 mod 연산 시행.
                str[i] += 'A'; // 매핑 했던 0~25의 값을 다시 문자로 되돌린다.
            }
            else if((str[i] >= 'a') && (str[i] <= 'z')) {
                str[i] -= 'a';
                str[i] = (key1*str[i] + key2) % 26;
                str[i] += 'a';
            }
        }
    }
    else if(select==2){
        for(j = 0; j<26; j++){   // 복호화를 위한 key1의 역원을 찾는 코드이다. key1을 그냥 나누어버리면 소용이 없다!
            sol = (key1*j)%26;   // 그냥 나누는 것이 아닌, 역원을 곱해야만 원래의 Plaintext를 추출할 수가 있다.
            if(sol==1) {
                key_inv = j;
            }
        }
        for(i=0;i<str_size;i++)
        {
            if((str[i]>='A')&&(str[i]<='Z')) // 대문자에 대한 검사
            {
                str[i] -= 'A'; // str안의 문자에 대한 값을 0~25에 매핑.
                str[i] = ((str[i] - key2)*key_inv)%26; // (str-key2)/key_inv 값이 25를 넘어가버리면 매핑할 문자가 없으므로 mod 연산 시행.
                if (str[i] < 0) // (str-key2)/key_inv 로 복호화 한 값이 음수라면, 양수로 다시 매핑하기 위해 26을 더해준다.
                {
                    str[i] += 26;
                }
                str[i] += 'A'; // 매핑 했던 0~25의 값을 다시 문자로 되돌린다.
            }
            else if((str[i] >= 'a') && (str[i] <= 'z')) {
                str[i] -= 'a';
                str[i] = ((str[i] - key2)*key_inv)%26;
                if (str[i] < 0)    // (str-key2)/key_inv 로 복호화 한 값이 음수라면, 양수로 다시 매핑하기 위해 26을 더해준다.
                {
                    str[i] += 26;
                }
                str[i] += 'a';
            }
        }
    }
    else;
}

int main(){
    int i=0, select=1, key1=0, key2=0, str_size=0;
    char str[50]={0,};

    printf("Please Type Plaintext or Ciphertext :");
    gets(str);

    printf("1. Encryption / 2. Decryption :");
    scanf("%d",&select);
    fflush(stdin);

    printf("Please Type Key Value :");
    scanf("%d %d",&key1,&key2);

    str_size=strlen(str);

    AffineCipher(str, str_size, key1, key2, select);

    printf("\nEncrypted or Decrypted Text :");
    puts(str);

    return 0;
}
