/*
 * Archivo main.c inicial generado por Glade. Edítelo como
 * lo necesite, Glade nunca sobreescribirá este archivo.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "interface.h"
#include "support.h"
#include "callbacks.h"

#include "main.h"



int
main (int argc, char *argv[])
{
  GtkWidget *window1;
//  GtkWidget *filesel1;
  //GtkWidget *cellproperties;

#ifdef ENABLE_NLS
  bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
  bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
  textdomain (GETTEXT_PACKAGE);
#endif

  gtk_set_locale ();
  gtk_init (&argc, &argv);

  #ifdef _WIN32
  #else
    add_pixmap_directory (PACKAGE_DATA_DIR "/" PACKAGE "/pixmaps");
  #endif


  /*
   * The following code was added by Glade to create one of each component
   * (except popup menus), just so that you see something after building
   * the project. Delete any components that you don't want shown initially.
   */

  //  g_warning ("mensaje de alerta en linea de comandos\n");

   initiate_common_var (&c_var);
  window1 = create_window1 ();
  gtk_widget_show (window1);

  //filesel1 = create_fileselection1 ();
  //gtk_widget_show (filesel1);

  //cellproperties = create_window_cell_properties ();
  //gtk_widget_show (cellproperties);

  gtk_main ();
  return 0;
}

