#include "interface/interface.h"
#include <stdio.h>
#include <string.h>

static HANDLE handler[] = {MODIFY_UserName, MODIFY_UserPwd, MODIFY_UserTel};

void MODIFY_Interface() {
    int op = menu(MODIFY);
    while (op != optionNumber[MODIFY]) {
        loadingMessage();
        handler[op - 1]();
        op = menu(MODIFY);
    }
}

void MODIFY_UserName()
{
    User *tmp = Get_User(Now_User);
    printf("请输入修改后的名字: ");
    scanf("%s", tmp->name);
    free(tmp);
}

void MODIFY_UserPwd()
{
    User *tmp = Get_User(Now_User);
    printf("请输入密码：");
    scanf("%s", tmp->password);
    free(tmp);
}
void MODIFY_UserTel()
{
    User *tmp = Get_User(Now_User);
    printf("请输入联系方式：");
    scanf("%s", tmp->tel);
    free(tmp);
}
