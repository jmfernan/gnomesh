#include <gtk/gtk.h>

GdkGC *get_pen (GdkDrawable *pixmap, GdkColor *c);
GdkColor *new_color (long red, long green, long blue);
int create_pixmap_from_double (GtkWidget *widget,GdkPixmap *pixmap,double *matriz, int ancho, int alto);
void draw_brush(GtkWidget *widget, GdkDrawable *drawable, int type, gdouble x, gdouble y);
int create_pixmap_from_double_irregular (GtkWidget *widget,GdkPixmap *pixmap,double *matriz, double *horizontal_width, double *vertical_width, int ancho, int alto);
int create_pixmap_create_scale (GtkWidget *widget,GdkPixmap *pixmap, double min, double max);
int create_palete(GtkWidget *widget, GdkGC **palette,int number);
