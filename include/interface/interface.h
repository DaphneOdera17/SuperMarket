#ifndef _INTERFACE_H_
#define _INTERFACE_H_

#include "User/User.h"
#include "Order/Order.h"
#include "Product/Product.h"
#include "Menu/menu.h"
#include "config.h"
#include "tools/color.h"
#include "tools/hint.h"
#include "tools/info.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef void (*HANDLE)(void); // 定义函数指针

extern int Now_User;
extern int Now_Good;

void MAKE_Interface(Menu type, HANDLE handler[]);

/* USER_Interface */
void USER_Interface();

/* MAIN_Interface */
void MAIN_Interface();
void getName(char* name);
void getPassword(char* password);
void try_again(char *username, char *password, int cnt);
void User_LoginSuccess(char *username);
void User_Login();
void Admin_Login();
void User_SignUp();

/* ADMIN_Interface */
void ADMIN_Interface();
void ADMIN_DELETE_Good();
void DELETE_User();

/* BUYER_Interface */
void BUYER_Interface();
void Search_Good();
void BUYER_OwnOrder();
void GOOD_Detail();
void Buy_Good();
int Search_Good_Idx();

/* SELLER_Interface */
void SELLER_Interface();
void DELETE_Good();
void ADD_Good();
void SELLER_OwnOrder();
void SELLER_OwnGoods();
void MODIFY_Good();

/* MODIFY_Interface */
void MODIFY_Interface();
void MODIFY_UserPwd();
void MODIFY_UserTel();
void MODIFY_UserAddress();

/* INFO_Interface */
void INFO_Interface();
void RECHARGE();

/* PRODUCT_Interface */
void PRODUCT_Interface();
void MODIFY_GoodName();
void MODIFY_GoodPrice();
void MODIFY_GoodDes();

#endif