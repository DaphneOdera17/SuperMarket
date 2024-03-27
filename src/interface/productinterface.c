#include "interface/interface.h"
#include <stdio.h>

static HANDLE handler[] = {MODIFY_GoodName, MODIFY_GoodPrice, MODIFY_GoodDes};

int Now_Good = -1; 

void PRODUCT_Interface() {MAKE_Interface(PRODUCTS, handler);}

void MODIFY_GoodName() // 修改产品名字
{
    Product *tmp = Get_Good(Now_Good);
    printf("请输入修改后的商品名字：");
    scanf("%s", tmp->name);
    successMessage();
}

void MODIFY_GoodPrice() // 修改产品价格
{
    Product *tmp = Get_Good(Now_Good);
    printf("请输入修改后的商品价格：");
    scanf("%lf", &tmp->price);
    successMessage();
}

void MODIFY_GoodDes() // 修改产品描述
{
    Product *tmp = Get_Good(Now_Good);
    printf("请输入修改后的商品描述：");
    scanf("%s", tmp->discribe);
    successMessage();
}