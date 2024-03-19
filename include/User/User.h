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

int SearchUserID(char* id);

User *Get_User(int idx);

void Out_User();

void Print_UserInfo();

void User_Info();

int SearchUserID(char* id);

int SearchUserName(char *name);

void Recharge();

int Add_User(User* tmp);

void Delete_User(char *name);

//void getUserName(char* username);

//void getPassword(char* password);

#endif