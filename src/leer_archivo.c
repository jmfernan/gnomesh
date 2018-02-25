/***************************************************************************
                          leer_archivo.c  -  description
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
 
 #include "main.h"

 int read_dxf_file (char *filename, struct file_data *filedatas)
 {
   FILE *fp;
   char szBuffer0[1024];
   char szBuffer1[1024];
   
   //printf("leyendo archivo %s\n",filename);
   fp = fopen (filename, "r");
   if (fp)
   {
      while (feof(fp) == 0)
       {
         //printf("leido: %ld",ftell(fp));
         
         (void)fgets(szBuffer0, (int)sizeof (szBuffer0),fp);
         strcpy(szBuffer0,stripWhiteSpace(szBuffer0));
         (void)fgets(szBuffer1, (int)sizeof (szBuffer1),fp);
         strcpy(szBuffer1,stripWhiteSpace(szBuffer1));
         if(atoi(szBuffer0)==0 && strcmp("POLYLINE",szBuffer1)==0)
         {
           read_polyline(filedatas ,fp);
           //printf("%s %s\n",szBuffer0,szBuffer1);
         }
         if(atoi(szBuffer0)==0 && strcmp("LWPOLYLINE",szBuffer1)==0)
         {
           read_lwpolyline(filedatas ,fp);
           //printf("%s %s\n",szBuffer0,szBuffer1);
         }
         else if(atoi(szBuffer0)==0 && strcmp("LINE",szBuffer1)==0)
         {
           //printf("%s %s\n",szBuffer0,szBuffer1);
           read_line(filedatas ,fp);
         }
         else if(atoi(szBuffer0)==0 && strcmp("CIRCLE",szBuffer1)==0)
         {
           read_circle(filedatas ,fp);
           //printf("%s %s\n",szBuffer0,szBuffer1);
         }
         else if(atoi(szBuffer0)==0 && strcmp("TEXT",szBuffer1)==0)
         {
           //printf("%s %s\n",szBuffer0,szBuffer1);
           read_text(filedatas ,fp);
         }
         else if(atoi(szBuffer0)==0 && strcmp("LAYER",szBuffer1)==0)
         {
           //printf("%s %s\n",szBuffer0,szBuffer1);
         }
         else if(atoi(szBuffer0)==0 && strcmp("POINT",szBuffer1)==0)
         {
           //printf("%s %s\n",szBuffer0,szBuffer1);
           read_point(filedatas ,fp);
         }


       }
 

   }
  return 0;
 }

int read_line(struct file_data *filedatas, FILE *fp)
{
  char szBuffer0[1024];
  char szBuffer1[1024];
  int argument;
  double xi;
  double yi;
  double zi;
  double xf;
  double yf;
  double zf;
  char layername[1024];

  fpos_t posfile;
  
  argument=-1;
   
  while(argument!=0 || feof(fp))
  {
    fgetpos(fp,&posfile);
    (void)fgets(szBuffer0, (int)sizeof (szBuffer0), fp);
    strcpy(szBuffer0,stripWhiteSpace(szBuffer0));

    (void)fgets(szBuffer1, (int)sizeof (szBuffer1),fp);
    strcpy(szBuffer1,stripWhiteSpace(szBuffer1));

    argument = atoi(szBuffer0);

    switch (argument){
      case 10:
        xi = atof(szBuffer1);
        break;
      case 20:
        yi = atof(szBuffer1);
        break;
      case 30:
        zi = atof(szBuffer1);
        break;
      case 11:
        xf = atof(szBuffer1);
        break;
      case 21:
        yf = atof(szBuffer1);
        break;
      case 31:
        zf = atof(szBuffer1);
        break;
      case 8:
        strcpy(layername,szBuffer1);
        break;
      case 0:
        fsetpos(fp, &posfile);
        //printf("LINE: %f %f %f %f %f %f %s\n",xi,yi,zi,xf,yf,zf,layername);
        add_line(filedatas, xi, yi, zi, xf, yf, zf);
        return(1);
        break;
    }
    if( feof(fp)!=0 )
    {
      printf("End of File, no EOF defined into data file\n");
        //printf("LINE: %f %f %f %f %f %f %s\n",xi,yi,zi,xf,yf,zf,layername);
        add_line(filedatas, xi, yi, zi, xf, yf, zf);
        return(1);
    }
    
  }
  //printf("linea: %f %f %f %f %f %f %s\n",xi,yi,zi,xf,yf,zf,layername);
  return(0);
}


int read_point(struct file_data *filedatas, FILE *fp)
{
  char szBuffer0[1024];
  char szBuffer1[1024];
  int argument;
  double xi;
  double yi;
  double zi;

  char layername[1024];

  fpos_t posfile;

  argument=-1;

  while(argument!=0 || feof(fp))
  {
    fgetpos(fp,&posfile);
    (void)fgets(szBuffer0, (int)sizeof (szBuffer0), fp);
    strcpy(szBuffer0,stripWhiteSpace(szBuffer0));

    (void)fgets(szBuffer1, (int)sizeof (szBuffer1),fp);
    strcpy(szBuffer1,stripWhiteSpace(szBuffer1));

    argument = atoi(szBuffer0);

    switch (argument){
      case 10:
        xi = atof(szBuffer1);
        break;
      case 20:
        yi = atof(szBuffer1);
        break;
      case 30:
        zi = atof(szBuffer1);
        break;
      case 8:
        strcpy(layername,szBuffer1);
        break;
      case 0:
        fsetpos(fp, &posfile);
        //printf("LINE: %f %f %f %f %f %f %s\n",xi,yi,zi,xf,yf,zf,layername);
        add_point(filedatas, xi, yi, zi);
        return(1);
        break;
    }
    if( feof(fp)!=0 )
    {
      printf("End of File, no EOF defined into data file\n");
        //printf("LINE: %f %f %f %f %f %f %s\n",xi,yi,zi,xf,yf,zf,layername);
        add_point(filedatas, xi, yi, zi);
        return(1);
    }

  }
  //printf("linea: %f %f %f %f %f %f %s\n",xi,yi,zi,xf,yf,zf,layername);
  return(0);
}


int read_polyline(struct file_data *filedatas, FILE *fp)
{
  char szBuffer0[1024];
  char szBuffer1[1024];
  int argument;
  int flag;
  double xo;
  double yo;
  double zo;
  double xi;
  double yi;
  double zi;
  double xf;
  double yf;
  double zf;
  char layername[1024];

  fpos_t posfile;

  argument=-1;
  //read initial information and first vertex
  while(argument!=0 || feof(fp))
  {
    fgetpos(fp,&posfile);
    (void)fgets(szBuffer0, (int)sizeof (szBuffer0), fp);
    strcpy(szBuffer0,stripWhiteSpace(szBuffer0));

    (void)fgets(szBuffer1, (int)sizeof (szBuffer1),fp);
    strcpy(szBuffer1,stripWhiteSpace(szBuffer1));

    argument = atoi(szBuffer0);

    switch (argument){
      case 10:
        xo = atof(szBuffer1);
        xi = xo;
        break;
      case 20:
        yo = atof(szBuffer1);
        yi = yo;
        break;
      case 30:
        zo = atof(szBuffer1);
        zi = zo;
        break;
      case 8:
        strcpy(layername,szBuffer1);
        break;
      case 66:
        flag = atoi(szBuffer1);
        break;
      case 0:
        
        //printf("POLYLINE 1th vertex: %f %f %f %d %s\n",xi,yi,zi,flag,layername);
        //return(1);
        break;
    }
    if( feof(fp)!=0 )
    {
      printf("End of File, no EOF defined into data file\n");
        //printf("POLYLINE 1th vertex: %f %f %f %d %s\n",xi,yi,zi,flag,layername);
        return(1);
    }

  }
  
  //now read each vertex to obtain lines
  
  while( !((argument==0) && (strcmp(szBuffer1,"SEQEND") == 0)) || feof(fp))
  {
    fgetpos(fp,&posfile);
    (void)fgets(szBuffer0, (int)sizeof (szBuffer0), fp);
    strcpy(szBuffer0,stripWhiteSpace(szBuffer0));

    (void)fgets(szBuffer1, (int)sizeof (szBuffer1),fp);
    strcpy(szBuffer1,stripWhiteSpace(szBuffer1));

    argument = atoi(szBuffer0);

    switch (argument){
      case 10:
        xf = atof(szBuffer1);
        break;
      case 20:
        yf = atof(szBuffer1);
        break;
      case 30:
        zf = atof(szBuffer1);
        break;
      case 8:
        strcpy(layername,szBuffer1);
        break;
      case 0:
        //fsetpos(fp, &posfile);
        //printf("LINE: %f %f %f %f %f %f %d %s\n",xi,yi,zi,xf,yf,zf,flag,layername);
        add_line(filedatas, xi, yi, zi, xf, yf, zf);
        xi=xf;yi=yf;zi=zf;
        //return(1);
        break;
    }
    if( feof(fp)!=0 )
    {
      printf("End of File, no EOF defined into data file\n");
        //printf("LINE: %f %f %f %f %f %f %d %s\n",xi,yi,zi,xf,yf,zf,flag,layername);
        add_line(filedatas, xi, yi, zi, xf, yf, zf);
        xi=xf;yi=yf;zi=zf;
        //return(1);
    }

  }
  if(flag == 1)
  {
    //close the polygon
    //printf("LINE: %f %f %f %f %f %f %d %s\n",xf,yf,zf,xo,yo,zo,flag,layername);
    add_line(filedatas, xf, yf, zf, xo, yo, zo);
    
  }
  
  //printf("linea: %f %f %f %f %f %f %s\n",xi,yi,zi,xf,yf,zf,layername);
  return(0);

}

int read_lwpolyline(struct file_data *filedatas, FILE *fp)
{
  char szBuffer0[1024];
  char szBuffer1[1024];
  int argument;
  int flag;
  int nl;
  int count;
  double xo;
  double yo;
  double zo;
  double xi;
  double yi;
  double zi;
  double xf;
  double yf;
  double zf;
  char layername[1024];

  fpos_t posfile;

  argument=-1;

  zo = 0;
  nl = 0;
  count = 0;
  
  //read z0 and number of vertex
  while((argument!=0 && argument!=10) || feof(fp))
  {
    fgetpos(fp,&posfile);
    (void)fgets(szBuffer0, (int)sizeof (szBuffer0), fp);
    strcpy(szBuffer0,stripWhiteSpace(szBuffer0));

    (void)fgets(szBuffer1, (int)sizeof (szBuffer1),fp);
    strcpy(szBuffer1,stripWhiteSpace(szBuffer1));

    argument = atoi(szBuffer0);
    //printf("argumento0: %d, %s\n",argument, szBuffer1);

    switch (argument){
      case 10:
        xo = atof(szBuffer1);
        xi = xo;
        break;
      case 20:
        yo = atof(szBuffer1);
        yi = yo;
        count++;
        break;
      case 90:
        nl = atoi(szBuffer1);
        break;
      case 38:    //default elevation
        zo = atof(szBuffer1);
        break;
      case 8:
        strcpy(layername,szBuffer1);
        break;
      case 70:
        flag = atoi(szBuffer1);
        break;
      case 0:

        //printf("POLYLINE 1th vertex: %f %f %f %d %s\n",xi,yi,zi,flag,layername);
        //return(1);
        break;
    }
    if( feof(fp)!=0 )
    {
      printf("End of File, no EOF defined into data file lwpol1\n");
        //printf("POLYLINE 1th vertex: %f %f %f %d %s\n",xi,yi,zi,flag,layername);
        return(1);
    }

  }


  
  //read initial information and first vertex
  while((argument!=0 && count<1) || feof(fp))
  {
    fgetpos(fp,&posfile);
    (void)fgets(szBuffer0, (int)sizeof (szBuffer0), fp);
    strcpy(szBuffer0,stripWhiteSpace(szBuffer0));

    (void)fgets(szBuffer1, (int)sizeof (szBuffer1),fp);
    strcpy(szBuffer1,stripWhiteSpace(szBuffer1));

    argument = atoi(szBuffer0);
    //printf("argumento1: %d, %s\n",argument, szBuffer1);

    switch (argument){
      case 10:
        xo = atof(szBuffer1);
        xi = xo;
        break;
      case 20:
        yo = atof(szBuffer1);
        yi = yo;
        count++;
        break;
      case 8:
        strcpy(layername,szBuffer1);
        break;
      case 66:
        flag = atoi(szBuffer1);
        break;
      case 0:

        //printf("POLYLINE 1th vertex: %f %f %f %d %s\n",xi,yi,zi,flag,layername);
        //return(1);
        break;
    }
    if( feof(fp)!=0 )
    {
      printf("End of File, no EOF defined into data file lwpol2\n");
        //printf("POLYLINE 1th vertex: %f %f %f %d %s\n",xi,yi,zi,flag,layername);
        return(1);
    }

  }

  //now read each vertex to obtain lines

  //while( !((argument==0) && (strcmp(szBuffer1,"SEQEND") == 0)) || feof(fp))
  while( (argument!=0 && count<nl) || feof(fp))
    {
    fgetpos(fp,&posfile);
    (void)fgets(szBuffer0, (int)sizeof (szBuffer0), fp);
    strcpy(szBuffer0,stripWhiteSpace(szBuffer0));

    (void)fgets(szBuffer1, (int)sizeof (szBuffer1),fp);
    strcpy(szBuffer1,stripWhiteSpace(szBuffer1));

    argument = atoi(szBuffer0);
    //printf("argumento2: %d, %s\n",argument, szBuffer1);

    switch (argument){
      case 10:
        xf = atof(szBuffer1);
        break;
      case 20:
        yf = atof(szBuffer1);
        //printf("LINE: %f %f %f %f %f %f %d %s\n",xi,yi,zi,xf,yf,zf,flag,layername);
        add_line(filedatas, xi, yi, zo, xf, yf, zo);
        xi=xf;yi=yf;
        count++;
        break;
      case 8:
        strcpy(layername,szBuffer1);
        break;
      case 0:
        //fsetpos(fp, &posfile);
        /*
        printf("LINE: %f %f %f %f %f %f %d %s\n",xi,yi,zi,xf,yf,zf,flag,layername);
        add_line(filedatas, xi, yi, zo, xf, yf, zo);
        xi=xf;yi=yf;
        */
        //return(1);
        break;
    }
    if( feof(fp)!=0 )
    {
      printf("End of File, no EOF defined into data file lwpol3\n");
        //printf("LINE: %f %f %f %f %f %f %d %s\n",xi,yi,zi,xf,yf,zf,flag,layername);
        add_line(filedatas, xi, yi, zo, xf, yf, zo);
        xi=xf;yi=yf;;
        //return(1);
    }

  }
  if(flag == 1)
  {
    //close the polygon
    //printf("LINEf: %f %f %f %f %f %f %d %s\n",xf,yf,zf,xo,yo,zo,flag,layername);
    add_line(filedatas, xf, yf, zo, xo, yo, zo);

  }

  //printf("linea: %f %f %f %f %f %f %s\n",xi,yi,zi,xf,yf,zf,layername);
  return(0);

}




