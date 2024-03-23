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

User *Get_User(int idx);
int SearchUserID(char* id);
int SearchUserName(char *name);

void Load_User();
void Out_User();

void Print_UserInfo();
void User_Info();

void Recharge(double res);

int Add_User(User* tmp);
int Delete_User(char *name);

int check(char *name, char *pwd);

#endif