#include <stdio.h>
#include <string.h>
#include "Product/Product.h"
#include "tools/hint.h"
#include "tools/info.h"
#include "Admin/Admin.h"
#include "User/User.h"

static const char* FILEPATH = "src/Data/Goods_Info.txt";
static int Total_ProductsNumber = 0;
static int Total_OrdersNumber = 0;
static int Total_UserNumber = 0;
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
        while(fscanf(ptr ,"%s%s%lf%s%s%s%d%d", goods[Total_ProductsNumber].id, \
            goods[Total_ProductsNumber].name, \
            &(goods[Total_ProductsNumber].price), goods[Total_ProductsNumber].discribe, \
            goods[Total_ProductsNumber].SellID, goods[Total_ProductsNumber].SellTime, \
            &(goods[Total_ProductsNumber].cnt), &(goods[Total_ProductsNumber].state))!= EOF)
            Total_ProductsNumber ++;
    }
    fclose(ptr);
}

void Print_Products(char type)
{
    for(int i = 0; i < Total_ProductsNumber; i ++)
    {
        printf("%10s %10s %.1f %10s %10s %10s %d %d \n", goods[i].id, \
            goods[i].name, \
            goods[i].price, goods[i].discribe, \
            goods[i].SellID, goods[i].SellTime, \
            goods[i].cnt, goods[i].state);
    }
    if(type == 'U') Buyer_Menu();
    else Admin_Menu();
}

void Out_Products()
{
    FILE *ptr = fopen(FILEPATH, "w");

    for(int i = 0; i < Total_ProductsNumber; i ++)
    {
        fprintf(ptr, "%s %s %lf %s %s %s %d %d\n", goods[i].id, \
            goods[i].name, \
            goods[i].price, goods[i].discribe, \
            goods[i].SellID, goods[i].SellTime, \
            goods[i].cnt, goods[i].state);
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


void Add_Product(char *Now_User)
{
    char name[MAX_NAME_LENGTH];
    char discribe[MAX_DIS_LENGTH];
    double price;
    int cnt;

    printf("请输入商品名称：");
    scanf("%s", goods[Total_ProductsNumber].name);
    printf("请输入商品价格: ");
    scanf("%lf", &(goods[Total_ProductsNumber].price));
    printf("请输入对商品的描述： ");
    scanf("%s", goods[Total_ProductsNumber].discribe);
    printf("请输入需要添加商品的数量：");
    scanf("%d", &(goods[Total_ProductsNumber].cnt));

    Generate_ID(goods[Total_ProductsNumber].id, 'G');
    printf("该商品的id:%s\n",goods[Total_ProductsNumber].id);

    Get_Time(goods[Total_ProductsNumber].SellTime);
    printf("该商品的上架时间：%s\n",goods[Total_ProductsNumber].SellTime);
    
    strcpy(goods[Total_ProductsNumber].SellID, Now_User);

    goods[Total_ProductsNumber].state = 1;

    Total_ProductsNumber++;

    FILE* ptr = fopen(FILEPATH, "w");
    fprintf(ptr, "%s %s %lf %s %s %s %d %d\n", goods[Total_ProductsNumber].id, \
    goods[Total_ProductsNumber].name, goods[Total_ProductsNumber].price, \
    goods[Total_ProductsNumber].discribe, goods[Total_ProductsNumber].SellID, \
    goods[Total_ProductsNumber].SellTime, goods[Total_ProductsNumber].cnt, \
    goods[Total_ProductsNumber].state);
    fclose(ptr);
}


void Delete_Product(char *Now_User)
{
    char goodid[MAX_ID_LENGTH];

    printf("请输入需要删除的商品id: ");
    scanf("%s",goodid);
    
    for(int i = 0; i < Total_ProductsNumber; i++)
    {
        if (strcmp(goods[i].id , goodid) == 0)
        {
            if(strcmp("A", Now_User) == 0)
            {
                goods[i].state = 0 ;//下架后 商品状态状态为 已下架
                printf("下架成功！");
                Out_Products();
                Admin_Menu();
            }
            else
            {
                for(int i = 0; i < Total_ProductsNumber; i++)
                {
                    if(strcmp(goods[i].SellID , Now_User) == 0)
                    {
                        goods[i].state = 0 ;//下架后 商品状态状态为 已下架
                        printf("下架成功！");
                        return ;
                    }
                }
                printf("您不是该商品的发布者，无法下架该商品!");
                Seller_Menu(*Now_User);
                return ;
            }
            
        }
    }         
    printf("未查询到该商品！");
    Seller_Menu(*Now_User);
}

void Search_Product()
{
    printf("请输入您要查找的商品名称：");

}
