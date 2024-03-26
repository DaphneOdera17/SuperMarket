#ifndef _ORDER_H_
#define _ORDER_H_
#include "config.h"

typedef struct 
{
    char id[MAX_ID_LENGTH];
    char good_id[MAX_ID_LENGTH];
    double price;
    char date[MAX_TIME_LENGTH];
    char seller_id[MAX_ID_LENGTH];
    char buyer_id[MAX_ID_LENGTH];
}Order;

void Load_Order();
void Out_Order();

void Print_Orders();
void Print_SellerOwnOrder(char *id);
int Print_BuyerOwnOrder(char *id);

void Add_Order(Order *tmp);

#endif