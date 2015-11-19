/************************** determineQuote *******************************
 QuoteResult determineQuote(Tree tree, QuoteSelection quoteSelection)
 Purpose:
    . After the QUOTE END command is received, this is called.
    . Prints the quote details including the title and cost for each option value.
    . Handles error cases and understands a partial quote.
 Parameters:
    I Tree tree                         Tree being passed in to be traversered
                                            through for the quote
 
    I/O QuoteSelection quoteSelection
 Returns:
    Returns a QuoteResult which includes a total cost
 **************************************************************************/
QuoteResult determineQuote(Tree tree, QuoteSelection quoteSelection)
{
    int i = 0;
    QuoteResult quote;
    while (i <= quoteSelection->iQuoteItemCnt)
    {
        NodeT *p = findId(tree->pRoot,quoteSelection->quoteItemM[i].szOptionId);
        switch(quoteSelection->quoteItemM[i].iLevel)
        {

        }

    }
    // QuoteResult is supposed to be dTotalCost;
    return quote; //only put here to prevent error messages
}

/******************************* findId ***********************************
 NodeT *findId(NodeT *p, char szId[])
 Purpose:
    Recursively going through the tree to find the specific Id we are looking for.
 Parameters:
    NodeT *p        Node that is being Id searched.
    char szId[]     Character array containing the Id we are searching
                        for.
 Returns:
    Returns the child we are looking that has the specified Id.
 **************************************************************************/
NodeT *findId(NodeT *p, char szId[])
{
    NodeT *pFound = NULL;
    //base case
    if (p == NULL)
        return NULL;

    //szId is found
    if (strcmp(p->element.szId,szId)==0)
        return p;

    //iterate through the rest of the tree
    if (p->pSibling != NULL)
        pFound = findId(p->pSibling, szId);
    if (pFound != NULL)
        return pFound;
    if (p->pChild != NULL)
        pFound =findId(p->pChild, szId);

    return pFound;
}

/***************************** findParent *********************************
 NodeT *findParent(NodeT *pParent, NodeT *p, NodeT *pkid)
 Purpose:
    Finds the parent of the child we are currently on.
 Parameters:
    NodeT *pParent
    NodeT *p
    NodeT *pkid
 Returns:
    Returns that specified child's parent node.
 **************************************************************************/
NodeT *findParent(NodeT *pParent, NodeT *p, NodeT *pkid)
{
    NodeT *pFound = NULL;
    if (p == NULL)
        return NULL;
    if (strcmp(p->element.szId,pkid->element.szId)==0)
        return pParent;
    if (p->pSibling !=NULL)
        pFound = findParent(pParent,p->pSibling,pkid);
    if (pFound != NULL)
        return pFound;
    if (p->pChild != NULL)
        pFound = findParent(p,p->pChild,pkid);
    return pFound;
}

/********************************* allocateNodeT *******************************
 NodeT *allocateNodeT(Element value)
 
 Purpose:
 
 Parameters:
 
 Returns:
 
 **************************************************************************/

NodeT *allocateNodeT(Element value)
{
    NodeT *pNew = (NodeT *) malloc(sizeof(NodeT));
    pNew->element = value;
    pNew->pChild = NULL;
    pNew->pSibling = NULL;
    return pNew;
}

/********************************* insertT *******************************
 NodeT *insertT(NodeT *pRoot,Element value,char szSubId[])
 
 Purpose:
 
 Parameters:
 
 Returns:
 
 **************************************************************************/

NodeT *insertT(NodeT *pRoot,Element value,char szSubId[])
{
    NodeT *p = findId(pRoot,szSubId);

    if (p == NULL)
        return NULL;
    //if child is not null, traverses sibling chain until null is found
    if (p->pChild != NULL)
    {
        p = p->pChild;
        while (p->pSibling != NULL)
            p = p->pSibling;
        p->pSibling = allocateNodeT(value);
        return p->pSibling;
    }
    //parent node is found and child is empty
    else
    {
        p->pChild = allocateNodeT(value);
        return p->pChild;
    }
    return NULL;

}

