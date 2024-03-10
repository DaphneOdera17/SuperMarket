/*#include <stdio.h>
#include <string.h>
#include "tools/color.h"
#include "User/User.h"
#include "config.h"

#define N 25

void Load_User()
{
    FILE *ptr;
    // 以只读方式打开文件
    ptr = fopen("src/Data/User_Info.txt", "r");
    if(ptr == NULL)
    {
        printf("%s%s无法打开文件%s\n", BOLD, FRONT_RED, RESET);
        return ;
    }
    int k = 0;
    while(fscanf(ptr, "%s%s%s%s%s%lf", users[k].id, users[k].name, \
                 users[k].password, users[k].tel, users[k].address, \
                 &(users[k].res)) != EOF)
        k ++;
    fclose(ptr);
}

*/
