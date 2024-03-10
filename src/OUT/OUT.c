#include<stdio.h>
#include<string.h>
#include "OUT/OUT.h"
#include "tools/color.h"
#include "config.h"
#include "User/User.h"
#include "tools/hint.h"

/*
void Out_User()
{
    FILE* ptr;
    ptr = fopen("src/Data/User_Info.txt" , "w");
    if (fopen == NULL)
    {
        openErrorMessage();
        return ;
    }
    else
    {
        for(int i = 0; i < MAX_USER_NUMBER ; i++)
        {
            fprintf(ptr,"%s %s %s %s %s %.1f\n", users[i].id , users[i].name , users[i].password , users[i].tel , users[i].address , users[i].res);
        }
        fclose(ptr);
        
    }



}
*/