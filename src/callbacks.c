#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "main.h"

void
on_nuevo1_activate (GtkMenuItem * menuitem, gpointer user_data)
{

}


void
on_abrir1_activate (GtkMenuItem * menuitem, gpointer user_data)
{
  GtkWidget *filesel1;
  filesel1 = create_fileselection1 ();
  gtk_widget_show (filesel1);

  //printf("abrir archivo\n");
}


void
on_guardar1_activate (GtkMenuItem * menuitem, gpointer user_data)
{
  GtkWidget *filesel2;
  filesel2 = create_fileselection2 ();
  gtk_widget_show (filesel2);

  //printf("abrir archivo\n");

}


void
on_guardar_como1_activate (GtkMenuItem * menuitem, gpointer user_data)
{

}


void
on_salir1_activate (GtkMenuItem * menuitem, gpointer user_data)
{

}


void
on_cortar1_activate (GtkMenuItem * menuitem, gpointer user_data)
{

}


void
on_copiar1_activate (GtkMenuItem * menuitem, gpointer user_data)
{

}


void
on_pegar1_activate (GtkMenuItem * menuitem, gpointer user_data)
{

}


void
on_borrar1_activate (GtkMenuItem * menuitem, gpointer user_data)
{

}


void
on_about1_activate (GtkMenuItem * menuitem, gpointer user_data)
{

}


void
on_window1_destroy (GtkObject * object, gpointer user_data)
{
  exit (0);
}


gboolean
on_drawingarea1_configure_event (GtkWidget * widget,
				 GdkEventConfigure * event,
				 gpointer user_data)
{
//  printf("drawingarea1 configure\n");
  return FALSE;
}


gboolean
on_drawingarea1_expose_event (GtkWidget * widget,
			      GdkEventExpose * event, gpointer user_data)
{
  //printf("drawingarea1 expose\n");
  return FALSE;
}


gboolean
on_drawingarea1_motion_notify_event (GtkWidget * widget,
				     GdkEventMotion * event,
				     gpointer user_data)
{
  //printf("drawingarea1 motion\n");
  return FALSE;
}


gboolean
on_drawingarea1_button_press_event (GtkWidget * widget,
				    GdkEventButton * event,
				    gpointer user_data)
{
  //printf("drawingarea1 button\n");
  return FALSE;
}


void
on_fileselection1_destroy (GtkObject * object, gpointer user_data)
{
  //printf("fileselection destroy\n");
}


void
on_fileselection1_close (GtkDialog * dialog, gpointer user_data)
{
  //printf("fileselection close\n");


}


void
on_fileselection1_response (GtkDialog * dialog,
			    gint response_id, gpointer user_data)
{
  //printf("fileselection response\n");


}


void
on_open_button_activate (GtkButton * button, gpointer user_data)
{
  GtkWidget *filesel1;
  filesel1 = create_fileselection1 ();
  gtk_widget_show (filesel1);

}


void
on_fileselection1_ok_button1_clicked (GtkButton * button, gpointer user_data)
{
  int i;
  //read_file (gtk_file_selection_get_filename (GTK_FILE_SELECTION (button)),&file_datas);
  c_var.actualmap++;

  //set the default values for the variables
  c_var.mapsvector[c_var.actualmap].raster_ncol = 10;
  c_var.mapsvector[c_var.actualmap].raster_nrow = 10;

  c_var.mapsvector[c_var.actualmap].raster_mesh_ncol = 0;
  c_var.mapsvector[c_var.actualmap].raster_mesh_nrow = 0;

  
  c_var.mapsvector[c_var.actualmap].file_datas.linkpoints = NULL;
  c_var.mapsvector[c_var.actualmap].file_datas.linklines = NULL;
  c_var.mapsvector[c_var.actualmap].file_datas.linkcircles = NULL;
  c_var.mapsvector[c_var.actualmap].file_datas.linktexts = NULL;

  c_var.mapsvector[c_var.actualmap].raster_data =
    (double *) g_malloc (sizeof (double) *
			 c_var.mapsvector[c_var.actualmap].raster_ncol *
			 c_var.mapsvector[c_var.actualmap].raster_nrow);
  c_var.mapsvector[c_var.actualmap].raster_mask =
    (int *) g_malloc (sizeof (int) *
		      c_var.mapsvector[c_var.actualmap].raster_ncol *
		      c_var.mapsvector[c_var.actualmap].raster_nrow);
  c_var.mapsvector[c_var.actualmap].raster_data_interpolated =
    (double *) g_malloc (sizeof (double) *
			 c_var.mapsvector[c_var.actualmap].raster_ncol *
			 c_var.mapsvector[c_var.actualmap].raster_nrow);

  c_var.mapsvector[c_var.actualmap].horizontal_mesh =
    (int *) g_malloc (sizeof (int) *
		      (c_var.mapsvector[c_var.actualmap].raster_ncol + 1));
  c_var.mapsvector[c_var.actualmap].vertical_mesh =
    (int *) g_malloc (sizeof (int) *
		      (c_var.mapsvector[c_var.actualmap].raster_nrow + 1));

  c_var.mapsvector[c_var.actualmap].horizontal_mesh_width = NULL;
  c_var.mapsvector[c_var.actualmap].vertical_mesh_width = NULL;

  for (i = 0; i < c_var.mapsvector[c_var.actualmap].raster_ncol + 1; i++)
    {
      c_var.mapsvector[c_var.actualmap].horizontal_mesh[i] = 0;
    }
  for (i = 0; i < c_var.mapsvector[c_var.actualmap].raster_nrow + 1; i++)
    {
      c_var.mapsvector[c_var.actualmap].vertical_mesh[i] = 0;
    }
  c_var.mapsvector[c_var.actualmap].raster_mesh = NULL;
  c_var.mapsvector[c_var.actualmap].raster_mesh_advection_number = NULL;
  c_var.mapsvector[c_var.actualmap].raster_mesh_standar_desviation = NULL;
  c_var.mapsvector[c_var.actualmap].raster_mesh_aspect_ratio = NULL;
  c_var.mapsvector[c_var.actualmap].raster_mesh_gradient_horizontal = NULL;
  c_var.mapsvector[c_var.actualmap].raster_mesh_gradient_vertical = NULL;

  c_var.mapsvector[c_var.actualmap].courant_dt = -1;
  c_var.mapsvector[c_var.actualmap].courant_max_speed = -1;
  c_var.mapsvector[c_var.actualmap].courant_dx = -1;

  c_var.mapsvector[c_var.actualmap].brush_level = 0;
  c_var.mapsvector[c_var.actualmap].open_boundary = 8888;
  c_var.mapsvector[c_var.actualmap].land_boundary = 9999;

  c_var.mapsvector[c_var.actualmap].interpolation_maxiter = 1000;
  c_var.mapsvector[c_var.actualmap].interpolation_precision = .01;
  //c_var.mapsvector[c_var.actualmap].raster_data = (double *)g_malloc(sizeof(double)*1);
  //c_var.mapsvector[c_var.actualmap].raster_mask = (int *)g_malloc(sizeof(int)*1);
  //printf("archivos abiertos:%d\n",c_var.actualmap+1);
  read_dxf_file (gtk_file_selection_get_filename
		 (GTK_FILE_SELECTION (button)),
		 &c_var.mapsvector[c_var.actualmap].file_datas);

  (void) domain_box (&c_var.mapsvector[c_var.actualmap].file_datas,
		     &c_var.mapsvector[c_var.actualmap].xmin,
		     &c_var.mapsvector[c_var.actualmap].xmax,
		     &c_var.mapsvector[c_var.actualmap].ymin,
		     &c_var.mapsvector[c_var.actualmap].ymax,
		     &c_var.mapsvector[c_var.actualmap].zmin,
		     &c_var.mapsvector[c_var.actualmap].zmax);

}


void
  on_fileselection1_cancel_button1_clicked
  (GtkButton * button, gpointer user_data)
{

}


gboolean
on_window1_configure_event (GtkWidget * widget,
			    GdkEventConfigure * event, gpointer user_data)
{
  //se ejecuta cada que la ventana se mueve
  //printf("me estoy ejecutando como configuracion\n");
  return FALSE;
}


int
initiate_common_var (struct common_var *variable)
{
  //printf("iniciando comunes\n");

  variable->mapsnumber = 0;;
  variable->actualmap = -1;
  variable->button_mesh_active = 0;
  variable->mapsvector = (struct map *) g_malloc (sizeof (struct map *) * 10);
  //variable->
  return (0);
}



gboolean
on_drawingarea2_configure_event (GtkWidget * widget,
				 GdkEventConfigure * event,
				 gpointer user_data)
{
  //printf("configure drawing area2\n");

  if (pixmap2)
    {
      gdk_pixmap_unref (pixmap2);
    }

  pixmap2 = gdk_pixmap_new (widget->window,
			    widget->allocation.width,
			    widget->allocation.height, -1);
  if (c_var.mapsvector[c_var.actualmap].raster_data != NULL
      && c_var.actualmap > -1)
    {
      create_pixmap_from_double (widget, pixmap2,
				 c_var.mapsvector[c_var.actualmap].
				 raster_data,
				 c_var.mapsvector[c_var.actualmap].
				 raster_ncol,
				 c_var.mapsvector[c_var.actualmap].
				 raster_nrow);
    }
  else
    {

      gdk_draw_rectangle (pixmap2,
			  widget->style->white_gc,
			  TRUE,
			  0, 0,
			  widget->allocation.width,
			  widget->allocation.height);
    }

  gdk_draw_pixmap (widget->window,
		   widget->style->fg_gc[GTK_WIDGET_STATE (widget)],
		   pixmap2,
		   0, 0,
		   0, 0, widget->allocation.width, widget->allocation.height);
  return TRUE;
}


gboolean
on_drawingarea2_expose_event (GtkWidget * widget,
			      GdkEventExpose * event, gpointer user_data)
{

  gdk_draw_pixmap (widget->window,
		   widget->style->fg_gc[GTK_WIDGET_STATE (widget)],
		   pixmap2,
		   event->area.x, event->area.y,
		   event->area.x, event->area.y,
		   event->area.width, event->area.height);

  return FALSE;

}


gboolean
on_drawingarea2_motion_notify_event (GtkWidget * widget,
				     GdkEventMotion * event,
				     gpointer user_data)
{

//  if(c_var.button_raster_active ==2 && pixmap2 != NULL)
  int x, y;
  int indexx, indexy;
  gdouble coordx;
  GdkModifierType state;
  if (c_var.button_raster_active == 2 && pixmap2 != NULL)
    {
      if (event->is_hint)
	gdk_window_get_pointer (event->window, &x, &y, &state);
      else
	{
	  x = event->x;
	  y = event->y;
	  state = event->state;
	}

      if (state & GDK_BUTTON1_MASK && pixmap2 != NULL)
	{

	  draw_brush (widget, pixmap2, 0, event->x, event->y);


	  indexx =
	    (int) (0.0 +
		   event->y *
		   (double) c_var.mapsvector[c_var.actualmap].raster_nrow /
		   (double) widget->allocation.height);

	  indexy =
	    (int) (0.0 +
		   event->x *
		   (double) c_var.mapsvector[c_var.actualmap].raster_ncol /
		   (double) widget->allocation.width);

	  c_var.mapsvector[c_var.actualmap].raster_data[indexx *
							c_var.
							mapsvector[c_var.
								   actualmap].
							raster_ncol +
							indexy] =
	    c_var.mapsvector[c_var.actualmap].brush_level;
	  c_var.mapsvector[c_var.actualmap].raster_mask[indexx *
							c_var.
							mapsvector[c_var.
								   actualmap].
							raster_ncol +
							indexy] = 1;
	  //create_change_cell_properties   (indexx, indexy, c_var.mapsvector[c_var.actualmap].raster_data, c_var.mapsvector[c_var.actualmap].raster_nrow, c_var.mapsvector[c_var.actualmap].raster_ncol);
	}
    }
  return FALSE;


}


gboolean
on_drawingarea2_button_press_event (GtkWidget * widget,
				    GdkEventButton * event,
				    gpointer user_data)
{



  gdouble coordx;
  gdouble coordy;
  int index, indexx, indexy;
  int i;

  //printf("en drawingarea2\n");

  if (c_var.button_raster_active == 1 && pixmap2 != NULL)
    //if (event->button == 1 && pixmap4 != NULL)
    {
      indexx =
	(int) (0.0 +
	       event->y *
	       (double) c_var.mapsvector[c_var.actualmap].raster_nrow /
	       (double) widget->allocation.height);
      coordx =
	(gdouble) indexx *((double) widget->allocation.height /
			   (double) c_var.mapsvector[c_var.actualmap].
			   raster_nrow);
      //printf("%d %f\n",indexy,coordx);

      indexy =
	(int) (0.0 +
	       event->x *
	       (double) c_var.mapsvector[c_var.actualmap].raster_ncol /
	       (double) widget->allocation.width);
      coordx =
	(gdouble) indexy *((double) widget->allocation.width /
			   (double) c_var.mapsvector[c_var.actualmap].
			   raster_ncol);
      //printf("%d %f\n",indexx,coordx);

      //printf("\n\n**%f**\n\n",c_var.mapsvector[c_var.actualmap].raster_data[indexy*c_var.mapsvector[c_var.actualmap].raster_ncol+indexx]);

      create_change_cell_properties (indexx, indexy,
				     c_var.mapsvector[c_var.actualmap].
				     raster_data,
				     c_var.mapsvector[c_var.actualmap].
				     raster_nrow,
				     c_var.mapsvector[c_var.actualmap].
				     raster_ncol);

    }

  return FALSE;
}


void
on_button4_clicked (GtkButton * button, gpointer user_data)
{
  int i, j;
  GtkWidget *tmp_widget;
  GdkEventConfigure *tmpconfigureevent;
  gboolean tmpboolean;

  if(c_var.actualmap<0)
  {
    printf("no hay mapa abierto\n");
    return FALSE;
  }
  
  for (j = 0; j < c_var.mapsvector[c_var.actualmap].raster_nrow; j++)
    {
      for (i = 0; i < c_var.mapsvector[c_var.actualmap].raster_ncol; i++)
	{

	  c_var.mapsvector[c_var.actualmap].raster_mask[j *
							c_var.
							mapsvector[c_var.
								   actualmap].
							raster_ncol + i] = 0;
	  c_var.mapsvector[c_var.actualmap].raster_data[j *
							c_var.
							mapsvector[c_var.
								   actualmap].
							raster_ncol + i] =
	    0.0;

	}

    }

//   (void)domain_box(&c_var.mapsvector[c_var.actualmap].file_datas,&c_var.mapsvector[c_var.actualmap].xmin, &c_var.mapsvector[c_var.actualmap].xmax, &c_var.mapsvector[c_var.actualmap].ymin, &c_var.mapsvector[c_var.actualmap].ymax, &c_var.mapsvector[c_var.actualmap].zmin, &c_var.mapsvector[c_var.actualmap].zmax);

  vec2ras (&c_var.mapsvector[c_var.actualmap].file_datas,
	   c_var.mapsvector[c_var.actualmap].raster_data,
	   c_var.mapsvector[c_var.actualmap].raster_mask,
	   c_var.mapsvector[c_var.actualmap].raster_ncol,
	   c_var.mapsvector[c_var.actualmap].raster_nrow);
/*
   for (j=0;j<c_var.mapsvector[c_var.actualmap].raster_nrow;j++)
   {
     for (i=0;i<c_var.mapsvector[c_var.actualmap].raster_ncol;i++)
     {
       if(c_var.mapsvector[c_var.actualmap].raster_mask[i*c_var.mapsvector[c_var.actualmap].raster_ncol+j]==1)
       {
         printf("dato %d %d %f\n",j,i, c_var.mapsvector[c_var.actualmap].raster_data[i*c_var.mapsvector[c_var.actualmap].raster_ncol+j]);
       
       }
     }
     //printf("\n");
   }
   //printf("\n\n");
*/

  export_xpm (c_var.mapsvector[c_var.actualmap].raster_data,
	      "/tmp/batimetria_gnomesh.xpm",
	      c_var.mapsvector[c_var.actualmap].raster_ncol,
	      c_var.mapsvector[c_var.actualmap].raster_nrow);


  tmp_widget = lookup_widget (button, "drawingarea2");
  gtk_signal_emit_by_name (GTK_OBJECT (tmp_widget), "configure_event",
			   tmpconfigureevent, &tmpboolean);
  tmp_widget = lookup_widget (button, "drawingarea6");
  gtk_signal_emit_by_name (GTK_OBJECT (tmp_widget), "configure_event",
			   tmpconfigureevent, &tmpboolean);
  tmp_widget = lookup_widget (button, "vruler1");
  gtk_signal_emit_by_name (GTK_OBJECT (tmp_widget), "configure_event",
			   tmpconfigureevent, &tmpboolean);
  tmp_widget = lookup_widget (button, "hruler1");
  gtk_signal_emit_by_name (GTK_OBJECT (tmp_widget), "configure_event",
			   tmpconfigureevent, &tmpboolean);
  tmp_widget = lookup_widget (button, "vruler2");
  gtk_signal_emit_by_name (GTK_OBJECT (tmp_widget), "configure_event",
			   tmpconfigureevent, &tmpboolean);
  tmp_widget = lookup_widget (button, "vruler3");
  gtk_signal_emit_by_name (GTK_OBJECT (tmp_widget), "configure_event",
			   tmpconfigureevent, &tmpboolean);
  tmp_widget = lookup_widget (button, "hruler2");
  gtk_signal_emit_by_name (GTK_OBJECT (tmp_widget), "configure_event",
			   tmpconfigureevent, &tmpboolean);




}


