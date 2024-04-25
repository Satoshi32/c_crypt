typedef struct _overlapped_
{
OVERLAPPED overlapped;
HANDLE file;
uint8_t operation;
uint8_t inpbuff[];
uint8_t outbuff[];
ULONGLONG current_block;
ULONGLONG file_size;
} overlapped_enc;
