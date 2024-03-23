#include "interface/interface.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>

static HANDLE handler[] = {User_Login, User_SignUp, Admin_Login};

void getName(char* name)
{
    printf("请输入用户名：");
    int i = 0;
    char c;
    while((c = getchar()) != '\n' && i < MAX_NAME_LENGTH - 1)
        name[i ++] = c;
    name[i] = '\0';
}

// 从终端获取密码（隐藏输入）
void getPassword(char* password) {
    struct termios oldAttr, newAttr;
    
    // 禁止终端回显
    tcgetattr(fileno(stdin), &oldAttr);
    newAttr = oldAttr;
    newAttr.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(fileno(stdin), TCSAFLUSH, &newAttr);
    
    printf("请输入密码：");
    // 读取密码
    int i = 0;
    char c;
    while ((c = getchar()) != '\n' && i < MAX_PASSWORD_LENGTH - 1) {
        password[i++] = c;
        putchar('*');  // 回显星号
    }
    password[i] = '\0';
    
    // 恢复终端设置
    tcsetattr(fileno(stdin), TCSANOW, &oldAttr);
}

void User_Login()
{
    getchar();

    char username[MAX_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    getName(username); // 获取用户名
    getPassword(password); // 获取密码
    puts("");

    int flag = check(username, password); // 0 表示未查找到用户 1 表示查找到对应的用户
    if(flag == -1)
    {
        error_finding_user();
    }
    else if(check(username, password))
    {
        Now_User = SearchUserName(username);
        loginsuccessMessage();
        USER_Interface();
    }
    else
    {
        loginfailureMessage();
    }
}

void Admin_Login()
{
    getchar();
    char name[MAX_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    getName(name);
    getPassword(password);
    puts("");
    if(strcmp(name, ADMIN_NAME) == 0 && strcmp(password, ADMIN_PASSWORD) == 0)
    {
        loginsuccessMessage();
        ADMIN_Interface();
    }
    else
        loginfailureMessage();
}

void User_SignUp()
{
    User *tmp = (User *)malloc(sizeof(User));
    printf("请输入您的姓名： ");
    scanf("%s", tmp->name);
    printf("请输入您的密码： ");
    scanf("%s", tmp->password);
    printf("请输入您的联系方式： ");
    scanf("%s", tmp->tel);
    printf("请输入您的地址： ");
    scanf("%s", tmp->address);
    tmp->res = 0.0;
    if(Add_User(tmp) == -1)
        failureMessage();
    else
        successMessage();
    free(tmp);
}

void MAIN_Interface()
{
    int op = menu(MAIN);
    while(op != optionNumber[MAIN]) 
    {
        loadingMessage();
        handler[op - 1](); 
        op = menu(MAIN);
    }
    loadingMessage();
}