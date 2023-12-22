# include<stdio.h>
# include<string.h>
# include"..\Header_files\charMap.h"
# include"..\Header_files\Heap_function.h"
# include"..\Header_files\BitStream.h"

mapChar* map[MAP_SIZE];
int main() {
    mapInit(map);
    FILE *fptr1=fopen("../../Main_Folder/inputFile.txt", "r");
    FILE *fptr2=fopen("../../Main_Folder/outputFile.bin", "wb");
    if (fptr1==NULL) {
        printf("Cannot find file");
        return 0;
    }
    char str1[2000];
    fgets(str1, 2000, fptr1);
    int i=0;
    while(str1[i]!='\0') {
        if(containsKey(map,str1[i])) {
            map[str1[i]]->value+=1;
        }
        else {
            addToMap(map,str1[i], 1);
        }
        i++;
    }
    printf("\nText Taken-\n\n");

    for(int i=0; i<128; i++) {
        if(map[i]!=NULL) {
            printf("%c %d\n", map[i]->character, map[i]->value);
        }
    }
    
    Node *charNode;
    Heap *heap=CreateHeap();
    char *ch=(char*)calloc(2, sizeof(char));
    for(i=0; i<128; i++) {
        if(map[i]!=NULL) {
            ch[0]=map[i]->character;
            ch[1]='\0';
            //printf("%s ", ch);
            charNode=createNode(ch, map[i]->value);
            InsertNode(heap, charNode);
            free(charNode);
            charNode=NULL;
        }
    }

    printf("\n\nCreating tree...\n\n");
    Node *first, *second, *joined;
    while(heap->curr_size>1) {
        first=DeleteRootNode(heap);
        second=DeleteRootNode(heap);
        joined=linking(first, second);
        InsertNode(heap, joined);
        free(first);
        free(second);
        free(joined);
    }
    first = NULL;
    second = NULL;
    joined = NULL;
    Node *root=DeleteRootNode(heap);

    printf("\nGenerating....\n\n");
    mapInit(map);
    char str2[10000]="";
    i=0;

    while(str1[i]!='\0') {
        char bin[128]="";
        binaryEq(bin, root, str1[i]);
        if(!containsKey(map, str1[i])) {
            addToMap(map, str1[i],   atoi(bin));
        }
        strcat(str2, bin);
        i++;
    }
    char *string = (char*)calloc(2000, sizeof(char));
    string[0] = '\0';
    for (int i = 0; str1[i]!='\0' ; i++) {
        int bin = getValue(map, str1[i]);
        snprintf(string,2000,"%s%d",string,bin);
    }
    printf("\nDone\n\n");

    bit_stream *stream = create_bitStream();
    
    for (int i = 0; string[i]!='\0' ; i++) {
        char ch = string[i];
        if (is_BitStream_Full(stream)){
            fprintf(fptr2,"%c", bitStream_getBit(stream));
            clear_bitStream(stream);
            push_bit_right(stream, ch);
        }
        else {
            push_bit_right(stream, ch);
        }
    }
    printf("\nBit Stream created\n\n");
    fprintf(fptr2,"%c  ", bitStream_getBit(stream));

    clear_bitStream(stream);
    free_bitStream(stream);
    printf("\nStatus : Completed\n\n\n");
    return 0;
}