int read_circle(struct file_data *filedatas, FILE *fp)
{
  char szBuffer0[1024];
  char szBuffer1[1024];
  int argument;
  double xi;
  double yi;
  double zi;
  double rc;
  char layername[1024];

  fpos_t posfile;

  argument=-1;

  while(argument!=0 || feof(fp))
  {
    fgetpos(fp,&posfile);
    (void)fgets(szBuffer0, (int)sizeof (szBuffer0), fp);
    strcpy(szBuffer0,stripWhiteSpace(szBuffer0));

    (void)fgets(szBuffer1, (int)sizeof (szBuffer1),fp);
    strcpy(szBuffer1,stripWhiteSpace(szBuffer1));

    argument = atoi(szBuffer0);

    switch (argument){
      case 10:
        xi = atof(szBuffer1);
        break;
      case 20:
        yi = atof(szBuffer1);
        break;
      case 30:
        zi = atof(szBuffer1);
        break;
      case 40:
        rc = atof(szBuffer1);
        break;
      case 8:
        strcpy(layername,szBuffer1);
        break;
      case 0:
        fsetpos(fp, &posfile);
        //printf("CIRCLE: %f %f %f %f %s\n",xi,yi,zi,rc,layername);
        return(1);
        break;
    }
    if( feof(fp)!=0 )
    {
      printf("End of File, no EOF defined into data file\n");
        //printf("CIRCLE: %f %f %f %f %s\n",xi,yi,zi,rc,layername);
        return(1);
    }

  }
  return(0);
}