void
on_button_interpolate_clicked (GtkButton * button, gpointer user_data)
{
  int i, j;
  int nlineas;
  GtkWidget *tmp_widget;
  GdkEventConfigure *tmpconfigureevent;
  gboolean tmpboolean;
  FILE *fp;
  
  if(c_var.mapsvector[c_var.actualmap].raster_data==NULL)
  {
    printf("no hay mapa abierto\n");
    return FALSE;
  }
  

  for (j = 0; j < c_var.mapsvector[c_var.actualmap].raster_nrow; j++)
    {
      for (i = 0; i < c_var.mapsvector[c_var.actualmap].raster_ncol; i++)
	{
	  c_var.mapsvector[c_var.actualmap].raster_data_interpolated[j *
								     c_var.
								     mapsvector
								     [c_var.
								      actualmap].
								     raster_ncol
								     + i] =
	    c_var.mapsvector[c_var.actualmap].raster_data[j *
							  c_var.
							  mapsvector[c_var.
								     actualmap].
							  raster_ncol + i];
	}

    }
  //printf("rasterizandoa\n");
/*
   nlineas=count_lines(&c_var.mapsvector[c_var.actualmap].file_datas);
   printf("numero lineas: %d\n",nlineas);
   (void)domain_box(&c_var.mapsvector[c_var.actualmap].file_datas,&c_var.mapsvector[c_var.actualmap].xmin, &c_var.mapsvector[c_var.actualmap].xmax, &c_var.mapsvector[c_var.actualmap].ymin, &c_var.mapsvector[c_var.actualmap].ymax, &c_var.mapsvector[c_var.actualmap].zmin, &c_var.mapsvector[c_var.actualmap].zmax);

   vec2ras(&c_var.mapsvector[c_var.actualmap].file_datas,c_var.mapsvector[c_var.actualmap].raster_data,c_var.mapsvector[c_var.actualmap].raster_mask, c_var.mapsvector[c_var.actualmap].raster_ncol, c_var.mapsvector[c_var.actualmap].raster_nrow);
*/

 //printf("antes interpolacion gauss\n");
  interpolation_gauss (c_var.mapsvector[c_var.actualmap].
		       raster_data_interpolated,
		       c_var.mapsvector[c_var.actualmap].raster_mask,
		       c_var.mapsvector[c_var.actualmap].raster_ncol,
		       c_var.mapsvector[c_var.actualmap].raster_nrow,
		       c_var.mapsvector[c_var.actualmap].
		       interpolation_maxiter,
		       c_var.mapsvector[c_var.actualmap].
		       interpolation_precision);

  //printf("despues gauss\n");
  

  if ((fp = fopen ("raster_interp.txt", "w")) != NULL)
  {
    for (j=0;j<c_var.mapsvector[c_var.actualmap].raster_nrow;j++)
    {
      for (i=0;i<c_var.mapsvector[c_var.actualmap].raster_ncol;i++)
      {
        fprintf(fp,"%.3f ", c_var.mapsvector[c_var.actualmap].raster_data_interpolated[j*c_var.mapsvector[c_var.actualmap].raster_ncol+i]);
      }
      fprintf(fp,"\n");
    }
    //printf("\n\n");
    fclose(fp);   
  }
   


  //matriz interpolada

/*   
   for (j=0;j<c_var.mapsvector[c_var.actualmap].raster_nrow;j++)
   {
     for (i=0;i<c_var.mapsvector[c_var.actualmap].raster_ncol;i++)
     {
       printf("%f ", c_var.mapsvector[c_var.actualmap].raster_data_interpolated[j*c_var.mapsvector[c_var.actualmap].raster_ncol+i]);
     }
     printf("\n");
   }
*/
   
   
   //printf("\n\n");
 

  //printf("rasterizandob\n");
//   export_xpm(c_var.mapsvector[c_var.actualmap].raster_data, "/tmp/batimetria_gnomesh.xpm", c_var.mapsvector[c_var.actualmap].raster_ncol, c_var.mapsvector[c_var.actualmap].raster_nrow);
  //printf("exportadob\n");

  tmp_widget = lookup_widget (button, "drawingarea3");
  gtk_signal_emit_by_name (GTK_OBJECT (tmp_widget), "configure_event",
			   tmpconfigureevent, &tmpboolean);
/*   tmp_widget = lookup_widget (button, "drawingarea4");
   gtk_signal_emit_by_name(GTK_OBJECT(tmp_widget),"configure_event",tmpconfigureevent,&tmpboolean);
  */
  tmp_widget = lookup_widget (button, "hruler3");
  gtk_signal_emit_by_name (GTK_OBJECT (tmp_widget), "configure_event",
			   tmpconfigureevent, &tmpboolean);
  tmp_widget = lookup_widget (button, "vruler4");
  gtk_signal_emit_by_name (GTK_OBJECT (tmp_widget), "configure_event",
			   tmpconfigureevent, &tmpboolean);
  tmp_widget = lookup_widget (button, "hruler5");
  gtk_signal_emit_by_name (GTK_OBJECT (tmp_widget), "configure_event",
			   tmpconfigureevent, &tmpboolean);
  tmp_widget = lookup_widget (button, "vruler7");
  gtk_signal_emit_by_name (GTK_OBJECT (tmp_widget), "configure_event",
			   tmpconfigureevent, &tmpboolean);


}


gboolean
on_drawingarea3_configure_event (GtkWidget * widget,
				 GdkEventConfigure * event,
				 gpointer user_data)
{
  //printf("configure drawing area2\n");

  if (pixmap3)
    {
      gdk_pixmap_unref (pixmap3);
    }

  pixmap3 = gdk_pixmap_new (widget->window,
			    widget->allocation.width,
			    widget->allocation.height, -1);
  if (c_var.mapsvector[c_var.actualmap].raster_data != NULL
      && c_var.actualmap > -1)
    {
      create_pixmap_from_double (widget, pixmap3,
				 c_var.mapsvector[c_var.actualmap].
				 raster_data_interpolated,
				 c_var.mapsvector[c_var.actualmap].
				 raster_ncol,
				 c_var.mapsvector[c_var.actualmap].
				 raster_nrow);
    }
  else
    {

      gdk_draw_rectangle (pixmap3,
			  widget->style->white_gc,
			  TRUE,
			  0, 0,
			  widget->allocation.width,
			  widget->allocation.height);
    }

  gdk_draw_pixmap (widget->window,
		   widget->style->fg_gc[GTK_WIDGET_STATE (widget)],
		   pixmap3,
		   0, 0,
		   0, 0, widget->allocation.width, widget->allocation.height);

  return TRUE;
}


gboolean
on_drawingarea3_expose_event (GtkWidget * widget,
			      GdkEventExpose * event, gpointer user_data)
{

  gdk_draw_pixmap (widget->window,
		   widget->style->fg_gc[GTK_WIDGET_STATE (widget)],
		   pixmap3,
		   event->area.x, event->area.y,
		   event->area.x, event->area.y,
		   event->area.width, event->area.height);

  return FALSE;
}


gboolean
on_drawingarea3_motion_notify_event (GtkWidget * widget,
				     GdkEventMotion * event,
				     gpointer user_data)
{

  return FALSE;
}


gboolean
on_drawingarea3_button_press_event (GtkWidget * widget,
				    GdkEventButton * event,
				    gpointer user_data)
{
  gdouble coordx;
  gdouble coordy;
  int index, indexx, indexy;
  int i;
  
  if (c_var.button_interpolation_active == 1 && pixmap3 != NULL)
    
    {
      indexx =
	(int) (0.0 +
	       event->y *
	       (double) c_var.mapsvector[c_var.actualmap].raster_nrow /
	       (double) widget->allocation.height);
      coordx =
	(gdouble) indexx *((double) widget->allocation.height /
			   (double) c_var.mapsvector[c_var.actualmap].
			   raster_nrow);
      //printf("%d %f\n",indexy,coordx);

      indexy =
	(int) (0.0 +
	       event->x *
	       (double) c_var.mapsvector[c_var.actualmap].raster_ncol /
	       (double) widget->allocation.width);
      coordx =
	(gdouble) indexy *((double) widget->allocation.width /
			   (double) c_var.mapsvector[c_var.actualmap].
			   raster_ncol);
      //printf("%d %f\n",indexx,coordx);

      //printf("\n\n**%f**\n\n",c_var.mapsvector[c_var.actualmap].raster_data[indexy*c_var.mapsvector[c_var.actualmap].raster_ncol+indexx]);

      create_change_cell_properties (indexx, indexy,
				     c_var.mapsvector[c_var.actualmap].
				     raster_data,
				     c_var.mapsvector[c_var.actualmap].
				     raster_nrow,
				     c_var.mapsvector[c_var.actualmap].
				     raster_ncol);

    }
  return FALSE;
}


gboolean
on_drawingarea4_configure_event (GtkWidget * widget,
				 GdkEventConfigure * event,
				 gpointer user_data)
{
  //printf("configure drawing area2\n");
  int i;
  if (pixmap4)
    {
      gdk_pixmap_unref (pixmap4);
    }

  pixmap4 = gdk_pixmap_new (widget->window,
			    widget->allocation.width,
			    widget->allocation.height, -1);
  if (c_var.mapsvector[c_var.actualmap].raster_data != NULL
      && c_var.actualmap > -1)
    {
      create_pixmap_from_double (widget, pixmap4,
				 c_var.mapsvector[c_var.actualmap].
				 raster_data_interpolated,
				 c_var.mapsvector[c_var.actualmap].
				 raster_ncol,
				 c_var.mapsvector[c_var.actualmap].
				 raster_nrow);

      for (i = 0; i < c_var.mapsvector[c_var.actualmap].raster_ncol + 1; i++)
	{
	  if (c_var.mapsvector[c_var.actualmap].horizontal_mesh[i] == 1)
	    {

	      draw_brush (widget, pixmap4, 1,
			  (gdouble) ((double) i *
				     (double) widget->allocation.width /
				     (double) c_var.mapsvector[c_var.
							       actualmap].
				     raster_ncol), 0.0);

	    }


	}


      for (i = 0; i < c_var.mapsvector[c_var.actualmap].raster_nrow + 1; i++)
	{
	  if (c_var.mapsvector[c_var.actualmap].vertical_mesh[i] == 1)
	    {
	      //printf("estoy recuperando una linea \n");
	      draw_brush (widget, pixmap4, 2, 0.0,
			  (gdouble) ((double) i *
				     (double) widget->allocation.height /
				     (double) c_var.mapsvector[c_var.
							       actualmap].
				     raster_nrow));

	    }


	}


    }
  else
    {

      gdk_draw_rectangle (pixmap4,
			  widget->style->white_gc,
			  TRUE,
			  0, 0,
			  widget->allocation.width,
			  widget->allocation.height);
    }

  return TRUE;
}


gboolean
on_drawingarea4_expose_event (GtkWidget * widget,
			      GdkEventExpose * event, gpointer user_data)
{

  gdk_draw_pixmap (widget->window,
		   widget->style->fg_gc[GTK_WIDGET_STATE (widget)],
		   pixmap4,
		   event->area.x, event->area.y,
		   event->area.x, event->area.y,
		   event->area.width, event->area.height);

  return FALSE;
}


gboolean
on_drawingarea4_motion_notify_event (GtkWidget * widget,
				     GdkEventMotion * event,
				     gpointer user_data)
{
  int x, y;
  GdkModifierType state;

  if (event->is_hint)
    gdk_window_get_pointer (event->window, &x, &y, &state);
  else
    {
      x = event->x;
      y = event->y;
      state = event->state;
    }

  if (state & GDK_BUTTON1_MASK && pixmap4 != NULL)
    //draw_brush (widget, x, y);
    //printf("%f %f\n",event->x, event->y);

    return FALSE;
}


gboolean
on_drawingarea4_button_press_event (GtkWidget * widget,
				    GdkEventButton * event,
				    gpointer user_data)
{

  gdouble coordx;
  gdouble coordy;
  int index, indexx, indexy;
  int i;

  if (c_var.button_mesh_active == 1 && pixmap4 != NULL)
    //if (event->button == 1 && pixmap4 != NULL)
    {
      //c_var.mapsvector[c_var.actualmap].raster_ncol=100;
      //c_var.mapsvector[c_var.actualmap].raster_nrow=100;

      //draw_brush (widget, pixmap4, event->x, event->y);
      //coordx=(gdouble)((int)(event->x/(c_var.mapsvector[c_var.actualmap].raster_ncol*widget->allocation.width)))*(widget->allocation.width/c_var.mapsvector[c_var.actualmap].raster_ncol);
      index =
	(int) (0.5 +
	       event->x *
	       (double) c_var.mapsvector[c_var.actualmap].raster_ncol /
	       (double) widget->allocation.width);
      coordx =
	(gdouble) index *((double) widget->allocation.width /
			  (double) c_var.mapsvector[c_var.actualmap].
			  raster_ncol);
      c_var.mapsvector[c_var.actualmap].horizontal_mesh[index] = 1;
      draw_brush (widget, pixmap4, 1, coordx, event->y);
      //printf("on_drawingarwa %f %f %d %d %f %d\n",event->x, event->y, c_var.mapsvector[c_var.actualmap].raster_ncol, widget->allocation.width, coordx, index);
    }

  else if (c_var.button_mesh_active == 2 && pixmap4 != NULL)
    //if (event->button == 1 && pixmap4 != NULL)
    {
      //c_var.mapsvector[c_var.actualmap].raster_ncol=100;
      //c_var.mapsvector[c_var.actualmap].raster_nrow=100;

      //draw_brush (widget, pixmap4, event->x, event->y);
      //coordx=(gdouble)((int)(event->x/(c_var.mapsvector[c_var.actualmap].raster_ncol*widget->allocation.width)))*(widget->allocation.width/c_var.mapsvector[c_var.actualmap].raster_ncol);
      index =
	(int) (0.5 +
	       event->y *
	       (double) c_var.mapsvector[c_var.actualmap].raster_nrow /
	       (double) widget->allocation.height);
      coordy =
	(gdouble) index *((double) widget->allocation.height /
			  (double) c_var.mapsvector[c_var.actualmap].
			  raster_nrow);
      c_var.mapsvector[c_var.actualmap].vertical_mesh[index] = 1;
      draw_brush (widget, pixmap4, 2, event->x, coordy);
      //printf("on_drawingarwa %f %f %d %d %f %d\n",event->x, event->y, c_var.mapsvector[c_var.actualmap].raster_ncol, widget->allocation.width, coordx, index);
    }

  else if (c_var.button_mesh_active == 3 && pixmap4 != NULL)
    //if (event->button == 1 && pixmap4 != NULL)
    {
      //c_var.mapsvector[c_var.actualmap].raster_ncol=100;
      //c_var.mapsvector[c_var.actualmap].raster_nrow=100;

      //draw_brush (widget, pixmap4, event->x, event->y);
      //coordx=(gdouble)((int)(event->x/(c_var.mapsvector[c_var.actualmap].raster_ncol*widget->allocation.width)))*(widget->allocation.width/c_var.mapsvector[c_var.actualmap].raster_ncol);
      index =
	(int) (0.5 +
	       event->y *
	       (double) c_var.mapsvector[c_var.actualmap].raster_nrow /
	       (double) widget->allocation.height);
      coordy =
	(gdouble) index *((double) widget->allocation.height /
			  (double) c_var.mapsvector[c_var.actualmap].
			  raster_nrow);
      c_var.mapsvector[c_var.actualmap].vertical_mesh[index] = 0;
      //draw_brush (widget, pixmap4, 2, event->x, coordy);
      //printf("borrando %d\n",index);
      //printf("on_drawingarwa %f %f %d %d %f %d\n",event->x, event->y, c_var.mapsvector[c_var.actualmap].raster_ncol, widget->allocation.width, coordx, index);
    }
  else if (c_var.button_mesh_active == 4 && pixmap4 != NULL)
    //if (event->button == 1 && pixmap4 != NULL)
    {
      //c_var.mapsvector[c_var.actualmap].raster_ncol=100;
      //c_var.mapsvector[c_var.actualmap].raster_nrow=100;

      //draw_brush (widget, pixmap4, event->x, event->y);
      //coordx=(gdouble)((int)(event->x/(c_var.mapsvector[c_var.actualmap].raster_ncol*widget->allocation.width)))*(widget->allocation.width/c_var.mapsvector[c_var.actualmap].raster_ncol);
      index =
	(int) (0.5 +
	       event->x *
	       (double) c_var.mapsvector[c_var.actualmap].raster_ncol /
	       (double) widget->allocation.width);
      coordx =
	(gdouble) index *((double) widget->allocation.width /
			  (double) c_var.mapsvector[c_var.actualmap].
			  raster_ncol);
      c_var.mapsvector[c_var.actualmap].horizontal_mesh[index] = 0;
      //draw_brush (widget, pixmap4, 2, event->x, coordy);
      //printf("borrando %d\n",index);
      //printf("on_drawingarwa %f %f %d %d %f %d\n",event->x, event->y, c_var.mapsvector[c_var.actualmap].raster_ncol, widget->allocation.width, coordx, index);
    }
  else if (c_var.button_mesh_active == 5 && pixmap4 != NULL)
    //if (event->button == 1 && pixmap4 != NULL)
    {
      indexx =
	(int) (0.0 +
	       event->y *
	       (double) c_var.mapsvector[c_var.actualmap].raster_nrow /
	       (double) widget->allocation.height);
      coordx =
	(gdouble) indexx *((double) widget->allocation.height /
			   (double) c_var.mapsvector[c_var.actualmap].
			   raster_nrow);
      //printf("%d %f\n",indexy,coordx);

      indexy =
	(int) (0.0 +
	       event->x *
	       (double) c_var.mapsvector[c_var.actualmap].raster_ncol /
	       (double) widget->allocation.width);
      coordx =
	(gdouble) indexy *((double) widget->allocation.width /
			   (double) c_var.mapsvector[c_var.actualmap].
			   raster_ncol);
      //printf("%d %f\n",indexx,coordx);

      //printf("\n\n**%f**\n\n",c_var.mapsvector[c_var.actualmap].raster_data[indexy*c_var.mapsvector[c_var.actualmap].raster_ncol+indexx]);

      create_change_cell_properties (indexx, indexy,
				     c_var.mapsvector[c_var.actualmap].
				     raster_data,
				     c_var.mapsvector[c_var.actualmap].
				     raster_nrow,
				     c_var.mapsvector[c_var.actualmap].
				     raster_ncol);
    }

  return FALSE;
}


void
on_togglebutton_mesh_addhline_toggled (GtkToggleButton * togglebutton,
				       gpointer user_data)
{
  //printf("on_togglebutton_mesh_addhline_toggled\n");
}




void
on_button_mesh_addvline_clicked (GtkButton * button, gpointer user_data)
{
  //printf("%d\n",c_var.button_mesh_active);
  if (c_var.button_mesh_active != 1)
    {
      c_var.button_mesh_active = 1;
    }
  else
    {
      c_var.button_mesh_active = 0;
    }
}


