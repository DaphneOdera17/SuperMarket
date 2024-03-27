#include "interface/interface.h"

static HANDLE handler[] = {Print_Products, Search_Good, Print_Orders , Print_UserInfo , DELETE_User , ADMIN_DELETE_Good};

void ADMIN_Interface() {MAKE_Interface(ADMIN, handler);}

void DELETE_User()
{
    char id[MAX_USERNAME_LENGTH];
    printf("请输入您要删除的用户ID: ");
    scanf("%s", id);
    int idx = SearchUserID(id);
    if(idx == -1)
        error_finding_user(), failureMessage();
    else
        Delete_User(idx), successMessage();
}

void ADMIN_DELETE_Good()
{
    char good[MAX_NAME_LENGTH];
    printf("请输入您要查找的商品名称或ID: ");
    scanf("%s",good);
    int k = Delete_Product(good, 1);
    if(k == -1)
        error_finding_good(), failureMessage();
    else if(k == 2)
        Repeat_Delete(), failureMessage();
    else
        successMessage();
}
