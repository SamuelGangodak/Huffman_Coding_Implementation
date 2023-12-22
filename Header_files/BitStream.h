# include<stdlib.h>
# include<stdbool.h>

typedef struct {
    unsigned char byte;
    int size;
}bit_stream;

bit_stream* create_bitStream();

bool is_BitStream_Full(bit_stream *stream);

void push_bit_right(bit_stream *stream, char bit);

void clear_bitStream(bit_stream *stream);

void free_bitStream(bit_stream *stream);

unsigned char bitStream_getBit(bit_stream *stream);