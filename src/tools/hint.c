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
+==========+==========+==============+==============+=========+ \n\
|ID        |用户名    |联系方式      |地址          |余额     | \n\
+----------+----------+--------------+--------------+---------+ \n\
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
static const char* OPEN_ERROR = "\t\t*** 打开文件失败！ ***";
static const char* SUCCESSFUL = "\t\t*** 操作成功！***";
static const char* ERRO_FINDING_USER = "\t\t*** 未找到该用户！***";

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
    printf("\n%s%s%s%s\n", FRONT_RED, BOLD, GOODBYE, RESET);
    printf("%s%s%s\n", FRONT_YELLOW, NEXTTIME, RESET);
}

void loginfailureMessage(){printf("%s%s%s%s\n", BOLD, FRONT_RED, LOGINFAILURE, RESET);}

void loginsuccessMessage(){printf("%s%s%s%s\n", BOLD, FRONT_BLUE, LOGINSUCCESS, RESET);}

void loadingMessage(){printf("%s%s%s\n\n", BOLD, LOADING, RESET);}

void open_ErrorMessage(){printf("%s%s%s%s\n", BOLD, FRONT_RED , OPEN_ERROR , RESET);}

void Print_UserInfo_Banner(){printf("%s%s%s", BOLD, USER_INFO_BANNER, RESET);}

void successful(){printf("%s%s%s\n", BOLD, SUCCESSFUL, RESET);}

void error_finding_user(){printf("%s%s%s\n", FRONT_RED, ERRO_FINDING_USER, RESET);}