#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linktable.h"
#include "menu.h"

typedef struct CMDNode
{
	char* cmd;
	char* desc;
	int(*handler)(int argc, char* argv[]);
}tCMDNode;

int Help(int argc, char* argv[]);
int Version(int argc, char* argv[]);
int Quit(int argc, char* argv[]);
int Hello(int argc, char* argv[]);
int Time(int argc, char* argv[]);
int Author(int argc, char* argv[]);
int Triangle(int argc, char* argv[]);
int Heart(int argc, char* argv[]);

tCMDNode dHead[] =
{
	{ "version","Show version of this menu program.", Version },
	{ "quit", "Quit and back to OS.", Quit },
	{ "hello", "Say hello to users.", Hello },
	{ "time", "Show system date and time.", Time },
	{ "author", "Show author information.", Author },
	{ "triangle", "Show a big triangle on screen.", Triangle },
	{ "heart", "Show a big heart on screen.", Heart },
};

int numOfCmdExHelp = sizeof(dHead) / sizeof(dHead[0]);

int InitMenuData(tCMDNode* dHead, int length)
{
	int i;
	for (i = 0; i < length; i++)
	{
		tCMDNode* pCMDNode = &dHead[i];
		MenuConfig(pCMDNode->cmd, pCMDNode->desc, pCMDNode->handler);
	}
	return 0;
}

int main(int argc, char* argv[])
{
	InitMenuData(dHead, numOfCmdExHelp);
	ExecuteMenu();
	return 0;
}

int Version(int argc, char* argv[])
{
	printf("menu version v3.0\n");
	return 0;
}

int Quit(int argc, char* argv[])
{
	printf("Goodbye\n");
	exit(0);
}

int Hello(int argc, char* argv[])
{
	printf("Hi, How are you?\n");
	char answer;
	printf("Input (Y/N), Y:I'm fine, thank you!  N:I'm feeling terrible\n");
	getchar();
	answer = getchar();
	if (answer == 'Y' || answer == 'y')
	{
		printf("Wish you happy everyday!\n");
	}
	else if (answer == 'N' || answer == 'n')
	{
		printf("Cheer up, things will work out for the best!\n");
	}
	else
	{
		printf("Sorry, I can't understand it!\n");
	}
	return 0;
}

int Time(int argc, char* argv[])
{
	system("date");
	return 0;
}

int Author(int argc, char* argv[])
{
	printf("*************************************************************\n");
	printf("Author infomation\n\n");
	printf("%12s :  Li Zhijun (À÷ÖÎ¾ü)\n", "name");
	printf("%12s :  SA17225184\n", "Student ID");
	printf("%12s :  ÈíÉè2°à\n", "Class");
	printf("School of software engineering, USTC\n");
	printf("*************************************************************\n");
	return 0;
}

int Triangle(int argc, char* argv[])
{
	int i, j;
	int n = 20;
	for (i = 0; i < n; i++)
	{
		for (j = n - i + 10; j > 0; j--)
		{
			putchar(' ');
		}
		for (j = 0; j < i * 2 - 1; j++)
		{
			putchar('*');
		}
		putchar('\n');
	}
	return 0;
}

int Heart(int argc, char* argv[])
{
	float x, y;
	for (y = 1.5f; y > -1.5f; y -= 0.1f)
	{
		for (x = -1.5f; x < 1.5f; x += 0.05f)
		{
			float a = x * x + y * y - 1;
			putchar(a * a * a - x * x * y * y * y <= 0.0f ? '*' : ' ');
		}
		putchar('\n');
	}
	return 0;
}

