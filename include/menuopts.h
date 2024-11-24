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
  dict *options[];
} menu;


#endif // !MENUOPTS_H  
