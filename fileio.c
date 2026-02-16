
#include "fileio.h"


node* readfile(char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    node *head = NULL, *tail = NULL;
    uint8_t transport[block_size];
    size_t bytesRead;

    while ((bytesRead = fread(transport, 1, block_size, file)) > 0) {

        if (bytesRead < block_size) {
            memset(transport + bytesRead, 0, block_size - bytesRead);
        }

        node *newNode = createnode(transport);
        if (!head) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
    }
    fclose(file);
    return head;
}


void writelisttofile(node *head,const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error creating file: %s\n", filename);
        return;
    }

    node *current = head;
    while (current) {
        fwrite(current->data, 1, block_size, file);
        current = current->next;
    }

    fclose(file);
}

