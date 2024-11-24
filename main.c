/* INCLUDES */
#include <stdio.h>
#include <stdlib.h>
#include "printer.h"


/* PROTOTYPES */
void clear_screen(void);


/* INIT */
int main(void) {
  int opt, err = 0;;

  do {
    clear_screen();
    print_app_title();
    print_main_menu(err);

    // Get user input
    printf("\t$ ");
    scanf("%d", &opt);

    // Menu options
    switch (opt) {
      case 1:
        // TODO: Go to Alogirthms section
        break;
      case 2:
        // TODO: Go to data structures section
        break;
      case 3:
        printf("\tExiting program... Godbye!\n\n");
        break;
      default:
        err = 1;
    }

    // Clear buffer fix: #1
    while(getchar() != '\n');

  } while (opt != 3);

  return 0;
}


/* Functions */
void clear_screen(void) {
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}
