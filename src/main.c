#include "interface/interface.h"
#include "tools/hint.h"
#include "config.h"
#include "User/User.h"
#include "Product/Product.h"
#include "Order/Order.h"
#include <unistd.h>
#include <stdio.h>

int main()
{
    // 加载
    Load_User();
    Load_Products();
    Load_Order();

    welcomeMessage(); // 初始界面信息

    loadingMessage();
    sleep(1);
    loadingSuccess();

    MAIN_Interface();

    // 输出外部文件
    Out_Products();
    Out_Order();
    Out_User(); 

    exitMessage(); // 退出信息

    return 0;
}
