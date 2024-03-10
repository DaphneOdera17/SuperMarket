#include <stdio.h>
#include "tools/color.h"
#include "User/User.h"
#include "tools/hint.h"

void Info_Menu()
{
    info_menuMessage();

    int op;

    while( op < 1 || op > 4)
    {
        failureMessage();
        printf("请输入您的操作：");
        scanf("%d", &op);
    }

    switch(op)
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
            User_Menu();
            break;
    }


}
