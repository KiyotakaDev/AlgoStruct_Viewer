#ifndef MENUOPTS_H // Protect file against multiple includes
#define MENUOPTS_H

/* STRUCTS */
typedef struct {
  int index;
  char *option;
} dict; // Created for key pair value

typedef struct {
  int id;
  char *title;
  dict **options;        // <- From *options[]
  void (*action)(void);  // Function pointer to an action
} menu;

/* PROTOTYPES */
void print_app_title(void);
menu *create_menu(int menu_id, const char *title, int opts_num);
void free_memory(menu *menu);

#endif // !MENUOPTS_H  
