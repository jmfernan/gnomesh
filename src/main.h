/***************************************************************************
                          main.h  -  description
                             -------------------
    begin                : dom dic 22 2002
    copyright            : (C) 2002 by José Manuel Fernandez Jaramillo
    email                : jmfernan@perseus.unalmed.edu.co
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

 #ifndef TRUE
  #define TRUE 1
 #endif
 #ifndef FALSE
  #define FALSE 0
 #endif
 
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <math.h>

 #include <gdk/gdkkeysyms.h>
 #include <gtk/gtk.h>

 #include "base_structures.h"
 #include "leer_archivo.h"
 #include "object_admin.h"
 #include "file_plot.h"
 #include "vec2ras.h"
 #include "export_bathymetry_elcom.h"
 #include "gtk_routines.h" 


 #define PALETTENUMBER 4 
 /*Global variables*/

 //struct file_data file_datas;
 struct common_var c_var;

 struct file_data file_datas;

 static GdkPixmap *pixmap2 = NULL;
 static GdkPixmap *pixmap3 = NULL;
 static GdkPixmap *pixmap4 = NULL; 
 static GdkPixmap *pixmap5 = NULL;   
 static GdkPixmap *pixmap6 = NULL;
 static GdkPixmap *pixmap7 = NULL;
 static GdkPixmap *pixmap8 = NULL;
 static GdkPixmap *pixmap9 = NULL;
 static GdkPixmap *pixmap10 = NULL;
 static GdkPixmap *pixmap11 = NULL;
 static GdkPixmap *pixmap12 = NULL;
 static GdkPixmap *pixmap13 = NULL;
 static GdkPixmap *pixmap14 = NULL;
 static GdkPixmap *pixmap15 = NULL;
 static GdkPixmap *pixmap16 = NULL;
 static GdkPixmap *pixmap17 = NULL;
 static GdkPixmap *pixmap18 = NULL;
 static GdkPixmap *pixmap19 = NULL;