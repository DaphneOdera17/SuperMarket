#include <stdio.h>
#include "Product/Product.h"
#include "tools/hint.h"

static const char* FILEPATH = "src/Data/Goods_Info.txt";
static int Total_ProductsNumber = 0;
static int Total_OrdersNumber = 0;
static Product goods[MAX_PRODUCT_NUMBER];
static Order orders[MAX_ORDER_NUMBER];

void Load_Products()
{
    FILE *ptr = fopen(FILEPATH, "r");

    if(ptr == NULL)
    {
        open_ErrorMessage();
        return ;
    }
    else
    {
        Total_ProductsNumber = 0;
        while(fscanf(ptr ,"%s%s%lf%s%s%s%d", goods[Total_ProductsNumber].id, \
            goods[Total_ProductsNumber].name, \
            &(goods[Total_ProductsNumber].price), goods[Total_ProductsNumber].discribe, \
            goods[Total_ProductsNumber].SellID, goods[Total_ProductsNumber].SellTime, \
            &(goods[Total_ProductsNumber].state))!= EOF)
            Total_ProductsNumber ++;
    }
    fclose(ptr);
}

void Print_Products()
{
    for(int i = 0; i < Total_ProductsNumber; i ++)
    {
        printf("%10s %10s %.1f %10s %10s %10s %d\n", goods[i].id, \
            goods[i].name, \
            goods[i].price, goods[i].discribe, \
            goods[i].SellID, goods[i].SellTime, \
            goods[i].state);
    }
}

void Out_Products()
{
    FILE *ptr = fopen(FILEPATH, "w");

    for(int i = 0; i < Total_ProductsNumber; i ++)
    {
        fprintf(ptr, "%s %s %lf %s %s %s %d\n", goods[i].id, \
            goods[i].name, \
            goods[i].price, goods[i].discribe, \
            goods[i].SellID, goods[i].SellTime, \
            goods[i].state);
    }

    fclose(ptr);
}


void Out_Order()
{
    FILE *ptr = fopen(FILEPATH,"w");
    if(ptr == NULL)
    for (int i = 0; i < Total_OrdersNumber; i++)
    {
        fprintf(ptr,"%s %s %.1f %s %s %s\n",orders[i].id , \
        orders[i].good_id , orders[i].price , \
        orders[i].date , orders[i].seller_id , \
        orders[i].buyer_id);
    }
    fclose(ptr);
}

void Load_Order()
{
    FILE *ptr = fopen(FILEPATH, "r");
    if (ptr == NULL)
    {
        open_ErrorMessage();
        return ;
    }
    else 
    {
        Total_OrdersNumber = 0;
        while(fscanf(ptr,"%s%s%lf%s%s%s",orders[Total_OrdersNumber].id,\
        orders[Total_OrdersNumber].good_id ,&orders[Total_OrdersNumber].price,\
        orders[Total_OrdersNumber].date , orders[Total_OrdersNumber].seller_id , \
        orders[Total_OrdersNumber].buyer_id) != EOF)
        Total_OrdersNumber++;
    }
    fclose(ptr);
}

void Printf_Order()
{
    for(int i = 0; i < Total_OrdersNumber ; i++)
    {
        printf("%-10s%-10s%-10.1f%-10s%-10s%-10s\n",orders[i].id , \
        orders[i].good_id , orders[i].price , \
        orders[i].date , orders[i].seller_id , \
        orders[i].buyer_id);
    }

}

