# include"../Header_files/BitStream.h"

bit_stream* create_bitStream() {
    bit_stream *stream = malloc(sizeof(bit_stream));
    stream->byte = 0;
    stream->size = 0;
    return stream;
}

bool is_BitStream_Full(bit_stream *stream) {
    bool ret_val=false;
    if(stream->size==8) ret_val=true;
    return ret_val;
}

void push_bit_right(bit_stream *stream, char bit) {
    char *stringBit = (char*)malloc(2);
    stringBit[0]=bit;
    stringBit[1]='\0';
    char x = (char)(atoi(stringBit));
    stream->byte = stream->byte << 1;
    stream->byte |= x;
    stream->size++;
    free(stringBit);
}

void clear_bitStream(bit_stream *stream) {
    stream->byte = 0;
    stream->size = 0;
}

void free_bitStream(bit_stream *stream) {
    free(stream);
}

unsigned char bitStream_getBit(bit_stream *stream) {
    return stream->byte;
}