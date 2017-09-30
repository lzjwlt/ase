typedef struct CMDNode
{
    char* cmd;
    char* disc;
    void (*handler)();
    struct CMDNode *next;
}tCMDNode;

tCMDNode* FindCmd(tCMDNode* head, char* cmd);

void ShowAllCmd(tCMDNode* head);
