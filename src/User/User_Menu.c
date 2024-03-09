#include <stdio.h>
#include "Menu/Main_Menu.h"
#include "User/User.h"

void choose(int op)
{
    switch (op)
    {
    case 1:
        Main_Menu();
        break;
    case 2:
        Buyer_Menu();
        break;
    case 3:
        Seller_Menu();
        break;
    case 4:
        Info_Menu();
        break;
    }
}

void User_Menu()
{
    printf("+===========+===========+===========+===============+\n");
    printf("| 1.注销登陆 | 2.我是买家 | 3.我是卖家 | 4.个人信息管理 |\n");
    printf("+===========+===========+===========+===============+\n");
    int op;

    printf("请输入您的操作：");
    scanf("%d", &op);

    while(op < 1 || op > 4)
    {
        printf("操作符无效，请重新输入！\n");
        printf("请输入您的操作：");
        scanf("%d", &op);
    }

    choose(op);
}
