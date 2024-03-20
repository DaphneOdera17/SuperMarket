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

#endif