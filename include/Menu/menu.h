#ifndef _MENU_H_
#define _MENU_H_

void Main_Menu();

typedef enum {MAIN, USER, SELLER, BUYER, ADMIN, PRODUCTS, MODIFY, INFO} Menu;

extern const int optionNumber[];

int menu(Menu type);

#endif