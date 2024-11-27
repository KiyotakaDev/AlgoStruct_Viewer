#include "menuopts.h"

#ifndef MENUS_H // Protect file against multiple includes
#define MENUS_H

/* DEFINES */
#define MAIN_OPTS 3
#define ALGO_OPTS 5

/* PROTOTYPES */
menu *create_main_menu(void);
menu *create_algorithms_menu(void);
menu *error_menu_handler(void);
menu *menu_to_render(int menu_id);

#endif // !MENUS_H  
