#include <stdio.h>
#include <stdlib.h>
#include "ansi.h"
#include "menuopts.h"

void print_app_title(void) {
    printf("\n");
    printf("%s", CYAN);
    printf("\t █████╗ ██╗      ██████╗  ██████╗ ███████╗████████╗██████╗ ██╗   ██╗ ██████╗████████╗\n");
    printf("\t██╔══██╗██║     ██╔════╝ ██╔═══██╗██╔════╝╚══██╔══╝██╔══██╗██║   ██║██╔════╝╚══██╔══╝\n");
    printf("\t███████║██║     ██║  ███╗██║   ██║███████╗   ██║   ██████╔╝██║   ██║██║        ██║\n");
    printf("\t██╔══██║██║     ██║   ██║██║   ██║╚════██║   ██║   ██╔══██╗██║   ██║██║        ██║\n");
    printf("\t██║  ██║███████╗╚██████╔╝╚██████╔╝███████║   ██║   ██║  ██║╚██████╔╝╚██████╗   ██║\n");
    printf("\t╚═╝  ╚═╝╚══════╝ ╚═════╝  ╚═════╝ ╚══════╝   ╚═╝   ╚═╝  ╚═╝ ╚═════╝  ╚═════╝   ╚═╝\n");
    printf("%s", RESET);
}

menu *create_menu(int menu_id, const char *title, int opts_num) {
  menu *new_menu = malloc(sizeof(menu));  // Allocating memory for memory struct
  // Assigning values
  new_menu->id = menu_id;
  new_menu->title = (char *)title;
  
  // Allocating memory for options (dict *)pointer size
  // new_menu->options = malloc(opts_num * sizeof(dict *));

  return new_menu;
}

void free_memory(menu *menu) {
  // free(menu->options);
  free(menu);
  menu = NULL;
}
