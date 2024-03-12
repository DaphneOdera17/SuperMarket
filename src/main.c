#include "tools/hint.h"
#include "Menu/Main_Menu.h"
#include "User/User.h"
#include "config.h"
#include "Product/Product.h"
#include <unistd.h>

int main()
{
    welcomeMessage();
    loadingMessage();
    sleep(1);

    Load_User();
    Load_Products();

    Main_Menu();

    Out_Products();
    Out_User(); // 推出菜单后 将所有用户 打印到 .txt （因为你前面会有增 删 改） 那我增加了  推出不久保存了马 就是要保存 那我哈在喜爱买年
    return 0;
}
