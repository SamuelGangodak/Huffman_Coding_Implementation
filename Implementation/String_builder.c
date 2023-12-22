#include"../Header_files/String_builder.h"

string_builder* build_string() {
    string_builder *str =(string_builder*)malloc(sizeof(string_builder));
    str->string = (char*) calloc(DEFAULT_BUILD_SIZE,sizeof(char));
    str->size = DEFAULT_BUILD_SIZE;
    str->current_size = 0;
    return str;
}

void stringBuilder_reallocate(string_builder *str) {
    char *ptr =(char*)realloc(str->string,str->size*2);
    if(ptr!=NULL)
        str->string = ptr;
    str->size *= 2;
}

void append_string(string_builder *str1, const char *str2) {
    while (strlen(str2)>=(str1->size-str1->current_size)) {
        stringBuilder_reallocate(str1);
    }
    str1->current_size++;
    strcat(str1->string,str2);
}

