#include "interface/interface.h"
#include <stdio.h>

static HANDLE handler[] = {Modify_Name, Modify_Price, Modify_Des};

int Now_Good = -1;

void PRODUCT_Interface()
{
    int op = menu(MAIN);
    while(op != optionNumber[MAIN]) // 操作不为退出时
    {
        loadingMessage();
        handler[op - 1](); // () 调用
        // User_Login
        op = menu(MAIN);
    }
    loadingMessage();
}

void Modify_Name() 
{
    Product *tmp = Get_User(Now_Good);
    printf("请输入商品名字：");
    scanf("%s", tmp->name);
    free(tmp);
    
}

void Modify_Price()
{
    Product *tmp = Get_User(Now_Good);
    printf("请输入商品价格：");
    scanf("%s", tmp->name);
    free(tmp);

}

void Modify_Des()
{
    Product *tmp = Get_User(Now_Good);
    printf("请输入商品描述：");
    scanf("%s", tmp->name);
    free(tmp);
    
}