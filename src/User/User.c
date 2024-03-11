#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <string.h>
#include "User/User.h"
#include "tools/color.h"
#include "config.h"
#include "tools/hint.h"

static const char* FILEPATH = "src/Data/User_Info.txt";
static User users[MAX_USER_NUMBER];
static int Total_UserNumber = 0;

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
    // 问题：当按下 backspace 也会计入密码，需要改进
    while ((c = getchar()) != '\n' && i < MAX_PASSWORD_LENGTH - 1) {
        password[i++] = c;
        putchar('*');  // 回显星号
    }
    password[i] = '\0';
    
    // 恢复终端设置
    tcsetattr(fileno(stdin), TCSANOW, &oldAttr);
}

void getUserName(char* username)
{
    printf("请输入用户名：");

    int i = 0;
    char c;
    while((c = getchar()) != '\n' && i < MAX_USERNAME_LENGTH - 1){
        username[i ++] = c;
    }
    username[i] = '\0';
}

void User_Login()
{
    getchar();
    
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char saved_password[MAX_PASSWORD_LENGTH] = "123456";

    getUserName(username);

    getPassword(password);

    puts("");

    while(!(strcmp(password, saved_password) == 0))
    {
        printf("%s密码输入错误,请重新再试!%s\n", FRONT_RED, RESET);
        printf("请输入密码：");

        getPassword(password);
        puts("");
    }

    puts("登陆成功！");
    User_Menu();
    
}


void Print_UserInfo()
{
    Print_UserInfo_Banner();
    for(int i = 0; i < Total_UserNumber; i ++)
    {
        printf("|%-6s |%-7s |%-15s |%-15s |%-15s |%-9.1lf |\n", \
            users[i].id, users[i].name, users[i].password, users[i].tel, \
            users[i].address, users[i].res);
        printf("------------------------------------------------------------------------\n");
    }
}

void Out_User()
{
    FILE* ptr = fopen(FILEPATH, "w");
    for (int i = 0; i < Total_UserNumber; i++)
        fprintf(ptr, "%s %s %s %s %s %.1f\n", users[i].id, users[i].name, users[i].password, \
users[i].tel, users[i].address, users[i].res);
    fclose(ptr);
}

void Load_User()
{
    Total_UserNumber = 0;
    FILE *ptr;
    // 以只读方式打开文件
    ptr = fopen(FILEPATH, "r");
    if(ptr == NULL)
    {
        open_ErrorMessage();
    }
    else
    {
        while (fscanf(ptr, "%s%s%s%s%s%lf", users[Total_UserNumber].id, users[Total_UserNumber].name,\
        users[Total_UserNumber].password, users[Total_UserNumber].tel, \
        users[Total_UserNumber].address, &(users[Total_UserNumber].res)) != EOF) 
            Total_UserNumber++;
        fclose(ptr);
    }
}
