#include "interface/interface.h"

static HANDLE handler[] = {User_Info, MODIFY_Interface, RECHARGE};

void INFO_Interface() {MAKE_Interface(INFO, handler);}

void RECHARGE()
{
    double res;
    printf("请输入您要充值的金额：");
    scanf("%lf", &res);
    Recharge(res);
}