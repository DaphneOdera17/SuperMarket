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
    int idx = SearchGood(tmp->name);
    if(idx != -1) // 名字已经存在的商品无法添加
        FailToAddGood(), failureMessage();
    else
    {
        Add_Product(tmp);
        successMessage();
    }
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
    int k = Delete_Product(good, 2);
    if(k == -1)
        error_finding_good(), failureMessage();
    else if(k == 2)
        printf("%s%s商品已经下架，请勿重复操作！%s", BOLD, FRONT_RED, RESET), failureMessage();
    else if(k == 3)
        printf("%s%s您不是该商品的发布者！无操作权限！%s", BOLD, FRONT_RED, RESET), failureMessage();
    else
        successMessage();
}

void MODIFY_Good()
{
    printf("请输入您要修改的商品名称或ID: ");
    Now_Good = Search_Good_Idx();
    if(Now_Good != -1){
        printf("请输入您要修改的选项\n");
        PRODUCT_Interface();
    }
}