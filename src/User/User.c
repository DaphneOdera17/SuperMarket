#include "interface/interface.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static const char* FILEPATH = "src/Data/User_Info.txt";
static User users[MAX_USER_NUMBER];
static int Total_UserNumber = 0;

User *Get_User(int idx) {return users + idx;}

void Load_User()
{
    FILE *ptr;
    ptr = fopen(FILEPATH, "r");
        while (fscanf(ptr, "%s%s%s%s%s%lf", users[Total_UserNumber].id, users[Total_UserNumber].name, users[Total_UserNumber].password, users[Total_UserNumber].tel, \
            users[Total_UserNumber].address, &(users[Total_UserNumber].res)) != EOF) 
                Total_UserNumber++; 
        fclose(ptr);
}

void Out_User()
{
    FILE* ptr = fopen(FILEPATH, "w");
    for (int i = 0; i < Total_UserNumber; i++)
        fprintf(ptr, "%s %s %s %s %s %.1f\n", users[i].id, users[i].name, users[i].password, \
users[i].tel, users[i].address, users[i].res);
    fclose(ptr);
}

int SearchUserID(char* id)
{
    //二分查找
    int left = 0;
    int right = Total_UserNumber;
        while(left <= right)
        {
            int middle = (left + right) / 2;
            if(strcmp(users[middle].id , id) > 0)//第一个字符串大于第二个字符串 返回正数
                right = middle - 1;
            else if(strcmp(users[middle].id , id) < 0)//第一个字符串小于第二个字符串 返回负数
                left = middle + 1;
            else 
            return middle;
        }
        return -1;

    // for(int i = 0; i < Total_UserNumber; i ++)
    //     if(strcmp(users[i].id, id) == 0)
    //         return i;
    // return -1;
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
    int idx = SearchUserID(name);
    if(idx == -1)
        return -1;
    for(int i = idx; i < Total_UserNumber - 1; i ++)
        users[i] = users[i + 1];
    Total_UserNumber --;
    return 0;
}

int check(char *name, char *pwd)
{
    int idx = SearchUserName(name);
    if(idx == -1)
        return -1;
    return strcmp(users[idx].password, pwd) == 0;
}