#include "interface/interface.h"
#include <stdio.h>
#include <string.h>

static HANDLE handler[] = {Modify_Name, Modify_Pwd, Modify_Tel};

void MODIFY_Interface() {
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

void Modify_Name()
{
    User *tmp = Get_User(Now_User);
    printf("请输入修改后的名字: ");
    scanf("%s", tmp->name);
    free(tmp);
}

void Modify_Pwd()
{
    User *tmp = Get_User(Now_User);
    printf("请输入密码：");
    scanf("%s", tmp->password);
    free(tmp);
}
void Modify_Tel()
{
    User *tmp = Get_User(Now_User);
    printf("请输入联系方式：");
    scanf("%s", tmp->tel);
    free(tmp);
}


/*
void MODIFY_GoodInfo()
{
    char good[MAX_NAME_LENGTH];
    printf("请输入您要修改的商品名称或ID: ");
    scanf("%s",good);
    SearchGood(good);
    int idx = SearchGood(good);
    if(idx == -1)
    {
        error_finging_good();
        failureMessage();
    }
    else
    {
        int op;
    }
}
*/