/* INCLUDES */
#include "apprenderer.h"  // Funcs clear_terminal, app_renderer
#include "menuopts.h"     // Func print_app_title


/* ENTRY */
int main(void) {
  int u_opt = 0;

  // Static
  clear_terminal();
  print_app_title();

  // Dynamic render
  app_renderer(u_opt); 

  return 0;
}
