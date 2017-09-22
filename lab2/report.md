# 实验二：命令行菜单小程序V1.0
#### SA17225184 厉治军
## 目录
1. 实验要求
1. 实验过程
1. 实验心得
1. 实验总结
1. 附录：从非实验楼环境提交代码
## 1. 实验要求
### 代码风格规范
- 代码风格的原则：简明、易读、无二义性
- 缩进、命名、注释等代码编排的风格规范
### 本周实验要求
- 参考视频演示按自己的方式实现一个命令行的菜单小程序，执行某个命令时调用一个特定的函数作为执行动作，实现的命令个数不少于8个；
- 评分标准：主要以是否符合代码风格规范为准；
- 思考：如何将代码模块化以包容变化？
## 2. 实验过程
进入实验文件夹，新建一个menu.c并编辑它。
``` bash
cd /home/lzj/homework/asework/ase
mkdir lab2
cd lab2
vim menu.c
```
![image](/lab2/img/shell1.png)  
实验代码如下：
``` c
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
    printf("*************************************************************\n");
    printf("This is help command.\n\n");
    printf("commands:\n");
    printf("help:\t\t show this help command.\n");
    printf("version:\t show version of menu.\n");
    printf("author:\t\t show author infomation\n");
    printf("quit:\t\t quit this menu program and back to os.\n");
    printf("hello:\t\t say hello to users.\n");
    printf("time:\t\t show the system date and time.\n");
    printf("triangle:\t show a big triangle on screen.\n");
    printf("heart:\t\t show a big heart on screen.\n");
    printf("*************************************************************\n");
}

void Version()
{
    printf("menu version v1.0\n");
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
gcc menu.c -o menu
./ menu
```
```bash
git add lab2/menu.c
git commit -m "add menu.c"
git push
```
## 实验结果
![image](/lab2/img/helpVersionTime.png)  
![image](/lab2/img/authorHelloHeart.png)  
![image](/lab2/img/triangleQuit.png)  

## 实验心得
学习并采用了通过以链表的方式遍历查找到函数指针来执行相应的函数，复习了C语言和数据结构方面的知识。