/* INCLUDES */
#include <stdio.h>
#include <stdlib.h>


/* PROTOTYPES */
void clear_screen(void);


/* INIT */
int main(void) {
  int opt;

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

  // Print options
  printf("\n");
  printf("\t*****************************\n");
  printf("\t* What do you want to view? *\n");
  printf("\t* 1. Data Structures        *\n");
  printf("\t* 2. Algorithms             *\n");
  printf("\t* 3. Exit                   *\n");
  printf("\t*****************************\n");

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
