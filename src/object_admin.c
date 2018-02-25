/***************************************************************************
                          object_admin.c  -  description
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

 #include "main.h"
                  
 int add_line(struct file_data *filedatas, double xi, double yi, double zi, double xf, double yf, double zf)
 {
   struct linkline *tmplink;

   tmplink = (struct linkline *)g_malloc(sizeof(struct linkline));

   tmplink->line.pi.xi=xi;
   tmplink->line.pi.yi=yi;
   tmplink->line.pi.zi=zi;
   tmplink->line.pf.xi=xf;
   tmplink->line.pf.yi=yf;
   tmplink->line.pf.zi=zf;
   
   tmplink->nextptr = filedatas->linklines;
   filedatas->linklines = tmplink;

   //printf("LINE: %f %f %f %f %f %f\n",tmplink->line.pi.xi=xi,   tmplink->line.pi.yi=yi,   tmplink->line.pi.zi=zi,   tmplink->line.pf.xi=xf,   tmplink->line.pf.yi=yf,   tmplink->line.pf.zi=zf);
   
   return(0);
 }

 int add_point(struct file_data *filedatas, double xi, double yi, double zi)
 {
   struct linkpoint *tmplink;

   tmplink = (struct linkpoint *)g_malloc(sizeof(struct linkpoint));

   tmplink->point.xi=xi;
   tmplink->point.yi=yi;
   tmplink->point.zi=zi;

   tmplink->nextptr = filedatas->linkpoints;
   filedatas->linkpoints = tmplink;

   //printf("LINE: %f %f %f %f %f %f\n",tmplink->line.pi.xi=xi,   tmplink->line.pi.yi=yi,   tmplink->line.pi.zi=zi,   tmplink->line.pf.xi=xf,   tmplink->line.pf.yi=yf,   tmplink->line.pf.zi=zf);

   return(0);
 }
 

 int count_lines(struct file_data *filedatas)
 {
   int count;
   struct linkline *tmplink;
   
   count = 0;

   tmplink = filedatas->linklines;
   
   while (tmplink != NULL)
   {
     count++;
     tmplink = tmplink->nextptr;


   }

   return (count);

 }

 int count_points(struct file_data *filedatas)
 {
   int count;
   struct linkpoint *tmplink;

   count = 0;

   tmplink = filedatas->linkpoints;

   while (tmplink != NULL)
   {
     count++;
     tmplink = tmplink->nextptr;


   }

   return (count);

 }

 
 int domain_box(struct file_data *filedatas,double *xmin, double *xmax, double *ymin, double *ymax, double *zmin, double *zmax)
 {
   struct linkline  *tmplink;
   struct linkpoint *tmplinkpoint;
   
   tmplink = filedatas->linklines;
   tmplinkpoint = filedatas->linkpoints;

   if(tmplink!=NULL)
   {
	   *xmin = tmplink->line.pi.xi;
       *ymin = tmplink->line.pi.yi;
       *zmin = tmplink->line.pi.zi;
   }
   else if(tmplinkpoint!=NULL)
   {
	   *xmin = tmplinkpoint->point.xi;
       *ymin = tmplinkpoint->point.yi;
       *zmin = tmplinkpoint->point.zi;   
   }
   else
   {
	   *xmin = 0;
       *ymin = 0;
       *zmin = 0;
   }
   *xmax=*xmin;
   *ymax=*ymin;
   *zmax=*zmin;

   while (tmplink != NULL)
   {
     //printf("%f %f %f %f %f %f\n",tmplink->line.pi.xi,tmplink->line.pi.yi,tmplink->line.pi.zi,tmplink->line.pf.xi,tmplink->line.pf.yi,tmplink->line.pf.zi);
     if(*xmin > tmplink->line.pi.xi)
     {
       *xmin = tmplink->line.pi.xi;
     }
     if(*xmin > tmplink->line.pf.xi)
     {
       *xmin = tmplink->line.pf.xi;
     }

     if(*ymin > tmplink->line.pi.yi)
     {
       *ymin = tmplink->line.pi.yi;
     }
     if(*ymin > tmplink->line.pf.yi)
     {
       *ymin = tmplink->line.pf.yi;
     }

     if(*zmin > tmplink->line.pi.zi)
     {
       *zmin = tmplink->line.pi.zi;
     }
     if(*zmin > tmplink->line.pf.zi)
     {
       *zmin = tmplink->line.pf.zi;
     }

     if(*xmax < tmplink->line.pi.xi)
     {
       *xmax = tmplink->line.pi.xi;
     }
     if(*xmax < tmplink->line.pf.xi)
     {
       *xmax = tmplink->line.pf.xi;
     }

     if(*ymax < tmplink->line.pi.yi)
     {
       *ymax = tmplink->line.pi.yi;
     }
     if(*ymax < tmplink->line.pf.yi)
     {
       *ymax = tmplink->line.pf.yi;
     }

     if(*zmax < tmplink->line.pi.zi)
     {
       *zmax = tmplink->line.pi.zi;
     }
     if(*zmax < tmplink->line.pf.zi)
     {
       *zmax = tmplink->line.pf.zi;
     }     
     
     tmplink = tmplink->nextptr;
     //printf("%f %f\n",xmin,ymin);

   }

   //tmplinkpoint = filedatas->linkpoints;

   while (tmplinkpoint != NULL)
   {
     //printf("%f %f %f %f %f %f\n",tmplink->line.pi.xi,tmplink->line.pi.yi,tmplink->line.pi.zi,tmplink->line.pf.xi,tmplink->line.pf.yi,tmplink->line.pf.zi);
     if(*xmin > tmplinkpoint->point.xi)
     {
       *xmin = tmplinkpoint->point.xi;
     }

     if(*ymin > tmplinkpoint->point.yi)
     {
       *ymin = tmplinkpoint->point.yi;
     }

     if(*zmin > tmplinkpoint->point.zi)
     {
       *zmin = tmplinkpoint->point.zi;
     }


     if(*xmax < tmplinkpoint->point.xi)
     {
       *xmax = tmplinkpoint->point.xi;
     }

     if(*ymax < tmplinkpoint->point.yi)
     {
       *ymax = tmplinkpoint->point.yi;
     }

     if(*zmax < tmplinkpoint->point.zi)
     {
       *zmax = tmplinkpoint->point.zi;
     }

     tmplinkpoint = tmplinkpoint->nextptr;
     
	 //printf("%f %f\n",xmin,ymin);

   }





   
   return(0);
 }


 int export_dxf(struct file_data *filedatas)
 {
   struct linkline *tmplink;

   tmplink = filedatas->linklines;

   while (tmplink != NULL)
   {
     //printf("  0\nLINE\n10\n%f\n20\n%f\n30\n%f\n11\n%f\n21\n%f\n31\n%f\n", tmplink->line.pi.xi, tmplink->line.pi.yi, tmplink->line.pi.zi, tmplink->line.pf.xi, tmplink->line.pf.yi, tmplink->line.pf.zi);
     tmplink = tmplink->nextptr;
   }

   return(0);
 }
