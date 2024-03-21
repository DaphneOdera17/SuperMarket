#include "interface/interface.h"
#include <stdio.h>
#include <string.h>

static HANDLE handler[] = {ADD_Good , PRINT_OwnGoods, DELETE_Good ,PRINT_OwnOrder };

void ADD_Good()
{
    Product *tmp = (Product *)malloc(sizeof(Product));
    printf("请输入商品名称： ");
    scanf("%s", tmp->name);
    printf("请输入商品价格： ");
    scanf("%s", tmp->price);
    printf("请输入商品描述： ");
    scanf("%s", tmp->discribe);
    printf("请输入商品上架数量： ");
    scanf("%s", tmp->cnt);
    Add_Product(tmp);
    if(Add_Product(tmp) == -1)
        failureMessage();
    else
        successful();

    free(tmp);
}

void PRINT_OwnGoods()
{
    User *tmp = Get_User(Now_User);
    Print_OwnProduct(tmp->id);
}

void PRINT_OwnOrder()
{
    User *tmp = Get_User(Now_User);
    Print_SellerOwnOrder(tmp->id);
}

void DELETE_Good()
{
    char good[MAX_NAME_LENGTH];
    printf("请输入您要查找的商品名称或ID: ");
    scanf("%s",good);
    // Delete_Product(good, );
}



