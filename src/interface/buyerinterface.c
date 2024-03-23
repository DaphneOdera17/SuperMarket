#include "interface/interface.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static HANDLE handler[] = {Print_Products, Search_Good , Buy_Good , BUYER_OwnOrder, GOOD_Detail};

void BUYER_Interface() {
    int op = menu(BUYER);
    while (op != optionNumber[BUYER]) {
        loadingMessage();
        handler[op - 1]();
        op = menu(BUYER);
    }
}

int SEARCH_Good()
{
    char good[MAX_NAME_LENGTH];
    scanf("%s",good);
    int idx = SearchGood(good);
    if(idx == -1)
    {
        error_finding_good();
        failureMessage();
        return -1;
    }
    else
        return idx;
}

void Search_Good()
{
    printf("请输入您要查找的商品名称或ID: ");
    int idx = SEARCH_Good();
    puts("");
    if(idx != -1)
        Print_Product(idx);
}

void Buy_Good()
{
    printf("请输入您要购买的商品名称或ID: ");
    int idx = SEARCH_Good();
    printf("您确定购买此商品吗?请输入Yes/No\n");//Y表示确定购买 N表示取消购买
    Buy_Good_Confirm(idx);
}

void BUYER_OwnOrder()
{
    User *tmp = Get_User(Now_User);
    Print_BuyerOwnOrder(tmp->id);
}

void GOOD_Detail()
{
    printf("请输入您要查找的商品名称或ID: ");
    int idx = SEARCH_Good();
    if(idx != -1)
        Product_Info(idx);
}