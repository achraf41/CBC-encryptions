#include "cbc.h"
#include "fileio.h"

int main() {
    uint8_t key[block_size] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
                               0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10};
    uint8_t iv[block_size] = {0xFF, 0xEE, 0xDD, 0xCC, 0xBB, 0xAA, 0x99, 0x88,
                              0x77, 0x66, 0x55, 0x44, 0x33, 0x22, 0x11, 0x00};

    CBC* cbc = cbcdefine( key, iv);

    
    char *filename = "C:\\the path to the .txt file you one to use \\file.txt";
    node *head = readfile(filename);
    encryptlist(cbc,head);

    filename = "C:\\where do you one the encrypted file to be \\encrypted_file.bin";
    writelisttofile(head,filename);

    cbc = cbcdefine( key, iv);
    decryptlist(cbc,head);

    filename = "C:\\where do you one the decrypted file to be \\decripted_file.bin";
    writelisttofile(head,filename);
    return 0;
}
