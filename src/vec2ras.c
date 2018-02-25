/***************************************************************************
                          vec2ras.c  -  description
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

 #include "main.h"

 double return_max(double a, double b);

 double return_max(double a, double b)
   {
     if(a>=b)
      {return a;}
     else
      {return b;}


   }
 
 int vec2ras_old(struct file_data *filedatas,double *matras,int *mmask, int ancho, int alto)
 {
   double xmin, xmax, ymin, ymax, zmin, zmax;
   int i,j,k;
   int p0, p1;
   int dx, dy;
   int xi, yi, xf, yf, zi, zf;
   int xk,yk;
   double xrange, yrange, zrange;
   int mgtone;

   struct linkline *tmplink;
      
   (void)domain_box(filedatas,&xmin, &xmax, &ymin, &ymax, &zmin, &zmax);
   xrange = xmax-xmin;
   yrange = ymax-ymin;
   zrange = zmax-zmin;

   //realloc(matras, sizeof(double)*ancho*alto);
   //realloc(mmask, sizeof(int)*ancho*alto);


   //print original matrix

/*
   printf("matriz original\n");
   for (j=0;j<alto;j++)
   {
     for (i=0;i<ancho;i++)
     {
       matras[j*ancho+i]=0.0;
       //mmask[j*ancho+i]=0;
       printf("%d",mmask[j*ancho+i]);
       //printf("%.0f",matras[j*ancho+i]);

     }
     printf(" %d",j*ancho+i);
     printf("\n");
   }
*/

   tmplink = filedatas->linklines;

   while (tmplink != NULL)
   {
     //printf("\nRASTER: %f,%f,%f-%f,%f,%f\n",tmplink->line.pi.xi, tmplink->line.pi.yi,tmplink->line.pi.zi, tmplink->line.pf.xi, tmplink->line.pf.yi,tmplink->line.pf.zi);
     /*
     xi = (int) ((ancho-1) * (tmplink->line.pi.xi - xmin) / xrange);
     yi = (int) ((alto-1)  * (ymax - tmplink->line.pi.yi) / yrange);
     xf = (int) ((ancho-1) * (tmplink->line.pf.xi - xmin) / xrange);
     yf = (int) ((alto-1)  * (ymax - tmplink->line.pf.yi) / yrange);

     dx=xf-xi;
     dy=yf-yi;
     printf("abs <1 dx=%d dy=%d %f  %f ::  ",dx,dy,(double)dy/(double)dx, abs((double)dy/(double)dx) );
     */              
     
     if(
       (tmplink->line.pf.xi != tmplink->line.pi.xi) &&
       (

         //abs((double)(tmplink->line.pf.yi-tmplink->line.pi.yi)/(double)(tmplink->line.pf.xi-tmplink->line.pi.xi))
           
           (double)((int) ((alto-1)  * (ymax - tmplink->line.pf.yi) / yrange)-(int) ((alto-1)  * (ymax - tmplink->line.pi.yi) / yrange)) / (double)((int) ((ancho-1) * (tmplink->line.pf.xi - xmin) / xrange)-(int) ((ancho-1) * (tmplink->line.pi.xi - xmin) / xrange)) <=1
           &&(double)((int) ((alto-1)  * (ymax - tmplink->line.pf.yi) / yrange)-(int) ((alto-1)  * (ymax - tmplink->line.pi.yi) / yrange)) / (double)((int) ((ancho-1) * (tmplink->line.pf.xi - xmin) / xrange)-(int) ((ancho-1) * (tmplink->line.pi.xi - xmin) / xrange)) >=-1
        )
       )
     {
       if(tmplink->line.pi.xi < tmplink->line.pf.xi)
       {
         xi = (int) ((ancho-1) * (tmplink->line.pi.xi - xmin) / xrange);
         yi = (int) ((alto-1)  * (ymax - tmplink->line.pi.yi) / yrange);
         xf = (int) ((ancho-1) * (tmplink->line.pf.xi - xmin) / xrange);
         yf = (int) ((alto-1)  * (ymax - tmplink->line.pf.yi) / yrange);
       }
       else if (tmplink->line.pi.xi > tmplink->line.pf.xi)
       {
         xf = (int) ((ancho-1) * (tmplink->line.pi.xi - xmin) / xrange);
         yf = (int) ((alto-1)  * (ymax - tmplink->line.pi.yi) / yrange);
         xi = (int) ((ancho-1) * (tmplink->line.pf.xi - xmin) / xrange);
         yi = (int) ((alto-1)  * (ymax - tmplink->line.pf.yi) / yrange);
       }
       else
       {
         //nunca deberia entrar en este codigo
         //printf("no deberias pasar por aqui\n");
         mgtone=1;
       }

       dx=xf-xi;
       dy=yf-yi;
       p0=2*dy-dx;

       xk=xi;
       yk=yi;

       //printf("abs <1 dx=%d dy=%d %f  ::  ",dx,dy,(double)dy/(double)dx);
       
       if(mmask[yk*ancho+xk]==1)
       {
         matras[yk*ancho+xk]=return_max(tmplink->line.pi.zi,matras[yk*ancho+xk]);
       }
       else
       {
         matras[yk*ancho+xk]=tmplink->line.pi.zi;
         mmask[yk*ancho+xk]=1;
       }
       
       if( (double)dy/(double)dx <= 1 && (double)dy/(double)dx >= 0 )
       {
         //printf("estoy calculando 0<=m<=1\n");
         for(i=xi; i< xf; i++)
         {
           if(p0<0)
           {
             xk++;
             yk=yk;
             p0=p0+2*dy;

           }
           else
           {
             xk++;
             yk++;
             p0=p0+2*dy-2*dx;
           }
           if(mmask[yk*ancho+xk]==1)
           {
             matras[yk*ancho+xk]=return_max(tmplink->line.pi.zi,matras[yk*ancho+xk]);
           }
           else
           {
             matras[yk*ancho+xk]=tmplink->line.pi.zi;
             mmask[yk*ancho+xk]=1;
           }

         }
       }

       else if( (double)dy/(double)dx >= -1 && (double)dy/(double)dx < 0 )
       {
         //printf("estoy calculando -1<=m<=0\n");
         for(i=xi; i< xf; i++)
         {
           if(p0<0)
           {
             xk++;
             yk=yk;
             p0=p0-2*dy;

           }
           else
           {
             xk++;
             yk--;
             p0=p0-2*dy-2*dx;
           }
           if(mmask[yk*ancho+xk]==1)
           {
             matras[yk*ancho+xk]=return_max(tmplink->line.pi.zi,matras[yk*ancho+xk]);
           }
           else
           {
             matras[yk*ancho+xk]=tmplink->line.pi.zi;
             mmask[yk*ancho+xk]=1;
           }
        }
       }
     }
     else //cuando la pendiente sea mayor a 1 se invierten las coordenadas
     {
       if(tmplink->line.pi.yi > tmplink->line.pf.yi)
       {
         yi = (int) ((ancho-1) * (tmplink->line.pi.xi - xmin) / xrange);
         xi = (int) ((alto-1)  * (ymax - tmplink->line.pi.yi) / yrange);
         yf = (int) ((ancho-1) * (tmplink->line.pf.xi - xmin) / xrange);
         xf = (int) ((alto-1)  * (ymax - tmplink->line.pf.yi) / yrange);
       }
       else if (tmplink->line.pi.yi < tmplink->line.pf.yi)
       {
         yf = (int) ((ancho-1) * (tmplink->line.pi.xi - xmin) / xrange);
         xf = (int) ((alto-1)  * (ymax - tmplink->line.pi.yi) / yrange);
         yi = (int) ((ancho-1) * (tmplink->line.pf.xi - xmin) / xrange);
         xi = (int) ((alto-1)  * (ymax - tmplink->line.pf.yi) / yrange);
       }
       else
       {
         //printf("linea vertical\n");
         mgtone=1;
       }

       dx=xf-xi;
       dy=yf-yi;
       p0=2*dy-dx;

       //printf("dx=%d dy=%d %f ::  ",dx,dy,(double)dy/(double)dx);
       
       xk=xi;
       yk=yi;

           if(mmask[xk*alto+yk]==1)
           {
             matras[xk*alto+yk]=return_max(tmplink->line.pi.zi,matras[xk*alto+yk]);
           }
           else
           {
             matras[xk*alto+yk]=tmplink->line.pi.zi;
             mmask[xk*alto+yk]=1;
           }
           
       if( (double)dy/(double)dx <= 1 && (double)dy/(double)dx >= 0 )
       {
         //printf("***estoy calculando 1<=m<=INF\n");
         for(i=xi; i< xf; i++)
         {
           if(p0<0)
           {
             xk++;
             yk=yk;
             p0=p0+2*dy;

           }
           else
           {
             xk++;
             yk++;
             p0=p0+2*dy-2*dx;
           }
           if(mmask[xk*alto+yk]==1)
           {
             matras[xk*alto+yk]=return_max(tmplink->line.pi.zi,matras[xk*alto+yk]);
           }
           else
           {
             matras[xk*alto+yk]=tmplink->line.pi.zi;
             mmask[xk*alto+yk]=1;
           }
         }
       }

       else if( (double)dy/(double)dx >= -1 && (double)dy/(double)dx < 0 )
       {
         //printf("***estoy calculando -INF<=m<-1\n");
         for(i=xi; i< xf; i++)
         {
           if(p0<0)
           {
             xk++;
             yk=yk;
             p0=p0-2*dy;

           }
           else
           {
             xk++;
             yk--;
             p0=p0-2*dy-2*dx;
           }
           if(mmask[xk*alto+yk]==1)
           {
             matras[xk*alto+yk]=return_max(tmplink->line.pi.zi,matras[xk*alto+yk]);
           }
           else
           {
             matras[xk*alto+yk]=tmplink->line.pi.zi;
             mmask[xk*alto+yk]=1;
           }
        }
       }
     }
     
     //next line          
     tmplink = tmplink->nextptr;
   }

