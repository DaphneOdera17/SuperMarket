#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <string.h>
#include "User/User.h"
#include "tools/color.h"
#include "config.h"

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


    //printf("请输入用户名：");

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


void Out_User()
{
    FILE* ptr;
    ptr = fopen("src/Data/User_Info.txt" , "w");
    if (fopen == NULL)
    {
        openErrorMessage();
        return ;
    }
    else
    {
        for(int i = 0; i < Total_UserNumber; i++)
        {
            fprintf(ptr,"%s %s %s %s %s %.1f\n", users[i].id , users[i].name , users[i].password , users[i].tel , users[i].address , users[i].res);
        }
        fclose(ptr);
        
    }
}

void Print_UserInfo()
{
    for(int i = 0; i < Total_UserNumber; i++)
    {
        printf("ID: %10s\n",users[i].id);
        printf("Name: %10s\n",users[i].name);
        printf("Password: %10s\n",users[i].password);
        printf("Tel: %10s\n",users[i].tel);
        printf("Address: %10s\n",users[i].address);
        printf("Res: %10.1lf\n",users[i].res);
        printf("------------------------------------\n");
    }
}

void Load_User()
{
    FILE *ptr;
    // 以只读方式打开文件
    ptr = fopen("src/Data/User_Info.txt", "r");
    if(ptr == NULL)
    {
        printf("%s%s无法打开文件%s\n", BOLD, FRONT_RED, RESET);
        return ;
    }
    int k = 0;
    while(fscanf(ptr, "%s%s%s%s%s%lf", users[k].id, users[k].name, \
                 users[k].password, users[k].tel, users[k].address, \
                 &(users[k].res)) != EOF)
    {
        k ++;
        printf("%s %s %s %s %s %.1f\n", users[k].id , users[k].name , users[k].password , users[k].tel , users[k].address , users[k].res);
    }
    fclose(ptr);
    Total_UserNumber = k;
}