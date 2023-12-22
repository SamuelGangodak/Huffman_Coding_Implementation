
/**
*   This program demonstrates a basic key-value mapping implementation using an array of pointers
*   to structs. It includes functions to initialize the map, add key-value pairs, retrieve values
*   based on keys, and check for key existence.
*/

#define MAP_SIZE 128
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char character;
    int value;
}mapChar;



void mapInit(mapChar* map[MAP_SIZE]);

void addToMap(mapChar* map[MAP_SIZE], char ch, int value);

int getValue(mapChar* map[MAP_SIZE], char ch);

int containsKey(mapChar* map[MAP_SIZE],char ch);

void removeKey(mapChar* map[MAP_SIZE],char key);