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

static const char* USER_INFO_BANNER = "\
+===========+===========+===========+===========+===============+===========+ \n\
|ID         |用户名     |密码       |联系方式   |地址           |余额       | \n\
+-----------+-----------+-----------+-----------+---------------+-----------+ \n\
";

static const char* PRODUCT_INFO_BANNER = "\
+===============+===============+=======+===============+==========+==========+====+========+ \n\
|商品ID         |商品名称       |价格   |商品描述       |卖家ID    |上架时间  |库存|商品状态| \n\
+---------------+---------------+-------+---------------+----------+----------+----+--------+ \n\
";

static const char* SINGLE_PRODUCT_INFO_BANNER = "\
|商品ID         |商品名称       |价格   |上架时间  |库存|商品状态| \n\
+---------------+---------------+-------+----------+----+--------+ \n\
";

static const char* ORDER_INFO_BANNER = "\
+===========+===========+======+===========+===========+===========+ \n\
|订单编号   |商品ID     |价格  |交易日期   |卖家ID     |买家ID     | \n\
+-----------+-----------+------+-----------+-----------+-----------+ \n\
";

static const char* FAILURE = "\t\t*** 操作失败,请重新再试! ***";
static const char* EXIT = "\t\t*** 退出成功! ***";
static const char* LOGINFAILURE = "\t\t*** 登陆失败，请重新再试！***";
static const char* LOGINSUCCESS = "\n\t\t*** 登陆成功！***";
static const char* DESIGNERS = "Designer: Zhang Xinyi, Huang Xueqin.";
static const char* NEXTTIME = "\t\t*** 欢迎下次再来！***";
static const char* LOADING = "\n\t\t***** 加载中 *****";
static const char* LOADINGSUCCESS = "\t\t*** 加载成功! ***";
static const char* LOGINOUT = "\t\t*** 注销成功！***";
static const char* MAIN_MENU_TITLE = "\n\t\t+-+ Main Menu +-+";
static const char* User_MENU_TITLE = "\n\t\t+-+ User Menu +-+";
static const char* Seller_MENU_TITLE = "\n\t\t+-+ Seller Menu +-+";
static const char* Buyer_MENU_TITLE = "\n\t\t+-+ Buyer Menu +-+";
static const char* Info_MENU_TITLE = "\n\t\t+-+ Info Menu +-+";
static const char* Admin_MENU_TITLE = "\n\t\t+-+ Admin Menu +-+";
static const char* OPEN_ERROR = "\t\t*** 打开文件失败！ ***";
static const char* SUCCESSFUL = "\t\t*** 操作成功！***";
static const char* ERRO_FINDING_USER = "\t\t*** 未找到该用户！***";
static const char* ERRO_FINDING_GOOD = "\t\t*** 未找到该商品！***";
static const char* FAILTOADDGOOD = "\t\t*** 该商品已存在! ***";

void welcomeMessage() 
{
    printf("\n%s%sWelcome to%s\n", BOLD, FRONT_RED, RESET);
    printf("%s%s%s%s\n", FRONT_BLUE, BOLD, BANNER, RESET);
    printf("%s%s%s\n\n", FRONT_PURPLR, DESIGNERS, RESET);
}

void failureMessage() {printf("%s%s%s\n", FRONT_RED, FAILURE, RESET);}

void exitMessage()
{
    printf("%s%s%s%s\n", BOLD, FRONT_RED, EXIT, RESET);
    printf("\n%s%s%s%s\n", FRONT_RED, BOLD, GOODBYE, RESET);
    printf("%s%s%s\n", FRONT_YELLOW, NEXTTIME, RESET);
}

void loginfailureMessage(){printf("%s%s%s%s\n\n", BOLD, FRONT_RED, LOGINFAILURE, RESET);}

void loginsuccessMessage(){printf("%s%s%s%s\n\n", BOLD, FRONT_BLUE, LOGINSUCCESS, RESET);}

void loadingMessage(){printf("%s%s%s\n\n", BOLD, LOADING, RESET);}

void loadingSuccess(){printf("%s%s%s%s\n\n", BOLD, FRONT_RED, LOADINGSUCCESS, RESET);}

void open_ErrorMessage(){printf("%s%s%s%s\n", BOLD, FRONT_RED , OPEN_ERROR , RESET);}

void Print_UserInfo_Banner(){printf("%s%s%s", BOLD, USER_INFO_BANNER, RESET);}

void successMessage(){printf("%s%s%s\n\n", BOLD, SUCCESSFUL, RESET);}

void error_finding_user(){printf("%s%s%s\n", FRONT_RED, ERRO_FINDING_USER, RESET);}

void error_finding_good(){printf("%s%s%s\n",FRONT_RED, ERRO_FINDING_GOOD, RESET);}

void FailToAddGood() {printf("%s%s%s%s", BOLD, FRONT_RED, FAILTOADDGOOD, RESET);}

void Print_GoodInfo_Banner(){printf("%s%s%s", BOLD, PRODUCT_INFO_BANNER, RESET);}

void Print_SingleGood_Banner(){printf("%s%s%s", BOLD, SINGLE_PRODUCT_INFO_BANNER, RESET);}

void Print_OrderInfo_Banner(){printf("%s%s%s", BOLD,  ORDER_INFO_BANNER, RESET);}
