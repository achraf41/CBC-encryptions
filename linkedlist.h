#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define block_size 16
// i shosed to divide the data by 16
typedef struct node {
    uint8_t data[block_size];
    //data contain 16 of 8 bites
    struct node* next;
}node;

node* createnode( uint8_t* data);
node* insertnode(node *head, uint8_t* data);
node* deletenode(node *head, uint8_t* data);
void displaylist(node *head);
void frrelist(node *head);

#endif