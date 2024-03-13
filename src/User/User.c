#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <string.h>
#include "User/User.h"
#include "tools/color.h"
#include "config.h"
#include "tools/hint.h"
#include "tools/info.h"

static const char* FILEPATH = "src/Data/User_Info.txt";
static User users[MAX_USER_NUMBER];
static int Total_UserNumber = 0;
static int Now_User = 0;

void choose(int op)
{
    switch (op)
    {
    case 1:
        Main_Menu();
        break;
    case 2:
        Buyer_Menu();
        break;
    case 3:
        Seller_Menu(Now_User);
        break;
    case 4:
        Info_Menu();
        break;
    }
}

void User_Menu()
{
    user_menuMessage();

    int op;

    printf("请输入您的操作：");
    scanf("%d", &op);

    while(op < 1 || op > 4)
    {
        failureMessage();
        printf("请输入您的操作：");
        scanf("%d", &op);
    }

    choose(op);
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

    // char search_name[MAX_NAME_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char saved_password[MAX_PASSWORD_LENGTH];

    getUserName(username); // 获取了用户名



  

    getPassword(password); // 获取密码

    puts("");


    //  如果用户存在： 用这个用户名对应的 saved_password 与输入的 password 比对
    //  如果不存在。那么就输出 不存在。
    // 你先用顺序查找


    for(int i = 0; i < Total_UserNumber; i++)
    {
        if(strcmp(username , users[i].name) == 0)
        {
            strcpy(&saved_password[i] , users[i].password);
            Now_User = i;
            break;
        }
        else
        {
            printf("用户不存在！");
        }

    }

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


// 

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
        //这里就是把文件信息一行一行读取
        // 就跟你 scanf 一样的
        // 第 i + 1 行的用户名就是 users[i].name 密码 users[i].password

        while (fscanf(ptr, "%s%s%s%s%s%lf", users[Total_UserNumber].id, users[Total_UserNumber].name,\
        users[Total_UserNumber].password, users[Total_UserNumber].tel, \
        users[Total_UserNumber].address, &(users[Total_UserNumber].res)) != EOF) 
            Total_UserNumber++; // 他从 0 开始加的 
        fclose(ptr);
    }
}


void Recharge()
{
    double res;
    printf("请输入需要充值的金额： ");
    scanf("%lf",&res);
    users[0].res += res;
    printf("充值成功！\n");
    printf("目前您的余额为：%.1lf\n", users[0].res);
}


void User_Sign()
{
// 注册用户
// 让他输入 姓名、密码、联系方式、地址

    printf("请输入您的姓名： ");
    scanf("%s",users[Total_UserNumber].name);
    printf("请输入您的密码： ");
    scanf("%s",users[Total_UserNumber].password);
    printf("请输入您的来联系方式： ");
    scanf("%s",users[Total_UserNumber].tel);
    printf("请输入您的地址： ");
    scanf("%s",users[Total_UserNumber].address);

// 他的余额 为 0  
    printf("%s %s \n", users[Total_UserNumber].name, users[Total_UserNumber].password);
    users[Total_UserNumber].res = 0.0;

    
// ID 通过 info 里面的 Generate_ID 生成
    Generate_ID(users[Total_UserNumber].id, 'U');

    printf("%s\n", users[Total_UserNumber].id);
    Total_UserNumber ++;

// 并且存储到 User_Info.txt
    // 参考 Out._User();
    
    FILE* ptr = fopen(FILEPATH , "w"); // write -> w写入 read -> 只读

    // 首先， 你 total- 已经加 1 了， 为什么还加
    
    // 家不加目前美影响
    
    fprintf(ptr, "%s %s %s %s %s %.1f\n", users[Total_UserNumber].id, \
    users[Total_UserNumber].name, users[Total_UserNumber].password, \
    users[Total_UserNumber].tel, users[Total_UserNumber].address, users[Total_UserNumber].res);
    
    
    fclose(ptr);
    

    Out_User();
    User_Menu();
    
}

void Delete_User()
{
    // 提示需要输入的用户 ID
    char id[MAX_ID_LENGTH];
    printf("请输入您要删除的id: ");
    scanf("%s", id);
    printf("%s", id);
    // 查找用户 ID （带实现： 用二分查找）
    int flag = 0; // flag 为 0 表示未找到， 为 1 表示已经找到
    for(int i = 0; i < Total_UserNumber ; i++)
    {
        if(strcmp(id , users[i].id) == 0)
        {
            flag = 1;
            // 覆盖：后一位到这一位的位置  那你后面的 不补上来马 你写循环
            for(int j = i ; j < Total_UserNumber - 1; j ++)
            {
                users[j] = users[j + 1];
            }
            
        }
        
    }

    if(!flag)
    {
        puts("未找到该用户");
    }
    // 你可以先用 顺序查找写
    // 找到该 ID 用户 
    // 作者的方法是，将该位置 后面的所有都往前移动一个位置，就可以实现覆盖(被覆盖了不就是山了==)

}