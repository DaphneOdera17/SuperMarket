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

void Print_Orders(char type);

void Add_Order(int i, char *user, char *good);

void Search_OwnOrders(char type, char *id);

#endif