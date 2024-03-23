#ifndef _INTERFACE_H_
#define _INTERFACE_H_

#include "User/User.h"
#include "Order/Order.h"
#include "Product/Product.h"
#include "Menu/menu.h"
#include "tools/color.h"
#include "tools/hint.h"
#include "tools/info.h"

typedef void (*HANDLE)(void); // 定义函数指针

extern int Now_User;

void USER_Interface();
void BUYER_Interface();
void SELLER_Interface();
void INFO_Interface();
void ADMIN_Interface();
void PRODUCT_Interface();
void MODIFY_Interface();

#endif