/*   

   printf("matriz original\n");
   for (j=0;j<alto;j++)
   {
     for (i=0;i<ancho;i++)
     {

       printf("%d",mmask[j*ancho+i]);

     }
     printf("\n");
   }
*/
   
   return(1);
   
 }

 int vec2ras(struct file_data *filedatas,double *matras,int *mmask, int ancho, int alto)
 {
   double xmin, xmax, ymin, ymax, zmin, zmax;
   int i,j,k;
   int p0, p1;
   int dx, dy;
   int xi, yi, xf, yf;
   double zi, zf;
   int xk,yk;
   double xrange, yrange, zrange;
   int mgtone;

   struct linkline *tmplink;
   struct linkpoint *tmplinkpoint;

   /*
   printf("dentro vec2ras\n\n");   
   for (j=0;j<alto;j++)
   {
     for (i=0;i<ancho;i++)
     {
       printf("%.0f", matras[ancho*i+j]);
     }
     printf("\n");
   }
   printf("dentro vec2ras\n\n");

   for (j=0;j<c_var.mapsvector[c_var.actualmap].raster_nrow;j++)
   {
     for (i=0;i<c_var.mapsvector[c_var.actualmap].raster_ncol;i++)
     {
       printf("%.0f", c_var.mapsvector[c_var.actualmap].raster_data[i*c_var.mapsvector[c_var.actualmap].raster_ncol+j]);
     }
     printf("\n");
   }
   printf("dentro vec2ras\n\n");
   */

   //printf("",);

   //(void)domain_box(&c_var.mapsvector[c_var.actualmap].file_datas,&xmin, &xmax, &ymin, &ymax, &zmin, &zmax);
   
   //(void)domain_box(filedatas,&xmin, &xmax, &ymin, &ymax, &zmin, &zmax);
   xmin=c_var.mapsvector[c_var.actualmap].xmin;
   xmax=c_var.mapsvector[c_var.actualmap].xmax;
   ymin=c_var.mapsvector[c_var.actualmap].ymin;
   ymax=c_var.mapsvector[c_var.actualmap].ymax;
   zmin=c_var.mapsvector[c_var.actualmap].zmin;
   zmax=c_var.mapsvector[c_var.actualmap].zmax;
   
   xrange = xmax-xmin;
   yrange = ymax-ymin;
   zrange = zmax-zmin;

   //realloc(matras, sizeof(double)*ancho*alto);
   //realloc(mmask, sizeof(int)*ancho*alto);


   //print original matrix

   //printf("desp caja\n");
   //raster lines
   tmplink = filedatas->linklines;

   while (tmplink != NULL)
   {
     
     xi = (int) ((ancho-1) * (tmplink->line.pi.xi - xmin) / xrange);
     yi = (int) ((alto-1)  * (ymax - tmplink->line.pi.yi) / yrange);
     xf = (int) ((ancho-1) * (tmplink->line.pf.xi - xmin) / xrange);
     yf = (int) ((alto-1)  * (ymax - tmplink->line.pf.yi) / yrange);
     zi = tmplink->line.pi.zi;

     vec2ras_line(xi, yi, xf, yf, zi,matras,mmask, ancho, alto);
     //printf("maximos y minimos %f %f %f %f %f %f\n",xmax,xmin,ymax,ymin,zmax,zmin);

     //printf("pintando linea  %d %d %d %d %f %f %f %f\n",xi,xf,yi,yf,tmplink->line.pi.xi,tmplink->line.pf.xi,tmplink->line.pi.yi,tmplink->line.pf.yi);
     tmplink = tmplink->nextptr;

   }
   //printf("desp rasterlines\n" );
   //raster points
   
   tmplinkpoint = filedatas->linkpoints;

   while (tmplinkpoint != NULL)
   {

     xi = (int) ((ancho-1) * (tmplinkpoint->point.xi - xmin) / xrange);
     yi = (int) ((alto-1)  * (ymax - tmplinkpoint->point.yi) / yrange);
     xf=xi;
     yf=yi;
     zi = tmplinkpoint->point.zi;

     //printf("puntos: %d %d %f\n",xi,yi,zi);
     vec2ras_point(xi, yi, zi,matras,mmask, ancho, alto);
     
     tmplinkpoint = tmplinkpoint->nextptr;

   }
   
   //printf("desp rasterpoints\n" );


   return(1);

 }


 
 int vec2ras_line(int x1, int y1, int x2, int y2, double z0,double *matras,int *mmask, int ancho, int alto)
 {
	int dx, dy, incr1, incr2, d, x, y, xend, yend, xdirflag, ydirflag;
	dx = abs(x2-x1);
	dy = abs(y2-y1);
	if (dy <= dx) {
		d = 2*dy - dx;
		incr1 = 2*dy;
		incr2 = 2 * (dy - dx);
		if (x1 > x2) {
			x = x2;
			y = y2;
			ydirflag = (-1);
			xend = x1;
		} else {
			x = x1;
			y = y1;
			ydirflag = 1;
			xend = x2;
		}

       if(mmask[y*ancho+x]==1)
       {
         matras[y*ancho+x]=return_max(z0,matras[y*ancho+x]);
       }
       else
       {
         matras[y*ancho+x]=z0;
         mmask[y*ancho+x]=1;
       }
    //gdImageSetPixel(im, x, y, color);
    if (((y2 - y1) * ydirflag) > 0) {
      while (x < xend) {
        x++;
        if (d <0) {
        d+=incr1;
        } else {
          y++;
          d+=incr2;
        }

       if(mmask[y*ancho+x]==1)
       {
         matras[y*ancho+x]=return_max(z0,matras[y*ancho+x]);
       }
       else
       {
         matras[y*ancho+x]=z0;
         mmask[y*ancho+x]=1;
       }
				//gdImageSetPixel(im, x, y, color);
			}
		} else {
			while (x < xend) {
				x++;
				if (d <0) {
					d+=incr1;
				} else {
					y--;
					d+=incr2;
				}
               if(mmask[y*ancho+x]==1)
       {
         matras[y*ancho+x]=return_max(z0,matras[y*ancho+x]);
       }
       else
       {
         matras[y*ancho+x]=z0;
         mmask[y*ancho+x]=1;
       }
				//gdImageSetPixel(im, x, y, color);
			}
		}
	} else {
		d = 2*dx - dy;
		incr1 = 2*dx;
		incr2 = 2 * (dx - dy);
		if (y1 > y2) {
			y = y2;
			x = x2;
			yend = y1;
			xdirflag = (-1);
		} else {
			y = y1;
			x = x1;
			yend = y2;
			xdirflag = 1;
		}
           if(mmask[y*ancho+x]==1)
       {
         matras[y*ancho+x]=return_max(z0,matras[y*ancho+x]);
       }
       else
       {
         matras[y*ancho+x]=z0;
         mmask[y*ancho+x]=1;
       }
		//gdImageSetPixel(im, x, y, color);
		if (((x2 - x1) * xdirflag) > 0) {
			while (y < yend) {
				y++;
				if (d <0) {
					d+=incr1;
				} else {
					x++;
					d+=incr2;
				}
               if(mmask[y*ancho+x]==1)
       {
         matras[y*ancho+x]=return_max(z0,matras[y*ancho+x]);
       }
       else
       {
         matras[y*ancho+x]=z0;
         mmask[y*ancho+x]=1;
       }
        //gdImageSetPixel(im, x, y, color);
			}
		} else {
			while (y < yend) {
				y++;
				if (d <0) {
					d+=incr1;
				} else {
					x--;
					d+=incr2;
        }
               if(mmask[y*ancho+x]==1)
       {
         matras[y*ancho+x]=return_max(z0,matras[y*ancho+x]);
       }
       else
       {
         matras[y*ancho+x]=z0;
         mmask[y*ancho+x]=1;
       }
				//gdImageSetPixel(im, x, y, color);
			}
		}
	}
}

 int vec2ras_point(int x, int y, double z0,double *matras,int *mmask, int ancho, int alto)
 {
   if(mmask[y*ancho+x]==1)
   {
     matras[y*ancho+x]=return_max(z0,matras[y*ancho+x]);
   }
   else
   {
     matras[y*ancho+x]=z0;
     mmask[y*ancho+x]=1;
   }

 }

       
 
 int interpolation_gauss (double *matras,int *mmask, int ancho, int alto, int maxiter, double precision)
 {
    int i,j,k,l;

    int a,b;
    double za,zb;
    double normbegin,normend;
    double correction,maxcorrection;
    double lan;
    double tmp;

    //llenando con valores promediados
    for (i=1; i<alto-1; i++)
    {
      for(j=1; j<ancho; j++)
      {
        if(mmask[i*ancho+j]!=1)
        {
          mmask[i*ancho+j]=0;
          matras[i*ancho+j]=(c_var.mapsvector[c_var.actualmap].zmin+c_var.mapsvector[c_var.actualmap].zmax)/2;
        }
      }
    }

    //interpolacion lineal primer paso                                            
    
    for (i=0; i<alto; i++)
    {
      a=0;
      b=0;
      za= matras[i*ancho+a];
      for(j=1; j<ancho; j++)
      {
        if(mmask[i*ancho+j]==1)
        {
          b=j;
          zb= matras[i*ancho+b];
          for(k=a+1; k<b; k++)
          {
            matras[i*ancho+k]=(k-a)*(zb-za)/(b-a) + za;
            mmask[i*ancho+k]=2;
          }
          a=b;
          za=zb;
        }
        //if information is not avalilable in right side
        /*else if(j==ancho-1)
        {
          b=j;
          zb= matras[i*ancho+b];
          for(k=a+1; k<b; k++)
          {
            //matras[i*ancho+k]=(k-a)*(zb-za)/(b-a) + za;
            matras[i*ancho+k]=za;
            mmask[i*ancho+k]=2;
          }
          a=b;
          za=zb;          
        } */
      }
    }
        
    //interpolacion lineal otra direccion primer paso
    for (j=0; j<ancho; j++)
    {
      a=0;
      b=0;
      za= matras[a*ancho+j];
      for(i=1; i<alto; i++)
      {
        if(mmask[i*ancho+j]==1)
        {
          b=i;
          zb= matras[b*ancho+j];
          for(k=a+1; k<b; k++)
          {
            if(mmask[k*ancho+j]!=0)
            {
              matras[k*ancho+j]=(((k-a)*(zb-za)/(b-a) + za)+(matras[k*ancho+j]))/2;
            }
            else
            {
              matras[k*ancho+j]=(k-a)*(zb-za)/(b-a) + za;
            }
            mmask[k*ancho+j]=2;
          }
          a=b;
          za=zb;
        }
        //if information is not avalilable in button side
        /*else if(j==alto-1)
        {
          b=i;
          zb= matras[b*ancho+j];
          for(k=a+1; k<b; k++)
          {
            //matras[i*ancho+k]=(k-a)*(zb-za)/(b-a) + za;
            matras[k*ancho+j]=za;
            mmask[k*ancho+j]=2;
          }
          a=b;
          za=zb;
        }*/        
      }
    }

    if(maxiter!=-1)
    {
    //  l=0;
    //while(l<10)
    //{
    //  l++;
    
    //interpolacion lineal segundo paso
    for (i=0; i<alto; i++)
    {
      a=0;
      b=0;
      za= matras[i*ancho+a];
      for(j=1; j<ancho; j++)
      {
        if(mmask[i*ancho+j]==1 || mmask[i*ancho+j]==2)
        {
          b=j;
          zb= matras[i*ancho+b];
          for(k=a+1; k<b; k++)
          {
            matras[i*ancho+k]=(k-a)*(zb-za)/(b-a) + za;
          }
          a=b;
          za=zb;
        }
      }
    }

    //interpolacion lineal otra direccion segundo paso
    for (j=0; j<ancho; j++)
    {
      a=0;
      b=0;
      za= matras[a*ancho+j];
      for(i=1; i<alto; i++)
      {
        if(mmask[i*ancho+j]==1 || mmask[i*ancho+j]==2)
        {
          b=i;

          zb= matras[b*ancho+j];
          for(k=a+1; k<b; k++)
          {

            if(mmask[k*ancho+j]!=0)
            {
              matras[k*ancho+j]=(((k-a)*(zb-za)/(b-a) + za)+(matras[k*ancho+j]))/2;
            }
            else
            {
              matras[k*ancho+j]=(k-a)*(zb-za)/(b-a) + za;
            }
          }
          a=b;
          za=zb;
        }
      }
    }

    //}
    }
    
    
    //printf("interpolacion 3\n");
    //printf("gauss 4\n");    
    normend = norm2mat (matras, ancho, alto); 
    normbegin = 3*normend;
    //printf("norma: %f\n",normbegin/(ancho*alto));
    k=0;
    //printf("%d %f\n",maxiter, precision);  


    lan=1;    // (h^2/k^2)
    maxcorrection=2*precision;
    //while (k<maxiter && (abs((int)((normbegin - normend)/(normend*precision))) > 1))
    while (k<maxiter && maxcorrection>precision)
    //while(k<10)
    {

      //leftside
      maxcorrection=0;
      for (i=1; i<alto-1; i++)
      {
        if(mmask[i*ancho+0]!=1)
        {
          /*
          correction = ( 2*matras[(i)*ancho+(0+1)]-matras[(i)*ancho+(0+2)]
                        -lan*(matras[(i+1)*ancho+(0)]+matras[(i-1)*ancho+(0)]))/(1-2*lan);
          if(maxcorrection*maxcorrection<(correction-matras[i*ancho+0])*(correction-matras[i*ancho+0]))
          {
            maxcorrection=(correction-matras[i*ancho+0])*(correction-matras[i*ancho+0]);
          }
          matras[i*ancho+0]=correction;
          */
          matras[i*ancho+0]=matras[i*ancho+1];
           
        }
        if(mmask[i*ancho+(ancho-1)]!=1)
        {
          matras[i*ancho+(ancho-1)]=matras[i*ancho+(ancho-2)];
        }

      }

      for(j=1; j<ancho-1; j++)
      {
        if(mmask[0*ancho+j]!=1)
        {
          matras[0*ancho+j]=matras[(0+1)*ancho+j];
        }
        if(mmask[(alto-1)*ancho+j]!=1)
        {
          matras[(alto-1)*ancho+j]=matras[(alto-2)*ancho+j];
        }
      }
      if(mmask[(0)*ancho+0]!=1)
      {
        matras[(0)*ancho+0]=(matras[(1)*ancho+0]+matras[(0)*ancho+1])/2;
      }
      if(mmask[(alto-1)*ancho+0]!=1)
      {
        matras[(alto-1)*ancho+0]=(matras[(alto-2)*ancho+0]+matras[(alto-1)*ancho+1])/2;
      }
      if(mmask[(0)*ancho+(ancho-1)]!=1)
      {
        matras[(0)*ancho+(ancho-1)]=(matras[(1)*ancho+(ancho-1)]+matras[(0)*ancho+(ancho-2)])/2;
      }
      if(mmask[(alto-1)*ancho+(ancho-1)]!=1)
      {
        matras[(alto-1)*ancho+(ancho-1)]=(matras[(alto-2)*ancho+(ancho-1)]+matras[(alto-1)*ancho+(ancho-2)])/2;
      }

      //printf("gauss 5\n");
      //internal points 
      for (i=1; i<alto-1; i++)
      {
        for(j=1; j<ancho-1; j++)
        {
          if(mmask[i*ancho+j]!=1)
          {
            correction = ( matras[(i-1)*ancho+(j)]+matras[(i+1)*ancho+(j)]
                                +lan*(matras[(i)*ancho+(j-1)]+matras[(i)*ancho+(j+1)]))/(2+2*lan);
            if(maxcorrection*maxcorrection<(correction-matras[i*ancho+j])*(correction-matras[i*ancho+j]))
            {
              maxcorrection=(correction-matras[i*ancho+j])*(correction-matras[i*ancho+j]);
            }
            matras[i*ancho+j]=correction; 
          }
          /*else
          {
            correction = ( matras[(i-1)*ancho+(j)]+matras[(i+1)*ancho+(j)]
                                +lan*(matras[(i)*ancho+(j-1)]+matras[(i)*ancho+(j+1)]))/(2+2*lan);
            tmp=(matras[i*ancho+j]-correction)/4;
            matras[(i-1)*ancho+(j)]+=tmp;
            matras[(i+1)*ancho+(j)]+=tmp;
            matras[(i)*ancho+(j-1)]+=tmp;
            matras[(i)*ancho+(j+1)]+=tmp;
            
          }
          */

        }
 
      }
      //printf("k: %d maxcorrection: %.20f\n",k,maxcorrection);
      

      k++;
      normbegin = normend;
      normend = norm2mat (matras, ancho, alto);
      
      //printf("norma %f\n",normend/(ancho*alto));
      
    }
        
    //printf("NORMA %f iteraciones %d\n",normend/(ancho*alto), k);
     
   return(1);

 }

 float norm2mat (double *matras, int ancho, int alto)
 {
   int i,j;
   double sum;
   
   sum=0;
   for (i=0; i<alto; i++)
      {
        for(j=0; j<ancho; j++)
        {
          sum += matras[i*ancho+j]*matras[i*ancho+j];
        }

      }

      return (sum);


   
 }


 
       