void
on_button_mesh_addhline_clicked (GtkButton * button, gpointer user_data)
{
  //printf("%d\n",c_var.button_mesh_active);
  if (c_var.button_mesh_active != 2)
    {
      c_var.button_mesh_active = 2;
    }
  else
    {
      c_var.button_mesh_active = 0;
    }
}

void
on_button_mesh_delhline_clicked (GtkButton * button, gpointer user_data)
{
  if (c_var.button_mesh_active != 3)
    {
      c_var.button_mesh_active = 3;
    }
  else
    {
      c_var.button_mesh_active = 0;
    }
}


void
on_button_mesh_delvline_clicked (GtkButton * button, gpointer user_data)
{
  if (c_var.button_mesh_active != 4)
    {
      c_var.button_mesh_active = 4;
    }
  else
    {
      c_var.button_mesh_active = 0;
    }
}


gboolean
on_drawingarea5_configure_event (GtkWidget * widget,
				 GdkEventConfigure * event,
				 gpointer user_data)
{
  //printf("configure drawing area5\n");
  int i;
  if (pixmap5)
    {
      gdk_pixmap_unref (pixmap5);
    }

  pixmap5 = gdk_pixmap_new (widget->window,
			    widget->allocation.width,
			    widget->allocation.height, -1);
  //if(c_var.mapsvector[c_var.actualmap].raster_data_interpolated!=NULL && c_var.actualmap>-1)
  if (c_var.mapsvector[c_var.actualmap].raster_mesh != NULL
      && c_var.actualmap > -1)
    {
      //create_pixmap_from_double (widget,pixmap5,c_var.mapsvector[c_var.actualmap].raster_data_interpolated, c_var.mapsvector[c_var.actualmap].raster_ncol, c_var.mapsvector[c_var.actualmap].raster_nrow);

      //printf("antes crear pixmap irregular\n");
      create_pixmap_from_double_irregular (widget, pixmap5,
					   c_var.mapsvector[c_var.actualmap].
					   raster_mesh,
					   c_var.mapsvector[c_var.actualmap].
					   horizontal_mesh_width,
					   c_var.mapsvector[c_var.actualmap].
					   vertical_mesh_width,
					   c_var.mapsvector[c_var.actualmap].
					   raster_mesh_ncol,
					   c_var.mapsvector[c_var.actualmap].
					   raster_mesh_nrow);
//    create_pixmap_from_double_irregular (widget,pixmap5,c_var.mapsvector[c_var.actualmap].raster_mesh_advection_number, c_var.mapsvector[c_var.actualmap].horizontal_mesh_width, c_var.mapsvector[c_var.actualmap].vertical_mesh_width, c_var.mapsvector[c_var.actualmap].raster_mesh_ncol, c_var.mapsvector[c_var.actualmap].raster_mesh_nrow);
      //printf("despues crear pixmap irregular\n");


    }
  else
    {

      gdk_draw_rectangle (pixmap5,
			  widget->style->white_gc,
			  TRUE,
			  0, 0,
			  widget->allocation.width,
			  widget->allocation.height);
    }

  gdk_draw_pixmap (widget->window,
		   widget->style->fg_gc[GTK_WIDGET_STATE (widget)],
		   pixmap5,
		   0, 0,
		   0, 0, widget->allocation.width, widget->allocation.height);

  //printf("antes retornar configure area5\n");
  return TRUE;
}


gboolean
on_drawingarea5_expose_event (GtkWidget * widget,
			      GdkEventExpose * event, gpointer user_data)
{
  gdk_draw_pixmap (widget->window,
		   widget->style->fg_gc[GTK_WIDGET_STATE (widget)],
		   pixmap5,
		   event->area.x, event->area.y,
		   event->area.x, event->area.y,
		   event->area.width, event->area.height);

  return FALSE;
}


gboolean
on_drawingarea5_motion_notify_event (GtkWidget * widget,
				     GdkEventMotion * event,
				     gpointer user_data)
{
  int x, y;
  GdkModifierType state;

  if (event->is_hint)
    gdk_window_get_pointer (event->window, &x, &y, &state);
  else
    {
      x = event->x;
      y = event->y;
      state = event->state;
    }

  if (state & GDK_BUTTON1_MASK && pixmap5 != NULL)
    //draw_brush (widget, x, y);
    //printf("%f %f\n",event->x, event->y);

    return FALSE;
}


gboolean
on_drawingarea5_button_press_event (GtkWidget * widget,
				    GdkEventButton * event,
				    gpointer user_data)
{

  return FALSE;
}


void
on_button_defmesh_genmesh_clicked (GtkButton * button, gpointer user_data)
{

  int i, j, k, l;
  int a, b, c, d;
  double tmp_sum;
  int tmp_count;
  int *tmp_vecth;
  int *tmp_vectv;
  GtkWidget *tmp_widget;
  GdkEventConfigure *tmpconfigureevent;
  gboolean tmpboolean;
  int ncol, nrow;
  double velx, vely;
  double mindx;
  //count elements

  if(c_var.mapsvector[c_var.actualmap].raster_data_interpolated==NULL)
  {
    printf("no hay mapa abierto\n");
    return FALSE;
  }  
  
  ncol = 0;
  nrow = 0;
  for (i = 0; i < c_var.mapsvector[c_var.actualmap].raster_ncol + 1; i++)
    {
      if (c_var.mapsvector[c_var.actualmap].horizontal_mesh[i] == 1)
	{
	  ncol++;
	}
    }

  for (i = 0; i < c_var.mapsvector[c_var.actualmap].raster_nrow + 1; i++)
    {
      if (c_var.mapsvector[c_var.actualmap].vertical_mesh[i] == 1)
	{
	  nrow++;
	}
    }
    
 if(ncol==0 || nrow==0)
 {
   return FALSE;
 }

  //obtain memory to store the mesh
  ncol -= 1;
  nrow -= 1;

  c_var.mapsvector[c_var.actualmap].raster_mesh_ncol = ncol;
  c_var.mapsvector[c_var.actualmap].raster_mesh_nrow = nrow;

  if (c_var.mapsvector[c_var.actualmap].raster_mesh == NULL)
    {
//      g_free(c_var.mapsvector[c_var.actualmap].raster_mesh);
      c_var.mapsvector[c_var.actualmap].raster_mesh =
	(double *) g_try_malloc (sizeof (double) * ncol * nrow);
    }
  else
    {
      c_var.mapsvector[c_var.actualmap].raster_mesh =
	(double *) g_try_realloc (c_var.mapsvector[c_var.actualmap].
				  raster_mesh, sizeof (double) * ncol * nrow);
    }

  if (c_var.mapsvector[c_var.actualmap].raster_mesh_advection_number == NULL)
    {
//      g_free(c_var.mapsvector[c_var.actualmap].raster_mesh);
      c_var.mapsvector[c_var.actualmap].raster_mesh_advection_number =
	(double *) g_try_malloc (sizeof (double) * ncol * nrow);
    }
  else
    {
      c_var.mapsvector[c_var.actualmap].raster_mesh_advection_number =
	(double *) g_try_realloc (c_var.mapsvector[c_var.actualmap].
				  raster_mesh_advection_number,
				  sizeof (double) * ncol * nrow);
    }

  if (c_var.mapsvector[c_var.actualmap].raster_mesh_standar_desviation ==
      NULL)
    {
//      g_free(c_var.mapsvector[c_var.actualmap].raster_mesh);
      c_var.mapsvector[c_var.actualmap].raster_mesh_standar_desviation =
	(double *) g_try_malloc (sizeof (double) * ncol * nrow);
    }
  else
    {
      c_var.mapsvector[c_var.actualmap].raster_mesh_standar_desviation =
	(double *) g_try_realloc (c_var.mapsvector[c_var.actualmap].
				  raster_mesh_standar_desviation,
				  sizeof (double) * ncol * nrow);
    }

  if (c_var.mapsvector[c_var.actualmap].raster_mesh_aspect_ratio == NULL)
    {
//      g_free(c_var.mapsvector[c_var.actualmap].raster_mesh);
      c_var.mapsvector[c_var.actualmap].raster_mesh_aspect_ratio =
	(double *) g_try_malloc (sizeof (double) * ncol * nrow);
    }
  else
    {
      c_var.mapsvector[c_var.actualmap].raster_mesh_aspect_ratio =
	(double *) g_try_realloc (c_var.mapsvector[c_var.actualmap].
				  raster_mesh_aspect_ratio,
				  sizeof (double) * ncol * nrow);
    }

  if (c_var.mapsvector[c_var.actualmap].raster_mesh_gradient_horizontal ==
      NULL)
    {
//      g_free(c_var.mapsvector[c_var.actualmap].raster_mesh);
      c_var.mapsvector[c_var.actualmap].raster_mesh_gradient_horizontal =
	(double *) g_try_malloc (sizeof (double) * ncol * nrow);
    }
  else
    {
      c_var.mapsvector[c_var.actualmap].raster_mesh_gradient_horizontal =
	(double *) g_try_realloc (c_var.mapsvector[c_var.actualmap].
				  raster_mesh_gradient_horizontal,
				  sizeof (double) * ncol * nrow);
    }
  if (c_var.mapsvector[c_var.actualmap].raster_mesh_gradient_vertical == NULL)
    {
//      g_free(c_var.mapsvector[c_var.actualmap].raster_mesh);
      c_var.mapsvector[c_var.actualmap].raster_mesh_gradient_vertical =
	(double *) g_try_malloc (sizeof (double) * ncol * nrow);
    }
  else
    {
      c_var.mapsvector[c_var.actualmap].raster_mesh_gradient_vertical =
	(double *) g_try_realloc (c_var.mapsvector[c_var.actualmap].
				  raster_mesh_gradient_vertical,
				  sizeof (double) * ncol * nrow);
    }



  //g_free(tmp_vecth);
  //g_free(tmp_vectv);
  tmp_vecth = NULL;
  tmp_vectv = NULL;

  if (tmp_vecth != NULL)
    {
      //printf("antes dimensionar h\n");
      tmp_vecth = (int *) g_malloc (sizeof (int) * (ncol + 1));
      //printf("despues dimensionar h\n");

    }
  else
    {
      //printf("antes redimensionar h\n");
      tmp_vecth =
	(int *) g_try_realloc (tmp_vecth, sizeof (int) * (ncol + 1));
      if (tmp_vecth == NULL)
	{
	  //printf("no pude asignar memoria\n");
	}
      //printf("despues redimensionar h\n");
    }
  if (tmp_vectv != NULL)
    {
      //printf("antes dimensionar v\n");
      tmp_vectv = (int *) g_malloc (sizeof (int) * (nrow + 1));
      //printf("despues dimensionar v\n");
    }
  else
    {
      tmp_vectv =
	(int *) g_try_realloc (tmp_vectv, sizeof (int) * (nrow + 1));
    }

  k = 0;
  for (i = 0; i < c_var.mapsvector[c_var.actualmap].raster_ncol + 1; i++)
    {
      if (c_var.mapsvector[c_var.actualmap].horizontal_mesh[i] == 1)
	{
	  tmp_vecth[k] = i;
	  k++;
	}
    }

  k = 0;
  for (i = 0; i < c_var.mapsvector[c_var.actualmap].raster_nrow + 1; i++)
    {
      if (c_var.mapsvector[c_var.actualmap].vertical_mesh[i] == 1)
	{
	  tmp_vectv[k] = i;
	  k++;
	}
    }

  c_var.mapsvector[c_var.actualmap].horizontal_mesh_width =
    (double *) g_malloc (sizeof (double) * (ncol + 1));
  c_var.mapsvector[c_var.actualmap].vertical_mesh_width =
    (double *) g_malloc (sizeof (double) * (nrow + 1));

  for (i = 1; i < ncol + 1; i++)
    {
      c_var.mapsvector[c_var.actualmap].horizontal_mesh_width[i - 1] =
	(double) (tmp_vecth[i] -
		  tmp_vecth[i -
			    1]) *
	(double) (c_var.mapsvector[c_var.actualmap].xmax -
		  c_var.mapsvector[c_var.actualmap].xmin) /
	(double) (c_var.mapsvector[c_var.actualmap].raster_ncol);
    }

  for (i = 1; i < nrow + 1; i++)
    {
      c_var.mapsvector[c_var.actualmap].vertical_mesh_width[i - 1] =
	(double) (tmp_vectv[i] -
		  tmp_vectv[i -
			    1]) *
	(double) (c_var.mapsvector[c_var.actualmap].ymax -
		  c_var.mapsvector[c_var.actualmap].ymin) /
	(double) (c_var.mapsvector[c_var.actualmap].raster_nrow);
    }

  //calculate the irregular mesh
  for (i = 0; i < nrow; i++)
    {
      for (j = 0; j < ncol; j++)
	{
	  tmp_sum = 0;
	  tmp_count = 0;
	  for (k = tmp_vectv[i]; k < tmp_vectv[i + 1]; k++)
	    {
	      for (l = tmp_vecth[j]; l < tmp_vecth[j + 1]; l++)
		{
		  tmp_sum +=
		    c_var.mapsvector[c_var.actualmap].
		    raster_data_interpolated[k *
					     c_var.mapsvector[c_var.
							      actualmap].
					     raster_ncol + l];
		  tmp_count++;
		}
	    }
	  c_var.mapsvector[c_var.actualmap].raster_mesh[i * ncol + j] =
	    tmp_sum / (double) tmp_count;
	}
    }

  //calculate the standar desviation
  for (i = 0; i < nrow; i++)
    {
      for (j = 0; j < ncol; j++)
	{
	  tmp_sum = 0;
	  tmp_count = 0;
	  for (k = tmp_vectv[i]; k < tmp_vectv[i + 1]; k++)
	    {
	      for (l = tmp_vecth[j]; l < tmp_vecth[j + 1]; l++)
		{
		  tmp_sum +=
		    pow ((c_var.mapsvector[c_var.actualmap].
			  raster_data_interpolated[k *
						   c_var.mapsvector[c_var.
								    actualmap].
						   raster_ncol + l] -
			  c_var.mapsvector[c_var.actualmap].
			  raster_mesh[i * ncol + j]), 2);
		  tmp_count++;
		}
	    }
	  c_var.mapsvector[c_var.actualmap].
	    raster_mesh_standar_desviation[i * ncol + j] =
	    tmp_sum / (double) tmp_count;
	}
    }

  //calculate aspect ratio
  //printf("antes aspect ratio\n");
  for (i = 0; i < nrow; i++)
    {
      for (j = 0; j < ncol; j++)
	{
	  c_var.mapsvector[c_var.actualmap].raster_mesh_aspect_ratio[i *
								     ncol
								     +
								     j] =
	    c_var.mapsvector[c_var.actualmap].vertical_mesh_width[i] /
	    c_var.mapsvector[c_var.actualmap].horizontal_mesh_width[j];
	  //printf ("%f ",c_var.mapsvector[c_var.actualmap].raster_mesh_aspect_ratio[i*ncol+j]);
	}
      //printf("\n");
    }
  //printf("despues aspect ratio\n");

  //calculate horizontal gradient
  //printf("antes aspect hgradient\n");
  for (i = 0; i < nrow; i++)
    {
      c_var.mapsvector[c_var.actualmap].
	raster_mesh_gradient_horizontal[i * ncol + 0] = 1;
      for (j = 1; j < ncol; j++)
	{
	  c_var.mapsvector[c_var.actualmap].
	    raster_mesh_gradient_horizontal[i * ncol + j] =
	    c_var.mapsvector[c_var.actualmap].horizontal_mesh_width[j -
								    1] /
	    c_var.mapsvector[c_var.actualmap].horizontal_mesh_width[j];
	  //printf ("%f ",c_var.mapsvector[c_var.actualmap].raster_mesh_gradient_horizontal[i*ncol+j]);
	}
      //printf("\n");
    }
  //printf("despues aspect ratio\n");      

  //calculate vertical gradient
  //printf("antes aspect vgradient\n");
  for (i = 0; i < nrow; i++)
    {

      for (j = 0; j < ncol; j++)
	{
	  if (i == (nrow - 1))
	    {
	      c_var.mapsvector[c_var.actualmap].
		raster_mesh_gradient_vertical[i * ncol + j] = 1;
	    }
	  else
	    {
	      c_var.mapsvector[c_var.actualmap].
		raster_mesh_gradient_vertical[i * ncol + j] =
		c_var.mapsvector[c_var.actualmap].vertical_mesh_width[i +
								      1] /
		c_var.mapsvector[c_var.actualmap].vertical_mesh_width[i];
	    }
	  //printf ("%f ",c_var.mapsvector[c_var.actualmap].raster_mesh_gradient_vertical[i*ncol+j]);

	}
      //printf("\n");
    }
  //printf("despues aspect ratio\n");    

  //calculate the advection number

  for (i = 0; i < nrow; i++)
    {
      for (j = 0; j < ncol; j++)
	{
	  //velx=0;
	  //vely=0;
	  mindx = c_var.mapsvector[c_var.actualmap].horizontal_mesh_width[j];
	  if (c_var.mapsvector[c_var.actualmap].vertical_mesh_width[i] <
	      c_var.mapsvector[c_var.actualmap].horizontal_mesh_width[j])
	    {
	      mindx =
		c_var.mapsvector[c_var.actualmap].vertical_mesh_width[i];
	    }
	  c_var.mapsvector[c_var.actualmap].
	    raster_mesh_advection_number[i * ncol + j] =
	    c_var.mapsvector[c_var.actualmap].courant_max_speed *
	    c_var.mapsvector[c_var.actualmap].courant_dt / mindx;
	}
    }



  for (i = 0; i < nrow; i++)
    {
      for (j = 0; j < ncol; j++)
	{
	  printf ("%f ",
		  c_var.mapsvector[c_var.actualmap].raster_mesh[i * ncol +
								j]);

	}
      printf ("\n");
    }
  //printf("fin malla\n");

/*
    for(i=0;i< nrow;i++)
    {
      for(j=0;j<ncol;j++)
      {
        printf("%f ",c_var.mapsvector[c_var.actualmap].raster_mesh_advection_number[i*ncol+j]);

      }
      printf("\n");
    }
    printf("fin malla\n");
*/

  //redibuja pantalla

  tmp_widget = lookup_widget (button, "drawingarea5");
  gtk_signal_emit_by_name (GTK_OBJECT (tmp_widget), "configure_event",
			   tmpconfigureevent, &tmpboolean);
  tmp_widget = lookup_widget (button, "drawingarea9");
  gtk_signal_emit_by_name (GTK_OBJECT (tmp_widget), "configure_event",
			   tmpconfigureevent, &tmpboolean);
  tmp_widget = lookup_widget (button, "drawingarea10");
  gtk_signal_emit_by_name (GTK_OBJECT (tmp_widget), "configure_event",
			   tmpconfigureevent, &tmpboolean);
  tmp_widget = lookup_widget (button, "drawingarea11");
  gtk_signal_emit_by_name (GTK_OBJECT (tmp_widget), "configure_event",
			   tmpconfigureevent, &tmpboolean);
  tmp_widget = lookup_widget (button, "drawingarea12");
  gtk_signal_emit_by_name (GTK_OBJECT (tmp_widget), "configure_event",
			   tmpconfigureevent, &tmpboolean);
  tmp_widget = lookup_widget (button, "drawingarea13");
  gtk_signal_emit_by_name (GTK_OBJECT (tmp_widget), "configure_event",
			   tmpconfigureevent, &tmpboolean);
  tmp_widget = lookup_widget (button, "drawingarea14");
  gtk_signal_emit_by_name (GTK_OBJECT (tmp_widget), "configure_event",
			   tmpconfigureevent, &tmpboolean);
  tmp_widget = lookup_widget (button, "drawingarea15");
  gtk_signal_emit_by_name (GTK_OBJECT (tmp_widget), "configure_event",
			   tmpconfigureevent, &tmpboolean);
  tmp_widget = lookup_widget (button, "drawingarea16");
  gtk_signal_emit_by_name (GTK_OBJECT (tmp_widget), "configure_event",
			   tmpconfigureevent, &tmpboolean);
  tmp_widget = lookup_widget (button, "drawingarea17");
  gtk_signal_emit_by_name (GTK_OBJECT (tmp_widget), "configure_event",
			   tmpconfigureevent, &tmpboolean);
  tmp_widget = lookup_widget (button, "drawingarea18");
  gtk_signal_emit_by_name (GTK_OBJECT (tmp_widget), "configure_event",
			   tmpconfigureevent, &tmpboolean);
  tmp_widget = lookup_widget (button, "drawingarea19");
  gtk_signal_emit_by_name (GTK_OBJECT (tmp_widget), "configure_event",
			   tmpconfigureevent, &tmpboolean);




  tmp_widget = lookup_widget (button, "vruler16");
  gtk_signal_emit_by_name (GTK_OBJECT (tmp_widget), "configure_event",
			   tmpconfigureevent, &tmpboolean);
  tmp_widget = lookup_widget (button, "vruler17");
  gtk_signal_emit_by_name (GTK_OBJECT (tmp_widget), "configure_event",
			   tmpconfigureevent, &tmpboolean);
  tmp_widget = lookup_widget (button, "vruler18");
  gtk_signal_emit_by_name (GTK_OBJECT (tmp_widget), "configure_event",
			   tmpconfigureevent, &tmpboolean);

  tmp_widget = lookup_widget (button, "vruler19");
  gtk_signal_emit_by_name (GTK_OBJECT (tmp_widget), "configure_event",
			   tmpconfigureevent, &tmpboolean);
  tmp_widget = lookup_widget (button, "vruler20");
  gtk_signal_emit_by_name (GTK_OBJECT (tmp_widget), "configure_event",
			   tmpconfigureevent, &tmpboolean);
  tmp_widget = lookup_widget (button, "vruler24");
  gtk_signal_emit_by_name (GTK_OBJECT (tmp_widget), "configure_event",
			   tmpconfigureevent, &tmpboolean);



}


