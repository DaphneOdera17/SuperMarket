#include "interface/interface.h"
#include <stdio.h>

static HANDLE handler[] = {User_Info, MODIFY_Interface, RECHARGE};

void INFO_Interface() {
    int op = menu(INFO);
    while (op != optionNumber[INFO]) {
        loadingMessage();
        handler[op - 1]();
        op = menu(INFO);
    }
}

void RECHARGE()
{
    double res;
    printf("请输入您要充值的金额：");
    scanf("%lf", &res);
    Recharge(res);
}