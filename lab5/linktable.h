#ifndef _LINK_TABLE_H_
#define _LINK_TABLE_H_

#define SUCCESS 0
#define FAILURE (-1)

//信息隐藏
//LinkTable类型没有放在头文件
typedef struct LinkTableNode
{
    struct LinkTableNode* pNext;
}tLinkTableNode;

tLinkTableNode* CreateLinkTable();

int DeleteLinkTable(tLinkTableNode* pLinkTable);

int AddLinkTableNode(tLinkTableNode* pLinkTable, tLinkTableNode* pNode);

int DelLinkTableNode(tLinkTableNode* pLinkTable, tLinkTableNode* pNode);


tLinkTableNode * SearchLinkTableNode(tLinkTableNode *pLinkTable, int Conditon(tLinkTableNode * pNode,void* args), void* args);

tLinkTableNode* GetLinkTableHead(tLinkTableNode* pLinkTable);

tLinkTableNode * GetNextLinkTableNode(tLinkTableNode *pLinkTable,tLinkTableNode * pNode);

#endif /* _LINK_TABLE_H_ */