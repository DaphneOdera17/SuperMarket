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

typedef struct 
{
    char id[MAX_ID_LENGTH];
    char good_id[MAX_ID_LENGTH];
    double price;
    char date[MAX_TIME_LENGTH];
    char seller_id[MAX_ID_LENGTH];
    char buyer_id[MAX_ID_LENGTH];
}Order;


void Load_Products();

void Print_Products();

void Out_Products();

void Out_Order();

void Load_Order();

void Printf_Order();

void Add_Product(char * Now_User);

void Delete_Product(char *Now_User);

#endif