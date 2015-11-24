#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include "cs2123p5.h"


/****************************** freeSubTree *******************************
 void freeSubTree(NodeT *p)
 Purpose:
 Frees the current node and its children.
 Parameters:
 I NodeT *p    Node that will be freed.
 Returns:
 
 **************************************************************************/
void freeSubTree(NodeT *p)
{
    // If pointer is at NULL, return the pointer we are on
    if (p == NULL)
    {
        return;
    }
    
    // Recursively going through the children until NULL
    freeSubTree(p->pChild);
    // Once you hit NULL from children, you go to the siblings
    freeSubTree(p->pSibling);
    // Free the pointer it is currently on
    free(p);
    
}

/********************************* freeTree *******************************
 void freeTree(Tree tree)
 Purpose:
 Frees the whole tree.
 Parameters:
 I Tree tree     Tree that is being passed in for freeing.
 Returns:
 **************************************************************************/
void freeTree(Tree tree)
{
    
    NodeT *p;
    // p is set to the pRoot
    p = tree->pRoot;
    // Recursing through the tree and freeing
    freeSubTree(p);
    // Free tree for memory purposes
    free(tree);
    
}

/********************************* deleteItem *******************************
 // Still working on this function
 void deleteItem(Tree tree, char szId[])
 Purpose:
 Uses freeSubTree to free current node as well as the children of the current node.
 After freeSubTree is used, reconnects that sub-tree's sibiling to the parent, or to the other sub-tree's sibiling.
 Parameters:
 I/O Tree tree
 I   char szId[]
 Returns:
 
 **************************************************************************/
void deleteItem(Tree tree, char szId[])
{
    NodeT *pKid = findId(pKid, szId); // Change what this declared to
    NodeT *p  = findParent(NULL, tree->pRoot, pKid); // p is set to the parent
    
    if (*p == *pKid)
    {
        *p = pKid->pSibling;
        pKid->pSibling = NULL;
        freeSubTree(pKid);
    }
    else
    {
        *p = pKid->pSibling;
        freeSubTree(&((*p)->pSibling));
        
    }
}
