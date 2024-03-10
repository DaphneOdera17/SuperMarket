#include <stdio.h>
#include "tools/color.h"
#include <stdlib.h>
#include "Admin/Admin.h"
#include "User/User.h"
#include "tools/hint.h"

void Main_Menu()
{
    printf("                %s%sMain Menu%s                   \n",BOLD,REVERSE,RESET);
    printf("=============+============+==============+========+\n");
    printf("| 1.用户登录 | 2.用户注册 | 3.管理员登录 | 4.退出 |\n");
    printf("=============+============+==============+========+\n");

    int op;
    
    printf("请输入您的操作：");
    scanf("%d", &op);
    
    while(op < 1 || op > 4)
    {
        printf("%s%s无效的操作符，请重新再试！%s\n", BOLD, FRONT_RED, RESET);
        printf("请输入您的操作：");
        scanf("%d",&op);
    } 

    if (op == 1)
    {
        User_Login();
    }
    else if (op == 2)
    {
        //User_Sign();
    }
    else if (op == 3)
    {
        Admin_Login();
    }
    else if (op == 4)
    {
        exitMessage();
        exit(0);
    }    
}  
