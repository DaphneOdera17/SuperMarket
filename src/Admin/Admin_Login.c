#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Menu/Main_Menu.h"
#include "config.h"
#include "tools/hint.h"

void Admin_Login()
{
    char ch;
    char name[20];
    char password[20];

    printf("请输入管理员姓名:  ");
    scanf("%s", name);
    getchar();

    int i = 0;
    printf("请输入密码:  ");
    while(1)
    {
        system("stty -icanon"); //设置一次性读完操作，即不用回车也能获取字符
        system("stty -echo");
        ch = getchar();
        system("stty -echo");
        putchar('*');
        
        if(ch == '\n')
        {
            password[i] = '\0';
            break;
        }
        else
        {
            password[i++] = ch;
        }
    }

    if(strcmp(name, ADMIN_NAME) == 0 && strcmp(password, ADMIN_PASSWORD) == 0)
    {
        ADMIN
    }


    
    
    
    
    

}