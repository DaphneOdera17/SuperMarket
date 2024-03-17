#include <stdio.h>
#include <string.h>
#include "Order/Order.h"
#include "tools/hint.h"
#include "tools/info.h"
#include "Admin/Admin.h"
#include "User/User.h"
#include "Product/Product.h"

static const char* FILEPATH = "src/Data/Orders.txt";
static int Total_OrdersNumber = 0; 
extern int Now_User ;
static Order orders[MAX_ORDER_NUMBER];

void Out_Order()
{
    printf("!0");
    FILE *ptr = fopen(FILEPATH,"w");
    if(ptr == NULL)
    
    {
        open_ErrorMessage();
        return ;
    }
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

void Print_Orders(char type)
{
    for(int i = 0; i < Total_OrdersNumber ; i++)
    {
        printf("%10s%10s%.1f%10s%10s%10s\n",orders[i].id , \
        orders[i].good_id , orders[i].price , \
        orders[i].date , orders[i].seller_id , \
        orders[i].buyer_id);
    }
    if(type == 'U') Buyer_Menu();
    else Admin_Menu();
}

void Add_Order(int i, char *user, Good good)
{
    Generate_ID(orders[Total_OrdersNumber].id , 'T');
    strcpy(orders[Total_OrdersNumber].good_id, good;
    Get_Time(orders[Total_OrdersNumber].date);
    orders[Total_OrdersNumber].price = goods[i].price;
    strcpy(orders[Total_OrdersNumber].seller_id , goods[i].SellID);
    strcpy(orders[Total_OrdersNumber].buyer_id , user);

    //买家买完订单后 添加订单 输入信息到txt
    FILE* ptr = fopen(FILEPATH , "w");
    fprintf(ptr, "%10s%10s%.1lf%10s%10s%10s\n", orders[Total_OrdersNumber].id , \
    orders[Total_OrdersNumber].good_id , orders[Total_OrdersNumber].price , \
    orders[Total_OrdersNumber].date , orders[Total_OrdersNumber].seller_id , \
    orders[Total_OrdersNumber].buyer_id);
    fclose(ptr);

    Total_OrdersNumber++;

}

void Search_OwnOrders(char type, char *id)
{
    int flag = 0;
    if(type =='U')
    {
        
        for(int i = 0 ; i< Total_OrdersNumber ; i++)
        {
            if(strcmp(orders[i].buyer_id, id) == 0)//用户id与所购买商品的买家id一致
            {
                flag = 1;
                printf("%s\n", orders[i].id );
            }
            
        }
        if(flag == 0)
        {
            printf("暂无购买记录！");
        }
        Buyer_Menu();
    }
    if(type =='S')
    {
        printf("您的历史订单为:\n");

        for(int i = 0 ; i < Total_OrdersNumber ; i++)
        {   
            if(strcmp(orders[i].seller_id, id) == 0)//查看谁购买了自己的商品
            {
                flag = 1 ;
                printf("购买用户：%s 商品订单：%s\n", \
                id , orders[i].id );
            }
        }
        if(flag == 0)
        {
            printf("暂无历史订单");
        }
        
        Seller_Menu(Now_User);

    }
    
    
}


