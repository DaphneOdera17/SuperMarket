#ifndef _USER_H_
#define _USER_H_

#include "config.h"

// 定义用户类型
typedef struct{
    char id[MAX_ID_LENGTH]; // 用户 ID
    char name[MAX_NAME_LENGTH]; // 用户名称
    char password[MAX_PASSWORD_LENGTH]; // 用户密码
    char tel[MAX_TEL_LENGTH]; // 用户联系方式
    char address[MAX_ADRESS_LENGTH]; // 用户地址
    double res; // 用户余额
}User;


void User_Sign();

void getPassword(char* password);

void getUserName(char* username);

void User_Login();

void User_Menu();

void Buyer_Menu();

void Seller_Menu(int Now_User);

void choose(int op);

void Info_Menu();

void Print_UserInfo();

void Load_User();

void Out_User();

void Recharge();



#endif