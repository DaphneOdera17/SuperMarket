#include "interface/interface.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void User_SignUp()
{
    User *tmp = (User *)malloc(sizeof(User));
    printf("请输入您的姓名： ");
    scanf("%s", tmp->name);
    printf("请输入您的密码： ");
    scanf("%s", tmp->password);
    printf("请输入您的来联系方式： ");
    scanf("%s", tmp->tel);
    printf("请输入您的地址： ");
    scanf("%s", tmp->address);
    tmp->res = 0.0;
    if(Add_User(tmp) == -1)
        failureMessage();
    else
        successful();
    free(tmp);
}
