/* INCLUDES */
#include "apprenderer.h"  // Funcs clear_terminal, app_renderer
#include "menuopts.h"     // Func print_app_title


/* ENTRY */
int main(void) {
  int current_menu = 0, u_opt = 0;

  do {

    // Static
    clear_terminal();
    print_app_title();

    // Dynamic render
    app_renderer(&current_menu, &u_opt); 

  } while (u_opt != 0);

  return 0;
}
