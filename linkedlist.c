#include "linkedlist.h"

node* createnode( uint8_t* data) {
    node* newnode = (node*)malloc(sizeof(node));
    memcpy(newnode->data, data, block_size);
    newnode->next = NULL;
    return newnode;
};
node* insertnode(node *head, uint8_t* data) {
    node* newnode = createnode(data);
    if (head == NULL)head = newnode;
    else {
        node* tmp = head;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = newnode;
    }
    return head;
};
node* deletenode(node* head, uint8_t* data) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return NULL;
    }
    node* tmp = head;
    node* prev = NULL;
    while (tmp != NULL) {
        if (memcmp(tmp->data, data, block_size) == 0) {
            break;
        }
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp == NULL) {
        printf("This node does not exist.\n");
        return head;
    }
    if (prev == NULL) {
        head = tmp->next;
    } else {
        prev->next = tmp->next;
    }
    free(tmp);
    return head;
}
void displaylist(node *head) {
    node *current = head;
    while (current) {
        for (int i = 0; i < block_size; i++) {
            if (current->data[i] == '\0') { // Skip padded null bytes
                break;
            }
            printf("%c", current->data[i]); // Print as characters
        }
        printf("\n");
        current = current->next;
    }
};
void frrelist(node *head) {
    node *tmp;
    while (head) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
};




