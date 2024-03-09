#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Menu/Main_Menu.h"

void Admin_Login()
{
    char ch;
    char name[20];
    char password[20];
    char save_name[20];
    char save_password[20];

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

    FILE *ptr;
    ptr = fopen("Admin.txt", "r");
    if(ptr == NULL)
    {
        printf("error");
    }

    char line[256];
    int user_found = 0;
    while(fgets(line ,sizeof(line) , ptr) != NULL)
    {
        if(sscanf(line , "%s %s" , save_name , save_password) == 2)
        {
            if(strcmp(name, save_name) == 0)
            {
                user_found = 1;
                int k = strcmp(password, save_password);
                if(k = 0)
                {
                    printf("登陆成功!");
                    // Admin_Menu();
                    fclose(ptr);
                    
                }
                else
                {
                    printf("登陆失败，请重新再试！");
                    Main_Menu();
                    // 重新输入用户名功能？
                }
            }
        }

         
        
    }
    
    
    
    

}