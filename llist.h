#ifndef llist_included		/* prevent multiple inclusion */
#define llist_included


/* Binary Search Tree 'helper' */
typedef struct Child{
struct Child *left, *right; 
char *str;
} Child;

/* Binary Search Tree Root*/
typedef struct {
Child *root;
} BST;


/* Creates a New Binary Search Tree */
BST *BSTAlloc();

Child* addNode(Child *root, Child *node);

Child* deleteNode(Child *root, Child *node);

void BSTadd(BST *bst, char *s);

void printBSThelp(BST *bst);

void processFile(BST *bst);

void readFile();

#endif	/* included */
