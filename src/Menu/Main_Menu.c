#include <stdio.h>
#include "tools/color.h"
#include <stdlib.h>
#include "Admin/Admin_Login.h"
#include "User/User_Login.h"

void Main_Menu()
{
    printf("                %s%sMain Menu%s                   \n",BOLD,REVERSE,RESET);
    printf("=============+============+==============+========+\n");
    printf("| 1.用户登录 | 2.用户注册 | 3.管理员登录 | 4.退出 |\n");
    printf("=============+============+==============+========+\n");

    int num;
    
    printf("请输入您的操作：");
    scanf("%d", &num);
    
    while(num < 1 || num > 4)
    {
        printf("%s%s无效的操作符，请重新再试！%s\n", BOLD, FRONT_RED, RESET);
        printf("请输入您的操作：");
        scanf("%d",&num);
    } 

    if (num == 1)
    {
        User_Login();
    }
    else if (num == 2)
    {
        // User_sign();
    }
    else if (num == 3)
    {
        Admin_Login();
    }
    else if (num == 4)
    {
        printf("%sExit Successful!%s",FRONT_RED,RESET);
        exit(0);
    }    
    
    
    
}  
