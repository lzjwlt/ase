#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "linktable.h"
#include "menu.h"

#define CMD_MAX_LEN 128
#define DESC_LEN    1024
#define CMD_MAX_ARGV_LEN    16

typedef struct DataNode
{
    tLinkTableNode* pNext;
    char* cmd;
    char* desc;
    int (*handler)(int argc, char* argv[]);
}tDataNode;

tLinkTable* head = NULL;

int SearchCondition(tLinkTableNode * pLinkTableNode, void* args)
{
    char* cmd = (char*)args;
    tDataNode * pNode = (tDataNode *)pLinkTableNode;
    if(strcmp(pNode->cmd, cmd) == 0)
    {
        return  SUCCESS;  
    }
    return FAILURE;	       
}

tDataNode* FindCmd(tLinkTable* head, char* cmd)
{
    return  (tDataNode*)SearchLinkTableNode(head,SearchCondition,cmd);
}

int ShowAllCmd(tLinkTable* head)
{
    tDataNode* pNode = (tDataNode*) GetLinkTableHead(head);
    while(pNode != NULL)
    {
        printf("%10s   -----   %s\n", pNode->cmd, pNode->desc);
        pNode = (tDataNode*)GetNextLinkTableNode(head, (tLinkTableNode*)pNode);
    }
    return 0;
}

int Help(int argc, char* argv[])
{
    int ch;
    char* ch_prom;
	printf("*************************************************************\n");
	printf("This is help command.\n\n");
	printf("commands:\n");
    if(argc ==1)
    {
        ShowAllCmd(head);
        return 0;
    }
    while((ch = getopt(argc, argv, "shl:")) != -1)
    {
        switch(ch)
        {
            case 's':
                printf("This is \"-s\" mode help\n");
                break;
            case 'h':
                printf("This is \"-h\" mode help\n");
                break;
            case 'l':
                ch_prom = optarg;
                printf("This is \"-l\" mode help with %s\n", ch_prom);
                break;
            case '?':
                printf("Wrong argument!\n");
        }
    }
    optind = 1;
	printf("*************************************************************\n");
    return 0;
}

int MenuConfig(char* cmd, char* desc, int(*handler)(int argc, char* argv[]))
{
    tDataNode* pNode = NULL;
    if(head == NULL)
    {
        head = CreateLinkTable();
        pNode = (tDataNode*)malloc(sizeof(tDataNode));
        pNode->cmd = "help";
        pNode->desc = "This is help command.";
        pNode->handler = Help;
        AddLinkTableNode(head,(tLinkTableNode*)pNode);
    }
    pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = cmd;
    pNode->desc = desc;
    pNode->handler = handler;
    AddLinkTableNode(head,(tLinkTableNode*)pNode);
    return 0; 
}

int ExecuteMenu()
{
    while(1)
    {
        int argc = 0;
        char *argv[CMD_MAX_ARGV_LEN];
        char cmd[CMD_MAX_LEN];
        char *pcmd = NULL;
        printf("menu cmd-> ");
        //scanf("%s", cmd);
        pcmd = fgets(cmd, CMD_MAX_LEN, stdin);
        if(pcmd == NULL)
        {
            continue;
        }
        pcmd = strtok(pcmd, " ");
        while(pcmd != NULL && argc < CMD_MAX_ARGV_LEN)
        {
            argv[argc] = pcmd;
            argc++;
            pcmd = strtok(NULL, " ");
        }
        if(argc == 1)
        {
            int len = strlen(argv[0]);
            *(argv[0] + len - 1) = '\0';
        }          
        tDataNode* p = FindCmd(head, cmd);      
        if(p == NULL)
        {
            printf("error: Wrong command!\n");
        }
        else
        {
            p->handler(argc, argv);
        }
    }
    return 0;
}