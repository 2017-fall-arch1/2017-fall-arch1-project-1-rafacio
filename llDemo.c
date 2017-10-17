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

  printf("Time to build the Binary Search Tree!");

  while (gets_n(buf, 100)){	/* build list */
   printf("Enter a name you want to add, or type 'exit' to stop: ");
   
   if(strcmp(buf,"exit") == 0){
      break;
   }
   
   BSTadd(bst, buf);
  }
  
  printBSThelp(bst);
  
}
