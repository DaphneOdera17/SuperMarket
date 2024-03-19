#include "interface/interface.h"
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <string.h>
#include <unistd.h>

static const char* FILEPATH = "src/Data/User_Info.txt";
static User users[MAX_USER_NUMBER];
static int Total_UserNumber = 0;
int Now_User = 0;

void Load_User()
{
    FILE *ptr;
    ptr = fopen(FILEPATH, "r");
        while (fscanf(ptr, "%s%s%s%s%s%lf", users[Total_UserNumber].id, users[Total_UserNumber].name, users[Total_UserNumber].password, users[Total_UserNumber].tel, \
            users[Total_UserNumber].address, &(users[Total_UserNumber].res)) != EOF) 
                Total_UserNumber++; 
        fclose(ptr);
}

User *Get_User(int idx) {return users + idx;}

void Out_User()
{
    FILE* ptr = fopen(FILEPATH, "w");
    for (int i = 0; i < Total_UserNumber; i++)
        fprintf(ptr, "%s %s %s %s %s %.1f\n", users[i].id, users[i].name, users[i].password, \
users[i].tel, users[i].address, users[i].res);
    fclose(ptr);
}

void Print_UserInfo()
{
    Print_UserInfo_Banner();
    for(int i = 0; i < Total_UserNumber; i ++)
    {
        printf("|%-6s |%-7s |%-15s |%-15s |%-15s |%-9.1lf |\n", \
            users[i].id, users[i].name, users[i].password, users[i].tel, users[i].address, users[i].res);
        printf("------------------------------------------------------------------------\n");
    }
}

void User_Info()
{
    loadingMessage();
    sleep(0.5);
    printf("%s%s您的信息为: %s\n", BOLD, FRONT_GREEN, RESET);
    printf("用户名称: %s\n", users[Now_User].name);
    printf("用户密码: %s\n", users[Now_User].password);
    printf("用户联系方式: %s\n", users[Now_User].tel);
    printf("用户地址: %s\n", users[Now_User].address);
    printf("用户余额: %.2lf\n\n", users[Now_User].res);
}

int SearchUserID(char* id)
{
    for(int i = 0; i < Total_UserNumber; i ++)
        if(strcmp(users[i].id, id) == 0)
            return i;
    return -1;
}

int SearchUserName(char *name)
{
    for(int i = 0; i < Total_UserNumber; i ++)
        if(strcmp(users[i].name, name) == 0)
            return i;
    return -1;
}

void Recharge()
{
    User *tmp = Get_User(Now_User);
    double res;
    printf("请输入需要充值的金额： ");
    scanf("%lf",&res);
    tmp->res += res;
    printf("充值成功！\n");
    printf("目前您的余额为：%.1lf\n", tmp->res);
}

// 如果添加成功， 返回 0
int Add_User(User* tmp)
{
    // 不存在相同用户名
    if(SearchUserName(tmp->name) != -1)
        return -1;
    Generate_ID(tmp->id, 'U');
    // 把这个新的 user 加到 users 里面
    users[Total_UserNumber ++] = *tmp;
    return 0;
}

void Delete_User(char *name)
{
    int idx = SearchUserName(name);
    for(int i = idx; i < Total_UserNumber - 1; i ++)
        users[i] = users[i + 1];
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

/*
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
*/

/*
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
*/

/*
void User_Login()
{
    getchar();

    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char saved_password[MAX_PASSWORD_LENGTH];
    int flag = 0; // 0 表示未查找到用户 1 表示查找到对应的用户

    getUserName(username); // 获取了用户名
    getPassword(password); // 获取密码
    puts("");

    if(SearchUserName == -1)
    {

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
*/

/*
void User_Sign()
{
// 注册用户
// 让他输入 姓名、密码、联系方式、地址
    

// ID 通过 info 里面的 Generate_ID 生成
    Generate_ID(users[Total_UserNumber].id, 'U');

    printf("%s\n", users[Total_UserNumber].id);
    Total_UserNumber ++;
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
    Admin_Menu();
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
                users[Now_User].res -= goods[flag].price; 
                Out_User();
                printf("购买成功！\n");
                Add_Order(flag, users[Now_User].id);
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
*/