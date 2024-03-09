#include <stdio.h>
#include "tools/color.h"
#include "User/User.h"

void Seller_Menu()
{
    printf("+================================================\n");
    printf("| 1.发布商品 | 2.查看发布商品 | 3.修改商品信息 | 4.下架商品 | 5.查看历史订单 | 6.返回用户主界面\n");
    printf("+=======================================================\n");

    int op;

    printf("请输入您的操作：");
    scanf("%d", &op);

    while( op < 1 || op >6)
    {
        printf("%s%s无效的操作符,请重新再试!%s\n", BOLD, FRONT_RED, RESET);
        printf("请输入您的操作：");
        scanf("%d", &op);
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