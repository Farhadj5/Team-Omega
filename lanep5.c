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
 I/O Tree tree      Tree being traversed through.
 I   char szId[]    ID being passed in to be looking for.
 Returns:
 
 **************************************************************************/
void deleteItem(Tree tree, char szId[])
{
    NodeT *pKid = findId(tree->pRoot, szId); // The kid we are finding
    NodeT *pParentLogical = findParent(NULL, tree->pRoot, pKid); // Logical parent of pKid
    NodeT *pParentPhysical = findParentPhysical(pParentLogical, pKid); // pKid's parent
    
    // If it has the same physical and logical parent
    if (pParentLogical->pChild == pKid)
    {
<<<<<<< Updated upstream
        pParentLogical->pChild = pKid->pSibling;
=======
        pParentPhysical->pChild = pKid->pSibling;
>>>>>>> Stashed changes
        pKid->pSibling = NULL;
        freeSubTree(pKid);
    }
    // We're removing the middle of the three
    else if (pParentPhysical->pSibling == pKid)
    {
        pParentPhysical->pSibling = pKid->pSibling;
        pKid->pSibling = NULL;
        freeSubTree(pKid);
    }
    // Used for when you are deleting Model
    else if (pParentLogical == NULL)
    {
        pParentPhysical = tree->pRoot;
        pParentPhysical->pChild = pKid->pSibling;
        pKid->pSibling = NULL;
        freeSubTree(pKid);
        
    }
    // pKid doesn't have anymore siblings
    else
    {
        pParentPhysical = pParentPhysical->pSibling;
        pParentPhysical->pSibling = NULL;
        freeSubTree(pKid);
        
    }

}

/********************************* findParentPhysical *******************************
 // Still working on this function
 NodeT *findParentPhysical(NodeT *pLogical, NodeT *pKid)
 Purpose:
 
 Parameters:
 I  NodeT *pLogical        The logical parent of pKid
 I  NodeT *pKid            Node in the tree we are trying to find the physical parent of
 Returns:
    returns:
        - pTemp     returned if the sibling of temp is kid, that means temp is the physical parent
        - pLogical  returned if temp is kid, then the logical parent is the physical parent as well
 ***********************************************************************************/
NodeT *findParentPhysical(NodeT *pLogical, NodeT *pKid)
{
    // Made for a temp for physical parent
    NodeT *pTemp = pLogical->pChild;
    
    // Traversing through the tree
    while (pTemp != NULL)
    {
        // if temp is kid, then the logical parent is the physical parent as well
        if (pTemp == pKid)
            return pLogical;
        // if the sibling of temp is kid, that means temp is the physical parent
        if (pTemp->pSibling == pKid)
            return pTemp;
        else
            pTemp = pTemp->pSibling;
    }
    return NULL;
}