void
  on_raster_cell_properties_button_clicked
  (GtkButton * button, gpointer user_data)
{
  if (c_var.button_raster_active != 1)
    {
      c_var.button_raster_active = 1;
      c_var.matrix_change_cell_property = 1;
    }
  else
    {
      c_var.button_raster_active = 0;
      c_var.matrix_change_cell_property = 0;
    }
  //printf("raster cell %d\n",c_var.matrix_change_cell_property);
}

void
on_button_mesh_properties_clicked (GtkButton * button, gpointer user_data)
{
  if (c_var.button_mesh_active != 5)
    {
      c_var.button_mesh_active = 5;
      c_var.matrix_change_cell_property = 3;
    }
  else
    {
      c_var.button_mesh_active = 0;
      c_var.matrix_change_cell_property = 0;
    }
}

void
create_change_cell_properties (int ix, int iy, double *matrix, int m, int n)
{
  GtkWidget *cellproperties;

  c_var.mapsvector[c_var.actualmap].cell_prop_tmp_cellxcoord = iy;
  c_var.mapsvector[c_var.actualmap].cell_prop_tmp_cellycoord = ix;
  c_var.mapsvector[c_var.actualmap].cell_prop_tmp_xcoord = c_var.mapsvector[c_var.actualmap].xmin+iy*(c_var.mapsvector[c_var.actualmap].xmax-c_var.mapsvector[c_var.actualmap].xmin)/(c_var.mapsvector[c_var.actualmap].raster_ncol);	
  c_var.mapsvector[c_var.actualmap].cell_prop_tmp_ycoord = c_var.mapsvector[c_var.actualmap].ymin+ix*(c_var.mapsvector[c_var.actualmap].ymax-c_var.mapsvector[c_var.actualmap].ymin)/(c_var.mapsvector[c_var.actualmap].raster_nrow);
  c_var.mapsvector[c_var.actualmap].cell_prop_tmp_depth = matrix[ix * n + iy];


  cellproperties = create_window_cell_properties ();
  gtk_widget_show (cellproperties);

  //printf("\n\ndentro de create\n%d %d\n\n",ix,iy);
  //printf("**%f**\n\n",matrix[ix*n+iy]);

}

void
on_cell_properties_depth_entry_changed (GtkEditable * editable,
					gpointer user_data)
{
  //printf("cell entry change\n");
}


gboolean
  on_cell_properties_depth_entry_configure_event
  (GtkWidget * widget, GdkEventConfigure * event, gpointer user_data)
{
  //printf("cell entry configure\n");
  return FALSE;
}


gboolean
  on_cell_properties_cxc_entry_expose_event
  (GtkWidget * widget, GdkEventExpose * event, gpointer user_data)
{
  if (!strcmp (gtk_entry_get_text (GTK_ENTRY (user_data)), "null"))
    {

      char string[1000];
      //(void) sprintf (string, "%d",c_var.mapsvector[c_var.actualmap].cell_prop_tmp_cellxcoord);
      g_snprintf (string, 1000, "%d", c_var.mapsvector[c_var.actualmap].cell_prop_tmp_cellxcoord);

      //printf("%s\n",string);
      gtk_entry_set_text (GTK_ENTRY (user_data), string);
      //g_free(string);

    }
  else
    {
      //gtk_entry_set_text (GTK_ENTRY (user_data), _("b"));

    }

  return FALSE;
}


gboolean
  on_cell_properties_cyc_entry_expose_event
  (GtkWidget * widget, GdkEventExpose * event, gpointer user_data)
{
  if (!strcmp (gtk_entry_get_text (GTK_ENTRY (user_data)), "null"))
    {

      char string[1000];
      //(void) sprintf (string, "%d",c_var.mapsvector[c_var.actualmap].cell_prop_tmp_cellycoord);
      g_snprintf (string, 1000, "%d",c_var.mapsvector[c_var.actualmap].cell_prop_tmp_cellycoord);

      //printf("%s\n",string);
      gtk_entry_set_text (GTK_ENTRY (user_data), string);
      //g_free(string);

    }
  else
    {
      //gtk_entry_set_text (GTK_ENTRY (user_data), _("b"));

    }
  return FALSE;
}


gboolean
  on_cell_properties_xc_entry_expose_event
  (GtkWidget * widget, GdkEventExpose * event, gpointer user_data)
{
  if (!strcmp (gtk_entry_get_text (GTK_ENTRY (user_data)), "null"))
    {
      char string[1000];
      //(void) sprintf (string, "%f",c_var.mapsvector[c_var.actualmap].cell_prop_tmp_xcoord);

      g_snprintf (string, 1000, "%f",c_var.mapsvector[c_var.actualmap].cell_prop_tmp_xcoord);
      //printf("xc %s\n",string);
      gtk_entry_set_text (GTK_ENTRY (user_data), string);
      //g_free(string);

    }
  else
    {
      //gtk_entry_set_text (GTK_ENTRY (user_data), _("b"));

    }
  return FALSE;
}


gboolean
  on_cell_properties_yc_entry_expose_event
  (GtkWidget * widget, GdkEventExpose * event, gpointer user_data)
{
  if (!strcmp (gtk_entry_get_text (GTK_ENTRY (user_data)), "null"))
    {
      char string[1000];
      //(void) sprintf (string, "%f",c_var.mapsvector[c_var.actualmap].cell_prop_tmp_ycoord);

      g_snprintf (string, 1000, "%f", c_var.mapsvector[c_var.actualmap].cell_prop_tmp_ycoord);
      //printf("%s\n",string);
      gtk_entry_set_text (GTK_ENTRY (user_data), string);
      //g_free(string);
    }
  else
    {
      //gtk_entry_set_text (GTK_ENTRY (user_data), _("b"));

    }
  return FALSE;
}


gboolean
  on_cell_properties_depth_entry_expose_event
  (GtkWidget * widget, GdkEventExpose * event, gpointer user_data)
{
  char string[1000];
  if (!strcmp (gtk_entry_get_text (GTK_ENTRY (user_data)), "null"))
    {
      //(void) sprintf (string, "%f", c_var.mapsvector[c_var.actualmap].cell_prop_tmp_depth);

      g_snprintf (string, 1000, "%f",c_var.mapsvector[c_var.actualmap].cell_prop_tmp_depth);    
      gtk_entry_set_text (GTK_ENTRY (user_data), string);
      //g_free(string);
    }
  else
    {
      //gtk_entry_set_text (GTK_ENTRY (user_data), _("b"));

    }
  return FALSE;
}


void
  on_cell_properties_depth_entry_activate
  (GtkEntry * entry, gpointer user_data)
{

  char string[1000];
  double tmp;
  GtkWidget *tmp_widget;
  GdkEventConfigure *tmpconfigureevent;
  gboolean tmpboolean;

  //sprintf (string, "%s", gtk_entry_get_text (GTK_ENTRY (user_data)));

  g_snprintf (string, 1000, "%s", gtk_entry_get_text (GTK_ENTRY (user_data)));


  tmp = strtod (gtk_entry_get_text (GTK_ENTRY (user_data)), NULL);

  if (c_var.matrix_change_cell_property == 1)
    {
      c_var.mapsvector[c_var.actualmap].raster_data[c_var.
						    mapsvector[c_var.
							       actualmap].
						    cell_prop_tmp_cellycoord
						    *
						    c_var.mapsvector[c_var.
								     actualmap].
						    raster_ncol +
						    c_var.mapsvector[c_var.
								     actualmap].
						    cell_prop_tmp_cellxcoord]
	= tmp;
      c_var.mapsvector[c_var.actualmap].raster_mask[c_var.
						    mapsvector[c_var.
							       actualmap].
						    cell_prop_tmp_cellycoord
						    *
						    c_var.mapsvector[c_var.
								     actualmap].
						    raster_ncol +
						    c_var.mapsvector[c_var.
								     actualmap].
						    cell_prop_tmp_cellxcoord]
	= 1;
  /*
      tmp_widget = lookup_widget (entry, "drawingarea2");
      gtk_signal_emit_by_name (GTK_OBJECT (tmp_widget), "configure_event",
			       tmpconfigureevent, &tmpboolean);
 */
 }
  else if ((c_var.matrix_change_cell_property == 2)
	   || (c_var.matrix_change_cell_property == 3))
    {
      c_var.mapsvector[c_var.actualmap].raster_data_interpolated[c_var.
								 mapsvector
								 [c_var.
								  actualmap].
								 cell_prop_tmp_cellycoord
								 *
								 c_var.
								 mapsvector
								 [c_var.
								  actualmap].
								 raster_ncol
								 +
								 c_var.
								 mapsvector
								 [c_var.
								  actualmap].
								 cell_prop_tmp_cellxcoord]
	= tmp;
      c_var.mapsvector[c_var.actualmap].raster_mask[c_var.
						    mapsvector[c_var.
							       actualmap].
						    cell_prop_tmp_cellycoord
						    *
						    c_var.mapsvector[c_var.
								     actualmap].
						    raster_ncol +
						    c_var.mapsvector[c_var.
								     actualmap].
						    cell_prop_tmp_cellxcoord]
	= 1;
      /*
      tmp_widget = lookup_widget (entry, "drawingarea3");
  gtk_signal_emit_by_name (GTK_OBJECT (tmp_widget), "configure_event",
			   tmpconfigureevent, &tmpboolean);
               tmp_widget = lookup_widget (entry, "drawingarea4");
  gtk_signal_emit_by_name (GTK_OBJECT (tmp_widget), "configure_event",
			   tmpconfigureevent, &tmpboolean);
  */       
  }
}


void
on_button_mesh_check_courant_clicked (GtkButton * button, gpointer user_data)
{

  GtkWidget *window_courant_properties;

  if (c_var.mapsvector[c_var.actualmap].courant_dt == -1)
    {
      c_var.mapsvector[c_var.actualmap].courant_dt = 1;
    }
  if (c_var.mapsvector[c_var.actualmap].courant_max_speed == -1)
    {
      c_var.mapsvector[c_var.actualmap].courant_max_speed =
	sqrt (2 * 9.81 *
	      sqrt (pow
		    (c_var.mapsvector[c_var.actualmap].zmax -
		     c_var.mapsvector[c_var.actualmap].zmin, 2)));
    }
  if (c_var.mapsvector[c_var.actualmap].courant_dx == -1)
    {
      c_var.mapsvector[c_var.actualmap].courant_dx =
	c_var.mapsvector[c_var.actualmap].courant_dt *
	c_var.mapsvector[c_var.actualmap].courant_max_speed;
    }
  window_courant_properties = create_window_courant_properties ();

  gtk_widget_show (window_courant_properties);

}


gboolean
  on_courant_dt_property_entry_expose_event
  (GtkWidget * widget, GdkEventExpose * event, gpointer user_data)
{
  char string[1000];
  if (!strcmp (gtk_entry_get_text (GTK_ENTRY (user_data)), "null"))
    {
      (void) sprintf (string, "%f",
		      c_var.mapsvector[c_var.actualmap].courant_dt);


      gtk_entry_set_text (GTK_ENTRY (user_data), string);
      //g_free(string);
    }
  else
    {
      //gtk_entry_set_text (GTK_ENTRY (user_data), _("b"));

    }
  return FALSE;
}


gboolean
  on_courant_speed_property_entry_expose_event
  (GtkWidget * widget, GdkEventExpose * event, gpointer user_data)
{
  char string[1000];
  if (!strcmp (gtk_entry_get_text (GTK_ENTRY (user_data)), "null"))
    {
      (void) sprintf (string, "%f",
		      c_var.mapsvector[c_var.actualmap].courant_max_speed);

      gtk_entry_set_text (GTK_ENTRY (user_data), string);
      //g_free(string);
    }
  else
    {
      //gtk_entry_set_text (GTK_ENTRY (user_data), _("b"));

    }
  return FALSE;
}


gboolean
  on_courant_dx_property_entry_expose_event
  (GtkWidget * widget, GdkEventExpose * event, gpointer user_data)
{
  char string[1000];
  if (!strcmp (gtk_entry_get_text (GTK_ENTRY (user_data)), "null"))
    {
      (void) sprintf (string, "%f",
		      c_var.mapsvector[c_var.actualmap].courant_dx);

      gtk_entry_set_text (GTK_ENTRY (user_data), string);
      //g_free(string);
    }
  else
    {
      //gtk_entry_set_text (GTK_ENTRY (user_data), _("b"));

    }
  return FALSE;
}


void
  on_courant_properties_ok_button_clicked
  (GtkButton * button, gpointer user_data)
{
  int i;
  int a, b;
  double width;

  //lineas verticales
  //printf("verificando courant\n");
  i = 0;
  width =
    sqrt (pow
	  (c_var.mapsvector[c_var.actualmap].xmin -
	   c_var.mapsvector[c_var.actualmap].xmax,
	   2)) / c_var.mapsvector[c_var.actualmap].raster_ncol;
  while (c_var.mapsvector[c_var.actualmap].horizontal_mesh[i] != 1
	 && c_var.mapsvector[c_var.actualmap].raster_ncol + 1)
    {
      i++;
      a = i;
      //printf("%d tiene la primera linea\n",a);

    }
  //printf("%d tiene la primera linea\n",a);
  for (i = a + 1; i < c_var.mapsvector[c_var.actualmap].raster_ncol + 1; i++)
    {
      if (c_var.mapsvector[c_var.actualmap].horizontal_mesh[i] == 1)
	{
	  b = i;
	  if ((b - a) * width < c_var.mapsvector[c_var.actualmap].courant_dx)
	    {
	      printf ("No esta cumpliendo courant entre %d %d\n", a, b);

	    }
	  a = b;
	}
    }


//lineas horizontales
  i = 0;
  width =
    sqrt (pow
	  (c_var.mapsvector[c_var.actualmap].ymin -
	   c_var.mapsvector[c_var.actualmap].ymax,
	   2)) / c_var.mapsvector[c_var.actualmap].raster_nrow;
  while (c_var.mapsvector[c_var.actualmap].vertical_mesh[i] != 1
	 && c_var.mapsvector[c_var.actualmap].raster_nrow + 1)
    {
      i++;
      a = i;
      //printf("%d tiene la primera linea\n",a);

    }
  //printf("%d tiene la primera linea\n",a);
  for (i = a + 1; i < c_var.mapsvector[c_var.actualmap].raster_nrow + 1; i++)
    {
      if (c_var.mapsvector[c_var.actualmap].vertical_mesh[i] == 1)
	{
	  b = i;
	  if ((b - a) * width < c_var.mapsvector[c_var.actualmap].courant_dx)
	    {
	      printf ("No esta cumpliendo courant entre %d %d\n", a, b);

	    }
	  a = b;
	}
    }
}


