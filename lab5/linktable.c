#include <stdio.h>
#include <stdlib.h>
#include "linktable.h"

tLinkTable* CreateLinkTable()
{
    tLinkTable* pLinkTable = (tLinkTable*)malloc(sizeof(tLinkTable));
    if(pLinkTable == NULL)
    {
        return NULL;
    }
    pLinkTable->pHead = NULL;
    pLinkTable->pTail = NULL;
    pLinkTable->sumOfNode = 0;
    return pLinkTable;
}

int DeleteLinkTable(tLinkTable* pLinkTable)
{
    if(pLinkTable == NULL)
    {
        return FAILURE;
    }
    while(pLinkTable->pHead != NULL)
    {
        tLinkTableNode* pNode = pLinkTable->pHead;
        pLinkTable->pHead = pLinkTable->pHead->pNext;
        free(pNode);  
    } 
    pLinkTable->pHead = NULL;
    pLinkTable->pTail = NULL;
    pLinkTable->sumOfNode = -1;
    free(pLinkTable);
    return SUCCESS;
}

int AddLinkTableNode(tLinkTable* pLinkTable, tLinkTableNode* pNode)
{
    if (pLinkTable == NULL || pNode == NULL)
    {
        return FAILURE;
    }
    pNode->pNext = NULL;
    if (pLinkTable->pHead == NULL)
    {
        pLinkTable->pHead = pNode;
    }
    if (pLinkTable->pTail == NULL)
    {
        pLinkTable->pTail = pNode;
    }
    else
    {
        pLinkTable->pTail->pNext = pNode;
        pLinkTable->pTail = pNode;
    }
    pLinkTable->sumOfNode = pLinkTable->sumOfNode + 1;
    return SUCCESS;
}

int DelLinkTableNode(tLinkTable* pLinkTable, tLinkTableNode* pNode)
{
    if (pLinkTable == NULL || pNode == NULL)
    {
        return FAILURE;
    }
    if (pLinkTable->pHead == pNode)
    {
        pLinkTable->pHead = pLinkTable->pHead->pNext;
        pLinkTable->sumOfNode = pLinkTable->sumOfNode - 1;
        if (pLinkTable->sumOfNode == 0)
        {
            pLinkTable->pTail == NULL;
        }
        return SUCCESS;
    }
    tLinkTableNode* p = pLinkTable->pHead;
    while (p != NULL)
    {
        if (p->pNext == pNode)
        {
            p->pNext = p->pNext->pNext;
            pLinkTable->sumOfNode = pLinkTable->sumOfNode - 1;
            if (pLinkTable->sumOfNode == 0)
            {
                pLinkTable->pTail = NULL;
            }
            return SUCCESS;
        }
        p = p->pNext;
    }
    return FAILURE;
}

tLinkTableNode * SearchLinkTableNode(tLinkTable *pLinkTable, int Conditon(tLinkTableNode * pNode))
{
    if(pLinkTable == NULL || Conditon == NULL)
    {
        return NULL;
    }
    tLinkTableNode * pNode = pLinkTable->pHead;
    while(pNode != NULL)
    {    
        if(Conditon(pNode) == SUCCESS)
        {
            return pNode;				    
        }
        pNode = pNode->pNext;
    }
    return NULL;
}

tLinkTableNode* GetLinkTableHead(tLinkTable* pLinkTable)
{
    if (pLinkTable == NULL || pLinkTable->pHead == NULL)
    {
        return NULL;
    }
    return pLinkTable->pHead;
}

tLinkTableNode * GetNextLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode * pNode)
{
    if (pLinkTable == NULL || pNode == NULL)
    {
        return NULL;
    }
    tLinkTableNode* pTempNode = pLinkTable->pHead;
    while (pTempNode != NULL)
    {
        if (pTempNode == pNode)
        {
            return pTempNode->pNext;
        }
        pTempNode = pTempNode->pNext;
    }
    return NULL;
}