#include "interface/interface.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Admin_Login()
{
    char ch, name[20], password[20];

    printf("请输入管理员姓名: ");
    scanf("%s", name);
    getchar();

    int i = 0;
    printf("请输入密码: ");
    while(1)
    {
        system("stty -icanon"); // 设置一次性读完操作，即不用回车也能获取字符
        system("stty -echo");
        ch = getchar();
        system("stty -echo");
        putchar('*');
        
        if(ch == '\n')
        {
            password[i] = '\0';
            system("stty icanon echo"); // 恢复终端设置
            break;
        }
        else
            password[i++] = ch;
    }
    printf("\n");

    if(!(strcmp(name, ADMIN_NAME) == 0 && strcmp(password, ADMIN_PASSWORD) == 0))
    {
        loginfailureMessage();
        Main_Menu();
    }
    else
    {
        loginsuccessMessage();
        Admin_Menu();
    }
}

/*
void Admin_Menu()
{
    admin_menuMessage();

    int op;
    
    printf("请输入您的操作：");
    scanf("%d", &op);
    
    while(op < 1 || op > 7)
    {
        failureMessage();
        printf("请输入您的操作：");
        scanf("%d",&op);
    } 

    switch (op)
    {
    case 1:Print_Products('A');break;    
    case 2:Search_Product('A');break;
    case 3:Print_Orders('A');break;
    case 4:Print_UserInfo();break;
    case 5:Delete_User();break;
    case 6:Delete_Product("A");break;
    case 7:printf("%sLogout Successfully!%s",FRONT_RED,RESET);Main_Menu();break;
    }
}
*/
