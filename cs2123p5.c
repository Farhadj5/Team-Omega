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
#include "cs2123p5.h"


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
 I      Tree tree       Struct containing the Root and Nodes of a tree
 IO     char szId[]     Element Identification
 Returns:
 
 **************************************************************************/
void printOne(Tree tree, char szId[])
{
    
<<<<<<< Updated upstream
        p = findId(tree->pRoot,szToken);
        if (p == NULL)
            printf("PRINT ERROR: Id %s not found\n", szToken);
        else
            printf("PRINT ONE:\n Title: %s Cost: %lf\n"
                   ,p->element.szTitle
                   ,p->element.dCost);
    
=======
>>>>>>> Stashed changes
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
    . After the QUOTE END command is received, this is called.
    . Prints the quote details including the title and cost for each option value.
    . Handles error cases and understands a partial quote.
 Parameters:
    Tree tree                       Tree being passed in to be traversered
                                        through for the quote
 
    QuoteSelection quoteSelection
 Returns:
    Returns a QuoteResult which includes a total cost
 **************************************************************************/
QuoteResult determineQuote(Tree tree, QuoteSelection quoteSelection)
{
    int iIncrement;

    for (iIncrement = quoteSelection->iQuoteItemCnt; iIncrement < sizeof(quoteItemM); iIncrement++)
    {
        // What needs to be the subscript of the array?
        printf("Title: %s\nCost: %d", quoteSelection->quoteItemM[quoteSelection->iQuoteItemCnt].szOptionId, quoteSelection->quoteItemM[quoteSelection->iQuoteItemCnt].dCost);
    }
    
    
    
    // QuoteResult is supposed to be dTotalCost;
    return QuoteResult = dTotalCost;
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

/**************************************************************************
                                    QuoteEnd
 ***************************************************************************/

/******************************** quoteEND ********************************
 void quoteEND(Tree tree, char szId[])
 Purpose:
 
 Parameters:
 
 Returns:
 
 **************************************************************************
void quoteEND(Tree tree, char szId[])
{
    //Local Variable Declaration
    char szTitle[30] = tree->pRoot->element.szTitle;
    
    //Print Model
    while(szId == model)
    {
        if(tree->pRoot->element.szTitle == base) //Prints BASE Model
            printf("\t Base
                   \t\t\t\t
                   
                   else if(tree->pRoot->element.szTitle == lx) //Prints PLUS Model
                   printf("\t Plus\n");
                   else if(tree->pRoot->element.szTitle == oy) //Prints OH_YEAH! Model
                   printf("\t Oh_Yeah!\n");
                   else
                   printf("\nInvalid Model\n");
                   }
                   
                   //Print Engine
                   while(szId == engine)
                   {
                       if(tree->pRoot->element.szId == base) //Prints BASE Model
                           if
                               printf("\t\t\t Base\n");
                       
                           else
                               printf("\nInvalid Engine\n");
                       
                   }
                   
                   //Print Color
                   while(szId == color)
                   {
                       if(tree->pRoot->element.szId == base) //Prints BASE Model
                           if
                               printf("\t\t\t Base\n");
                       
                           else
                               printf("\nInvalid Engine\n");
                       
                   }
                   
                   //Print Audio
                   while(szId == audio)
                   {
                       if(tree->pRoot->element.szId == base) //Prints BASE Model
                           if
                               printf("\t\t\t Base\n");
                       
                           else
                               printf("\nInvalid Engine\n");
                       
                   }
                   
                   //Print Warranty
                   while(szId == warranty)
                   {
                       if(tree->pRoot->element.szId == base) //Prints BASE Model
                           if
                               printf("\t\t\t Base\n");
                       
                           else
                               printf("\nInvalid Engine\n");
                       
                   }
        }
*/
