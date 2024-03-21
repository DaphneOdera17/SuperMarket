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

void Load_Products();

void Print_Products();

void Out_Products();

int search(char *s);

Product* Get_Good(int idx);

#endif