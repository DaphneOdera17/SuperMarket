#include <stdio.h>
#include "tools/color.h"
#include "User/User.h"
#include "tools/hint.h"

void Seller_Menu()
{
    seller_menuMessage();

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
