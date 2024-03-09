#include <stdio.h>
#include "User/User.h"
#include "tools/color.h"

void Buyer_Menu()
{
    printf("+===================================================================================================+\n");
    printf("| 1.查看商品列表 | 2.搜索商品 | 3.购买商品 | 4.查看历史订单 | 5.查看商品详细信息 | 6.返回用户主界面 |\n");
    printf("+===============================================================================================\n");

    int op;

    printf("请输入您的操作：");
    scanf("%d",&op);

    while(op < 1 || op > 6)
    {
        printf("%s%s无效的操作符,请重新再试!%s\n", BOLD, FRONT_RED, RESET);
        printf("请输入您的操作：");
        scanf("%d",&op);
    } 

    switch (op)
    {
    case 1:
        //
        break;    
    case 2:
        //
        break;
    case 3:
        //
        break;
    case 4:
        //
        break;
    case 5:
        // 
        break;
    case 6:
        User_Menu();
        break;
    }


}

