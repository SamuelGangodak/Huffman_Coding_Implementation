#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define DEFAULT_BUILD_SIZE 1000000000

typedef struct {
    char *string;
    int current_size;
    int size;
}string_builder;

string_builder* build_string();

void stringBuilder_reallocate(string_builder *str);

void append_string(string_builder *str1, const char *str2);
