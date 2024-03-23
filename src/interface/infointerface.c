#include "interface/interface.h"
#include <stdio.h>

static HANDLE handler[] = {User_Info, MODIFY_Interface, RECHARGE};

void INFO_Interface() {
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

void RECHARGE()
{
    double res;
    printf("请输入您要充值的金额：");
    scanf("%lf", &res);
    Recharge(res);
}