#include "interface/interface.h"
#include <stdio.h>
#include <string.h>

static HANDLE handler[] = {ADD_Good, SELLER_OwnGoods, PRODUCT_Interface, DELETE_Good , SELLER_OwnOrder};

void SELLER_Interface() {
    successMessage();
    int op = menu(SELLER);
    while (op != optionNumber[SELLER]) {
        loadingMessage();
        handler[op - 1]();
        op = menu(SELLER);
    }
    loadingMessage();
    successMessage();
}

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
    if(SearchGood(tmp->name) == -1)
        failureMessage();
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
    Print_SellerOwnOrder(tmp->id);
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
    
}

