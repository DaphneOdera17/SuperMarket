#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <string.h>
#include "User/User.h"
#include "tools/color.h"
#include "config.h"
#include "tools/hint.h"
#include "tools/info.h"
#include "Admin/Admin.h"
#include <unistd.h>
#include "Product/Product.h"
#include "Menu/Main_Menu.h"
#include "Order/Order.h"

static const char* FILEPATH = "src/Data/User_Info.txt";
static User users[MAX_USER_NUMBER];
static int Total_UserNumber = 0;
extern Product goods[MAX_PRODUCT_NUMBER];
int Now_User = 0;

void Info_Menu()
{
    info_menuMessage();

    int op;
    
    printf("请输入您的操作：");
    scanf("%d", &op);

    while( op < 1 || op > 4)
    {
        failureMessage();
        printf("请输入您的操作：");
        scanf("%d", &op);
    }

    switch(op)
    {
        case 1:User_Info();break;
        case 2:Modify_Info();break;
        case 3:Recharge();break;
        case 4:User_Menu();break;
    }
}

void Buyer_Menu()
{
    buyer_menuMessage();

    int op;

    printf("请输入您的操作：");
    scanf("%d",&op);

    while(op < 1 || op > 6)
    {
        failureMessage();
        printf("请输入您的操作：");
        scanf("%d",&op);
    } 

    switch (op)
    {
    case 1:Print_Products('U');break;    
    case 2:Search_Product('U');break;
    case 3:Buy_Product();break;
    case 4:Search_OwnOrders('U', users[Now_User].id);break;
    case 5:Print_ProductInfo();break;
    case 6:User_Menu();break;
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

void Seller_Menu(int Now_User)
{
    seller_menuMessage();

    int op;

    printf("请输入您的操作：");
    scanf("%d", &op);

    while( op < 1 || op >6)
    {
        failureMessage();
        printf("请输入您的操作：");
        scanf("%d", &op);
    }
    switch (op)
    {
    case 1:Add_Product(users[Now_User].id);break;    
    case 2:Search_Product('S');break;
    case 3://break;
    case 4:Delete_Product(users[Now_User].id);break;
    case 5:Search_OwnOrders('S', users[Now_User].id);break;
    case 6:User_Menu();break;
    }
}


void choose(int op)
{
    switch (op)
    {
    case 1:Main_Menu();break;
    case 2:Buyer_Menu();break;
    case 3:Seller_Menu(Now_User);break;
    case 4:Info_Menu();break;
    }
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
    int flag = 0; // 0 表示未查找到用户 1 表示查找到对应的用户

    getUserName(username); // 获取了用户名
    
    getPassword(password); // 获取密码

    puts("");


    for(int i = 0; i < Total_UserNumber; i++)
    {
        if(strcmp(username , users[i].name) == 0)
        {
            strcpy(saved_password , users[i].password);
            Now_User = i;
            flag = 1;
        }
    }
    if(flag == 0)
        {
            printf("用户不存在,请重新再试！");
            Main_Menu();

        }
//当用户存在但密码不匹配则进入循环 直到密码正确
    while(flag == 1)
    {
        if(!(strcmp(password, saved_password) == 0))
        {
            printf("%s密码输入错误,请重新再试!%s\n", FRONT_RED, RESET);
            getPassword(password);
            puts("");
        }
        else
        {
            puts("登陆成功！");
            User_Menu();
            break;
        }
    
    }
    
    
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
    Admin_Menu();
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
    users[Now_User].res += res;
    printf("充值成功！\n");
    printf("目前您的余额为：%.1lf\n", users[Now_User].res);
    Info_Menu();
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

// 余额 为 0  
    printf("%s %s \n", users[Total_UserNumber].name, users[Total_UserNumber].password);
    users[Total_UserNumber].res = 0.0;

    
// ID 通过 info 里面的 Generate_ID 生成
    Generate_ID(users[Total_UserNumber].id, 'U');

    printf("%s\n", users[Total_UserNumber].id);
    Total_UserNumber ++;

// 并且存储到 User_Info.txt

    
    FILE* ptr = fopen(FILEPATH , "w"); // write -> w写入 read -> 只读
    
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
    Admin_Menu();
}

void User_Info()
{
    puts("");
    loadingMessage();
    sleep(0.5);
    printf("%s%s您的信息为: %s\n", BOLD, FRONT_GREEN, RESET);
    printf("用户名称: %s\n", users[Now_User].name);
    printf("用户密码: %s\n", users[Now_User].password);
    printf("用户联系方式: %s\n", users[Now_User].tel);
    printf("用户地址: %s\n", users[Now_User].address);
    printf("用户余额: %.2lf\n", users[Now_User].res);
    
    puts("");

    Info_Menu();
}

void Modify_Info()
{
    int op;
    char password[MAX_PASSWORD_LENGTH];
    char address[MAX_ADRESS_LENGTH];
    char tel[MAX_TEL_LENGTH];
    printf("请输入要修改的信息:1.修改密码 2.地址 3.联系方式 \n");
    scanf("%d",&op);
    switch(op)
    {
        case 1: 
        {
            printf("请输入密码: ");
            scanf("%s",password);
            strcpy(users[Now_User].password , password);
            printf("修改成功！");
            Info_Menu() ;
            break;
        }
        case 2: 
        {
            printf("请输入地址: ");
            scanf("%s",address); 
            strcpy(users[Now_User].address , address);
            printf("修改成功！");
            Info_Menu() ;
            break;
        }
        case 3: 
        {
            printf("请输入联系方式: ");
            scanf("%s",tel); 
            strcpy(users[Now_User].tel , tel);
            printf("修改成功！");
            Info_Menu() ;
            break;
        }
        default: printf("无效操作，请重试！");Info_Menu() ; break;
    }


    
}

void Buy_Product()
{
    char ch;
    char a[MAX_NAME_LENGTH];

    printf("请输入您要查找的商品名称或商品id: ");
    scanf("%s", a);
    extern int Now_User;

    int flag = search(a);
    if(flag == -1)
    {
        printf("未查找到商品！");
        Buyer_Menu();
    }
    else
    {
        printf("商品id:%s \n", goods[flag].id );
        printf("商品名称：%s \n",goods[flag].name);
        printf("商品价格：%.1f\n", goods[flag].price);
        printf("商品描述：%s\n",goods[flag].discribe);
        printf("上架时间：%s\n",goods[flag].SellTime);
        printf("剩余数量：%d\n",goods[flag].cnt);
        switch(goods[flag].state)
        {
            case 0: printf("商品状态： 已下架 \n"); break;
            case 1: printf("商品状态： 在售中 \n"); break;
            case 2: printf("商品状态： 已售空 \n"); break;
        }

        printf("您确定购买此商品吗?请输入Yes/No\n");//Y表示确定购买 N表示取消购买
        char ch[5];
        scanf("%s",ch);
    
        if(strcmp(ch , "Yes") == 0)
        {
            if(users[Now_User].res < goods[flag].price)
            {
                printf("余额不足，请前往个人信息管理充值后购买！");
                User_Menu();
            }
            else if(goods[flag].state == 0 || goods[flag].state == 2)
            {
                printf("该商品已下架或已售空，请选择其他商品购买！");
                Buyer_Menu();
            }
            else
            {
                users[Now_User].res -= goods[flag].price ; 
                printf("购买成功！\n");
                Add_Order(flag);
                printf("当前账户余额为： %.1f",users[Now_User].res);
                Buyer_Menu();
            }

        }
        else
        {
            printf("已取消购买！");Buyer_Menu();
        }
           
    }
    
}

void Print_ProductInfo()
{

}

