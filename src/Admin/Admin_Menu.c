#include <stdio.h>
#include "Admin/Admin.h"
#include "Menu/Main_Menu.h"
#include "tools/color.h"
#include "tools/hint.h"
#include "Product/Product.h"
#include "User/User.h"

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
    case 1:
        Print_Products();
        break;    
    case 2:
        //
        break;
    case 3:
        //
        break;
    case 4:
        Print_UserInfo();
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
    

        
    
    
