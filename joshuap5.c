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
    //Local Variables
    int i;
    NodeT *pTitle = p->element.szTitle;
    NodeT *pCost = p->element.dCost;
    NodeT *pCostIdn = p->element.cCostInd;

    if (p == NULL)
        return;
    for (i = 0; i < iIndent; i++)
      printf("   ");
      if(pCostIdn == 0) //Prints the szTitle of each node NOT containing a price
         printf("  %2s\n", *pTitle);
      else              //Prints the szTitle of each node containing a price
      {
        printf("  %2s", *pTitle);
        printf("\t %d", *pCost); //Still Needs Work (Allignment)
      }

    prettyPrintT(p->pChild,iIndent+1);
    prettyPrintT(p->pSibling,iIndent+1);
}

/**************************************************************************
                             Main Functions
 ***************************************************************************/
/*************************** printPriceMenu *******************************
 void printPriceMenu(Tree tree)
 Purpose:
 
 Parameters:
 
 Returns:
 
 **************************************************************************/
void printPriceMenu(Tree tree)
{
    //Local Variable(s)
    Node *pCurrentNode = tree->pRoot;

    //Price Menu Title
    printf("Price Menu\n");

    //Traverse the tree and print each nodes Title
    prettyPrintMenu(*pCurrentNode, 1); //Start indents = 1
}

/****************************** printOne **********************************
 void printOne(Tree tree, char szId[])
 Purpose:
    Supposed to print only one part of the tree
        - Title
        - Cost
 Parameters:
 I      Tree tree       Struct containing the Root and Nodes of a tree
 IO     char szId[]     Element Identification
 Returns:
 
**************************************************************************/
void printOne(Tree tree, char szId[])
{
    NodeT *p = findId(tree->pRoot,szId);
    if (p == NULL)
        printf("PRINT ERROR: Id %s not found\n", szId);
    else
        printf("PRINT ONE:\n Title: %s Cost: %lf\n"
                ,p->element.szTitle
                ,p->element.dCost);
}

