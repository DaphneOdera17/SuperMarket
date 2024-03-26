#include "interface/interface.h"
#include <stdio.h>
#include <string.h>

static const char* FILEPATH = "src/Data/Orders.txt";
static int Total_OrdersNumber = 0; 
extern int Now_User;
static Order orders[MAX_ORDER_NUMBER];

void Load_Order()
{
    FILE *ptr = fopen(FILEPATH, "r");
    while(fscanf(ptr,"%s%s%lf%s%s%s",orders[Total_OrdersNumber].id,orders[Total_OrdersNumber].good_id ,&orders[Total_OrdersNumber].price,\
        orders[Total_OrdersNumber].date , orders[Total_OrdersNumber].seller_id , orders[Total_OrdersNumber].buyer_id) != EOF)
            Total_OrdersNumber++;
    fclose(ptr);
}

void Out_Order()
{
    FILE *ptr = fopen(FILEPATH,"w");
    for (int i = 0; i < Total_OrdersNumber; i++)
        fprintf(ptr,"%s %s %.1f %s %s %s\n",orders[i].id , orders[i].good_id , orders[i].price , \
        orders[i].date , orders[i].seller_id , orders[i].buyer_id);
    fclose(ptr);
}

void Print_Orders()
{
    Print_OrderInfo_Banner();
    for(int i = 0; i < Total_OrdersNumber ; i++){
        printf("|%-10s |%-10s |%-5.1f |%-10s |%-10s |%-10s |\n",orders[i].id , orders[i].good_id , orders[i].price , \
            orders[i].date, orders[i].seller_id , orders[i].buyer_id);
        printf("%s--------------------------------------------------------------------%s\n", BOLD, RESET);}
}

int Print_SellerOwnOrder(char *id)
{
    int flag = 0;
    for(int i = 0; i < Total_OrdersNumber; i ++)
    {
        if(strcmp(orders[i].seller_id, id) == 0)
        {
            printf("购买用户：%s 商品订单：%s\n", id, orders[i].id );
            flag = 1;
        }
    }  
    return flag; 
}

int Print_BuyerOwnOrder(char *id)
{
    int flag = 0;
    for(int i = 0; i < Total_OrdersNumber; i ++)
    {
        if(strcmp(orders[i].buyer_id, id) == 0){
            printf("商品订单：%s 商品卖家：%s \n", orders[i].id , orders[i].seller_id );
            flag = 1;
        }
    }
    return flag;
}

void Add_Order(Order *tmp)
{
    Generate_ID(tmp->id, 'T');
    Get_Time(tmp->date);
    orders[Total_OrdersNumber ++] = *tmp;
}
