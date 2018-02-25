/***************************************************************************
                          export_bathymetry_elcom.c  -  description
                             -------------------
    begin                : mié mar 26 2003
    copyright            : (C) 2003 by José Manuel Fernandez Jaramillo
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
 
 int export_bathymetry_elcom (double *matriz, char *archivo,int ancho, int alto)
 {
   int i,j;
   double max,min;
   FILE *out;

   
   max= matriz[0];
   min= matriz[0];

   //determine el rango
   for (i = 0; i < alto; i++)
     {
       for (j = 0; j < ancho; j++)
         {
           if(matriz[i * ancho + j]<min)
             {min = matriz[i * ancho + j];}
           if(matriz[i * ancho + j]>max)
             {max = matriz[i * ancho + j];}
         }
     }

     if ((out = fopen (archivo, "w")) != NULL)
     {
       fprintf(out,"FILE %s\nVERSION 1.5.0\n",archivo);
       fprintf(out,"! ------------------------------------------------------- !\n");
       fprintf(out,"'Malla 1' TITLE\n");
       fprintf(out,"'Fernandez Jaramillo' ANALYST\n");
       fprintf(out,"'Universidad Nacional' ORGANIZATION\n");
       fprintf(out,"'CANAL' COMMENT\n");
       fprintf(out,"! ------------------------------------------------------- !\n");
       fprintf(out,"yes overwrite files\n");
       fprintf(out,"! ------------------------------------------------------- !\n");
       fprintf(out,"! number of grid cells !\n");
       fprintf(out,"%d x_rows\n",ancho);
       fprintf(out,"%d y_columns\n",alto);
       fprintf(out,"7 z_layers\n"); //que pregunte
       fprintf(out,"0 n_max\n"); //numero de celdas reservadas o en 0 para que elcom lo haga automaticamente
       fprintf(out,"! ------------------------------------------------------- !\n");
       fprintf(out,"! land and open boundary bathymetry values !\n");
       fprintf(out,"99 land_value\n"); //calcularlo con la cota maxima
       fprintf(out,"88 open_value\n"); //preguntarle al usuario
       fprintf(out,"! ------------------------------------------------------- !\n");

       fprintf(out,"! geographic position !\n");
       fprintf(out,"-1.0 north_x\n"); //preguntarle al usuario
       fprintf(out,"0.0 north_y\n");
       fprintf(out,"55.0 latitude\n"); //sacarla de dxf
       fprintf(out,"0.0 longitude\n");
       fprintf(out,"0.0 altitude\n");
       fprintf(out,"! ------------------------------------------------------- !\n");
       fprintf(out,"! grid spacing !\n");
       fprintf(out,"0.1 x_grid_size\n"); //se calcula
       fprintf(out,"0.3 y_grid_size\n");
       fprintf(out,"! ------------------------------------------------------- !\n");
       fprintf(out,"! dz vector starting from top going down !\n");
       fprintf(out,"0.05 dz top\n");   //preguntar en una tabla
       fprintf(out,"0.05 dz\n");
       fprintf(out,"0.05 dz\n");
       fprintf(out,"0.05 dz\n");
       fprintf(out,"0.05 dz\n");
       fprintf(out,"0.05 dz\n");
       fprintf(out,"0.05 dz bottom\n");
       fprintf(out,"! ------------------------------------------------------- !\n");
       fprintf(out,"! x in rows (increasing down), y in columns (increasing across) !\n");
       fprintf(out,"BATHYMETRY DATA\n");
     
       for (j=0;j<alto;j++)
       {
         for (i=0;i<ancho;i++)
         {
           fprintf(out,"%.3f ",matriz[j*ancho+i]);
         }
         fprintf(out,"\n");
       }
       fclose(out);
     }
     




 }
