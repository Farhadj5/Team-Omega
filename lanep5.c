

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
    
    if (p == NULL)
    {
        return;
    }
    
    freeTree(p->pChild);
    freeTree(p->pSibling);
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
    p = tree->pRoot;
    
    freeSubTree(p);
    
}

/********************************* deleteItem *******************************
 void deleteItem(Tree tree, char szId[])
 Purpose:
 Uses freeSubTree to free current node as well as the children of the current node.
 After freeSubTree is used, reconnects that sub-tree's sibiling to the parent, or to the other sub-tree's sibiling.
 Parameters:
 I/O Tree tree
 Returns:
 
 **************************************************************************/
void deleteItem(Tree tree, char szId[])
{
    NodeT *p;
    NodeT *pKid = findParent(NULL, p-pRoot, pKid);
    
    if (*p == pKid)
    {
        *p = pKid->pSibling;
        pKid->pSibling = NULL;
        freeSubTree(pKid);
    }
    else
    {
        
    }
}