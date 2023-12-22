# include<stdio.h>
# include<stdlib.h>
# include<string.h>

typedef enum{FALSE, TRUE}boolean;

typedef struct Node{
    char str[128];
    int frequency;
    struct Node *left;
    struct Node *right;
}Node;

Node* createNode(char *str,int frequency);

void InOrder(struct Node *root);

Node* linking(Node *n1, Node *n2);

void binaryEq(char *bin, Node *root, char ch);