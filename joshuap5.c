#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include "cs2123p5.h"

/**************************************************************************
                            Helper Functions
 ***************************************************************************/

/**************************** prettyPrintMenu *****************************
 void prettyPrintMenu(NodeT *p, int iIndent)
 Purpose:
    Traverses the tree, prints out the siblings, and their details in the
 form of a price menu.
 Parameters:
 I      NodeT *p        Pointer directed to the root of the Tree
 I      int Indent       Used to determine starting point of indented print
 Returns:
 N/A
 **************************************************************************/
void prettyPrintMenu(NodeT *p, int iIndent)
{
    int i;
    if (p == NULL)
        return;
    prettyPrintMenu(p->pChild, iIndent);
    for (i = 0; i < iIndent; i++)
        printf("   ");
    if((strcmp(p->element.szID, "base") == 0) || //Formating improvement for Model Cat.
       (strcmp(p->element.szID, "lx") == 0)   ||
       (strcmp(p->element.szID, "oy") == 0))
    {
        printf("  %-26s", p->element.szTitle);
        printf("\t\t\t%.2lf\n",p->element.dCost);
    }
    else if (p->element.cNodeType == 'V')
    {
        printf("  %-26s", p->element.szTitle);
        printf("\t%.2lf\n",p->element.dCost);
    }
    else
    {
        printf("  %-26s\n",p->element.szTitle);
    }

    prettyPrintMenu(p->pChild,iIndent+2);
    prettyPrintMenu(p->pSibling, iIndent);
}
/**************************************************************************
                             Main Functions
 ***************************************************************************/
/*************************** printPriceMenu *******************************
 void printPriceMenu(Tree tree)
 Purpose:
    Prints the preliminary price menu at the beginning of the output
 Parameters:
 I      Tree Tree     Struct containing the Root and Nodes of a tree
 Returns:
 N/A
 **************************************************************************/
void printPriceMenu(Tree tree)
{
    //Local Variable(s)
    NodeT *pCurrentNode = tree->pRoot;

    //Price Menu Title
    printf("Price Menu\n");

    //Traverse the tree and print each nodes Title
    prettyPrintMenu(pCurrentNode, 0); //Start indents = 0
}

/****************************** printOne **********************************
 void printOne(Tree tree, char szId[])
 Purpose:
    Prints specific attributes of a node.
        -   szTitle
        -   dCost
 Parameters:
 I      Tree tree       Struct containing the Root and Nodes of a tree
 IO     char szId[]     Element Identification
 Returns:
 N/A
**************************************************************************/
void printOne(Tree tree, char szId[])
{
    NodeT *p = findId(tree->pRoot,szId);
    if (p == NULL)
        printf("PRINT ERROR: Id %s not found\n", szId);
    else
        printf("Title: %s\nCost: %.2lf\n"
                ,p->element.szTitle
                ,p->element.dCost);
}

