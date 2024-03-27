#include "interface/interface.h"

int Now_User = -1; // 当前用户索引

static HANDLE handler[] = {BUYER_Interface, SELLER_Interface, INFO_Interface};

void USER_Interface() {MAKE_Interface(USER, handler);}
