#ifndef _C_CRYPT_H_
#DEFINE _C_CRYPT_H_
#DEFINE WRITE 1
#DEFINE READ 2
#DEFINE HANDLE_EOF 3
#DEFINE CLOSE_IO 4
#DEFINE _BLOCK_SIZE_ (16384 * 5)
#include <aes.h>
#include <minwinbase.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
typedef struct 
{
OVERLAPPED overlapped;
HANDLE file;
char *filename;
uint8_t operation;
uint8_t inpbuff[BLOCK_SIZE-1];
uint8_t outbuff[BLOCK_SIZE-1];
ULONGLONG current_block;
ULONGLONG file_size;
} overlapped_enc;
