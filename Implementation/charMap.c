#include"../Header_files/charMap.h"

void mapInit(mapChar* map[MAP_SIZE]) {
    for (int i = 0; i < 128; ++i) {
        map[i] = NULL;
    }
}

void addToMap(mapChar* map[MAP_SIZE], char ch, int value) {
    map[ch] = (mapChar*) malloc(sizeof(mapChar));
    map[ch]->character = ch;
    map[ch]->value = value;
}

int getValue(mapChar* map[MAP_SIZE], char ch) {
    return map[ch]->value;
}

int containsKey(mapChar* map[MAP_SIZE], char ch) {
    if (map[ch]!=NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

void removeKey(mapChar* map[MAP_SIZE], char key) {
    if (map[key] != NULL) {
        free(map[key]);
        map[key] = NULL;
    }
}