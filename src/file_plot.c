/***************************************************************************
                          file_plot.c  -  description
                             -------------------
    begin                : dom dic 29 2002
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

 #include "main.h"

 #include <gd.h>
 #include <gdfonts.h>
 #include <gdfontl.h>
 
 
 int file_plot(struct file_data *filedatas, char *archivo, int ancho, int alto)               
 {
   double xmin, xmax, ymin, ymax, zmin, zmax;
   //char *archivo;

   struct linkline *tmplink;
         
  double rangoh, rangov;
  double mr, ml, mt, mb;
  double mx, my;

  //int ancho, alto;

  gdImagePtr im;
  FILE *out;


  /*colores */
  int black;
  int white;
  int blue;
  int dark_blue;
  int red;
  int green;

  
    if ((im = gdImageCreate (ancho, alto)) == NULL)
    {
      return(0);
    }

       domain_box(filedatas,&xmin, &xmax, &ymin, &ymax, &zmin, &zmax);
   //printf("\nrangos: %f %f %f %f %f %f\n",xmin, xmax, ymin, ymax, zmin, zmax);
    
  white = gdImageColorAllocate (im, 255, 255, 255);
  black = gdImageColorAllocate (im, 0, 0, 0);
  blue = gdImageColorAllocate (im, 20, 20, 255);
  dark_blue = gdImageColorAllocate (im, 17, 0, 96);
  red = gdImageColorAllocate (im, 255, 0, 0);
  green = gdImageColorAllocate (im, 20, 220, 20);

  /*
      mt = (0.2 + 1 + 0.2 + 1 + 0.2) * gdFontSmall->h + 1;
      mb = 0.4 + (0.2 + 1 + 0) * gdFontSmall->h + 1;
      ml = (0.2 + 1 + 0.2 + 1 + 0.2 + 1 + 0.2) * gdFontSmall->h + 1;
      mr = (0.5) * gdFontSmall->h + 1;
  */
  mt=0;
  mb=0;
  ml=0;
  mr=0;
      mx = ancho - ml - mr;
      my = alto - mt - mb;
      rangov = ymax - ymin;
      rangoh = xmax - xmin;

   tmplink = filedatas->linklines;

   while (tmplink != NULL)
   {
     //printf("  %f %f %f %f %f %f\n", tmplink->line.pi.xi, tmplink->line.pi.yi, tmplink->line.pi.zi, tmplink->line.pf.xi, tmplink->line.pf.yi, tmplink->line.pf.zi);

                       
                         gdImageLine (im,
                           (int) (ml +
                                  mx * (tmplink->line.pi.xi -
                                        xmin) / rangoh),
                           (int) (mt +
                                  my * (ymax -
                                        tmplink->line.pi.yi) / (rangov)),
                           (int) (ml +
                                  mx * (tmplink->line.pf.xi -
                                        xmin) / rangoh),
                           (int) (mt +
                                  my * (ymax -
                                        tmplink->line.pf.yi) / (rangov)),
                           blue);
                       
     /*
     printf("coordenadas: %d %d %d %d\n",
            (int) (ml + mx * (tmplink->line.pi.xi - xmin) / rangoh),
            (int) (mt + my * (ymax - tmplink->line.pi.yi) / (rangov)),
            (int) (ml + mx * (tmplink->line.pf.xi - xmin) / rangoh),
            (int) (mt + my * (ymax - tmplink->line.pf.yi) / (rangov))
            

            );
     */
     tmplink = tmplink->nextptr;
   }

         if ((out = fopen (archivo, "wb")) != NULL)
        {
          gdImagePng (im, out);
/*        gdImageGif(im,out);*/
          (void) fclose (out);
          gdImageDestroy (im);
          return (1);
        }
      else
        {
          gdImageDestroy (im);
          return (0);
        }

      

      



 }
