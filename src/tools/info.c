#include <stdio.h>
#include <string.h>
#include <time.h>
#include "tools/hint.h"

// 保留上一次最大的 ID
static const char* FILEPATH = "src/Data/Max_ID.txt";

// type: U-用户 G-商品 T-订单
// ID 只和时间顺序有关，如果有数据被删了，ID 也不会被新的 ID 填补
void Generate_ID(char* s, char type) // *s 也就是 字符串 对应 users[i].ID 
{
    int uid, gid, tid;
    uid = gid = tid = 0;
    // 以只读方式打开文件
    FILE* ptr = fopen(FILEPATH, "r");
    
    if(ptr == NULL)
    {
        failureMessage();
        return ;
    }
    else
    {
        fscanf(ptr, "%d%d%d", &uid, &gid, &tid);
        fclose(ptr);
    }
    
    int ID = 0;
    switch(type)
    {
        case 'U': 
            ID = uid ++;
            break;
        case 'G':
            ID = gid ++;
            break;
        case 'T':
            ID = tid ++;
            break;
    }

    sprintf(s, "%c%05d", type, ID);// 意思就是 向 s 中写入 %c%05d 这样的字符串
    ptr = fopen(FILEPATH, "w");
    // 在 filepath 文件中显示 uid mid tid 的值
    fprintf(ptr, "%d %d %d\n", uid, gid, tid);
    fclose(ptr);
}

void Get_Time(char* s)
{
    // 计算当前日历时间 time_t 格式来存储时间
    time_t time_now;
    time(&time_now);

    // tm_year 从 1900 年算起
    // tm_mon 从 0 到 11

    struct tm* TIME = localtime(&time_now);
    sprintf(s, "%d-%d-%d", TIME->tm_year + 1900, TIME->tm_mon + 1, TIME->tm_mday);
}