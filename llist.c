#include <stdio.h>		/* for puts,  */
#include <stdlib.h> 		/* for malloc */
#include <assert.h>		/* for assert */
#include "llist.h"		
#include <string.h>

/* int llDoCheck = 1;		 set true for paranoid consistency checking */

#define doCheck(_lp) (llDoCheck && llCheck(_lp))

/* create a new list */
BST *BSTAlloc()
{
BST *bst = (BST *)malloc(sizeof(BST));
bst->root = NULL;
return bst;
}

/* Delete all elements off of the list */

void printBSThelp(BST *bst){
    printBST(bst->root);
}

void printBST(Child *node)
{
    if(node != NULL){
        printBST(node->left);
        printf("%s\n", node->str);
        printBST(node->right);
    }
}

/* Adds a node */
void BSTadd(BST *bst, char *s)
{
    int length;
    char *scopy;
    Child *i;

    i = (Child *)malloc(sizeof(Child));
    /* w = freshly allocated copy of putWord */
    for (length = 0; s[length]; length++) /* compute length */
    ;

    scopy = (char *)malloc(length+1);

    for (length = 0; s[length]; length++){ /* copy chars */
        scopy[length] = s[length];
    }

    scopy[length] = 0;			/* terminate copy */


    i->str = scopy;
    i->left = NULL;
    i->right = NULL;

    /* new item is last on list */
    bst->root = addNode(bst->root, i);
}

Child* addNode(Child *root, Child *node){
if(root == NULL){
    return node;
}

int cmpValue = strcmp(node->str, root->str);
if(cmpValue < 0){
    root->left = addNode(root->left, node);
}
else{
    root->right = addNode(root->right, node);
}

return root;
}

void processFile(BST *bst){
    FILE *fp;
    fp = fopen("test.txt", "w");
    writeToFile(bst->root, fp);
}    

void writeToFile(Child *curNode, FILE *fp){
    if(curNode != NULL){
        writeToFile(curNode->left, fp);
        printf("%s\n", curNode->str);
        fprintf(fp, "%s\n", curNode->str);
        writeToFile(curNode->right, fp);
    }
}

void readFile(){
    FILE *fileToRead;
    char filename[15];
    char ch;
    
    printf("Enter the filename to be opened: \n");
    scanf("%s", filename);
    fileToRead = fopen(filename, "r");
    if(fileToRead == NULL){
        printf("Can not open the file... either corrupt or does not exist\n");
        exit(0);
    }
    ch = fgetc(fileToRead);
    while(ch != EOF){
        printf("%c", ch);
        ch = fgetc(fileToRead);
    }
    
    printf("\n");
    fclose(fileToRead);
}
/*
void BSTdeletehelp(BST *bst){
        BSTdelete(bst->root);
    }
    
void BSTdelete(Child *root){
        
    }
*/
