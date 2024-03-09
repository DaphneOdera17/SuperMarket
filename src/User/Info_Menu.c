#include <stdio.h>
#include "tools/color.h"
#include "User/User.h"

void Info_Menu()
{
    printf("+============+============+========+==================+\n");
    printf("| 1.查看信息 | 2.修改信息 | 3.充值 | 4.返回用户主界面 |\n");
    printf("+============+============+========+==================+\n");

    int op;

    while( op < 1 || op > 4)
    {
        printf("%s%s无效的操作符,请重新再试!%s\n", BOLD, FRONT_RED, RESET);
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
