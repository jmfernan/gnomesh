/***************************************************************************
                          xpm_manager.h  -  description
                             -------------------
    begin                : dom mar 9 2003
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

  int export_xpm (double *matras, char *archivo, int m, int n);
  int convert_mat2xpm (double *matras, char **mat_xpm, int m, int n);
  