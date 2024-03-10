#include "tools/hint.h"
#include "Menu/Main_Menu.h"
#include "Load/Load.h"
#include "User/User.h"
#include "config.h"
#include <unistd.h>

int main()
{
    welcomeMessage();
    loadingMessage();
    sleep(3);

    Load_User();

    Main_Menu();
    return 0;
}
