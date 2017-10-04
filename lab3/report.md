# 实验三：内部模块化命令菜单小程序V2.0
#### SA17225184 厉治军
## 目录
1. 实验要求
1. 实验过程
1. 实验结果
1. 实验心得  
## 1. 实验要求
注意代码的业务逻辑和数据存储之间的分离，即将系统抽象为两个层级：菜单业务逻辑和菜单数据存储  
要求：
1. 遵守代码风格规范，参考借鉴代码设计规范的一些方法；
2. 代码的业务逻辑和数据存储使用不同的源文件实现，即应该有2个.c和一个.h作为接口文件。
## 2. 实验过程
1. 进入实验文件夹，新建一个`linklist.h`并编辑它。
``` bash
cd /home/lzj/homework/asework/ase
mkdir lab3
cd lab3
vim linklist.h
```
`linklist.h`代码如下：
``` c++
typedef struct CMDNode
{
    char* cmd;
    char* disc;
    void (*handler)();
    struct CMDNode *next;
}tCMDNode;

tCMDNode* FindCmd(tCMDNode* head, char* cmd);

void ShowAllCmd(tCMDNode* head);
```
2. 新建一个`linklist.c`并编辑，代码如下：  

``` c++
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
```
3. 新建`menu.c`， 代码如下：

``` c++
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Help();
void Versi#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linklist.h"

void Help();
void Version();
void Quit();
void Hello();
void Time();
void Author();
void Triangle();
void Heart();

#define CMD_MAX_LENGTH 128

static tCMDNode head[] = 
{
    {"help", "This is help command.", Help, &head[1]},
    {"version","Show version of this menu program.", Version, &head[2]},
    {"quit", "Quit and back to OS.", Quit, &head[3]},
    {"hello", "Say hello to users.", Hello, &head[4]},
    {"time", "Show system date and time.", Time, &head[5]},
    {"author", "Show author information.", Author, &head[6]},
    {"triangle", "Show a big triangle on screen.", Triangle, &head[7]},
    {"heart", "Show a big heart on screen.", Heart, NULL}
};

int main()
{
    char cmd[CMD_MAX_LENGTH];
    while(1)
    {
        printf("menu cmd-> ");
        scanf("%s", cmd);
        tCMDNode* p = FindCmd(head, cmd);      
        if(p == NULL)
        {
            printf("error: Wrong command!\n");
        }
        else
        {
            p->handler();
        }
    }
    return 0;
}

void Help()
{
    printf("*************************************************************\n");
    printf("This is help command.\n\n");
    printf("commands:\n");
    ShowAllCmd(head);
    printf("*************************************************************\n");
}

void Version()
{
    printf("menu version v2.0\n");
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
    printf("*************************************************************\n");
    printf("\t\t\tAuthor infomation\n\n");
    printf("Name:\t\t Li Zhijun (厉治军)\n");
    printf("Student ID:\t SA17225184\n");
    printf("Class:\t\t 软设2班\n");
    printf("\t\t School of software engineering, USTC\n");
    printf("*************************************************************\n");
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
```
之后将文件编译运行，并将源代码传入代码库
``` bash
gcc menu.c linklist.c -o menu
./ menu
```
``` bash
git add lab3/menu.c lab3/linklist.c lab3/linklist.h
git commit -m "add lab3"
git push
```
[代码库地址](https://github.com/lzjustc/ase/edit/master/lab3/report.md)  
## 3. 实验结果
![image](/lab3/img/img1.png)  
![image](/lab3/img/img2.png)  
![image](/lab3/img/img3.png)  

## 4. 实验心得
- 学习并采用了通过以链表的方式遍历查找到函数指针来执行相应的函数，复习了C语言和数据结构方面的知识。
- 编写代码时应该做到业务逻辑层与数据层的分离，提高代码的可扩展性和可重用性。

