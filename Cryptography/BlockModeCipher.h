#ifndef _BLOCKMODECIPHER_H
#define _BLOCKMODECIPHER_H

#include <stdio.h>
#include <string.h>
#include "DES.h"

void DES_CBC_Enc(BYTE *p_text, BYTE *c_text, BYTE *IV, BYTE *key, int msg_len, int cnt){
    BYTE prev[128]={0,};
    if(cnt==0){
        for(int i=0;i<8;i++)
            p_text[i] = p_text[i]^IV[i];
        DES_Encryption(p_text, c_text, key);
        for(int j=0; j<8; j++)
            prev[j] = c_text[j]; //이전 Cipher Block 저장
    }
    else{
        for(int k=0; k<8; k++)
            p_text[k] = p_text[k]^prev[k]; // 이전 Cipher Block과 XOR
        DES_Encryption(p_text, c_text, key);
        for(int n=0; n<8; n++)
            prev[n] = c_text[n];
    }
}

void DES_CBC_Dec(BYTE *c_text, BYTE *d_text, BYTE *IV, BYTE *key, int msg_len, int cnt){
    BYTE prev[128]={0,};
    if(cnt==0){
        DES_Decryption(c_text, d_text, key);
        for(int i=0;i<8;i++)
            d_text[i] = d_text[i]^IV[i];
        for(int j=0; j<8; j++)
            prev[j] = d_text[j]; //이전 Cipher Block 저장
    }
    else{
        DES_Decryption(c_text, d_text, key);
        for(int k=0; k<8; k++)
            d_text[k] = d_text[k]^prev[k]; // 이전 Cipher Block과 XOR
        for(int n=0; n<8; n++)
            prev[n] = d_text[n];
    }
}

void DES_CFB_Enc(BYTE *p_text, BYTE *c_text, BYTE *IV, BYTE *key, int msg_len, int cnt){
    BYTE prev[128]={0,};
    if(cnt==0){
        DES_Encryption(IV, c_text, key);
        for(int i=0; i<8; i++){
            c_text[i] = p_text[i]^c_text[i];
        }
        for(int j=0; j<8; j++)
            prev[j] = c_text[j];
    }
    else{
        DES_Encryption(prev, c_text, key);
        for(int k=0; k<8; k++){
            c_text[k] = p_text[k]^c_text[k];
        }
        for(int m=0; m<8; m++)
            prev[m] = c_text[m];
    }
}

void DES_CFB_Dec(BYTE *c_text, BYTE *d_text, BYTE *IV, BYTE *key, int msg_len, int cnt){
    BYTE prev[128]={0,};
    if(cnt==0){
        DES_Encryption(IV, d_text, key);
        for(int i=0; i<8; i++){
            d_text[i] = c_text[i]^d_text[i];
        }
        for(int j=0; j<8; j++)
            prev[j] = d_text[j];
    }
    else{
        DES_Encryption(prev, d_text, key);
        for(int k=0; k<8; k++){
            d_text[k] = c_text[k]^d_text[k];
        }
        for(int m=0; m<8; m++)
            prev[m] = d_text[m];
    }
}

void DES_OFB_Enc(BYTE *p_text, BYTE *c_text, BYTE *IV, BYTE *key, int msg_len, int cnt){
    BYTE prev[128]={0,};
    if(cnt==0) {
        DES_Encryption(IV, c_text, key);
        for (int j = 0; j < 8; j++)
            prev[j] = c_text[j];
        for (int i = 0; i < 8; i++) {
            c_text[i] = p_text[i] ^ c_text[i];
        }
    }
    else{
        DES_Encryption(prev, c_text, key);
        for(int m=0; m<8; m++)
            prev[m] = c_text[m];
        for(int k=0; k<8; k++){
            c_text[k] = p_text[k] ^ c_text[k];
        }
    }
}

void DES_OFB_Dec(BYTE *c_text, BYTE *d_text, BYTE *IV, BYTE *key, int msg_len, int cnt){
    BYTE prev[128]={0,};
    if(cnt==0) {
        DES_Encryption(IV, d_text, key);
        for (int j = 0; j < 8; j++)
            prev[j] = c_text[j];
        for (int i = 0; i < 8; i++) {
            d_text[i] = d_text[i] ^ c_text[i];
        }
    }
    else{
        DES_Encryption(prev, d_text, key);
        for(int m=0; m<8; m++)
            prev[m] = c_text[m];
        for(int k=0; k<8; k++){
            d_text[k] = d_text[k] ^ c_text[k];
        }
    }
}

void DES_CTR_Enc(BYTE *p_text, BYTE *c_text, BYTE *ctr, BYTE *key, int msg_len, int cnt){
    BYTE counter[10] = {0,};
    for(int m=0; m<7; m++)
        counter[m] = ctr[m];
    counter[6] = counter[6] + cnt;
    DES_Encryption(counter, c_text, key);
    for(int i=0;i<8;i++)
        c_text[i] = p_text[i] ^ c_text[i];
}

void DES_CTR_Dec(BYTE *c_text, BYTE *d_text, BYTE *ctr, BYTE *key, int msg_len, int cnt){
    BYTE counter[10] = {0,};
    for(int m=0; m<7; m++)
        counter[m] = ctr[m];
    counter[6] = counter[6] + cnt;
    DES_Encryption(counter, d_text, key);
    for(int i=0;i<8;i++)
        d_text[i] = d_text[i] ^ c_text[i];
}
#endif //_BLOCKMODECIPHER_H
