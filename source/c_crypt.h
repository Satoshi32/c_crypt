typedef struct 
{
OVERLAPPED overlapped;
HANDLE file;
uint8_t operation;
uint8_t inpbuff[BLOCK_SIZE-1];
uint8_t outbuff[BLOCK_SIZE-1];
ULONGLONG current_block;
ULONGLONG file_size;
} overlapped_enc;