/********************************* processCommand *******************************
 void processCommand(Tree tree, QuoteSelection quoteSelection, char *pszInput)
 
 Purpose:
 
 Parameters:
 
 Returns:
 
 ********************************************************************************/
void processCommand(Tree tree, QuoteSelection quoteSelection, char *pszInput)
{
    char szToken[MAX_TOKEN_SIZE+1];
    char szSubordinateToId[MAX_ID_SIZE];
    char szOptionId[MAX_ID_SIZE];
    NodeT *p;
    Element element;
    
    
    //Gets first word in input
    pszInput = getToken(pszInput,szToken,MAX_TOKEN_SIZE);
    
    //Set of if statmenets to check the command
    if (strcmp(szToken,"DEFINE")==0)
    {
        //checks the next word after the command
        pszInput = getToken(pszInput,szToken,MAX_TOKEN_SIZE);
        
        //check to see if it is OPTION or VALUE
        
        if (strcmp(szToken,"OPTION")==0)
        {
            sscanf(pszInput, "%s %s %[^\t\n]"
                   ,element.szId
                   ,szSubordinateToId
                   ,element.szTitle);
           printf("TITLE: %s\n",element.szTitle); 
            //check to see if it is root node
            if (strcmp(szSubordinateToId,"ROOT")==0)
            {
                if (tree->pRoot == NULL)
                {
                    tree->pRoot = allocateNodeT(element);
                }
                else
                { 
                    tree->pRoot->pSibling = allocateNodeT(element);
                }
            }
            else
            {
                p = insertT(tree->pRoot,element,szSubordinateToId);
                
                //(error handling) if the parent node was not found
                if (p == NULL)
                    printf("Error, parent %s not found\n", szSubordinateToId);
            }
        }
        else if (strcmp(szToken,"VALUE")==0)
        {
            sscanf(pszInput, "%s %s %s %lf %[^\t\n]"
                   ,element.szId
                   ,szOptionId
                   ,&element.cCostInd
                   ,&element.dCost
                   ,element.szTitle);
            printf("VALUE TITLE: %s\n",element.szTitle);
            p = insertT(tree->pRoot,element,szOptionId);
            
            //(error handling)if the parent node was not found
            if (p == NULL)
                printf("DEFINE ERROR: parent %s not found\n", szSubordinateToId);
        }
    }
    else if (strcmp(szToken,"PRINT")==0)
    {
        pszInput = getToken(pszInput,szToken,MAX_TOKEN_SIZE);
        
        //if the command is to print all
        if (strcmp(szToken,"ALL")==0)
        {
            //Pretty print
            prettyPrintT(tree->pRoot,0);
        }
        //if the command is print one
        else
        {
            pszInput = getToken(pszInput,szToken,MAX_TOKEN_SIZE);
            printOne(tree, szToken);
        }
    }
    else if (strcmp(szToken,"QUOTE")==0)
    {
        //3 cases, BEGIN, OPTION,END
        pszInput = getToken(pszInput,szToken,MAX_TOKEN_SIZE);
        if (strcmp(szToken,"BEGIN")==0)
        {
            //idk
        }
        if (strcmp(szToken,"OPTION")==0)
        {
            sscanf(pszInput," %d %s %d"
                   ,&quoteSelection->quoteItemM[quoteSelection->iQuoteItemCnt].iLevel
                   ,quoteSelection->quoteItemM[quoteSelection->iQuoteItemCnt].szOptionId
                   ,&quoteSelection->quoteItemM[quoteSelection->iQuoteItemCnt].iSelection);
            quoteSelection->iQuoteItemCnt++;
        }
    }
    else if (strcmp(szToken,"DELETE")==0)
    {
        pszInput = getToken(pszInput,szToken,MAX_TOKEN_SIZE);
        p = findId(tree->pRoot,szToken);
        if (p == NULL)
            printf("DELETE ERROR: Id %s not found\n",szToken);
        else
        {
            deleteItem(tree,szToken);
        }
    }
    
}