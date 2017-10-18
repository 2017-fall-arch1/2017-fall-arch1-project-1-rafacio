#include <stdio.h>		/* for printf */
#include <stdlib.h>		/* for free() */
#include <string.h> 		/* for strlen */
#include "llist.h"		/* for list operations */


/* read no more than limit chars into s, return #chars read.  Doesn't include trailing \n */
int gets_n(char *s, int limit)	
{
char *p = s;			/* for indexing into s */
char c;
if (fgets(s, limit, stdin)) {
    while ((c = *p) && c != '\n') /* scan p through s until 0 or \n */
    p++;
    if (c == '\n')		/* erase \n */
    *p = 0;
}
return (p - s);		/* #chars read (not including terminator or \n*/
}

void main()
{
printf("Welcome to Robert Facio's Arch 1 Demo~~!");
    
char buf[100];
BST *bst = BSTAlloc();	/* make empty list */

printf("Time to build the Binary Search Tree! \n");
printf("Enter a name you want to add, or type 'exit' to stop: ");

while (strcmp(buf,"exit") != 0){	/* build list */
    gets_n(buf, 100);
    printf("Enter a name you want to add, or type 'exit' to stop: ");
    
    if(strcmp(buf,"exit") == 0){
        break;
    }
    BSTadd(bst, buf);
}

printf("\n");
printf("\n");
printBSThelp(bst);

printf("\n");
printf("\n");
printf("Preparing to make file with items in Binary Search Tree...");
printf("....................................\n");
printf(".................................\n");
printf("..............................\n");
printf("...........................\n");
printf("........................\n");
printf(".....................\n");
printf("..................\n");
printf("...............\n");
printf("............\n");
printf(".........\n");
printf("......\n");
printf("...\n");
printf(".\n");

printf("Done :)\n");

printf("\n");
printf("\n");
printf("Printing what is in the file...");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");
printf("\n");

processFile(bst);
/*prinf("Would you like to delete a name? [N/y]: ");
if(gets_n(buf, 100) == "y"){
    
}*/

}
