# include<stdio.h>
#include "Admin/Admin.h"
#include "Menu/Main_Menu.h"
#include "tools/color.h"


void Admin_Menu()
{
    printf("====================================================\n");
    printf("| 1.查看所有商品 | 2.搜索商品 | 3.查看所有订单| 4.查看所有用户 | 5.删除用户 | 6.下架商品 | 7.注销|");
    printf("======================================================\n");

    int op;
    
    printf("请输入您的操作：");
    scanf("%d", &op);
    
    while(op < 1 || op > 7)
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
        //
        break;
    case 7:
        printf("%sLogout Successfully!%s",FRONT_RED,RESET);
        Main_Menu();
        break;
    }
}
    

        
    
    