void
on_courant_dt_property_entry_activate (GtkEntry * entry, gpointer user_data)
{

  char string[1000];
  double tmp;
  //printf("entry activate\n");
  sprintf (string, "%s", gtk_entry_get_text (GTK_ENTRY (user_data)));
  tmp = strtod (gtk_entry_get_text (GTK_ENTRY (user_data)), NULL);

  c_var.mapsvector[c_var.actualmap].courant_dt = tmp;
  c_var.mapsvector[c_var.actualmap].courant_dx =
    c_var.mapsvector[c_var.actualmap].courant_dt *
    c_var.mapsvector[c_var.actualmap].courant_max_speed;

}


void
  on_courant_speed_property_entry_activate
  (GtkEntry * entry, gpointer user_data)
{
  char string[1000];
  double tmp;
  //printf("entry activate\n");
  sprintf (string, "%s", gtk_entry_get_text (GTK_ENTRY (user_data)));
  tmp = strtod (gtk_entry_get_text (GTK_ENTRY (user_data)), NULL);

  c_var.mapsvector[c_var.actualmap].courant_max_speed = tmp;
  c_var.mapsvector[c_var.actualmap].courant_dx =
    c_var.mapsvector[c_var.actualmap].courant_dt *
    c_var.mapsvector[c_var.actualmap].courant_max_speed;

}


void
on_courant_dx_property_entry_activate (GtkEntry * entry, gpointer user_data)
{

}


void
on_raster_brush_button_clicked (GtkButton * button, gpointer user_data)
{
  GtkWidget *window_brush_properties;
  if (c_var.button_raster_active != 2)
    {
      c_var.button_raster_active = 2;
      c_var.matrix_change_cell_property = 1;
    }
  else
    {
      c_var.button_raster_active = 0;
      c_var.matrix_change_cell_property = 0;
    }





  window_brush_properties = create_window_brush_configure ();

  gtk_widget_show (window_brush_properties);


}

void
on_brush_level_entry_activate (GtkEntry * entry, gpointer user_data)
{
  char string[1000];
  double tmp;
  //printf("entry activate\n");
  sprintf (string, "%s", gtk_entry_get_text (GTK_ENTRY (user_data)));
  tmp = strtod (gtk_entry_get_text (GTK_ENTRY (user_data)), NULL);

  c_var.mapsvector[c_var.actualmap].brush_level = tmp;

}


gboolean
on_brush_level_entry_expose_event (GtkWidget * widget,
				   GdkEventExpose * event, gpointer user_data)
{
  char string[1000];
  if (!strcmp (gtk_entry_get_text (GTK_ENTRY (user_data)), "null"))
    {
      (void) sprintf (string, "%f",
		      c_var.mapsvector[c_var.actualmap].brush_level);

      gtk_entry_set_text (GTK_ENTRY (user_data), string);
      //g_free(string);
    }
  else
    {
      //gtk_entry_set_text (GTK_ENTRY (user_data), _("b"));

    }
  return FALSE;
}

gboolean
on_drawingarea2_event (GtkWidget * widget,
		       GdkEvent * event, gpointer user_data)
{

  return FALSE;
}



void
on_fileselection2_ok_button1_clicked (GtkButton * button, gpointer user_data)
{

  write_map (gtk_file_selection_get_filename (GTK_FILE_SELECTION (button)),
	     c_var.mapsvector[c_var.actualmap]);

}


void
on_button_defmesh_export_elcom_clicked (GtkButton * button,
					gpointer user_data)
{
  GtkWidget *filesel_export_elcom;
  filesel_export_elcom = create_fileselection_export_elcom ();
  gtk_widget_show (filesel_export_elcom);
}


void
  on_fileselection_export_elcom_ok_button2_clicked
  (GtkButton * button, gpointer user_data)
{
  write_elcom (gtk_file_selection_get_filename
	       (GTK_FILE_SELECTION (button)),
	       c_var.mapsvector[c_var.actualmap]);

}

void
on_map_properties_xmin_entry_activate (GtkEntry * entry, gpointer user_data)
{
  char string[1000];
  double tmp;

  sprintf (string, "%s", gtk_entry_get_text (GTK_ENTRY (user_data)));
  tmp = strtod (gtk_entry_get_text (GTK_ENTRY (user_data)), NULL);

  c_var.mapsvector[c_var.actualmap].xmin = tmp;
}


gboolean
  on_map_properties_xmin_entry_expose_event
  (GtkWidget * widget, GdkEventExpose * event, gpointer user_data)
{
  char string[1000];
  if (!strcmp (gtk_entry_get_text (GTK_ENTRY (user_data)), "null"))
    {
      (void) sprintf (string, "%f", c_var.mapsvector[c_var.actualmap].xmin);

      gtk_entry_set_text (GTK_ENTRY (user_data), string);
      //g_free(string);
    }
  else
    {
      //gtk_entry_set_text (GTK_ENTRY (user_data), _("b"));

    }
  return FALSE;
}


void
on_map_properties_xmax_entry_activate (GtkEntry * entry, gpointer user_data)
{
  char string[1000];
  double tmp;

  sprintf (string, "%s", gtk_entry_get_text (GTK_ENTRY (user_data)));
  tmp = strtod (gtk_entry_get_text (GTK_ENTRY (user_data)), NULL);

  c_var.mapsvector[c_var.actualmap].xmax = tmp;
}


gboolean
  on_map_properties_xmax_entry_expose_event
  (GtkWidget * widget, GdkEventExpose * event, gpointer user_data)
{
  char string[1000];
  if (!strcmp (gtk_entry_get_text (GTK_ENTRY (user_data)), "null"))
    {
      (void) sprintf (string, "%f", c_var.mapsvector[c_var.actualmap].xmax);

      gtk_entry_set_text (GTK_ENTRY (user_data), string);
      //g_free(string);
    }
  else
    {
      //gtk_entry_set_text (GTK_ENTRY (user_data), _("b"));

    }
  return FALSE;
}


void
  on_map_properties_xcells_entry_activate
  (GtkEntry * entry, gpointer user_data)
{
  char string[1000];
  int i;
  int tmp;

  sprintf (string, "%s", gtk_entry_get_text (GTK_ENTRY (user_data)));
  tmp = atoi (gtk_entry_get_text (GTK_ENTRY (user_data)));

  c_var.mapsvector[c_var.actualmap].raster_ncol = tmp;

  //redimencion de las matrices
  //c_var.mapsvector[c_var.actualmap].raster_mesh = (double *)g_try_realloc(c_var.mapsvector[c_var.actualmap].raster_mesh,sizeof(double)*c_var.mapsvector[c_var.actualmap].raster_mesh_ncol*c_var.mapsvector[c_var.actualmap].raster_mesh_nrow);

  c_var.mapsvector[c_var.actualmap].raster_data =
    (double *) g_try_realloc (c_var.mapsvector[c_var.actualmap].raster_data,
			      sizeof (double) *
			      c_var.mapsvector[c_var.actualmap].
			      raster_ncol *
			      c_var.mapsvector[c_var.actualmap].raster_nrow);
  c_var.mapsvector[c_var.actualmap].raster_mask =
    (int *) g_try_realloc (c_var.mapsvector[c_var.actualmap].raster_mask,
			   sizeof (int) *
			   c_var.mapsvector[c_var.actualmap].raster_ncol *
			   c_var.mapsvector[c_var.actualmap].raster_nrow);
  c_var.mapsvector[c_var.actualmap].raster_data_interpolated =
    (double *) g_try_realloc (c_var.mapsvector[c_var.actualmap].
			      raster_data_interpolated,
			      sizeof (double) *
			      c_var.mapsvector[c_var.actualmap].
			      raster_ncol *
			      c_var.mapsvector[c_var.actualmap].raster_nrow);

  c_var.mapsvector[c_var.actualmap].horizontal_mesh =
    (int *) g_try_realloc (c_var.mapsvector[c_var.actualmap].
			   horizontal_mesh,
			   sizeof (int) *
			   (c_var.mapsvector[c_var.actualmap].raster_ncol +
			    1));
  c_var.mapsvector[c_var.actualmap].vertical_mesh =
    (int *) g_try_realloc (c_var.mapsvector[c_var.actualmap].vertical_mesh,
			   sizeof (int) *
			   (c_var.mapsvector[c_var.actualmap].raster_nrow +
			    1));
  for (i = 0; i < c_var.mapsvector[c_var.actualmap].raster_ncol + 1; i++)
    {
      c_var.mapsvector[c_var.actualmap].horizontal_mesh[i] = 0;
    }
  for (i = 0; i < c_var.mapsvector[c_var.actualmap].raster_nrow + 1; i++)
    {
      c_var.mapsvector[c_var.actualmap].vertical_mesh[i] = 0;
    }



}


gboolean
  on_map_properties_xcells_entry_expose_event
  (GtkWidget * widget, GdkEventExpose * event, gpointer user_data)
{
  char string[1000];
  if (!strcmp (gtk_entry_get_text (GTK_ENTRY (user_data)), "null"))
    {
      (void) sprintf (string, "%d",
		      c_var.mapsvector[c_var.actualmap].raster_ncol);

      gtk_entry_set_text (GTK_ENTRY (user_data), string);
      //g_free(string);
    }
  else
    {
      //gtk_entry_set_text (GTK_ENTRY (user_data), _("b"));

    }
  return FALSE;
}


void
  on_map_properties_landvalue_entry_activate
  (GtkEntry * entry, gpointer user_data)
{
  char string[1000];
  double tmp;

  sprintf (string, "%s", gtk_entry_get_text (GTK_ENTRY (user_data)));
  tmp = strtod (gtk_entry_get_text (GTK_ENTRY (user_data)), NULL);

  c_var.mapsvector[c_var.actualmap].land_boundary = tmp;
}


gboolean
  on_map_properties_landvalue_entry_expose_event
  (GtkWidget * widget, GdkEventExpose * event, gpointer user_data)
{
  char string[1000];
  if (!strcmp (gtk_entry_get_text (GTK_ENTRY (user_data)), "null"))
    {
      (void) sprintf (string, "%f",
		      c_var.mapsvector[c_var.actualmap].land_boundary);

      gtk_entry_set_text (GTK_ENTRY (user_data), string);
      //g_free(string);
    }
  else
    {
      //gtk_entry_set_text (GTK_ENTRY (user_data), _("b"));

    }
  return FALSE;
}


void
on_map_properties_ymin_entry_activate (GtkEntry * entry, gpointer user_data)
{
  char string[1000];
  double tmp;

  sprintf (string, "%s", gtk_entry_get_text (GTK_ENTRY (user_data)));
  tmp = strtod (gtk_entry_get_text (GTK_ENTRY (user_data)), NULL);

  c_var.mapsvector[c_var.actualmap].ymin = tmp;
}


gboolean
  on_map_properties_ymin_entry_expose_event
  (GtkWidget * widget, GdkEventExpose * event, gpointer user_data)
{
  char string[1000];
  if (!strcmp (gtk_entry_get_text (GTK_ENTRY (user_data)), "null"))
    {
      (void) sprintf (string, "%f", c_var.mapsvector[c_var.actualmap].ymin);

      gtk_entry_set_text (GTK_ENTRY (user_data), string);
      //g_free(string);
    }
  else
    {
      //gtk_entry_set_text (GTK_ENTRY (user_data), _("b"));

    }
  return FALSE;
}


void
on_map_properties_ymax_entry_activate (GtkEntry * entry, gpointer user_data)
{
  char string[1000];
  double tmp;
  //printf("entry activate\n");
  sprintf (string, "%s", gtk_entry_get_text (GTK_ENTRY (user_data)));
  tmp = strtod (gtk_entry_get_text (GTK_ENTRY (user_data)), NULL);

  c_var.mapsvector[c_var.actualmap].ymax = tmp;

}


gboolean
  on_map_properties_ymax_entry_expose_event
  (GtkWidget * widget, GdkEventExpose * event, gpointer user_data)
{
  char string[1000];
  if (!strcmp (gtk_entry_get_text (GTK_ENTRY (user_data)), "null"))
    {
      (void) sprintf (string, "%f", c_var.mapsvector[c_var.actualmap].ymax);

      gtk_entry_set_text (GTK_ENTRY (user_data), string);
      //g_free(string);
    }
  else
    {
      //gtk_entry_set_text (GTK_ENTRY (user_data), _("b"));

    }
  return FALSE;
}


void
  on_map_properties_ycells_entry_activate
  (GtkEntry * entry, gpointer user_data)
{
  char string[1000];
  int i;
  int tmp;
  //printf("entry activate\n");
  sprintf (string, "%s", gtk_entry_get_text (GTK_ENTRY (user_data)));
  tmp = atoi (gtk_entry_get_text (GTK_ENTRY (user_data)));

  c_var.mapsvector[c_var.actualmap].raster_nrow = tmp;

  //redimencion de las matrices
  //c_var.mapsvector[c_var.actualmap].raster_mesh = (double *)g_try_realloc(c_var.mapsvector[c_var.actualmap].raster_mesh,sizeof(double)*c_var.mapsvector[c_var.actualmap].raster_mesh_ncol*c_var.mapsvector[c_var.actualmap].raster_mesh_nrow);

  c_var.mapsvector[c_var.actualmap].raster_data =
    (double *) g_try_realloc (c_var.mapsvector[c_var.actualmap].raster_data,
			      sizeof (double) *
			      c_var.mapsvector[c_var.actualmap].
			      raster_ncol *
			      c_var.mapsvector[c_var.actualmap].raster_nrow);
  c_var.mapsvector[c_var.actualmap].raster_mask =
    (int *) g_try_realloc (c_var.mapsvector[c_var.actualmap].raster_mask,
			   sizeof (int) *
			   c_var.mapsvector[c_var.actualmap].raster_ncol *
			   c_var.mapsvector[c_var.actualmap].raster_nrow);
  c_var.mapsvector[c_var.actualmap].raster_data_interpolated =
    (double *) g_try_realloc (c_var.mapsvector[c_var.actualmap].
			      raster_data_interpolated,
			      sizeof (double) *
			      c_var.mapsvector[c_var.actualmap].
			      raster_ncol *
			      c_var.mapsvector[c_var.actualmap].raster_nrow);

  c_var.mapsvector[c_var.actualmap].horizontal_mesh =
    (int *) g_try_realloc (c_var.mapsvector[c_var.actualmap].
			   horizontal_mesh,
			   sizeof (int) *
			   (c_var.mapsvector[c_var.actualmap].raster_ncol +
			    1));
  c_var.mapsvector[c_var.actualmap].vertical_mesh =
    (int *) g_try_realloc (c_var.mapsvector[c_var.actualmap].vertical_mesh,
			   sizeof (int) *
			   (c_var.mapsvector[c_var.actualmap].raster_nrow +
			    1));

  for (i = 0; i < c_var.mapsvector[c_var.actualmap].raster_ncol + 1; i++)
    {
      c_var.mapsvector[c_var.actualmap].horizontal_mesh[i] = 0;
    }
  for (i = 0; i < c_var.mapsvector[c_var.actualmap].raster_nrow + 1; i++)
    {
      c_var.mapsvector[c_var.actualmap].vertical_mesh[i] = 0;
    }
}


gboolean
  on_map_properties_ycells_entry_expose_event
  (GtkWidget * widget, GdkEventExpose * event, gpointer user_data)
{
  char string[1000];
  if (!strcmp (gtk_entry_get_text (GTK_ENTRY (user_data)), "null"))
    {
      (void) sprintf (string, "%d",
		      c_var.mapsvector[c_var.actualmap].raster_nrow);

      gtk_entry_set_text (GTK_ENTRY (user_data), string);
      //g_free(string);
    }
  else
    {
      //gtk_entry_set_text (GTK_ENTRY (user_data), _("b"));

    }
  return FALSE;
}


void
  on_map_properties_openvalue_entry_activate
  (GtkEntry * entry, gpointer user_data)
{
  char string[1000];
  double tmp;
  //printf ("entry activate\n");
  sprintf (string, "%s", gtk_entry_get_text (GTK_ENTRY (user_data)));
  tmp = strtod (gtk_entry_get_text (GTK_ENTRY (user_data)), NULL);

  c_var.mapsvector[c_var.actualmap].open_boundary = tmp;
}


gboolean
  on_map_properties_openvalue_entry_expose_event
  (GtkWidget * widget, GdkEventExpose * event, gpointer user_data)
{
  char string[1000];
  if (!strcmp (gtk_entry_get_text (GTK_ENTRY (user_data)), "null"))
    {
      (void) sprintf (string, "%f",
		      c_var.mapsvector[c_var.actualmap].open_boundary);

      gtk_entry_set_text (GTK_ENTRY (user_data), string);
      //g_free(string);
    }
  else
    {
      //gtk_entry_set_text (GTK_ENTRY (user_data), _("b"));

    }
  return FALSE;
}


void
on_map_properties_zmin_entry_activate (GtkEntry * entry, gpointer user_data)
{
  char string[1000];
  double tmp;
  //printf ("entry activate\n");
  sprintf (string, "%s", gtk_entry_get_text (GTK_ENTRY (user_data)));
  tmp = strtod (gtk_entry_get_text (GTK_ENTRY (user_data)), NULL);

  c_var.mapsvector[c_var.actualmap].zmin = tmp;
}


gboolean
  on_map_properties_zmin_entry_expose_event
  (GtkWidget * widget, GdkEventExpose * event, gpointer user_data)
{
  char string[1000];
  if (!strcmp (gtk_entry_get_text (GTK_ENTRY (user_data)), "null"))
    {
      (void) sprintf (string, "%f", c_var.mapsvector[c_var.actualmap].zmin);

      gtk_entry_set_text (GTK_ENTRY (user_data), string);
      //g_free(string);
    }
  else
    {
      //gtk_entry_set_text (GTK_ENTRY (user_data), _("b"));

    }
  return FALSE;
}


void
on_map_properties_zmax_entry_activate (GtkEntry * entry, gpointer user_data)
{
  char string[1000];
  double tmp;

  sprintf (string, "%s", gtk_entry_get_text (GTK_ENTRY (user_data)));
  tmp = strtod (gtk_entry_get_text (GTK_ENTRY (user_data)), NULL);

  c_var.mapsvector[c_var.actualmap].zmax = tmp;
}


