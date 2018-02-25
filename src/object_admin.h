/***************************************************************************
                          object_admin.h  -  description
                             -------------------
    begin                : sáb dic 28 2002
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

 int add_line(struct file_data *filedatas, double xi, double yi, double zi, double xf, double yf, double zf);
 int add_point(struct file_data *filedatas, double xi, double yi, double zi);
 int count_lines(struct file_data *filedatas);
 int count_points(struct file_data *filedatas);
 int domain_box(struct file_data *filedatas,double *xmin, double *xmax, double *ymin, double *ymax, double *zmin, double *zmax);
 int export_dxf(struct file_data *filedatas);
