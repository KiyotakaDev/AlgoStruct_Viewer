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
  dict **options;        // <- From *options[]
} menu;

/* PROTOTYPES */
void print_app_title(void);
menu *create_menu(int menu_id, const char *title, int opts_num);
void free_memory(menu *menu_ref, int opts_num);

#endif // !MENUOPTS_H  
