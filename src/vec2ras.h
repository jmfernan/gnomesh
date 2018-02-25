/***************************************************************************
                          vec2ras.h  -  description
                             -------------------
    begin                : dom feb 2 2003
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


 int vec2ras(struct file_data *filedatas,double *matras,int *mmask, int m, int n);
 int interpolation_gauss (double *matras,int *mmask, int m, int n, int maxiter, double precision);
 int vec2ras_line(int x1, int y1, int x2, int y2, double z0,double *matras,int *mmask, int ancho, int alto);
 int vec2ras_point(int x1, int y1, double z0,double *matras,int *mmask, int ancho, int alto);
 float norm2mat (double *matras, int ancho, int alto);
