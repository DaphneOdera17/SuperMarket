#ifndef _INTERFACE_H_
#define _INTERFACE_H_

#include "User/User.h"
#include "Order/Order.h"
#include "Product/Product.h"
#include "Menu/menu.h"
#include "tools/color.h"
#include "tools/hint.h"
#include "tools/info.h"
#include <stdlib.h>

typedef void (*HANDLE)(void); // 定义函数指针

extern int Now_User;

void USER_Interface();
void BUYER_Interface();
void SELLER_Interface();
void INFO_Interface();
void ADMIN_Interface();
void PRODUCT_Interface();
void MODIFY_Interface();
void MAIN_Interface();

void ADMIN_DELETE_Good();
void DELETE_User();
void DELETE_Good();

int SEARCH_Good();
void Search_Good();
void Buy_Good();

void RECHARGE();

void getName(char* name);
void getPassword(char* password);
void User_Login();
void Admin_Login();
void User_SignUp();

void MODIFY_UserName();
void MODIFY_UserPwd();
void MODIFY_UserTel();

void MODIFY_GoodName();
void MODIFY_GoodPrice();
void MODIFY_GoodDes();

void ADD_Good();
void SELLER_OwnOrder();
void SELLER_OwnGoods();
void BUYER_OwnOrder();
void GOOD_Detail();
void MODIFY_Good();

#endif