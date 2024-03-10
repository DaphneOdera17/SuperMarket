#include <stdio.h>
#include "Admin/Admin.h"
#include "Menu/Main_Menu.h"
#include "tools/color.h"
#include "tools/hint.h"
#include "User/User.h"

void Admin_Menu()
{
    admin_menuMessage();

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
    

        
    
    
