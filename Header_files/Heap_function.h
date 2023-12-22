# include<stdio.h>
# include<stdlib.h>
# include"..\Header_files\Node.h"
# define DEFAULT_SIZE 50
typedef struct{
    Node *data;
    int size;
    int curr_size;
}Heap;

Heap* CreateHeap();

int compare(Node *value1, Node *value2);

boolean IsHeapFull(Heap *heap);

void ExpandHeap(Heap *heap);

void Swap(Node *data, int indx1, int indx2);

void printHeap(Heap *heap);

void InsertNode(Heap *heap,Node *value);

Node* DeleteRootNode(Heap *heap);