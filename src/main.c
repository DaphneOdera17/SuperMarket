#include "interface/interface.h"
#include <unistd.h>

int main()
{
    // 从文件中加载数据
    Load_User(); 
    Load_Products();
    Load_Order();

    welcomeMessage(); // 初始界面信息

    loadingMessage();
    sleep(1);
    loadingSuccess();

    MAIN_Interface(); // 进入主交互界面

    // 输出外部文件
    Out_Products();
    Out_Order();
    Out_User(); 

    exitMessage(); // 退出信息

    return 0;
}
