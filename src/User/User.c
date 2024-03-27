#include "interface/interface.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static const char* FILEPATH = "src/Data/User_Info.txt"; // 用户信息存储地址
static User users[MAX_USER_NUMBER];
static int Total_UserNumber = 0; // 用户总数量

User *Get_User(int idx) {return users + idx;}

void Load_User() // 加载用户
{
    FILE *ptr;
    ptr = fopen(FILEPATH, "r");
        while (fscanf(ptr, "%s%s%s%s%s%lf", users[Total_UserNumber].id, users[Total_UserNumber].name, users[Total_UserNumber].password, users[Total_UserNumber].tel, \
            users[Total_UserNumber].address, &(users[Total_UserNumber].res)) != EOF) 
                Total_UserNumber++; 
        fclose(ptr);
}

void Out_User() // 将用户信息输出到文件中
{
    FILE* ptr = fopen(FILEPATH, "w");
    for (int i = 0; i < Total_UserNumber; i++)
        fprintf(ptr, "%s %s %s %s %s %.1f\n", users[i].id, users[i].name, users[i].password, \
users[i].tel, users[i].address, users[i].res);
    fclose(ptr);
}

int SearchUserID(char* id)
{
    int l = 0, r = Total_UserNumber - 1;
    while(l < r){
        int mid = l + r >> 1;
        if(strcmp(users[mid].id, id) >= 0) r = mid;
        else l = mid + 1;
    }
    if(strcmp(users[l].id, id) == 0)
        return l;
    return -1;
}

int SearchUserName(char *name)
{
    for(int i = 0; i < Total_UserNumber; i ++)
        if(strcmp(users[i].name, name) == 0)
            return i;
    return -1;
}

void Print_UserInfo()
{
    Print_UserInfo_Banner();
    for(int i = 0; i < Total_UserNumber; i ++)
    {
        printf("|%-10s |%-10s |%-10s |%-10s |%-15s\t|%-10.1lf |\n", \
            users[i].id, users[i].name, users[i].password, users[i].tel, users[i].address, users[i].res);
        printf("%s-----------------------------------------------------------------------------%s\n", BOLD, RESET);
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

void Recharge(double res)
{
    User *tmp = Get_User(Now_User);
    tmp->res += res;
    printf("充值成功！\n");
    printf("目前您的余额为：%.1lf\n", tmp->res);
}

int Add_User(User* tmp)
{
    if(SearchUserName(tmp->name) != -1)
        return -1;
    Generate_ID(tmp->id, 'U');
    users[Total_UserNumber ++] = *tmp;
    return 0;
}

void Delete_User(int idx)
{
    for(int i = idx; i < Total_UserNumber - 1; i ++)
        users[i] = users[i + 1];
    Total_UserNumber --;
}

int check(char *name, char *pwd)
{
    int idx = SearchUserName(name);
    if(idx == -1)
        return -1;
    return strcmp(users[idx].password, pwd) == 0;
}