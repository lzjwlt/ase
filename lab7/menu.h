#ifndef _MENU_H
#define _MENU_H
/*add cmd to menu*/
int MenuConfig(char *cmd, char *desc, int(*handler)());

/* menu engine execute*/
int ExecuteMenu();
#endif