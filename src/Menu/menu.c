#include "interface/interface.h"
#include "config.h"
#include <stdio.h>
#include <stdlib.h>

static const char *menuPrompts[MENU_NUMBER] = {"\
+============+============+==============+========+ \n\
| 1.用户登录 | 2.用户注册 | 3.管理员登录 | 4.退出 | \n\
+============+============+==============+========+ \n", \
"\
+============+============+================+============+ \n\
| 1.我是买家 | 2.我是卖家 | 3.个人信息管理 | 4.注销登陆 | \n\
+============+============+================+============+ \n", \
"\
+============+================+================+============+================+==================+ \n\
| 1.发布商品 | 2.查看发布商品 | 3.修改商品信息 | 4.下架商品 | 5.查看历史订单 | 6.返回用户主界面 | \n\
+============+================+================+============+================+==================+ \n", \
"\
+================+============+============+================+====================+==================+ \n\
| 1.查看商品列表 | 2.搜索商品 | 3.购买商品 | 4.查看历史订单 | 5.查看商品详细信息 | 6.返回用户主界面 | \n\
+================+============+============+================+====================+==================+ \n", \
"\
+================+============+================+================+============+============+========+ \n\
| 1.查看所有商品 | 2.搜索商品 | 3.查看所有订单 | 4.查看所有用户 | 5.删除用户 | 6.下架商品 | 7.注销 | \n\
+================+============+================+================+============+============+========+ \n", \
"\
+============+================+============+========+\n\
| 1.修改密码 | 2.修改联系方式 | 3.修改地址 | 4.返回 |\n\
+============+================+============+========+\n", \
"\
+============+============+========+==================+ \n\
| 1.查看信息 | 2.修改信息 | 3.充值 | 4.返回用户主界面 | \n\
+============+============+========+==================+ \n", \
"\
+========+========+========+========+ \n\
| 1.名称 | 2.价格 | 3.描述 | 4.返回 | \n\
+========+========+========+========+ \n"};

static const char *menuName[MENU_NUMBER] = {"Main", "User", "Seller", "Buyer", "Admin", "Modify", "Info", "Products"};

static const char *tapNum[MENU_NUMBER] = {"\t\t      ", "\t\t      ", "\t\t\t\t\t  ", "\t\t\t\t\t    ", "\t\t\t\t\t  ", "\t\t      ", "\t\t      ", "\t     "};

static void PromptMessage(Menu type){
    printf("%s%s%s Menu%s\n", tapNum[type], REVERSE, menuName[type], RESET);
    printf("%s\n%s请输入您的操作:%s ", menuPrompts[type], FRONT_GREEN, RESET);
}; 

const int optionNumber[MENU_NUMBER] = {4, 4, 6, 6, 7, 4, 4, 4};

int menu(Menu type)
{
    PromptMessage(type);
    char buffer[MAX_LEN]; 
    int res;
    scanf("%s", buffer);
    res = atoi(buffer);
    while(1)
    {
        if(res >= 1 && res <= optionNumber[type]) break;
        failureMessage();
        printf("%s请输入您的操作:%s ", FRONT_GREEN, RESET);
        scanf("%s", buffer);
        res = atoi(buffer);
    }
    return res;
}
