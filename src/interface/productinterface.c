#include "interface/interface.h"
#include <stdio.h>

static HANDLE handler[] = {Modify_Name, Modify_Price, Modify_Des};

// int Now_Good = -1;

void PRODUCT_Interface()
{
    int op = menu(MAIN);
    while(op != optionNumber[MAIN]) // 操作不为退出时
    {
        loadingMessage();
        handler[op - 1](); // () 调用
        // User_Login
        op = menu(MAIN);
    }
    loadingMessage();
}

void Modify_Name() 
{
    
}

void Modify_Price()
{

}

void Modify_Des()
{
    
}