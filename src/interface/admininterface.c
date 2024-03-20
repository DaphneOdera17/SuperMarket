#include "interface/interface.h"
#include <stdio.h>
#include <stdlib.h>

static HANDLE handler[] = {DELETE_User};

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
        successful();
}