gboolean
  on_map_properties_zmax_entry_expose_event
  (GtkWidget * widget, GdkEventExpose * event, gpointer user_data)
{
  char string[1000];
  if (!strcmp (gtk_entry_get_text (GTK_ENTRY (user_data)), "null"))
    {
      (void) sprintf (string, "%f", c_var.mapsvector[c_var.actualmap].zmax);

      gtk_entry_set_text (GTK_ENTRY (user_data), string);
      //g_free(string);
    }
  else
    {
      //gtk_entry_set_text (GTK_ENTRY (user_data), _("b"));

    }
  return FALSE;
}


void
  on_map_properties_zlayers_entry_activate
  (GtkEntry * entry, gpointer user_data)
{
  char string[1000];
  int tmp;

  sprintf (string, "%s", gtk_entry_get_text (GTK_ENTRY (user_data)));
  tmp = atoi (gtk_entry_get_text (GTK_ENTRY (user_data)));

  c_var.mapsvector[c_var.actualmap].nlayers = tmp;
}


gboolean
  on_map_properties_zlayers_entry_expose_event
  (GtkWidget * widget, GdkEventExpose * event, gpointer user_data)
{
  char string[1000];
  if (!strcmp (gtk_entry_get_text (GTK_ENTRY (user_data)), "null"))
    {
      (void) sprintf (string, "%d",
		      c_var.mapsvector[c_var.actualmap].nlayers);

      gtk_entry_set_text (GTK_ENTRY (user_data), string);
      //g_free(string);
    }
  else
    {
      //gtk_entry_set_text (GTK_ENTRY (user_data), _("b"));

    }
  return FALSE;
}


void
on_button3_clicked (GtkButton * button, gpointer user_data)
{
  GtkWidget *mapproperties;

  mapproperties = create_window_map_properties ();
  gtk_widget_show (mapproperties);

}


void
  on_map_properties_interpolation_precision_entry_activate
  (GtkEntry * entry, gpointer user_data)
{
  char string[1000];
  double tmp;

  sprintf (string, "%s", gtk_entry_get_text (GTK_ENTRY (user_data)));
  tmp = strtod (gtk_entry_get_text (GTK_ENTRY (user_data)), NULL);

  c_var.mapsvector[c_var.actualmap].interpolation_precision = tmp;
}


gboolean
  on_map_properties_interpolation_precision_entry_expose_event
  (GtkWidget * widget, GdkEventExpose * event, gpointer user_data)
{
  char string[1000];
  if (!strcmp (gtk_entry_get_text (GTK_ENTRY (user_data)), "null"))
    {
      (void) sprintf (string, "%f",
		      c_var.mapsvector[c_var.actualmap].
		      interpolation_precision);

      gtk_entry_set_text (GTK_ENTRY (user_data), string);
      //g_free(string);
    }
  else
    {
      //gtk_entry_set_text (GTK_ENTRY (user_data), _("b"));

    }
  return FALSE;;
}


void
  on_map_properties_interpolation_maxiter_entry_activate
  (GtkEntry * entry, gpointer user_data)
{
  char string[1000];
  int tmp;

  sprintf (string, "%s", gtk_entry_get_text (GTK_ENTRY (user_data)));
  tmp = atoi (gtk_entry_get_text (GTK_ENTRY (user_data)));

  c_var.mapsvector[c_var.actualmap].interpolation_maxiter = tmp;
}


gboolean
  on_map_properties_interpolation_maxiter_entry_expose_event
  (GtkWidget * widget, GdkEventExpose * event, gpointer user_data)
{
  char string[1000];
  if (!strcmp (gtk_entry_get_text (GTK_ENTRY (user_data)), "null"))
    {
      (void) sprintf (string, "%d",
		      c_var.mapsvector[c_var.actualmap].
		      interpolation_maxiter);

      gtk_entry_set_text (GTK_ENTRY (user_data), string);
      //g_free(string);
    }
  else
    {
      //gtk_entry_set_text (GTK_ENTRY (user_data), _("b"));

    }
  return FALSE;
}


gboolean
on_vruler2_configure_event (GtkWidget * widget,
			    GdkEventConfigure * event, gpointer user_data)
{
  gtk_ruler_set_range (GTK_RULER (widget),
		       c_var.mapsvector[c_var.actualmap].zmax,
		       c_var.mapsvector[c_var.actualmap].zmin, 0, 1000);

  return FALSE;
}


gboolean
on_drawingarea6_configure_event (GtkWidget * widget,
				 GdkEventConfigure * event,
				 gpointer user_data)
{

  if (pixmap6)
    {
      gdk_pixmap_unref (pixmap6);
    }

  pixmap6 = gdk_pixmap_new (widget->window,
			    widget->allocation.width,
			    widget->allocation.height, -1);

  if (c_var.mapsvector[c_var.actualmap].raster_data != NULL
      && c_var.actualmap > -1)
    {

      create_pixmap_create_scale (widget, pixmap6,
				  c_var.mapsvector[c_var.actualmap].zmin,
				  c_var.mapsvector[c_var.actualmap].zmax);
    }
  else
    {
      gdk_draw_rectangle (pixmap6,
			  widget->style->white_gc,
			  TRUE,
			  0, 0,
			  widget->allocation.width,
			  widget->allocation.height);
    }


  gdk_draw_pixmap (widget->window,
		   widget->style->fg_gc[GTK_WIDGET_STATE (widget)],
		   pixmap6,
		   0, 0,
		   0, 0, widget->allocation.width, widget->allocation.height);

  return FALSE;

}


gboolean
on_drawingarea6_expose_event (GtkWidget * widget,
			      GdkEventExpose * event, gpointer user_data)
{

  gdk_draw_pixmap (widget->window,
		   widget->style->fg_gc[GTK_WIDGET_STATE (widget)],
		   pixmap6,
		   0, 0,
		   0, 0, widget->allocation.width, widget->allocation.height);
  return FALSE;

}


int
create_pixmap_create_scale (GtkWidget * widget, GdkPixmap * pixmap,
			    double min, double max)
{

  int i, j;
  int indice;
  GdkColor color;
  char string[50];

  PangoFontDescription *font;
  PangoContext *context;
  PangoLayout *layout;


  GdkGC **palette;
  GdkGC *color_black;

  GdkGC *Nor_gc;

  int palette_elev[256 * 3] = {
    13005, 14138, 14905, 15670, 16430, 17187, 17941, 18690, 19435, 20176,
    20913, 21645, 22373, 23096, 23814, 24526, 25234, 25936, 26633, 27324,
    28010, 28689, 29363, 30031, 30693, 31348, 31997, 32639, 33275, 33904,
    34526, 35142, 35750, 36351, 36945, 37532, 38112, 38684, 39249, 39806,
    40355, 40897, 41431, 41957, 42475, 42985, 43487, 43981, 44467, 44945,
    45414, 45875, 46328, 46772, 47208, 47636, 48054, 48465, 48867, 49260,
    49644, 50020, 50388, 50746, 51096, 51437, 51770, 52093, 52408, 52714,
    53012, 53301, 53581, 53852, 54114, 54368, 54613, 54850, 55078, 55297,
    55507, 55709, 55902, 56087, 56263, 56431, 56591, 56742, 56884, 57018,
    57145, 57262, 57372, 57474, 57567, 57653, 57730, 57800, 57862, 57917,
    57963, 58002, 58034, 58058, 58075, 58084, 58087, 58082, 58070, 58052,
    58026, 57994, 57956, 57911, 57859, 57801, 57737, 57667, 57591, 57509,
    57422, 57329, 57230, 57126, 57017, 56903, 56784, 56660, 56532, 56399,
    56262, 56120, 55975, 55825, 55672, 55515, 55355, 55191, 55024, 54855,
    54682, 54507, 54330, 54150, 53968, 53784, 53599, 53412, 53224, 53034,
    52844, 52653, 52461, 52269, 52077, 51885, 51693, 51502, 51311, 51121,
    50932, 50745, 50559, 50375, 50193, 50014, 49836, 49662, 49490, 49322,
    49157, 48996, 48838, 48685, 48536, 48392, 48253, 48119, 47991, 47868,
    47751, 47641, 47537, 47440, 47349, 47267, 47192, 47125, 47066, 47015,
    46973, 46941, 46918, 46904, 46901, 46907, 46925, 46953, 46992, 47043,
    47106, 47181, 47269, 47369, 47482, 47609, 47750, 47904, 48073, 48257,
    48456, 48671, 48901, 49148, 49411, 49690, 49987, 50302, 50635, 50985,
    51355, 51743, 52151, 52579, 53027, 53495, 53984, 54495, 55027, 55581,
    56158, 56757, 57380, 58026, 58696, 59391, 60110, 60855, 61625, 62422,
    63245, 64094, 64971, 65025, 65025, 65025, 65025, 65025, 65025, 65025,
    65025, 65025, 65025, 65025, 65025, 65025,
    43241, 43422, 43585, 43751, 43920, 44092, 44266, 44442, 44621, 44802,
    44984, 45169, 45354, 45541, 45729, 45918, 46108, 46298, 46488, 46679,
    46870, 47061, 47252, 47442, 47632, 47821, 48010, 48197, 48384, 48569,
    48752, 48935, 49115, 49294, 49471, 49646, 49819, 49990, 50159, 50325,
    50488, 50649, 50807, 50962, 51114, 51263, 51409, 51551, 51691, 51826,
    51959, 52087, 52213, 52334, 52451, 52565, 52675, 52780, 52882, 52979,
    53072, 53161, 53245, 53326, 53401, 53473, 53539, 53602, 53659, 53712,
    53760, 53804, 53843, 53877, 53906, 53931, 53950, 53965, 53975, 53980,
    53981, 53976, 53967, 53952, 53933, 53909, 53880, 53846, 53808, 53764,
    53716, 53663, 53605, 53542, 53475, 53403, 53326, 53245, 53159, 53068,
    52973, 52873, 52770, 52661, 52549, 52432, 52310, 52185, 52056, 51922,
    51785, 51644, 51498, 51349, 51197, 51041, 50881, 50718, 50552, 50382,
    50209, 50033, 49854, 49672, 49488, 49300, 49111, 48918, 48724, 48527,
    48328, 48127, 47924, 47720, 47514, 47306, 47097, 46887, 46675, 46463,
    46250, 46036, 45822, 45607, 45392, 45177, 44963, 44748, 44534, 44320,
    44107, 43895, 43685, 43475, 43267, 43060, 42856, 42653, 42452, 42254,
    42058, 41865, 41675, 41489, 41305, 41125, 40949, 40777, 40609, 40445,
    40286, 40132, 39982, 39838, 39700, 39567, 39441, 39320, 39206, 39098,
    38998, 38904, 38818, 38740, 38670, 38607, 38554, 38508, 38472, 38445,
    38428, 38420, 38422, 38434, 38457, 38491, 38536, 38593, 38661, 38741,
    38833, 38938, 39056, 39187, 39331, 39489, 39662, 39848, 40050, 40266,
    40498, 40745, 41009, 41288, 41585, 41898, 42228, 42577, 42943, 43327,
    43730, 44152, 44594, 45055, 45536, 46037, 46560, 47103, 47668, 48255,
    48863, 49495, 50149, 50827, 51528, 52254, 53004, 53779, 54579, 55404,
    56256, 57134, 58039, 58971, 59931, 60918, 61935, 62980, 64054, 65025,
    65025, 65025, 65025, 65025, 65025, 65025,
    31862, 32280, 32426, 32575, 32728, 32884, 33042, 33203, 33367, 33533,
    33700, 33870, 34041, 34213, 34386, 34560, 34735, 34911, 35087, 35263,
    35439, 35615, 35790, 35965, 36139, 36313, 36485, 36656, 36826, 36994,
    37160, 37325, 37487, 37648, 37806, 37961, 38115, 38265, 38413, 38558,
    38699, 38838, 38973, 39105, 39233, 39357, 39478, 39595, 39708, 39817,
    39922, 40023, 40119, 40211, 40299, 40382, 40460, 40534, 40603, 40667,
    40726, 40780, 40829, 40873, 40912, 40946, 40975, 40998, 41016, 41029,
    41036, 41038, 41035, 41026, 41011, 40992, 40966, 40935, 40899, 40857,
    40810, 40757, 40698, 40634, 40565, 40490, 40410, 40324, 40233, 40136,
    40034, 39926, 39814, 39695, 39572, 39444, 39310, 39171, 39028, 38879,
    38725, 38566, 38403, 38235, 38062, 37885, 37703, 37516, 37325, 37130,
    36931, 36728, 36520, 36309, 36094, 35875, 35653, 35427, 35197, 34965,
    34729, 34490, 34249, 34004, 33757, 33508, 33256, 33002, 32745, 32487,
    32227, 31965, 31702, 31438, 31172, 30905, 30638, 30370, 30101, 29832,
    29563, 29294, 29025, 28756, 28488, 28221, 27955, 27690, 27426, 27164,
    26904, 26646, 26390, 26137, 25886, 25638, 25393, 25152, 24914, 24680,
    24450, 24224, 24003, 23787, 23575, 23369, 23169, 22974, 22786, 22604,
    22428, 22260, 22098, 21944, 21798, 21659, 21529, 21408, 21295, 21192,
    21098, 21014, 20940, 20876, 20823, 20781, 20751, 20732, 20725, 20730,
    20748, 20779, 20823, 20881, 20953, 21039, 21140, 21256, 21387, 21534,
    21697, 21877, 22074, 22287, 22518, 22768, 23035, 23321, 23627, 23951,
    24296, 24661, 25046, 25453, 25881, 26331, 26803, 27298, 27816, 28357,
    28923, 29512, 30127, 30767, 31432, 32124, 32842, 33587, 34359, 35159,
    35988, 36845, 37731, 38647, 39594, 40571, 41579, 42618, 43690, 44794,
    45931, 47101, 48306, 49544, 50818, 52127, 53472, 54854, 56272, 57728,
    59222, 60754, 62326, 63936, 65025, 65025
  };

  palette = (GdkGC **) g_malloc (sizeof (GdkGC *) * 256);


  gdk_draw_rectangle (pixmap,
		      widget->style->white_gc,
		      TRUE,
		      0, 0,
		      (int) (widget->allocation.width),
		      (int) (widget->allocation.height));

  color_black = get_pen (widget->window, new_color (0, 0, 0));

  create_palete (widget, palette, PALETTENUMBER);

  for (i = 0; i < 256; i++)
    {
      //palette[i]= get_pen (widget->window, new_color (palette_elev[256*0+i], palette_elev[256*1+i], palette_elev[256*2+i]));
      gdk_draw_rectangle (pixmap,
			  palette[i],
			  TRUE,
			  0,
			  (int) (.5 * (256 - i) *
				 widget->allocation.height / 256),
			  (int) (widget->allocation.width / 4),
			  (int) (.5 * (256 - i - 1) *
				 widget->allocation.height / 256));

    }



  Nor_gc = gdk_gc_new (widget->window);


  // obtain pango font object
  font = pango_font_description_from_string ("Courier,Medium 10");

  // obtain pango layout object
  context = gtk_widget_create_pango_context (widget);
  layout = pango_layout_new (context);
  g_object_unref (context);

  pango_layout_set_font_description (layout, font);

  // Draw some text

  gdk_gc_set_foreground (Nor_gc, color_black);


  g_snprintf (string, 50, "%f", max);
  pango_layout_set_text (layout, string, -1);
  gdk_draw_layout (pixmap, Nor_gc, (int) (widget->allocation.width / 4), 0,
		   layout);

  g_snprintf (string, 50, "%f", (min + max) / 2);
  pango_layout_set_text (layout, string, -1);
  gdk_draw_layout (pixmap, Nor_gc, (int) (widget->allocation.width / 4),
		   widget->allocation.height / 2 - 5, layout);

  g_snprintf (string, 50, "%f", min);
  pango_layout_set_text (layout, string, -1);
  gdk_draw_layout (pixmap, Nor_gc, (int) (widget->allocation.width / 4),
		   widget->allocation.height - 10, layout);

}


gboolean
on_vruler1_configure_event (GtkWidget * widget,
			    GdkEventConfigure * event, gpointer user_data)
{
  gtk_ruler_set_range (GTK_RULER (widget), 0,
		       c_var.mapsvector[c_var.actualmap].raster_nrow, 0, 10);
  return FALSE;
}

gboolean
on_hruler1_configure_event (GtkWidget * widget,
			    GdkEventConfigure * event, gpointer user_data)
{
  gtk_ruler_set_range (GTK_RULER (widget), 0,
		       c_var.mapsvector[c_var.actualmap].raster_ncol, 0, 10);

  return FALSE;
}


gboolean
on_drawingarea9_configure_event (GtkWidget * widget,
				 GdkEventConfigure * event,
				 gpointer user_data)
{
  int i;
  if (pixmap9)
    {
      gdk_pixmap_unref (pixmap9);
    }

  pixmap9 = gdk_pixmap_new (widget->window,
			    widget->allocation.width,
			    widget->allocation.height, -1);
  if (c_var.mapsvector[c_var.actualmap].raster_mesh != NULL
      && c_var.actualmap > -1)
    {
      //create_pixmap_from_double_irregular (widget,pixmap5,c_var.mapsvector[c_var.actualmap].raster_mesh, c_var.mapsvector[c_var.actualmap].horizontal_mesh_width, c_var.mapsvector[c_var.actualmap].vertical_mesh_width, c_var.mapsvector[c_var.actualmap].raster_mesh_ncol, c_var.mapsvector[c_var.actualmap].raster_mesh_nrow);
      create_pixmap_from_double_irregular (widget, pixmap9,
					   c_var.mapsvector[c_var.
							    actualmap].
					   raster_mesh_advection_number,
					   c_var.mapsvector[c_var.
							    actualmap].
					   horizontal_mesh_width,
					   c_var.mapsvector[c_var.
							    actualmap].
					   vertical_mesh_width,
					   c_var.mapsvector[c_var.
							    actualmap].
					   raster_mesh_ncol,
					   c_var.mapsvector[c_var.
							    actualmap].
					   raster_mesh_nrow);
    }
  else
    {

      gdk_draw_rectangle (pixmap9,
			  widget->style->white_gc,
			  TRUE,
			  0, 0,
			  widget->allocation.width,
			  widget->allocation.height);
    }

  gdk_draw_pixmap (widget->window,
		   widget->style->fg_gc[GTK_WIDGET_STATE (widget)],
		   pixmap9,
		   0, 0,
		   0, 0, widget->allocation.width, widget->allocation.height);

  return TRUE;
}


