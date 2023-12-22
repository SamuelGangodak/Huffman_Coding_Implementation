#include"../Header_files/Node.h"

Node* createNode(char *str,int frequency) {
    //printf("Called createNode\n");
    Node *p;
    p=(Node*)malloc(sizeof(Node));
    strcpy(p->str, str);
    p->frequency=frequency;
    p->left=NULL;
    p->right=NULL;
    return p;
}

void InOrder(struct Node *root) {
    if(root!=NULL) {
        InOrder(root->left);
        printf("%d \t%s\n", root->frequency, root->str);
        InOrder(root->right);
        
    }
}

Node* linking(Node *n1, Node *n2) {
    char str[128];
    strcpy(str, n1->str);
    strcat(str, n2->str);
    int value=n1->frequency+n2->frequency;
    Node *n3=createNode(str, value);
    n3->left = (Node*) malloc(sizeof(Node));
    n3->right = (Node*) malloc(sizeof(Node));
    if(n1->frequency<n2->frequency) {
        memcpy(n3->left, n2, sizeof(Node));
        memcpy(n3->right, n1, sizeof(Node));
    }
    else{
        memcpy(n3->right, n2, sizeof(Node));
        memcpy(n3->left, n1, sizeof(Node));
    }
    return n3;
}

void binaryEq(char *bin, Node *root, char ch) {
    if(strlen(root->str)==1) {
        return;
    }
    boolean direction=FALSE;
    for (int i = 0; root->left->str[i]!='\0' && direction==FALSE ; ++i) {

        if (root->left->str[i]==ch) {
            direction = TRUE;
        }
    }
    if (direction==TRUE) {
        strcat(bin, "0");
        return binaryEq(bin, root->left, ch);
    }
    else {
        strcat(bin, "1");
        return binaryEq(bin, root->right, ch);
    }

}