#ifndef MENUOPTS_H // Protect file against multiple includes
#define MENUOPTS_H

/* STRUCTS */
typedef struct {
  int index;
  char *option;
  void (*action)(void);  // Function pointer to an action
} dict; // Created for key pair value

typedef struct {
  int id;
  char *title;
  dict **options; // <- From *options[]
  int opts_num;
} menu;

/* PROTOTYPES */
void print_app_title(void);
menu *create_menu(int menu_id, const char *title, int opts_num);
void add_option(menu *menu_ref, int opt_index, const char *option, void (*action)(void));
void free_memory(menu *menu_ref);

#endif // !MENUOPTS_H  
