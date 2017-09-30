#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "linklist.h"

tCMDNode* FindCmd(tCMDNode* head, char* cmd)
{
    if(head == NULL)
    {
        return NULL;
    }
    tCMDNode* p = head;
    while(p != NULL)
    {
        if(strcmp(p->cmd, cmd) == 0)
        {
            if(p->handler != NULL)
            {
                return p;
            }
        }
        p = p->next;
    }
    assert(p == NULL);
    return p;
}

void ShowAllCmd(tCMDNode* head)
{
    if(head == NULL)
    {
        return;
    }
    tCMDNode* p = head;
    while(p != NULL)
    {
        printf("%10s   -----   %s\n", p->cmd, p->disc);
        p = p->next;
    }
    return;
}
