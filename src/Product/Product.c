#include "interface/interface.h"
#include <stdio.h>
#include <string.h>

static const char* FILEPATH = "src/Data/Goods_Info.txt";
static int Total_ProductsNumber = 0;
Product goods[MAX_PRODUCT_NUMBER];
extern int Now_User;

// 返回结构指针 
Product* Get_Good(int idx) {return goods + idx;}

// 从文件 src/Data/Goods_Info.txt 中读取数据到 goods 结构体数组中
void Load_Products()
{
    FILE *ptr = fopen(FILEPATH, "r");
    while(fscanf(ptr ,"%s%s%lf%s%s%s%d%d", goods[Total_ProductsNumber].id, goods[Total_ProductsNumber].name,\
        &(goods[Total_ProductsNumber].price), goods[Total_ProductsNumber].discribe, goods[Total_ProductsNumber].SellID, goods[Total_ProductsNumber].SellTime, &(goods[Total_ProductsNumber].cnt), &(goods[Total_ProductsNumber].state))!= EOF)
            Total_ProductsNumber ++;
    fclose(ptr);
}

void Print_Products()
{
    for(int i = 0; i < Total_ProductsNumber; i ++)
        printf("%10s %10s %.1f %10s %10s %10s %d %d \n", goods[i].id, goods[i].name, goods[i].price, goods[i].discribe, \
            goods[i].SellID, goods[i].SellTime, goods[i].cnt, goods[i].state);
}

void Print_OwnProduct(char *id)
{
    for(int i = 0; i < Total_ProductsNumber; i ++)
    {
        if(strcmp(goods[i].SellID, id) == 0)
            printf("%10s %10s %.1f %10s %10s %10s %d %d \n", goods[i].id, goods[i].name, goods[i].price, goods[i].discribe, \
            goods[i].SellID, goods[i].SellTime, goods[i].cnt, goods[i].state);

    }     
}

void Info_Product(Product *Good)
{
    printf("商品id: %s\n", Good->id);
    printf("商品名称: %s\n", Good->name);
    printf("商品价格: %s\n", Good->price);
    printf("卖家id: %s\n", Good->SellID);
    printf("商品上架时间: %s\n", Good->SellTime);
    printf("商品数量: %s\n", Good->cnt);
    printf("商品状态: %s\n", Good->state);    
}

void Out_Products()
{
    FILE *ptr = fopen(FILEPATH, "w");
    for(int i = 0; i < Total_ProductsNumber; i ++)
        fprintf(ptr, "%s %s %lf %s %s %s %d %d\n", goods[i].id, goods[i].name, \
            goods[i].price, goods[i].discribe, goods[i].SellID, goods[i].SellTime, goods[i].cnt, goods[i].state);
    fclose(ptr);
}

int SearchGood(char *s)
{
    for(int i = 0 ; i < Total_ProductsNumber ; i++)
        if(strcmp(s, goods[i].id) == 0 || strcmp(s, goods[i].name) == 0)
            return i;
    return -1;
}


void Add_Product(Product *tmp)
{
    Generate_ID(tmp->id, 'G');
    Get_Time(tmp->SellTime);
    tmp->state = 1;
    goods[Total_ProductsNumber ++] = *tmp;
    /*
    char name[MAX_NAME_LENGTH];
    char discribe[MAX_DIS_LENGTH];

    User *tmp = Get_User(Now_User);

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
    strcpy(goods[Total_ProductsNumber].SellID, tmp->id);
    goods[Total_ProductsNumber ++].state = 1;
    */
}

int Delete_Product(char *s)
{
    int idx = SearchGood(s);
    // 未找到商品或者名字bu匹配且不是管理与 管理员可以随便山
    if(idx == -1)
        return -1;
    
    goods[idx].state = 0;
    return 0;
    /*
    char goodid[MAX_ID_LENGTH];

    printf("请输入需要删除的商品id: ");
    scanf("%s",goodid);
    
    User *tmp = Get_User(Now_User);

    for(int i = 0; i < Total_ProductsNumber; i++)
    {
        if (strcmp(goods[i].id , goodid) == 0)
        {
            if(strcmp("A", *(tmp->name) == 0))
            {
                goods[i].state = 0 ;//下架后 商品状态状态为 已下架
                printf("下架成功！");
                Out_Products();
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
                return ;
            }
        }
    }         
    printf("未查询到该商品！");
    Seller_Menu(*Now_User);
    */
}

/*
void Search_Product(char type)
{
//可以按照商品名称商品名称查找商品
    char a[MAX_NAME_LENGTH];

    printf("请输入您要查找的商品名称或商品id: ");
    scanf("%s", a);
    extern int Now_User;

    int flag = search(a);
    if(flag == -1)
    {
        printf("未查找到商品！");
        if(type == 'U') Buyer_Menu();
        else if (type == 'A') Admin_Menu();
        else Seller_Menu(Now_User);
    }
    else
    {
        printf("商品id:%s \n", goods[flag].id );
        printf("商品名称：%s \n",goods[flag].name);
        printf("商品价格：%.1f\n", goods[flag].price);
        printf("商品描述：%s\n",goods[flag].discribe);
        printf("上架时间：%s\n",goods[flag].SellTime);
        printf("剩余数量：%d\n",goods[flag].cnt);
        /*
        switch(goods[flag].state)
        {
            case 0: printf("商品状态： 已下架 "); break;
            case 1: printf("商品状态： 在售中 "); break;
            case 2: printf("商品状态： 已售空 "); break;
        }
    }
}
*/