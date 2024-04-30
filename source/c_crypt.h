typedef struct 
{
OVERLAPPED overlapped;
HANDLE file;
uint8_t operation;
uint8_t inpbuff[BUFFER_SIZE];
uint8_t outbuff[BUFFER_SIZE];
ULONGLONG current_block;
ULONGLONG file_size;
} overlapped_enc;
