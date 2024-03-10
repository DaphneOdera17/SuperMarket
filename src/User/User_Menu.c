#include <stdio.h>
#include "Menu/Main_Menu.h"
#include "User/User.h"
#include "tools/hint.h"

void choose(int op)
{
    switch (op)
    {
    case 1:
        Main_Menu();
        break;
    case 2:
        Buyer_Menu();
        break;
    case 3:
        Seller_Menu();
        break;
    case 4:
        Info_Menu();
        break;
    }
}

void User_Menu()
{
    user_menuMessage();

    int op;

    printf("请输入您的操作：");
    scanf("%d", &op);

    while(op < 1 || op > 4)
    {
        failureMessage();
        printf("请输入您的操作：");
        scanf("%d", &op);
    }

    choose(op);
}
