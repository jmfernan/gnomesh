/***************************************************************************
                          base_structures.h  -  description
                             -------------------
    begin                : dom dic 15 2002
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

 struct point
 {
   double xi;
   double yi;
   double zi;
 };

 struct line
 {
   struct point pi;
   struct point pf;
 };

 struct circle
 {
   struct point pc;
   double radius;
   
 };

 struct text
 {
   struct point pi;
   double hi;
   char *textfield;
 };

 struct linkline
 {
   struct line line;
   struct linkline *nextptr;

 };

  struct linkpoint
 {
   struct point point;
   struct linkpoint *nextptr;

 };
 
 struct file_data
 {
   struct linkpoint *linkpoints;
   struct linkline *linklines;
   struct linkcircle *linkcircles;
   struct linktext *linktexts;
 };

 struct map
 {
   int raster_ncol, raster_nrow, nlayers;
   double xmin, xmax, ymin, ymax, zmin, zmax;
   struct file_data file_datas;
   double *raster_data;
   int *raster_mask;
   double *raster_data_interpolated;

   //mesh is the irregular
   int *horizontal_mesh;
   int *vertical_mesh;
   double *horizontal_mesh_width;
   double *vertical_mesh_width;
   
   double *raster_mesh;
   int raster_mesh_ncol, raster_mesh_nrow;
   double *raster_mesh_advection_number;
   double *raster_mesh_standar_desviation;
   double *raster_mesh_aspect_ratio;
   double *raster_mesh_gradient_horizontal;
   double *raster_mesh_gradient_vertical;
   

   //variables temporales para permitir cambiar las propiedades del nivel de una celda
   int cell_prop_tmp_cellxcoord, cell_prop_tmp_cellycoord;
   double cell_prop_tmp_xcoord, cell_prop_tmp_ycoord, cell_prop_tmp_depth;
   //variables to process courant condition
   double courant_max_speed, courant_dt, courant_dx;
   //var to set level in brush
   double brush_level;
   //var boundary
   double open_boundary;
   double land_boundary;

   //interpolation proterties
   int interpolation_maxiter;
   double interpolation_precision;
      
 };
 
 struct common_var
 {
   int mapsnumber;
   int actualmap;
   int button_mesh_active;
   int button_interpolation_active;
   int button_raster_active;
   int matrix_change_cell_property;
   struct map *mapsvector;



 };


