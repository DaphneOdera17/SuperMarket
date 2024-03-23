#include "interface/interface.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//1 2 4 5
static HANDLE handler[] = {PRINT_Goods , Search_good , Buy_Good , PRINT_OwnOrder};

void BUYER_Interface() {
    successMessage();
    int op = menu(USER);
    while (op != optionNumber[USER]) {
        loadingMessage();
        handler[op - 1]();
        op = menu(USER);
    }
    loadingMessage();
    successMessage();
}

void PRINT_Goods()
{
    Print_Products();
}

int SEARCH_Good()
{
    char good[MAX_NAME_LENGTH];
    scanf("%s",good);
    int idx = SearchGood(good);
    if(idx == -1)
    {
        error_finging_good();
        failureMessage();
    }
    else
    {
        Product *Good = Get_Good(idx);
        Info_Produt(Good);
        return idx;
    }
}

void Search_good()
{
    printf("请输入您要查找的商品名称或ID: ");
    SEARCH_Good();
}

void Buy_Good()
{
    
    printf("请输入您要购买的商品名称或ID: ");
    int idx = SEARCH_Good();
    printf("您确定购买此商品吗?请输入Yes/No\n");//Y表示确定购买 N表示取消购买
    Buy_Good_Confirm(idx);
}

void PRINT_OwnOrder()
{
    User *tmp = Get_User(Now_User);
    Print_BuyerOwnOrder(tmp->id);
}

/*
void Buy()
{
    char ch;
    char s[MAX_NAME_LENGTH];

    printf("请输入您要查找的商品名称或商品id: ");
    scanf("%s", s);
    extern int Now_User;

    int idx = SearchGood(s);
    Product *tmp = Get_Good(idx);

    int flag = search(idx);
    if(flag == -1)
    {
        printf("未查找到商品！");
        Buyer_Menu();
    }
    else
    {
        printf("商品id:%s \n", tmp->id );
        printf("商品名称：%s \n",tmp->name);
        printf("商品价格：%.1f\n", tmp->price);
        printf("商品描述：%s\n",tmp->discribe);
        printf("上架时间：%s\n",tmp->SellTime);
        printf("剩余数量：%d\n",tmp->cnt);
        switch(tmp->state)
        {
            case 0: printf("商品状态： 已下架 \n"); break;
            case 1: printf("商品状态： 在售中 \n"); break;
            case 2: printf("商品状态： 已售空 \n"); break;
        }

        printf("您确定购买此商品吗?请输入Yes/No\n");//Y表示确定购买 N表示取消购买
        char ch[5];
        scanf("%s",ch);
    
        if(strcmp(ch , "Yes") == 0)
        {
            if(users[Now_User].res < goods[flag].price)
            {
                printf("余额不足，请前往个人信息管理充值后购买！");
                User_Menu();
            }
            else if(goods[flag].state == 0 || goods[flag].state == 2)
            {
                printf("该商品已下架或已售空，请选择其他商品购买！");
                Buyer_Menu();
            }
            else
            {
                users[Now_User].res -= goods[flag].price; 
                Out_User();
                printf("购买成功！\n");
                Add_Order(flag, users[Now_User].id);
                printf("当前账户余额为： %.1f",users[Now_User].res);
                Buyer_Menu();
            }
        }
        else
        {
            printf("已取消购买！");Buyer_Menu();
        }
           
    }
}
*/