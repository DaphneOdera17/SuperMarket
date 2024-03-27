#include "interface/interface.h"
#include <stdio.h>
#include <string.h>

static const char* FILEPATH = "src/Data/Goods_Info.txt"; // 产品信息存储地址
static int Total_ProductsNumber = 0;
Product goods[MAX_PRODUCT_NUMBER];
extern int Now_User;

Product* Get_Good(int idx) {return goods + idx;}

void Load_Products()
{
    FILE *ptr = fopen(FILEPATH, "r");
    while(fscanf(ptr ,"%s%s%lf%s%s%s%d%d", goods[Total_ProductsNumber].id, goods[Total_ProductsNumber].name,\
        &(goods[Total_ProductsNumber].price), goods[Total_ProductsNumber].discribe, goods[Total_ProductsNumber].SellID, goods[Total_ProductsNumber].SellTime, &(goods[Total_ProductsNumber].cnt), &(goods[Total_ProductsNumber].state))!= EOF)
            Total_ProductsNumber ++;
    fclose(ptr);
}

void Out_Products()
{
    FILE *ptr = fopen(FILEPATH, "w");
    for(int i = 0; i < Total_ProductsNumber; i ++)
        fprintf(ptr, "%s %s %lf %s %s %s %d %d\n", goods[i].id, goods[i].name, \
            goods[i].price, goods[i].discribe, goods[i].SellID, goods[i].SellTime, goods[i].cnt, goods[i].state);
    fclose(ptr);
}

char *Get_State(int state)
{   
    switch(state){
        case 0: return "已下架"; break;
        case 1: return "在售中"; break;
        case 2: return "已售空"; break;}
}

int SearchGood(char *s)
{
    for(int i = 0 ; i < Total_ProductsNumber ; i++)
        if(strcmp(s, goods[i].id) == 0 || strcmp(s, goods[i].name) == 0)
            return i;
    return -1;
}

void Print_Product(int idx)
{
    Print_SingleGood_Banner();
    printf("|%-7s\t|%-15s\t|%-5.1f\t|%-10s|%-4d|%s%s%-11s%s|\n", goods[idx].id, goods[idx].name, goods[idx].price, goods[idx].SellTime, goods[idx].cnt, BOLD, FRONT_RED, Get_State(goods[idx].state), RESET);
}

void Print_Products()
{
    Print_GoodInfo_Banner();
    for(int i = 0; i < Total_ProductsNumber; i ++)
    {
        printf("|%-7s\t|%-15s\t|%-5.1f\t|%-15s\t|%-10s|%-10s|%-4d|%s%s%-11s%s|\n", goods[i].id, goods[i].name, goods[i].price, goods[i].discribe, \
            goods[i].SellID, goods[i].SellTime, goods[i].cnt, BOLD, FRONT_RED, Get_State(goods[i].state), RESET);
        printf("%s---------------------------------------------------------------------------------------------%s\n", BOLD, RESET);
    }
}

void Product_Info(int idx)
{
    Product *Good = Get_Good(idx);
    printf("商品id: %s\n", Good->id);
    printf("商品名称: %s\n", Good->name);
    printf("商品价格: %.1lf\n", Good->price);
    printf("卖家id: %s\n", Good->SellID);
    printf("商品上架时间: %s\n", Good->SellTime); 
    printf("商品数量: %d\n", Good->cnt);
    printf("商品状态: %s%s%s%s\n", BOLD, FRONT_RED, Get_State(Good->state), RESET);
}

void Print_OwnProduct(char *id)
{
    Print_GoodInfo_Banner();
    for(int i = 0; i < Total_ProductsNumber; i ++)
    {
        if(strcmp(goods[i].SellID, id) == 0)
            printf("|%-7s\t|%-15s\t|%-5.1f\t|%-15s\t|%-10s|%-10s|%-4d|%s%s%-11s%s|\n", goods[i].id, goods[i].name, goods[i].price, goods[i].discribe, \
            goods[i].SellID, goods[i].SellTime, goods[i].cnt, BOLD, FRONT_RED, Get_State(goods[i].state), RESET);
    }
    printf("%s---------------------------------------------------------------------------------------------%s\n", BOLD, RESET);
}

void Add_Product(Product *tmp)
{
    Generate_ID(tmp->id, 'G');
    Get_Time(tmp->SellTime);
    tmp->state = 1;
    goods[Total_ProductsNumber ++] = *tmp;
}

int Delete_Product(char *s, int level)
{
    int idx = SearchGood(s);
    if(idx == -1)
        return -1;
    if(level == 2 && strcmp(goods[idx].SellID, Get_User(Now_User)->id) != 0)
        return 3;
    if(goods[idx].state == 0)
        return 2;
    goods[idx].state = 0;
    return 0;
}

void Buy_Good_Confirm(int idx)
{
    char ch[5];
    scanf("%s",ch);
    if(strcmp(ch , "Yes") == 0)
    {
        User *tmp = Get_User(Now_User);
        if(tmp->res < goods[idx].price)
            printf("余额不足，请前往个人信息管理充值后购买！\n");
        else if(goods[idx].state == 0 || goods[idx].state == 2)
            printf("该商品已下架或已售空，请选择其他商品购买！\n");
        else
        {
            tmp->res -= goods[idx].price; 
            printf("购买成功！\n");
            Order *tmp_order = (Order *)malloc(sizeof(Order));
            strcpy(tmp_order->good_id, goods[idx].id);
            strcpy(tmp_order->seller_id, goods[idx].SellID);
            strcpy(tmp_order->buyer_id, tmp->id);
            tmp_order->price = goods[idx].price;
            Add_Order(tmp_order); //购买成功后添加订单到文件
            printf("当前账户余额为： %.1f\n",tmp->res);
            free(tmp_order);
        }
    }
    else
        printf("%s%s已取消购买！%s\n", BOLD, FRONT_RED, RESET);
}