int read_text(struct file_data *filedatas, FILE *fp)
{
  char szBuffer0[1024];
  char szBuffer1[1024];
  int argument;
  double xi;
  double yi;
  double zi;
  double hi;
  char layername[1024];
  char textfield[1024];

  fpos_t posfile;

  argument=-1;

  while(argument!=0 || feof(fp))
  {
    fgetpos(fp,&posfile);
    (void)fgets(szBuffer0, (int)sizeof (szBuffer0), fp);
    strcpy(szBuffer0,stripWhiteSpace(szBuffer0));

    (void)fgets(szBuffer1, (int)sizeof (szBuffer1),fp);
    strcpy(szBuffer1,stripWhiteSpace(szBuffer1));

    argument = atoi(szBuffer0);

    switch (argument){
      case 10:
        xi = atof(szBuffer1);
        break;
      case 20:
        yi = atof(szBuffer1);
        break;
      case 30:
        zi = atof(szBuffer1);
        break;
      case 40:
        hi = atof(szBuffer1);
        break;
      case 8:
        strcpy(layername,szBuffer1);
        break;
      case 1:
        strcpy(textfield,szBuffer1);
        break;
      case 0:
        fsetpos(fp, &posfile);
        //printf("TEXT: %f %f %f %f \"%s\" %s\n",xi,yi,zi,hi,textfield,layername);
        return(1);
        break;
    }
    if( feof(fp)!=0 )
    {
      printf("End of File, no EOF defined into data file\n");
        //printf("TEXT: %f %f %f %f \"%s\" %s\n",xi,yi,zi,hi,textfield,layername);
        return(1);
    }

  }
  //printf("linea: %f %f %f %f %f %f %s\n",xi,yi,zi,xf,yf,zf,layername);
  return(0);
}
int read_layer(struct file_data *filedatas, FILE *fp)
{

  return(0);
}

