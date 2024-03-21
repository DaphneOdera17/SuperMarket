#include "interface/interface.h"
#include <stdio.h>
#include <string.h>

static HANDLE handler[] = {MODIFY_GoodInfo};

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