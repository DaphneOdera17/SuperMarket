#include "interface/interface.h"

static HANDLE handler[] = {Print_Products, Search_Good , Buy_Good , BUYER_OwnOrder, GOOD_Detail};

void BUYER_Interface() {MAKE_Interface(BUYER, handler);}

void Search_Good()
{
    printf("请输入您要查找的商品名称或ID: ");
    int idx = Search_Good_Idx();
    puts("");
    if(idx != -1)
        Print_Product(idx);
}

void Buy_Good()
{
    printf("请输入您要购买的商品名称或ID: ");
    int idx = Search_Good_Idx();
    if(idx != -1){
        printf("您确定购买此商品吗? 请输入 %s%s%sYes/No%s\n", BOLD, FRONT_RED, UNDERLINE, RESET);//Y表示确定购买 N表示取消购买
        Buy_Good_Confirm(idx);
    }
}

void BUYER_OwnOrder()
{
    User *tmp = Get_User(Now_User);
    int k = Print_BuyerOwnOrder(tmp->id);
    if (k == 0)
        printf("%s%s暂无订单%s\n", BOLD, FRONT_RED, RESET);
}

void GOOD_Detail()
{
    printf("请输入您要查找的商品名称或ID: ");
    int idx = Search_Good_Idx();
    if(idx != -1)
        Product_Info(idx);
}

int Search_Good_Idx() // 查找商品索引
{
    char good[MAX_NAME_LENGTH];
    scanf("%s",good);
    int idx = SearchGood(good);
    if(idx == -1){
        error_finding_good(), failureMessage();
        return -1;
    }
    return idx;
}