#include "tools/hint.h"
#include "Menu/Main_Menu.h"
#include "Load/Load_User.h"

int main()
{
    welcomeMessage();
    Load_User();

    Main_Menu();
    return 0;
}
