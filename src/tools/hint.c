#include "tools/hint.h"
#include "tools/color.h"
#include <stdio.h>

static const char* BANNER = "\
\t  _ __ _                             __  __            _        _       _       \n\
\t /  __ _|                           |  \\/  |          | |      | |     | |                  \n\
\t|  |__ _  _   _ _ _ _  ___  _ __    | \\  / | __ _ _ __| | _____| |_    | |\n\
\t \\_ _   \\| | | |  _  \\/ _ \\| '__|   | |\\/| |/ _` | '__| |/ / _ \\ __|   | |      \n\
\t  __ _|  | |_| | |_| |  __/| |      | |  | | (_| | |  |   <  __/ |_    |_|     \n\
\t |__ _ _/ \\ _ /|  _ _/\\___||_|      |_|  |_|\\__,_|_|  |_|\\_\\___|\\__|   (_)           \n\
\t               | |                             \n\
\t               | |                                \n\
\t               |_|                               \n\
";

static const char* GOODBYE = "\
\t                                                                            ,---,  \n\
\t                                                                         ,`--.' |  \n\
\t  ,----..                                      ,---,.                    |   :  :  \n\
\t /   /   \\                            ,---,  ,'  .'  \\                   '   '  ;  \n\
\t|   :     :    ,---.     ,---.      ,---.'|,---.' .' |                   |   |  |  \n\
\t.   |  ;. /   '   ,'\\   '   ,'\\     |   | :|   |  |: |                   '   :  ;  \n\
\t.   ; /--`   /   /   | /   /   |    |   | |:   :  :  /     .--,   ,---.  |   |  '  \n\
\t;   | ;  __ .   ; ,. :.   ; ,. :  ,--.__| |:   |    ;    /_ ./|  /     \\ '   :  |  \n\
\t|   : |.' .''   | |: :'   | |: : /   ,'   ||   :     \\, ' , ' : /    /  |;   |  ;  \n\
\t.   | '_.' :'   | .; :'   | .; :.   '  /  ||   |   . /___/ \\: |.    ' / |`---'. |  \n\
\t'   ; : \\  ||   :    ||   :    |'   ; |:  |'   :  '; |.  \\  ' |'   ;   /| `--..`;  \n\
\t'   | '/  .' \\   \\  / \\   \\  / |   | '/  '|   |  | ;  \\  ;   :'   |  / |.--,_     \n\
\t|   :    /    `----'    `----'  |   :    :||   :   /    \\  \\  ;|   :    ||    |`.  \n\
\t \\   \\ .'                        \\   \\  /  |   | ,'      :  \\  \\   \\  / `-- -`, ; \n\
\t  `---`                           `----'   `----'         \\  ' ; `----'    '---`\"  \n\
\t                                                           `--`                    \n\
";

static const char* MAIN_MENU_BANNER = "\
+============+============+==============+========+ \n\
| 1.用户登录 | 2.用户注册 | 3.管理员登录 | 4.退出 | \n\
+============+============+==============+========+ \n\
";

static const char* USER_MENU_BANNER = "\
+===========+===========+===========+===============+ \n\
| 1.注销登陆 | 2.我是买家 | 3.我是卖家 | 4.个人信息管理 | \n\
+===========+===========+===========+===============+ \n\
";

static const char* ADMIN_MENU_BANNER = "\
+================+============+===============+================+============+============+========+ \n\
| 1.查看所有商品 | 2.搜索商品 | 3.查看所有订单| 4.查看所有用户 | 5.删除用户 | 6.下架商品 | 7.注销 | \n\
+================+============+===============+================+============+============+========+ \n\
";

static const char* BUYER_MENU_BANNER = "\
+================+============+============+================+====================+==================+ \n\
| 1.查看商品列表 | 2.搜索商品 | 3.购买商品 | 4.查看历史订单 | 5.查看商品详细信息 | 6.返回用户主界面 | \n\
+================+============+============+================+====================+==================+ \n\
";

static const char* SELLER_MENU_BANNER = "\
+============+================+================+============+================+==================+ \n\
| 1.发布商品 | 2.查看发布商品 | 3.修改商品信息 | 4.下架商品 | 5.查看历史订单 | 6.返回用户主界面 | \n\
+============+================+================+============+================+==================+ \n\
";

