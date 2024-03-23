#ifndef _PRODUCT_H_
#define _PRODUCT_H_

#include "config.h"

typedef struct 
{
    char id[MAX_ID_LENGTH];
    char name[MAX_NAME_LENGTH];
    double price;
    char discribe[MAX_DIS_LENGTH];
    char SellID[MAX_ID_LENGTH];
    char SellTime[MAX_TIME_LENGTH];
    int cnt;
    int state;
    // state 有 3 种情况：
    // 0 为已经下架
    // 1 为销售中
    // 2 为已售出
}Product;

Product* Get_Good(int idx);
char *Get_State(int state);

void Load_Products();
void Out_Products();

void Print_Product(int idx);
void Print_Products();
void Print_OwnProduct(char *id);
void Product_Info(int idx);

int SearchGood(char *s);

void Buy_Good_Confirm(int idx);

void Add_Product(Product *tmp);
int Delete_Product(char *s);

#endif