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
  new_menu->opts_num = opts_num;
  
  // Allocating memory for options (dict *)pointer size
  new_menu->options = malloc(opts_num * sizeof(dict *));

  return new_menu;
}

void add_option(menu *menu_ref, int opt_index, const char *option, void (*action)(void)) {
  if (opt_index < 0 || opt_index > menu_ref->opts_num) {
    printf("\tInvalid index size\n");
    return;
  }

  menu_ref->options[opt_index] = malloc(sizeof(dict));
  menu_ref->options[opt_index]->index = opt_index;
  menu_ref->options[opt_index]->option = (char *)option;
  menu_ref->options[opt_index]->action = action;
}

void free_memory(menu *menu_ref) {
  int size = menu_ref->opts_num;
  for (int i = 0; i < size; i++) {
    if (menu_ref->options[0] != NULL)
      free(menu_ref->options[i]);
  }
  free(menu_ref->options);
  free(menu_ref);
  menu_ref = NULL;
}
