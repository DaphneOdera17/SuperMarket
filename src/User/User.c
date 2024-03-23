#include "interface/interface.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static const char* FILEPATH = "src/Data/User_Info.txt";
static User users[MAX_USER_NUMBER];
static int Total_UserNumber = 0;

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

void Recharge(double res)
{
    User *tmp = Get_User(Now_User);
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

int Delete_User(char *name)
{
    int idx = SearchUserName(name);
    if(idx == -1)
        return -1;
    for(int i = idx; i < Total_UserNumber - 1; i ++)
        users[i] = users[i + 1];
    return 0;
}

int check(char *name, char *pwd)
{
    int idx = SearchUserName(name);
    if(idx == -1)
        return -1;
    return strcmp(users[idx].password, pwd) == 0;
}

/*
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