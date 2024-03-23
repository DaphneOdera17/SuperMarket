#include "interface/interface.h"
#include <stdio.h>
#include <stdlib.h>

static HANDLE handler[] = {Print_Products, Search_Good, Print_Orders , Print_UserInfo , DELETE_User , DELETE_Good};

void ADMIN_Interface() {
    successMessage();
    int op = menu(ADMIN);
    while (op != optionNumber[ADMIN]) {
        loadingMessage();
        handler[op - 1]();
        op = menu(ADMIN);
    }
    loadingMessage();
    successMessage();
}

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
        successMessage();
}

void Search_Good()
{
    char good[MAX_NAME_LENGTH];
    printf("请输入您要查找的商品名称或ID: ");
    scanf("%s",good);
    int idx = SearchGood(good);
    if(idx == -1)
    {
        error_finding_good();
        failureMessage();
    }
    else
        Product_Info(idx);
}

void ADMIN_DELETE_Good()
{
    char good[MAX_NAME_LENGTH];
    printf("请输入您要查找的商品名称或ID: ");
    scanf("%s",good);
    Delete_Product(good);
}
