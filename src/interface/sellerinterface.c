#include "interface/interface.h"
#include <stdio.h>
#include <string.h>

static HANDLE handler[] = {ADD_Good, SELLER_OwnGoods, MODIFY_Good, DELETE_Good , SELLER_OwnOrder};

void SELLER_Interface() {MAKE_Interface(SELLER, handler);}

void ADD_Good()
{
    Product *tmp = (Product *)malloc(sizeof(Product));
    printf("请输入商品名称： ");
    scanf("%s", tmp->name);
    printf("请输入商品价格： ");
    scanf("%lf", &tmp->price);
    printf("请输入商品描述： ");
    scanf("%s", tmp->discribe);
    printf("请输入商品上架数量： ");
    scanf("%d", &tmp->cnt);
    strcpy(tmp->SellID, Get_User(Now_User)->id);
    Add_Product(tmp);
    int idx = SearchGood(tmp->name);
    if(idx != -1 && strcmp(Get_State(Get_Good(idx)->state), "在售中") == 0) // 名字已经存在并且还在出售的商品无法添加
    {
        failureMessage();
        FailToAddGood();
    }
    else
        successMessage();
    free(tmp);
}

void SELLER_OwnGoods()
{
    User *tmp = Get_User(Now_User);
    Print_OwnProduct(tmp->id);
}

void SELLER_OwnOrder()
{
    User *tmp = Get_User(Now_User);
    
    int k = Print_SellerOwnOrder(tmp->id);
    if (k == 0)
        printf("暂无订单\n");
}

void DELETE_Good()
{
    char good[MAX_NAME_LENGTH];
    printf("请输入您要查找的商品名称或ID: ");
    scanf("%s",good);

    if(Delete_Product(good) == -1)
        failureMessage();
    else
        successMessage();
}

void MODIFY_Good()
{
    printf("请输入您要修改的商品名称或ID: ");
    SEARCH_Good();
    PRODUCT_Interface();
}

