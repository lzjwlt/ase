#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Help();
void Version();
void Quit();
void Hello();
void Time();
void Author();
void Triangle();
void Heart();

#define CMD_MAX_LENGTH 128

typedef struct CMDNode
{
    char* cmd;
    void (*handler)();
    struct CMDNode *next;    
}tCMDNode;

static tCMDNode head[] = 
{
    {"help", Help, &head[1]},
    {"version", Version, &head[2]},
    {"quit", Quit, &head[3]},
    {"hello", Hello, &head[4]},
    {"time", Time, &head[5]},
    {"author", Author, &head[6]},
    {"triangle", Triangle, &head[7]},
    {"heart", Heart, NULL}
};

int main()
{
    char cmd[CMD_MAX_LENGTH];
    while(1)
    {
        tCMDNode *p = head;
        printf("menu cmd-> ");
        scanf("%s", cmd);
        while(p != NULL)
        {
            if(strcmp(p->cmd, cmd) == 0)
            {
                if(p->handler != NULL)
                {
                    p->handler();
                }
                break;
            }
            p = p->next;
        }
        if(p == NULL)
        {
            printf("error: Wrong command!\n");
        }
    }
    return 0;
}
void Help()
{
    printf("This is help command\n");
}
void Version()
{
    printf("menu version v1.0");
}
void Quit()
{
    printf("Goodbye\n");
    exit(0);
}
void Hello()
{
    printf("Hi, How are you?\n");
    char answer;
    printf("Input (Y/N), Y:I'm fine, thank you!  N:I'm feeling terrible\n");
    getchar();
    answer = getchar();
    if(answer == 'Y' || answer == 'y')
    {
        printf("Wish you happy everyday!\n");
    }
    else if(answer == 'N' || answer == 'n')
    {
        printf("Cheer up, things will work out for the best!\n");
    }
    else
    {
        printf("Sorry, I can't understand it!\n");
    }
}
void Time()
{
    system("date");
}
void Author()
{
}
void Triangle()
{
    int i,j;
    int n = 20;
    for(i = 0; i < n; i++)
    {
        for(j = n - i + 10; j > 0; j--)
        {
            putchar(' ');
        }
        for(j = 0; j < i * 2 - 1; j++)
        {
            putchar('*');
        }
        putchar('\n');
    }
}
void Heart()
{
    float x, y;
    for(y = 1.5f; y > -1.5f; y -= 0.1f)
    {
        for(x = -1.5f; x < 1.5f; x += 0.05f)
        {
            float a = x * x + y * y - 1;
            putchar(a * a * a - x * x * y * y * y <= 0.0f ? '*': ' ');
        }
        putchar('\n');
    }

}