gboolean
on_drawingarea9_expose_event (GtkWidget * widget,
			      GdkEventExpose * event, gpointer user_data)
{
  gdk_draw_pixmap (widget->window,
		   widget->style->fg_gc[GTK_WIDGET_STATE (widget)],
		   pixmap9,
		   event->area.x, event->area.y,
		   event->area.x, event->area.y,
		   event->area.width, event->area.height);

  return FALSE;
}


gboolean
on_drawingarea10_configure_event (GtkWidget * widget,
				  GdkEventConfigure * event,
				  gpointer user_data)
{
  int i;
  if (pixmap10)
    {
      gdk_pixmap_unref (pixmap10);
    }

  pixmap10 = gdk_pixmap_new (widget->window,
			     widget->allocation.width,
			     widget->allocation.height, -1);
  if (c_var.mapsvector[c_var.actualmap].raster_mesh_standar_desviation !=
      NULL && c_var.actualmap > -1)
    {
      create_pixmap_from_double_irregular (widget, pixmap10,
					   c_var.mapsvector[c_var.
							    actualmap].
					   raster_mesh_standar_desviation,
					   c_var.mapsvector[c_var.
							    actualmap].
					   horizontal_mesh_width,
					   c_var.mapsvector[c_var.
							    actualmap].
					   vertical_mesh_width,
					   c_var.mapsvector[c_var.
							    actualmap].
					   raster_mesh_ncol,
					   c_var.mapsvector[c_var.
							    actualmap].
					   raster_mesh_nrow);
    }
  else
    {

      gdk_draw_rectangle (pixmap10,
			  widget->style->white_gc,
			  TRUE,
			  0, 0,
			  widget->allocation.width,
			  widget->allocation.height);
    }

  gdk_draw_pixmap (widget->window,
		   widget->style->fg_gc[GTK_WIDGET_STATE (widget)],
		   pixmap10,
		   0, 0,
		   0, 0, widget->allocation.width, widget->allocation.height);

  return TRUE;
}


gboolean
on_drawingarea10_expose_event (GtkWidget * widget,
			       GdkEventExpose * event, gpointer user_data)
{
  gdk_draw_pixmap (widget->window,
		   widget->style->fg_gc[GTK_WIDGET_STATE (widget)],
		   pixmap10,
		   event->area.x, event->area.y,
		   event->area.x, event->area.y,
		   event->area.width, event->area.height);

  return FALSE;
}


gboolean
on_drawingarea11_configure_event (GtkWidget * widget,
				  GdkEventConfigure * event,
				  gpointer user_data)
{
  int i;
  if (pixmap11)
    {
      gdk_pixmap_unref (pixmap11);
    }

  pixmap11 = gdk_pixmap_new (widget->window,
			     widget->allocation.width,
			     widget->allocation.height, -1);
  if (c_var.mapsvector[c_var.actualmap].raster_mesh_aspect_ratio != NULL
      && c_var.actualmap > -1)
    {
      create_pixmap_from_double_irregular (widget, pixmap11,
					   c_var.mapsvector[c_var.
							    actualmap].
					   raster_mesh_aspect_ratio,
					   c_var.mapsvector[c_var.
							    actualmap].
					   horizontal_mesh_width,
					   c_var.mapsvector[c_var.
							    actualmap].
					   vertical_mesh_width,
					   c_var.mapsvector[c_var.
							    actualmap].
					   raster_mesh_ncol,
					   c_var.mapsvector[c_var.
							    actualmap].
					   raster_mesh_nrow);
    }
  else
    {

      gdk_draw_rectangle (pixmap11,
			  widget->style->white_gc,
			  TRUE,
			  0, 0,
			  widget->allocation.width,
			  widget->allocation.height);
    }

  gdk_draw_pixmap (widget->window,
		   widget->style->fg_gc[GTK_WIDGET_STATE (widget)],
		   pixmap11,
		   0, 0,
		   0, 0, widget->allocation.width, widget->allocation.height);

  return TRUE;
}


gboolean
on_drawingarea11_expose_event (GtkWidget * widget,
			       GdkEventExpose * event, gpointer user_data)
{
  gdk_draw_pixmap (widget->window,
		   widget->style->fg_gc[GTK_WIDGET_STATE (widget)],
		   pixmap11,
		   event->area.x, event->area.y,
		   event->area.x, event->area.y,
		   event->area.width, event->area.height);

  return FALSE;
}


gboolean
on_vruler3_configure_event (GtkWidget * widget,
			    GdkEventConfigure * event, gpointer user_data)
{
  gtk_ruler_set_range (GTK_RULER (widget),
		       c_var.mapsvector[c_var.actualmap].ymin,
		       c_var.mapsvector[c_var.actualmap].ymax, 0, 10);
  return FALSE;
}


gboolean
on_hruler2_configure_event (GtkWidget * widget,
			    GdkEventConfigure * event, gpointer user_data)
{
  gtk_ruler_set_range (GTK_RULER (widget),
		       c_var.mapsvector[c_var.actualmap].xmin,
		       c_var.mapsvector[c_var.actualmap].xmax, 0, 10000000);

  return FALSE;
}


gboolean
on_vruler6_configure_event (GtkWidget * widget,
			    GdkEventConfigure * event, gpointer user_data)
{

  return FALSE;
}


gboolean
on_vruler9_configure_event (GtkWidget * widget,
			    GdkEventConfigure * event, gpointer user_data)
{

  return FALSE;
}


gboolean
on_vruler16_configure_event (GtkWidget * widget,
			     GdkEventConfigure * event, gpointer user_data)
{
  double max, min;
  int i, j;
  int ncol, nrow;


  max = c_var.mapsvector[c_var.actualmap].raster_mesh[0];
  min = max;
  ncol = c_var.mapsvector[c_var.actualmap].raster_mesh_ncol;
  nrow = c_var.mapsvector[c_var.actualmap].raster_mesh_nrow;

  for (i = 0; i < nrow; i++)
    {
      for (j = 0; j < ncol; j++)
	{
	  if (c_var.mapsvector[c_var.actualmap].raster_mesh[i * ncol + j] >
	      max)
	    {
	      max =
		c_var.mapsvector[c_var.actualmap].raster_mesh[i * ncol + j];
	    }
	  if (c_var.mapsvector[c_var.actualmap].raster_mesh[i * ncol + j] <
	      min)
	    {
	      min =
		c_var.mapsvector[c_var.actualmap].raster_mesh[i * ncol + j];
	    }

	}
    }


  gtk_ruler_set_range (GTK_RULER (widget), max, min, 0, 2 * max);


  return FALSE;
}


gboolean
on_vruler17_configure_event (GtkWidget * widget,
			     GdkEventConfigure * event, gpointer user_data)
{
  //variance

  double max, min;
  int i, j;
  int ncol, nrow;


  max = c_var.mapsvector[c_var.actualmap].raster_mesh_standar_desviation[0];
  min = max;
  ncol = c_var.mapsvector[c_var.actualmap].raster_mesh_ncol;
  nrow = c_var.mapsvector[c_var.actualmap].raster_mesh_nrow;

  for (i = 0; i < nrow; i++)
    {
      for (j = 0; j < ncol; j++)
	{
	  if (c_var.mapsvector[c_var.actualmap].
	      raster_mesh_standar_desviation[i * ncol + j] > max)
	    {
	      max =
		c_var.mapsvector[c_var.actualmap].
		raster_mesh_standar_desviation[i * ncol + j];
	    }
	  if (c_var.mapsvector[c_var.actualmap].
	      raster_mesh_standar_desviation[i * ncol + j] < min)
	    {
	      min =
		c_var.mapsvector[c_var.actualmap].
		raster_mesh_standar_desviation[i * ncol + j];
	    }

	}
    }


  gtk_ruler_set_range (GTK_RULER (widget), max, min, 0, (2 * max));


  return FALSE;
}


gboolean
on_vruler18_configure_event (GtkWidget * widget,
			     GdkEventConfigure * event, gpointer user_data)
{
  double max, min;
  int i, j;
  int ncol, nrow;


  max = c_var.mapsvector[c_var.actualmap].raster_mesh_advection_number[0];
  min = max;
  ncol = c_var.mapsvector[c_var.actualmap].raster_mesh_ncol;
  nrow = c_var.mapsvector[c_var.actualmap].raster_mesh_nrow;

  for (i = 0; i < nrow; i++)
    {
      for (j = 0; j < ncol; j++)
	{
	  if (c_var.mapsvector[c_var.actualmap].
	      raster_mesh_advection_number[i * ncol + j] > max)
	    {
	      max =
		c_var.mapsvector[c_var.actualmap].
		raster_mesh_advection_number[i * ncol + j];
	    }
	  if (c_var.mapsvector[c_var.actualmap].
	      raster_mesh_advection_number[i * ncol + j] < min)
	    {
	      min =
		c_var.mapsvector[c_var.actualmap].
		raster_mesh_advection_number[i * ncol + j];
	    }

	}
    }


  gtk_ruler_set_range (GTK_RULER (widget), max, min, 0, (2 * max));

  return FALSE;
}


gboolean
on_vruler19_configure_event (GtkWidget * widget,
			     GdkEventConfigure * event, gpointer user_data)
{
  double max, min;
  int i, j;
  int ncol, nrow;


  max = c_var.mapsvector[c_var.actualmap].raster_mesh_aspect_ratio[0];
  min = max;
  ncol = c_var.mapsvector[c_var.actualmap].raster_mesh_ncol;
  nrow = c_var.mapsvector[c_var.actualmap].raster_mesh_nrow;

  for (i = 0; i < nrow; i++)
    {
      for (j = 0; j < ncol; j++)
	{
	  if (c_var.mapsvector[c_var.actualmap].
	      raster_mesh_aspect_ratio[i * ncol + j] > max)
	    {
	      max =
		c_var.mapsvector[c_var.actualmap].
		raster_mesh_aspect_ratio[i * ncol + j];
	    }
	  if (c_var.mapsvector[c_var.actualmap].
	      raster_mesh_aspect_ratio[i * ncol + j] < min)
	    {
	      min =
		c_var.mapsvector[c_var.actualmap].
		raster_mesh_aspect_ratio[i * ncol + j];
	    }

	}
    }


  gtk_ruler_set_range (GTK_RULER (widget), max, min, 0, (2 * max));


  return FALSE;

}


gboolean
on_vruler20_configure_event (GtkWidget * widget,
			     GdkEventConfigure * event, gpointer user_data)
{
  double max, min;
  int i, j;
  int ncol, nrow;


  max = c_var.mapsvector[c_var.actualmap].raster_mesh_gradient_horizontal[0];
  min = max;
  ncol = c_var.mapsvector[c_var.actualmap].raster_mesh_ncol;
  nrow = c_var.mapsvector[c_var.actualmap].raster_mesh_nrow;

  for (i = 0; i < nrow; i++)
    {
      for (j = 0; j < ncol; j++)
	{
	  if (c_var.mapsvector[c_var.actualmap].
	      raster_mesh_gradient_horizontal[i * ncol + j] > max)
	    {
	      max =
		c_var.mapsvector[c_var.actualmap].
		raster_mesh_gradient_horizontal[i * ncol + j];
	    }
	  if (c_var.mapsvector[c_var.actualmap].
	      raster_mesh_gradient_horizontal[i * ncol + j] < min)
	    {
	      min =
		c_var.mapsvector[c_var.actualmap].
		raster_mesh_gradient_horizontal[i * ncol + j];
	    }

	}
    }


  gtk_ruler_set_range (GTK_RULER (widget), max, min, 0, (2 * max));


  return FALSE;
}


gboolean
on_vruler24_configure_event (GtkWidget * widget,
			     GdkEventConfigure * event, gpointer user_data)
{
  double max, min;
  int i, j;
  int ncol, nrow;


  max = c_var.mapsvector[c_var.actualmap].raster_mesh_gradient_vertical[0];
  min = max;
  ncol = c_var.mapsvector[c_var.actualmap].raster_mesh_ncol;
  nrow = c_var.mapsvector[c_var.actualmap].raster_mesh_nrow;

  for (i = 0; i < nrow; i++)
    {
      for (j = 0; j < ncol; j++)
	{
	  if (c_var.mapsvector[c_var.actualmap].
	      raster_mesh_gradient_vertical[i * ncol + j] > max)
	    {
	      max =
		c_var.mapsvector[c_var.actualmap].
		raster_mesh_gradient_vertical[i * ncol + j];
	    }
	  if (c_var.mapsvector[c_var.actualmap].
	      raster_mesh_gradient_vertical[i * ncol + j] < min)
	    {
	      min =
		c_var.mapsvector[c_var.actualmap].
		raster_mesh_gradient_vertical[i * ncol + j];
	    }

	}
    }


  gtk_ruler_set_range (GTK_RULER (widget), max, min, 0, (2 * max));


  return FALSE;
}


gboolean
on_drawingarea17_configure_event (GtkWidget * widget,
				  GdkEventConfigure * event,
				  gpointer user_data)
{
  int i;
  if (pixmap17)
    {
      gdk_pixmap_unref (pixmap17);
    }

  pixmap17 = gdk_pixmap_new (widget->window,
			     widget->allocation.width,
			     widget->allocation.height, -1);
  if (c_var.mapsvector[c_var.actualmap].raster_mesh_gradient_horizontal !=
      NULL && c_var.actualmap > -1)
    {
      create_pixmap_from_double_irregular (widget, pixmap17,
					   c_var.mapsvector[c_var.
							    actualmap].
					   raster_mesh_gradient_horizontal,
					   c_var.mapsvector[c_var.
							    actualmap].
					   horizontal_mesh_width,
					   c_var.mapsvector[c_var.
							    actualmap].
					   vertical_mesh_width,
					   c_var.mapsvector[c_var.
							    actualmap].
					   raster_mesh_ncol,
					   c_var.mapsvector[c_var.
							    actualmap].
					   raster_mesh_nrow);
    }
  else
    {

      gdk_draw_rectangle (pixmap17,
			  widget->style->white_gc,
			  TRUE,
			  0, 0,
			  widget->allocation.width,
			  widget->allocation.height);
    }

  gdk_draw_pixmap (widget->window,
		   widget->style->fg_gc[GTK_WIDGET_STATE (widget)],
		   pixmap17,
		   0, 0,
		   0, 0, widget->allocation.width, widget->allocation.height);

  return TRUE;
}


gboolean
on_drawingarea17_expose_event (GtkWidget * widget,
			       GdkEventExpose * event, gpointer user_data)
{
  gdk_draw_pixmap (widget->window,
		   widget->style->fg_gc[GTK_WIDGET_STATE (widget)],
		   pixmap17,
		   event->area.x, event->area.y,
		   event->area.x, event->area.y,
		   event->area.width, event->area.height);

  return FALSE;
}


gboolean
on_drawingarea18_configure_event (GtkWidget * widget,
				  GdkEventConfigure * event,
				  gpointer user_data)
{
  int i;
  if (pixmap18)
    {
      gdk_pixmap_unref (pixmap18);
    }

  pixmap18 = gdk_pixmap_new (widget->window,
			     widget->allocation.width,
			     widget->allocation.height, -1);
  if (c_var.mapsvector[c_var.actualmap].raster_mesh_gradient_vertical !=
      NULL && c_var.actualmap > -1)
    {
      create_pixmap_from_double_irregular (widget, pixmap18,
					   c_var.mapsvector[c_var.
							    actualmap].
					   raster_mesh_gradient_vertical,
					   c_var.mapsvector[c_var.
							    actualmap].
					   horizontal_mesh_width,
					   c_var.mapsvector[c_var.
							    actualmap].
					   vertical_mesh_width,
					   c_var.mapsvector[c_var.
							    actualmap].
					   raster_mesh_ncol,
					   c_var.mapsvector[c_var.
							    actualmap].
					   raster_mesh_nrow);
    }
  else
    {

      gdk_draw_rectangle (pixmap18,
			  widget->style->white_gc,
			  TRUE,
			  0, 0,
			  widget->allocation.width,
			  widget->allocation.height);
    }

  gdk_draw_pixmap (widget->window,
		   widget->style->fg_gc[GTK_WIDGET_STATE (widget)],
		   pixmap18,
		   0, 0,
		   0, 0, widget->allocation.width, widget->allocation.height);

  return TRUE;
}


gboolean
on_drawingarea18_expose_event (GtkWidget * widget,
			       GdkEventExpose * event, gpointer user_data)
{
  gdk_draw_pixmap (widget->window,
		   widget->style->fg_gc[GTK_WIDGET_STATE (widget)],
		   pixmap18,
		   event->area.x, event->area.y,
		   event->area.x, event->area.y,
		   event->area.width, event->area.height);

  return FALSE;
}


gboolean
on_drawingarea7_configure_event (GtkWidget * widget,
				 GdkEventConfigure * event,
				 gpointer user_data)
{
  if (pixmap7)
    {
      gdk_pixmap_unref (pixmap7);
    }

  pixmap7 = gdk_pixmap_new (widget->window,
			    widget->allocation.width,
			    widget->allocation.height, -1);

  if (c_var.mapsvector[c_var.actualmap].raster_data != NULL
      && c_var.actualmap > -1)
    {
      create_pixmap_create_scale (widget, pixmap7,
				  c_var.mapsvector[c_var.actualmap].zmin,
				  c_var.mapsvector[c_var.actualmap].zmax);
    }
  else
    {

      gdk_draw_rectangle (pixmap7,
			  widget->style->white_gc,
			  TRUE,
			  0, 0,
			  widget->allocation.width,
			  widget->allocation.height);
    }


  gdk_draw_pixmap (widget->window,
		   widget->style->fg_gc[GTK_WIDGET_STATE (widget)],
		   pixmap7,
		   0, 0,
		   0, 0, widget->allocation.width, widget->allocation.height);

  return FALSE;

}


gboolean
on_drawingarea7_expose_event (GtkWidget * widget,
			      GdkEventExpose * event, gpointer user_data)
{
  gdk_draw_pixmap (widget->window,
		   widget->style->fg_gc[GTK_WIDGET_STATE (widget)],
		   pixmap7,
		   0, 0,
		   0, 0, widget->allocation.width, widget->allocation.height);
  return FALSE;
}


