#include "tools/hint.h"
#include "Menu/Main_Menu.h"
#include "Load/Load_User.h"
#include "config.h"

int main()
{
    welcomeMessage();
    loadingMessage();
    Load_User();

    Main_Menu();
    return 0;
}
