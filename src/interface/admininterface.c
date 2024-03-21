#include "interface/interface.h"
#include <stdio.h>
#include <stdlib.h>

static HANDLE handler[] = {PRINT_Goods, Search_Good, PRINT_Orders , PRINT_users , DELETE_User , DELETE_Good};

void DELETE_User()
{
    char name[MAX_USERNAME_LENGTH];
    printf("请输入您要删除的用户名: ");
    scanf("%s", name);
    if(Delete_User(name) == -1)
    {
        error_finding_user();
        failureMessage();
    }
    else
        successful();
}

void PRINT_Goods()
{
    Print_Products();
}

void Search_Good()
{
    char good[MAX_NAME_LENGTH];
    printf("请输入您要查找的商品名称或ID: ");
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
        printf("商品id: %s\n", Good->id);
        printf("商品名称: %s\n", Good->name);
        printf("商品价格: %s\n", Good->price);
        printf("卖家id: %s\n", Good->SellID);
        printf("商品上架时间: %s\n", Good->SellTime);
        printf("商品数量: %s\n", Good->cnt);
        printf("商品状态: %s\n", Good->state);
    }
}

void PRINT_Orders()
{
    Print_Orders();
}

void PRINT_users()
{
    Print_UserInfo();
}

void DELETE_Good()
{
    char good[MAX_NAME_LENGTH];
    printf("请输入您要查找的商品名称或ID: ");
    scanf("%s",good);
    Delete_Product(good);
}