gboolean
on_drawingarea8_configure_event (GtkWidget * widget,
				 GdkEventConfigure * event,
				 gpointer user_data)
{
  if (pixmap8)
    {
      gdk_pixmap_unref (pixmap8);
    }

  pixmap8 = gdk_pixmap_new (widget->window,
			    widget->allocation.width,
			    widget->allocation.height, -1);

  if (c_var.mapsvector[c_var.actualmap].raster_data != NULL
      && c_var.actualmap > -1)
    {
      create_pixmap_create_scale (widget, pixmap8,
				  c_var.mapsvector[c_var.actualmap].zmin,
				  c_var.mapsvector[c_var.actualmap].zmax);
    }
  else
    {

      gdk_draw_rectangle (pixmap8,
			  widget->style->white_gc,
			  TRUE,
			  0, 0,
			  widget->allocation.width,
			  widget->allocation.height);
    }


  gdk_draw_pixmap (widget->window,
		   widget->style->fg_gc[GTK_WIDGET_STATE (widget)],
		   pixmap8,
		   0, 0,
		   0, 0, widget->allocation.width, widget->allocation.height);

  return FALSE;

}


gboolean
on_drawingarea8_expose_event (GtkWidget * widget,
			      GdkEventExpose * event, gpointer user_data)
{
  gdk_draw_pixmap (widget->window,
		   widget->style->fg_gc[GTK_WIDGET_STATE (widget)],
		   pixmap8,
		   0, 0,
		   0, 0, widget->allocation.width, widget->allocation.height);
  return FALSE;
}


gboolean
on_drawingarea13_configure_event (GtkWidget * widget,
				  GdkEventConfigure * event,
				  gpointer user_data)
{

  double max, min;
  int i, j;
  int ncol, nrow;

  if (pixmap13)
    {
      gdk_pixmap_unref (pixmap13);
    }

  pixmap13 = gdk_pixmap_new (widget->window,
			     widget->allocation.width,
			     widget->allocation.height, -1);

  if (c_var.mapsvector[c_var.actualmap].raster_mesh_standar_desviation !=
      NULL && c_var.actualmap > -1)
    {
      max =
	c_var.mapsvector[c_var.actualmap].raster_mesh_standar_desviation[0];
      min = max;
      ncol = c_var.mapsvector[c_var.actualmap].raster_mesh_ncol;
      nrow = c_var.mapsvector[c_var.actualmap].raster_mesh_nrow;

      for (i = 0; i < nrow; i++)
	{
	  for (j = 0; j < ncol; j++)
	    {
	      if (c_var.mapsvector[c_var.actualmap].
		  raster_mesh_standar_desviation[i * ncol + j] > max)
		{
		  max =
		    c_var.mapsvector[c_var.actualmap].
		    raster_mesh_standar_desviation[i * ncol + j];
		}
	      if (c_var.mapsvector[c_var.actualmap].
		  raster_mesh_standar_desviation[i * ncol + j] < min)
		{
		  min =
		    c_var.mapsvector[c_var.actualmap].
		    raster_mesh_standar_desviation[i * ncol + j];
		}

	    }
	}
      create_pixmap_create_scale (widget, pixmap13, min, max);

    }
  else
    {

      gdk_draw_rectangle (pixmap13,
			  widget->style->white_gc,
			  TRUE,
			  0, 0,
			  widget->allocation.width,
			  widget->allocation.height);
    }


  gdk_draw_pixmap (widget->window,
		   widget->style->fg_gc[GTK_WIDGET_STATE (widget)],
		   pixmap13,
		   0, 0,
		   0, 0, widget->allocation.width, widget->allocation.height);

  return FALSE;
}


gboolean
on_drawingarea13_expose_event (GtkWidget * widget,
			       GdkEventExpose * event, gpointer user_data)
{
  gdk_draw_pixmap (widget->window,
		   widget->style->fg_gc[GTK_WIDGET_STATE (widget)],
		   pixmap13,
		   0, 0,
		   0, 0, widget->allocation.width, widget->allocation.height);
  return FALSE;
}


gboolean
on_drawingarea15_configure_event (GtkWidget * widget,
				  GdkEventConfigure * event,
				  gpointer user_data)
{
  double max, min;
  int i, j;
  int ncol, nrow;

  if (pixmap15)
    {
      gdk_pixmap_unref (pixmap15);
    }

  pixmap15 = gdk_pixmap_new (widget->window,
			     widget->allocation.width,
			     widget->allocation.height, -1);

  if (c_var.mapsvector[c_var.actualmap].raster_mesh_aspect_ratio != NULL
      && c_var.actualmap > -1)
    {
      max = c_var.mapsvector[c_var.actualmap].raster_mesh_aspect_ratio[0];
      min = max;
      ncol = c_var.mapsvector[c_var.actualmap].raster_mesh_ncol;
      nrow = c_var.mapsvector[c_var.actualmap].raster_mesh_nrow;

      for (i = 0; i < nrow; i++)
	{
	  for (j = 0; j < ncol; j++)
	    {
	      if (c_var.mapsvector[c_var.actualmap].
		  raster_mesh_aspect_ratio[i * ncol + j] > max)
		{
		  max =
		    c_var.mapsvector[c_var.actualmap].
		    raster_mesh_aspect_ratio[i * ncol + j];
		}
	      if (c_var.mapsvector[c_var.actualmap].
		  raster_mesh_aspect_ratio[i * ncol + j] < min)
		{
		  min =
		    c_var.mapsvector[c_var.actualmap].
		    raster_mesh_aspect_ratio[i * ncol + j];
		}

	    }
	}
      create_pixmap_create_scale (widget, pixmap15, min, max);

    }
  else
    {

      gdk_draw_rectangle (pixmap15,
			  widget->style->white_gc,
			  TRUE,
			  0, 0,
			  widget->allocation.width,
			  widget->allocation.height);
    }


  gdk_draw_pixmap (widget->window,
		   widget->style->fg_gc[GTK_WIDGET_STATE (widget)],
		   pixmap15,
		   0, 0,
		   0, 0, widget->allocation.width, widget->allocation.height);

  return FALSE;
}


gboolean
on_drawingarea15_expose_event (GtkWidget * widget,
			       GdkEventExpose * event, gpointer user_data)
{
  gdk_draw_pixmap (widget->window,
		   widget->style->fg_gc[GTK_WIDGET_STATE (widget)],
		   pixmap15,
		   0, 0,
		   0, 0, widget->allocation.width, widget->allocation.height);
  return FALSE;
}


gboolean
on_drawingarea14_configure_event (GtkWidget * widget,
				  GdkEventConfigure * event,
				  gpointer user_data)
{

  double max, min;
  int i, j;
  int ncol, nrow;

  if (pixmap14)
    {
      gdk_pixmap_unref (pixmap14);
    }

  pixmap14 = gdk_pixmap_new (widget->window,
			     widget->allocation.width,
			     widget->allocation.height, -1);

  if (c_var.mapsvector[c_var.actualmap].raster_mesh_advection_number != NULL
      && c_var.actualmap > -1)
    {
      max = c_var.mapsvector[c_var.actualmap].raster_mesh_advection_number[0];
      min = max;
      ncol = c_var.mapsvector[c_var.actualmap].raster_mesh_ncol;
      nrow = c_var.mapsvector[c_var.actualmap].raster_mesh_nrow;

      for (i = 0; i < nrow; i++)
	{
	  for (j = 0; j < ncol; j++)
	    {
	      if (c_var.mapsvector[c_var.actualmap].
		  raster_mesh_advection_number[i * ncol + j] > max)
		{
		  max =
		    c_var.mapsvector[c_var.actualmap].
		    raster_mesh_advection_number[i * ncol + j];
		}
	      if (c_var.mapsvector[c_var.actualmap].
		  raster_mesh_advection_number[i * ncol + j] < min)
		{
		  min =
		    c_var.mapsvector[c_var.actualmap].
		    raster_mesh_advection_number[i * ncol + j];
		}

	    }
	}
      create_pixmap_create_scale (widget, pixmap14, min, max);

    }
  else
    {

      gdk_draw_rectangle (pixmap14,
			  widget->style->white_gc,
			  TRUE,
			  0, 0,
			  widget->allocation.width,
			  widget->allocation.height);
    }


  gdk_draw_pixmap (widget->window,
		   widget->style->fg_gc[GTK_WIDGET_STATE (widget)],
		   pixmap14,
		   0, 0,
		   0, 0, widget->allocation.width, widget->allocation.height);

  return FALSE;
}


gboolean
on_drawingarea14_expose_event (GtkWidget * widget,
			       GdkEventExpose * event, gpointer user_data)
{
  gdk_draw_pixmap (widget->window,
		   widget->style->fg_gc[GTK_WIDGET_STATE (widget)],
		   pixmap14,
		   0, 0,
		   0, 0, widget->allocation.width, widget->allocation.height);
  return FALSE;
}


gboolean
on_drawingarea12_configure_event (GtkWidget * widget,
				  GdkEventConfigure * event,
				  gpointer user_data)
{

  double max, min;
  int i, j;
  int ncol, nrow;

  if (pixmap12)
    {
      gdk_pixmap_unref (pixmap12);
    }

  pixmap12 = gdk_pixmap_new (widget->window,
			     widget->allocation.width,
			     widget->allocation.height, -1);

  if (c_var.mapsvector[c_var.actualmap].raster_mesh != NULL
      && c_var.actualmap > -1)
    {
      max = c_var.mapsvector[c_var.actualmap].raster_mesh[0];
      min = max;
      ncol = c_var.mapsvector[c_var.actualmap].raster_mesh_ncol;
      nrow = c_var.mapsvector[c_var.actualmap].raster_mesh_nrow;

      for (i = 0; i < nrow; i++)
	{
	  for (j = 0; j < ncol; j++)
	    {
	      if (c_var.mapsvector[c_var.actualmap].
		  raster_mesh[i * ncol + j] > max)
		{
		  max =
		    c_var.mapsvector[c_var.actualmap].raster_mesh[i * ncol +
								  j];
		}
	      if (c_var.mapsvector[c_var.actualmap].
		  raster_mesh[i * ncol + j] < min)
		{
		  min =
		    c_var.mapsvector[c_var.actualmap].raster_mesh[i * ncol +
								  j];
		}

	    }
	}
      create_pixmap_create_scale (widget, pixmap12, min, max);

    }
  else
    {

      gdk_draw_rectangle (pixmap12,
			  widget->style->white_gc,
			  TRUE,
			  0, 0,
			  widget->allocation.width,
			  widget->allocation.height);
    }


  gdk_draw_pixmap (widget->window,
		   widget->style->fg_gc[GTK_WIDGET_STATE (widget)],
		   pixmap12,
		   0, 0,
		   0, 0, widget->allocation.width, widget->allocation.height);

  return FALSE;
}


gboolean
on_drawingarea12_expose_event (GtkWidget * widget,
			       GdkEventExpose * event, gpointer user_data)
{
  gdk_draw_pixmap (widget->window,
		   widget->style->fg_gc[GTK_WIDGET_STATE (widget)],
		   pixmap12,
		   0, 0,
		   0, 0, widget->allocation.width, widget->allocation.height);
  return FALSE;
}


gboolean
on_drawingarea16_configure_event (GtkWidget * widget,
				  GdkEventConfigure * event,
				  gpointer user_data)
{
  double max, min;
  int i, j;
  int ncol, nrow;

  if (pixmap16)
    {
      gdk_pixmap_unref (pixmap16);
    }

  pixmap16 = gdk_pixmap_new (widget->window,
			     widget->allocation.width,
			     widget->allocation.height, -1);

  if (c_var.mapsvector[c_var.actualmap].raster_mesh_gradient_horizontal !=
      NULL && c_var.actualmap > -1)
    {
      max =
	c_var.mapsvector[c_var.actualmap].raster_mesh_gradient_horizontal[0];
      min = max;
      ncol = c_var.mapsvector[c_var.actualmap].raster_mesh_ncol;
      nrow = c_var.mapsvector[c_var.actualmap].raster_mesh_nrow;

      for (i = 0; i < nrow; i++)
	{
	  for (j = 0; j < ncol; j++)
	    {
	      if (c_var.mapsvector[c_var.actualmap].
		  raster_mesh_gradient_horizontal[i * ncol + j] > max)
		{
		  max =
		    c_var.mapsvector[c_var.actualmap].
		    raster_mesh_gradient_horizontal[i * ncol + j];
		}
	      if (c_var.mapsvector[c_var.actualmap].
		  raster_mesh_gradient_horizontal[i * ncol + j] < min)
		{
		  min =
		    c_var.mapsvector[c_var.actualmap].
		    raster_mesh_gradient_horizontal[i * ncol + j];
		}

	    }
	}
      create_pixmap_create_scale (widget, pixmap16, min, max);

    }
  else
    {

      gdk_draw_rectangle (pixmap16,
			  widget->style->white_gc,
			  TRUE,
			  0, 0,
			  widget->allocation.width,
			  widget->allocation.height);
    }


  gdk_draw_pixmap (widget->window,
		   widget->style->fg_gc[GTK_WIDGET_STATE (widget)],
		   pixmap16,
		   0, 0,
		   0, 0, widget->allocation.width, widget->allocation.height);

  return FALSE;
}


gboolean
on_drawingarea16_expose_event (GtkWidget * widget,
			       GdkEventExpose * event, gpointer user_data)
{
  gdk_draw_pixmap (widget->window,
		   widget->style->fg_gc[GTK_WIDGET_STATE (widget)],
		   pixmap16,
		   0, 0,
		   0, 0, widget->allocation.width, widget->allocation.height);
  return FALSE;
}


gboolean
on_drawingarea19_configure_event (GtkWidget * widget,
				  GdkEventConfigure * event,
				  gpointer user_data)
{
  double max, min;
  int i, j;
  int ncol, nrow;

  if (pixmap19)
    {
      gdk_pixmap_unref (pixmap19);
    }

  pixmap19 = gdk_pixmap_new (widget->window,
			     widget->allocation.width,
			     widget->allocation.height, -1);

  if (c_var.mapsvector[c_var.actualmap].raster_mesh_gradient_vertical !=
      NULL && c_var.actualmap > -1)
    {
      max =
	c_var.mapsvector[c_var.actualmap].raster_mesh_gradient_vertical[0];
      min = max;
      ncol = c_var.mapsvector[c_var.actualmap].raster_mesh_ncol;
      nrow = c_var.mapsvector[c_var.actualmap].raster_mesh_nrow;

      for (i = 0; i < nrow; i++)
	{
	  for (j = 0; j < ncol; j++)
	    {
	      if (c_var.mapsvector[c_var.actualmap].
		  raster_mesh_gradient_vertical[i * ncol + j] > max)
		{
		  max =
		    c_var.mapsvector[c_var.actualmap].
		    raster_mesh_gradient_vertical[i * ncol + j];
		}
	      if (c_var.mapsvector[c_var.actualmap].
		  raster_mesh_gradient_vertical[i * ncol + j] < min)
		{
		  min =
		    c_var.mapsvector[c_var.actualmap].
		    raster_mesh_gradient_vertical[i * ncol + j];
		}

	    }
	}
      create_pixmap_create_scale (widget, pixmap19, min, max);

    }
  else
    {

      gdk_draw_rectangle (pixmap19,
			  widget->style->white_gc,
			  TRUE,
			  0, 0,
			  widget->allocation.width,
			  widget->allocation.height);
    }


  gdk_draw_pixmap (widget->window,
		   widget->style->fg_gc[GTK_WIDGET_STATE (widget)],
		   pixmap19,
		   0, 0,
		   0, 0, widget->allocation.width, widget->allocation.height);

  return FALSE;
}


gboolean
on_drawingarea19_expose_event (GtkWidget * widget,
			       GdkEventExpose * event, gpointer user_data)
{
  gdk_draw_pixmap (widget->window,
		   widget->style->fg_gc[GTK_WIDGET_STATE (widget)],
		   pixmap19,
		   0, 0,
		   0, 0, widget->allocation.width, widget->allocation.height);
  return FALSE;
}


gboolean
on_hruler3_configure_event (GtkWidget * widget,
			    GdkEventConfigure * event, gpointer user_data)
{
  gtk_ruler_set_range (GTK_RULER (widget), 0,
		       c_var.mapsvector[c_var.actualmap].raster_ncol, 0, 10);

  return FALSE;
}


gboolean
on_vruler4_configure_event (GtkWidget * widget,
			    GdkEventConfigure * event, gpointer user_data)
{
  gtk_ruler_set_range (GTK_RULER (widget), 0,
		       c_var.mapsvector[c_var.actualmap].raster_nrow, 0, 10);
  return FALSE;
}


gboolean
on_hruler5_configure_event (GtkWidget * widget,
			    GdkEventConfigure * event, gpointer user_data)
{
  gtk_ruler_set_range (GTK_RULER (widget), 0,
		       c_var.mapsvector[c_var.actualmap].raster_ncol, 0, 10);

  return FALSE;
}


gboolean
on_vruler7_configure_event (GtkWidget * widget,
			    GdkEventConfigure * event, gpointer user_data)
{
  gtk_ruler_set_range (GTK_RULER (widget), 0,
		       c_var.mapsvector[c_var.actualmap].raster_nrow, 0, 10);
  return FALSE;
}


gboolean
on_hruler8_configure_event (GtkWidget * widget,
			    GdkEventConfigure * event, gpointer user_data)
{

  return FALSE;
}


gboolean
on_vruler10_configure_event (GtkWidget * widget,
			     GdkEventConfigure * event, gpointer user_data)
{

  return FALSE;
}


gboolean
on_vruler12_configure_event (GtkWidget * widget,
			     GdkEventConfigure * event, gpointer user_data)
{

  return FALSE;
}


gboolean
on_hruler7_configure_event (GtkWidget * widget,
			    GdkEventConfigure * event, gpointer user_data)
{

  return FALSE;
}

void
on_button_interpolation_properties_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
  if (c_var.button_interpolation_active != 1)
    {
      c_var.button_interpolation_active = 1;
      c_var.matrix_change_cell_property = 2;
    }
  else
    {
      c_var.button_interpolation_active = 0;
      c_var.matrix_change_cell_property = 0;
    }
}

