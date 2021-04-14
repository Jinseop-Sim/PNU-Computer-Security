#include <stdio.h>
#include <string.h>

char CaesarCipher(char *str, int str_size, int key)
{
    int i;
    for(i=0;i<str_size;i++)
    {
        if((str[i]>='A')&&(str[i]<='Z')) // 대문자에 대한 검사
        {
            str[i] -= 'A'; // str안의 문자에 대한 값을 0~25에 매핑.

            if (str[i] + key < 0) // 문자 + key로 암호화 한 값이 음수라면, 양수로 다시 매핑하기 위해 26을 더해준다.
            {
                str[i] += 26;
            }
            str[i] = (str[i] + key) % 26; // 문자 + key 값이 25를 넘어가버리면 매핑할 문자가 없으므로 mod 연산 시행.
            str[i] += 'A'; // 매핑했던 0~25의 값을 다시 문자로 되돌린다.
        }
        else if((str[i] >= 'a') && (str[i] <= 'z')) {
            str[i] -= 'a';

            if (str[i] + key < 0) // 문자 + key로 암호화 한 값이 음수라면, 양수로 다시 매핑하기 위해 26을 더해준다.
            {
                str[i] += 26;
            }
            str[i] = (str[i] + key) % 26;
            str[i] += 'a';
        }
    }
}

int main(){
    int i=0, key=0, str_size=0;
    char str[50]={0,};

    printf("Please Type Plaintext or Ciphertext : ");
    gets(str);

    printf("Please Type Key Value : ");
    scanf("%d",&key);

    str_size=strlen(str);

    CaesarCipher(str, str_size, key);

    printf("\nEncrypted or Decrypted Text : ");
    puts(str);

    return 0;
}
