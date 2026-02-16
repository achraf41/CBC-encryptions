#ifndef FILEIO_H
#define FILEIO_H
#include "linkedlist.h"
#include <stdio.h>

node* readfile(char *filename);
void writelisttofile(node *head,const char *filename);

#endif

