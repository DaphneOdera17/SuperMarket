#include "interface/interface.h"
#include <stdio.h>

static HANDLE handler[] = {MODIFY_GoodName, MODIFY_GoodPrice, MODIFY_GoodDes};

int Now_Good = -1;

void PRODUCT_Interface()
{
    int op = menu(PRODUCTS);
    while(op != optionNumber[PRODUCTS]) 
    {
        loadingMessage();
        handler[op - 1](); 
        op = menu(PRODUCTS);
    }
}

void MODIFY_GoodName() 
{
    Product *tmp = Get_Good(Now_Good);
    printf("请输入商品名字：");
    scanf("%s", tmp->name);
    free(tmp);
}

void MODIFY_GoodPrice()
{
    Product *tmp = Get_Good(Now_Good);
    printf("请输入商品价格：");
    scanf("%s", tmp->name);
    free(tmp);

}

void MODIFY_GoodDes()
{
    Product *tmp = Get_Good(Now_Good);
    printf("请输入商品描述：");
    scanf("%s", tmp->name);
    free(tmp);
    
}