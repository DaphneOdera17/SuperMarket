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

static const char* FAILURE = "\t\t*** 操作失败,请重新再试! ***";

void welcomeMessage() 
{
    printf("\n%s%sWelcome to%s\n", BOLD, FRONT_RED, RESET);
    printf("%s%s%s%s\n", FRONT_BLUE, BOLD, BANNER, RESET);
    printf("%sDesigner: Zhang Xinyi, Huang Xueqin.%s\n\n", FRONT_PURPLR, RESET);
}

void failureMessage()
{
    printf("%s%s%s\n", FRONT_RED, FAILURE, RESET);
}

