#include "interface/interface.h"
#include <stdio.h>
#include <string.h>

static HANDLE handler[] = {MODIFY_UserPwd, MODIFY_UserTel, MODIFY_UserAddress};

void MODIFY_Interface() {MAKE_Interface(MODIFY, handler);}

void MODIFY_UserPwd()
{
    User *tmp = Get_User(Now_User);
    printf("请输入修改后的密码：");
    scanf("%s", tmp->password);
    successMessage();
}

void MODIFY_UserTel()
{
    User *tmp = Get_User(Now_User);
    printf("请输入修改后的联系方式：");
    scanf("%s", tmp->tel);
    successMessage();
}

void MODIFY_UserAddress()
{
    User *tmp = Get_User(Now_User);
    printf("请输入修改后的地址: ");
    scanf("%s", tmp->address);
    successMessage();
}
