#include "interface/interface.h"
#include <stdio.h>

int Now_User = -1; // 当前用户索引

static HANDLE handler[] = {BUYER_Interface, SELLER_Interface, INFO_Interface};

void USER_Interface() {
    int op = menu(USER);
    while (op != optionNumber[USER]) {
        loadingMessage();
        handler[op - 1]();
        op = menu(USER);
    }
}
