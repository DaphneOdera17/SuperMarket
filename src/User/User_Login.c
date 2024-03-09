#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <string.h>
#include "User/User.h"
#include "tools/color.h"

#define MAX_PASSWORD_LENGTH 20
#define MAX_USERNAME_LENGTH 10

// 从终端获取密码（隐藏输入）
void getPassword(char* password) {
    struct termios oldAttr, newAttr;
    
    // 禁止终端回显
    tcgetattr(fileno(stdin), &oldAttr);
    newAttr = oldAttr;
    newAttr.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(fileno(stdin), TCSAFLUSH, &newAttr);
    
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
    
}

void User_Login()
{
    getchar();
    
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char saved_password[MAX_PASSWORD_LENGTH] = "123456";


    //printf("请输入用户名：");

    //getUserName(username);

    //getchar();
    printf("请输入密码：");

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
