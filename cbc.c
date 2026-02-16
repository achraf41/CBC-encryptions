#include "cbc.h"


CBC* cbcdefine( const uint8_t *key, const uint8_t *iv) {
    CBC* cbc =(CBC*)malloc(sizeof(CBC));
    memcpy(cbc->iv,iv,16);
    memcpy(cbc->key,key,16);
    return cbc;
};



void decryptlist(CBC *cbc ,node *head) {
    node *tmp = head;
    while (tmp) {
        decryptblock(cbc,tmp->data);
        tmp = tmp->next;
    }
}

void decryptblock(CBC *cbc, uint8_t *block) {
    uint8_t currentCiphertext[block_size];
    memcpy(currentCiphertext, block, block_size);
    uint8_t decrypted[block_size];
    for (int i = 0; i < block_size; i++) {
        decrypted[i] = block[i] ^ cbc->key[i];
    }
    for (int i = 0; i < block_size; i++) {
        block[i] = decrypted[i] ^ cbc->iv[i];
    }
    memcpy(cbc->iv, currentCiphertext, block_size);
}




void encryptlist(CBC *cbc ,node *head) {
    node *tmp = head;
    while (tmp != NULL) {
        encryptblock(cbc,tmp->data);
        tmp = tmp ->next;
    }
}

void encryptblock(CBC *cbc, uint8_t *block) {
    uint8_t xorResult[block_size];
    for (int i = 0; i < block_size; i++) {
        xorResult[i] = block[i] ^ cbc->iv[i];
    }
    for (int i = 0; i < block_size; i++) {
        block[i] = xorResult[i] ^ cbc->key[i];
    }
    memcpy(cbc->iv, block, block_size);
}








