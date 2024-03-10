#include <stdio.h>
#include <stdlib.h>
#include "tools/color.h"
#include "Admin/Admin.h"
#include "User/User.h"
#include "tools/hint.h"

void Main_Menu()
{
    main_menuMessage();

    int op;
    
    printf("请输入您的操作：");
    scanf("%d", &op);
    
    while(op < 1 || op > 4)
    {
        failureMessage();
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