char * stripWhiteSpace(char *s)
{
  int lastChar;

  // Skip whitespace, excluding \n, at beginning of line
  while (s[0]==' ' || s[0]=='\t')
  {
    ++s;
  }
      
  lastChar = strlen(s) - 1; // Last non-NULL character in s

  // Is last character CR or LF?
  
  while ( (lastChar >= 0) &&
          ((s[lastChar] == '\n') || (s[lastChar] == '\r')) )
  {
    // Replace CR or LF with NULL and decrement string index
    // Would s[lastChar--] work?
    s[lastChar] = '\0';
    lastChar--;
  }  /*
   */
    
    //return("hola");
  return (s);

} // stripWhiteSpace()



 int write_map(char *filename, struct map maps)
{

  FILE *cfPtr;
  printf("en write file\n");

  if((cfPtr = fopen(filename,"w")) == NULL)
  {
    printf("no puedo abrir archivo\n");
    return(0);
  }

   /*
   int raster_ncol, raster_nrow;
   double xmin, xmax, ymin, ymax, zmin, zmax;
   struct file_data file_datas;
   double *raster_data;
   int *raster_mask;
   double *raster_data_interpolated;
   //mesh is the irregular
   int raster_mesh_ncol, raster_mesh_nrow;
   int *horizontal_mesh;
   int *vertical_mesh;
   double *raster_mesh;
   //variables temporales para permitir cambiar las propiedades del nivel de una celda
   int cell_prop_tmp_cellxcoord, cell_prop_tmp_cellycoord;
   double cell_prop_tmp_xcoord, cell_prop_tmp_ycoord, cell_prop_tmp_depth;
   //variables to process courant condition
   double courant_max_speed, courant_dt, courant_dx;
   */
    //fwrite(&maps,sizeof(struct map),1, cfPtr);

    fwrite(&maps.raster_ncol,sizeof(int),1, cfPtr);
    fwrite(&maps.raster_nrow,sizeof(int),1, cfPtr);
    fwrite(&maps.xmin,sizeof(double),1, cfPtr);
    fwrite(&maps.xmax,sizeof(double),1, cfPtr);
    fwrite(&maps.ymin,sizeof(double),1, cfPtr);
    fwrite(&maps.ymax,sizeof(double),1, cfPtr);
    fwrite(&maps.zmin,sizeof(double),1, cfPtr);
    fwrite(&maps.zmax,sizeof(double),1, cfPtr);
    //fwrite(&maps.file_datas,sizeof(struct file_data),1, cfPtr);

    fwrite(maps.raster_data,sizeof(double),maps.raster_ncol*maps.raster_nrow, cfPtr);
    fwrite(maps.raster_mask,sizeof(int),maps.raster_ncol*maps.raster_nrow, cfPtr);
    fwrite(maps.raster_data_interpolated,sizeof(double),maps.raster_ncol*maps.raster_nrow, cfPtr);
              

    fwrite(&maps.raster_mesh_ncol,sizeof(int),1, cfPtr);
    fwrite(&maps.raster_mesh_nrow,sizeof(int),1, cfPtr);       
    fwrite(maps.horizontal_mesh,sizeof(int),maps.raster_ncol, cfPtr);
    fwrite(maps.vertical_mesh,sizeof(int),maps.raster_nrow, cfPtr);
    fwrite(maps.raster_mesh,sizeof(double),maps.raster_mesh_ncol*maps.raster_mesh_nrow, cfPtr);


    fclose(cfPtr);


    printf("%d %d %f %f %f %f %f %f %d %d\n",maps.raster_ncol,maps.raster_nrow,maps.xmin,maps.xmax,maps.ymin,maps.ymax,maps.zmin,maps.zmax,maps.raster_mesh_ncol,maps.raster_mesh_nrow);
  

//  printf("");

}

int write_elcom(char *filename, struct map maps)
{
  int i,j;

  FILE *cfPtr;

  if((cfPtr = fopen(filename,"w")) == NULL)
  {
    printf("no puedo abrir archivo\n");
    return(0);
  }

   for(i=1;i< maps.raster_mesh_ncol+1;i++)
    {
      fprintf(cfPtr,"%f dx\n",maps.horizontal_mesh_width[i-1]);
    }
    for(i=1;i< maps.raster_mesh_nrow+1;i++)
    {
      fprintf(cfPtr,"%f dy\n",maps.vertical_mesh_width[i-1]);
    }
   
   for(i=0;i< maps.raster_mesh_nrow;i++)
    {
      for(j=0;j<maps.raster_mesh_ncol;j++)
      {
        fprintf(cfPtr,"%f ",maps.raster_mesh[i*maps.raster_mesh_nrow+j]);

      }
      fprintf(cfPtr,"\n");
    }
    fprintf(cfPtr,"\n");
    fclose(cfPtr);

   

 }


