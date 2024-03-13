#include <stdio.h>
#include "tools/color.h"
#include "User/User.h"
#include "tools/hint.h"
#include "Product/Product.h"

void Seller_Menu(int Now_User)
{
    seller_menuMessage();

    int op;

    printf("请输入您的操作：");
    scanf("%d", &op);

    while( op < 1 || op >6)
    {
        failureMessage();
        printf("请输入您的操作：");
        scanf("%d", &op);
    }
    switch (op)
    {
    case 1:
        Add_Product(Now_User);
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
