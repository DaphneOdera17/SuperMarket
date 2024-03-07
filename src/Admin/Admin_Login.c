#include<stdio.h>
#include <stdlib.h>

void Admin_Login()
{

    char name[20];
    char password[20] = '\0';

    printf("请输入管理员姓名:  ");
    scanf("%s",&name);
    getchar();

    int i = 0;
    printf("请输入密码:  ");
    while (i < 20)
    {
        system("stty -echo");
        password[i] = getchar();
        system("stty -echo");
        if(password[i++] == '\n')
        {
            break;
            printf("*");
        }
    }
    
    
    

}