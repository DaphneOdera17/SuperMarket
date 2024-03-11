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
    Out_User();
    return 0;
}
