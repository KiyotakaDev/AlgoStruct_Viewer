/* INCLUDES */
#include <stdio.h>
#include <stdlib.h>


/* PROTOTYPES */
void clear_screen(void);


/* INIT */
int main(void) {
  int opt, err = 0;;

  do {
    // Clear screen
    clear_screen();

    // Print title 
    printf("\n");
    printf("\t █████╗ ██╗      ██████╗  ██████╗ ███████╗████████╗██████╗ ██╗   ██╗ ██████╗████████╗\n");
    printf("\t██╔══██╗██║     ██╔════╝ ██╔═══██╗██╔════╝╚══██╔══╝██╔══██╗██║   ██║██╔════╝╚══██╔══╝\n");
    printf("\t███████║██║     ██║  ███╗██║   ██║███████╗   ██║   ██████╔╝██║   ██║██║        ██║\n");
    printf("\t██╔══██║██║     ██║   ██║██║   ██║╚════██║   ██║   ██╔══██╗██║   ██║██║        ██║\n");   
    printf("\t██║  ██║███████╗╚██████╔╝╚██████╔╝███████║   ██║   ██║  ██║╚██████╔╝╚██████╗   ██║\n");
    printf("\t╚═╝  ╚═╝╚══════╝ ╚═════╝  ╚═════╝ ╚══════╝   ╚═╝   ╚═╝  ╚═╝ ╚═════╝  ╚═════╝   ╚═╝\n"); 

    // Print menu
    printf("\n");
    printf("\t*****************************\n");
    printf("\t* What do you want to view? *\n");
    printf("\t* (1) Algorithms            *\n");
    printf("\t* (2) Data Structures       *\n");
    printf("\t* (3) Exit                  *\n");
    printf("\t*****************************\n");
    if (err == 1) {
      printf("\t*       Invalid Input       *\n");
      printf("\t*****************************\n");
    }

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

    // Clear buffer
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
