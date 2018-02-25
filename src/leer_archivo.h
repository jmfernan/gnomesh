/***************************************************************************
                          leer_archivo.h  -  description
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
 
 int read_dxf_file (char *filename, struct file_data *filedatas);
 char * stripWhiteSpace(char *s);
 int read_line(struct file_data *filedatas, FILE *fp);
 int read_point(struct file_data *filedatas, FILE *fp);
 int read_polyline(struct file_data *filedatas, FILE *fp);
 int read_lwpolyline(struct file_data *filedatas, FILE *fp);
 int read_circle(struct file_data *filedatas, FILE *fp);
 int read_text(struct file_data *filedatas, FILE *fp);
 int read_layer(struct file_data *filedatas, FILE *fp);

 int write_map(char *filename, struct map maps);
 int write_elcom(char *filename, struct map maps);


