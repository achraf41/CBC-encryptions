#ifndef CBC_H
#define CBC_H
#include <stdint.h>
#include "linkedlist.h"
#include <stdio.h>


typedef struct CBC {
    uint8_t iv[block_size];
    uint8_t key[block_size];
}CBC;

CBC* cbcdefine( const uint8_t *key, const uint8_t *iv);
void encryptblock(CBC *cbc,uint8_t *block);
void decryptblock(CBC *cbc,uint8_t *block);
void encryptlist(CBC *cbc ,node *head);
void decryptlist(CBC *cbc ,node *head);

#endif