static const char* INFO_MENU_BANNER = "\
+============+============+========+==================+ \n\
| 1.查看信息 | 2.修改信息 | 3.充值 | 4.返回用户主界面 | \n\
+============+============+========+==================+ \n\
";

static const char* FAILURE = "\t\t*** 操作失败,请重新再试! ***";
static const char* EXIT = "\t\t*** 退出成功! ***";
static const char* LOGINFAILURE = "\t\t*** 登陆失败，请重新再试！***";
static const char* LOGINSUCCESS = "\t\t*** 登陆成功！***";
static const char* DESIGNERS = "Designer: Zhang Xinyi, Huang Xueqin.";
static const char* NEXTTIME = "\t\t*** 欢迎下次再来！***";
static const char* LOADING = "\t\t***** 加载中 *****";
static const char* LOGINOUT = "\t\t*** 注销成功！***";
static const char* MAIN_MENU_TITLE = "\n\t\t+-+ Main Menu +-+";
static const char* User_MENU_TITLE = "\n\t\t+-+ User Menu +-+";
static const char* Seller_MENU_TITLE = "\n\t\t+-+ Seller Menu +-+";
static const char* Buyer_MENU_TITLE = "\n\t\t+-+ Buyer Menu +-+";
static const char* Info_MENU_TITLE = "\n\t\t+-+ Info Menu +-+";
static const char* Admin_MENU_TITLE = "\n\t\t+-+ Admin Menu +-+";

void welcomeMessage() 
{
    printf("\n%s%sWelcome to%s\n", BOLD, FRONT_RED, RESET);
    printf("%s%s%s%s\n", FRONT_BLUE, BOLD, BANNER, RESET);
    printf("%s%s%s\n\n", FRONT_PURPLR, DESIGNERS, RESET);
}

void failureMessage()
{
    printf("%s%s%s\n", FRONT_RED, FAILURE, RESET);
}

void exitMessage()
{
    printf("%s%s%s%s\n", BOLD, FRONT_RED, EXIT, RESET);
    printf("\n%s%s%s%s\n", FRONT_WHITE, BOLD, GOODBYE, RESET);
    printf("%s%s%s\n", FRONT_YELLOW, NEXTTIME, RESET);
}

void loginfailureMessage()
{
    printf("%s%s%s%s\n", BOLD, FRONT_RED, LOGINFAILURE, RESET);
}

void loginsuccessMessage()
{
    printf("%s%s%s%s\n", BOLD, FRONT_BLUE, LOGINSUCCESS, RESET);
}

void loadingMessage()
{
    printf("%s%s%s\n\n", BOLD, LOADING, RESET);
}

void main_menuMessage()
{
    printf("%s%s%s%s\n", REVERSE, BOLD, MAIN_MENU_TITLE, RESET);
    printf("\n%s%s%s", BOLD, MAIN_MENU_BANNER, RESET);
}

void buyer_menuMessage()
{
    printf("%s%s%s%s\n", REVERSE, BOLD, Buyer_MENU_TITLE, RESET);
    printf("\n%s%s%s", BOLD, BUYER_MENU_BANNER, RESET);
}

void seller_menuMessage()
{
    printf("%s%s%s%s\n", REVERSE, BOLD, Seller_MENU_TITLE, RESET);
    printf("\n%s%s%s", BOLD, SELLER_MENU_BANNER, RESET);
}

void user_menuMessage()
{
    printf("%s%s%s%s\n", REVERSE, BOLD, User_MENU_TITLE, RESET);
    printf("\n%s%s%s", BOLD, USER_MENU_BANNER, RESET);
}

void admin_menuMessage()
{
    printf("%s%s%s%s\n", REVERSE, BOLD, Admin_MENU_TITLE, RESET);
    printf("\n%s%s%s", BOLD, ADMIN_MENU_BANNER, RESET);
}

void info_menuMessage()
{
    printf("%s%s%s%s\n", REVERSE, BOLD, Info_MENU_TITLE, RESET);
    printf("\n%s%s%s", BOLD, INFO_MENU_BANNER, RESET);
}