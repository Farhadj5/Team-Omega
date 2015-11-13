/**********************************************************************
 cs2123p5.c by TEAM OMEGA [Farhad Jijina, Lane Burris, Joshua Weigand]
 
 Purpose:
 
 Command Parameters:
 
 Input:
 
 Results:
 
 Returns:
 
 Notes:
 
 **********************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include "cs2123p5Driver.c"


/**************************************************************************
                            Helper Functions
 ***************************************************************************/

//Insert Helper Functions to be used with with main Functions found in the
//  Header file.








/**************************************************************************
            Main Functions (NOTE: Helper Functions Listed Above)
 ***************************************************************************/

/******************************* findId ***********************************
 NodeT *findId(NodeT *p, char szId[])
 Purpose:
 
 Parameters:
 
 Returns:

 **************************************************************************/
NodeT *findId(NodeT *p, char szId[])
{
    //base case
    if (p == NULL)
        return NULL;

    //szId is found
    if (strcmp(p->element.szId,szId)==0)
        return p;

    //iterate through the rest of the tree
    findId(p->pChild, szId);
    findId(p->pSibling, szId);
    return NULL;
}

/***************************** findParent *********************************
 NodeT *findParent(NodeT *pParent, NodeT *p, NodeT *pkid)
 Purpose:
 
 Parameters:
 
 Returns:
 
 **************************************************************************/
NodeT *findParent(NodeT *pParent, NodeT *p, NodeT *pkid)
{
    //base case
    if (p==NULL)
        return NULL;

    //check to see if found
    if (strcmp(p->element.szId,pkid->element.szId)==0)
        return pParent;

    //check if there is no sibling
    if (p->pSibling == NULL)
        findParent(p,p->pChild,pkid);

    //if there is a sibling
    else
        findParent(pParent,p->pSibling,pkid);

    return NULL;

    
}

/*************************** printPriceMenu *******************************
 void printPriceMenu(Tree tree)
 Purpose:
 
 Parameters:
 
 Returns:
 
 **************************************************************************/
void printPriceMenu(Tree tree)
{
    
    
}

/****************************** printOne **********************************
 void printOne(Tree tree, char szId[])
 Purpose:
 
 Parameters:
 
 Returns:
 
 **************************************************************************/
void printOne(Tree tree, char szId[])
{
    
        p = findId(tree->pRoot,szToken);
        if (p == NULL)
            printf("PRINT ERROR: Id %s not found\n", szToken);
        else
            printf("PRINT ONE:\n Title: %s Cost: %lf\n"
                   ,p->element.szTitle
                   ,p->element.dCost);
    
}

/****************************** freeSubTree *******************************
 void freeSubTree(NodeT *p)
 Purpose:
 
 Parameters:
 
 Returns:
 
 **************************************************************************/
void freeSubTree(NodeT *p)
{
    
    
}

/********************************* freeTree *******************************
 void freeTree(Tree tree)
 Purpose:
 
 Parameters:
 
 Returns:
 
 **************************************************************************/
void freeTree(Tree tree)
{
    
    
}

/************************** insertPriceMenu *******************************
 void insertPriceMenu(Tree tree, Element element, char szParentId[])
 Purpose:
 
 Parameters:
 
 Returns:
 
 **************************************************************************/
void insertPriceMenu(Tree tree, Element element, char szParentId[])
{
    
    
}

/************************** determineQuote *******************************
 QuoteResult determineQuote(Tree tree, QuoteSelection quoteSelection)
 Purpose:
 
 Parameters:
 
 Returns:
 
 **************************************************************************/
QuoteResult determineQuote(Tree tree, QuoteSelection quoteSelection)
{
    
    
}

/********************************* deleteItem *******************************
 void deleteItem(Tree tree, char szId[])
 Purpose:
 
 Parameters:
 
 Returns:
 
 **************************************************************************/
void deleteItem(Tree tree, char szId[])
{
    
    
}

/**************************************************************************
    Driver function to process a input data line (Include in Driver?)
 ***************************************************************************/

/***************************** processCommand *****************************
 void processCommand(Tree tree, QuoteSelection quote, char szInputBuffer[])
 Purpose:
 
 Parameters:
 
 Returns:
 
 **************************************************************************/
void processCommand(Tree tree, QuoteSelection quote, char szInputBuffer[])
{
    
    
}


