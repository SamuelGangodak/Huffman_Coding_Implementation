#include"../Header_files/Heap_function.h"

Heap* CreateHeap() {
    Heap *heap=(Heap*)malloc(sizeof(Heap));
    heap->data=(Node*)malloc(sizeof(Node)*DEFAULT_SIZE);
    heap->size=DEFAULT_SIZE;
    heap->curr_size=0;
    return heap;
}

int compare(Node *value1, Node *value2) {
    int ret_val=0;
    if(value1->frequency<value2->frequency) ret_val=1;
    return ret_val;
}

boolean IsHeapFull(Heap *heap) {
    boolean ret_val=FALSE;
    if(heap->curr_size==heap->size) ret_val=TRUE;
    return ret_val;
}

void ExpandHeap(Heap *heap) {
    realloc(heap->data, heap->size*2);
    heap->size=heap->size*2;
}

void Swap(Node *data, int indx1, int indx2) {
    Node temp=data[indx1];
    data[indx1]=data[indx2];
    data[indx2]=temp;
}

void printHeap(Heap *heap) {
    Node *value=heap->data;
    printf("heap curr size : %d\n",heap->curr_size);
    for(int i=0; i<heap->curr_size; i++) {
         printf("String:%s, Frequency:%d\n", value[i].str, value[i].frequency);
    }
}

void InsertNode(Heap *heap,Node *value) {
    int i=heap->curr_size-1;
    if(IsHeapFull(heap)) {
        printf("The Heap is Full, need to expand");
        ExpandHeap(heap);
    }
    heap->data[heap->curr_size]=*value;
    heap->curr_size++;
    int childIndx=heap->curr_size-1;
    int parentIndx=(childIndx-1)/2;
    while(childIndx>0 && compare(&heap->data[childIndx],&heap->data[parentIndx] )) {
        Swap(heap->data, childIndx, parentIndx);
        childIndx=parentIndx;
        parentIndx=(childIndx-1)/2;
    }
}

Node* DeleteRootNode(Heap *heap) {
    Node *root=createNode(heap->data[0].str, heap->data[0].frequency);
    root->left=heap->data[0].left;
    root->right=heap->data[0].right;
    int i=0;
    heap->data[i]=heap->data[(heap->curr_size)-1];
    (heap->curr_size)--;
    int index1=2*i+1;
    int index2=2*i+2;
    int flag=1;
        
    while(index2<(heap->curr_size) && flag==1) {
        if(compare(&heap->data[i], &heap->data[index1])&&compare(&heap->data[i], &heap->data[index2])) {
            flag=0;
        }
        else {
            if(compare(&heap->data[index1], &heap->data[index2]) && compare(&heap->data[index1], &heap->data[i])) {
                Swap(heap->data, i, index1);
                i=index1;
                index1=2*i+1;
                index2=2*i+2;
           }
            else {
                Swap(heap->data, i, index2);
                i=index2;
                index1=2*i+1;
                index2=2*i+2;
            }
        }
    }
    if(index1<heap->curr_size && compare(&heap->data[index1], &heap->data[i])) {
         Swap(heap->data, i, index1);
    }
    return root;
}



