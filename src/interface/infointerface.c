#include "interface/interface.h"
#include <stdio.h>

static HANDLE handler[] = {User_Info, MODIFY_Interface, RECHARGE};

void INFO_Interface() {
    successMessage();
    int op = menu(INFO);
    while (op != optionNumber[INFO]) {
        loadingMessage();
        handler[op - 1]();
        op = menu(INFO);
    }
    loadingMessage();
    successMessage();
}

void RECHARGE()
{
    double res;
    printf("请输入您要充值的金额：");
    scanf("%lf", &res);
    Recharge(res);
}