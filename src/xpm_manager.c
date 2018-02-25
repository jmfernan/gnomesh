/***************************************************************************
                          xpm_manager.c  -  description
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

 #include "main.h"
 
 int export_xpm (double *matriz, char *archivo,int ancho, int alto)
 {
   int i,j;
   double max,min;
   FILE *out;

   char *letras[40] ={
                   "a","b","c","d","e","f","g","h","i","j",
                   "k","l","m","n","o","p","q","r","s","t",
                   "u","v","w","x","y","z","A","B","C","D",
                   "E","F","G","H","I","J","K","L","M"," "
                  };

   char *colores[40]={
                   "#000000","#000011","#000022","#000033","#000044","#000055","#000066","#000077","#000088","#000099",
                   "#0000aa","#0000bb","#0000cc","#0000dd","#0000ee","#0000ff","#1100ee","#2200dd","#3300cc","#4400bb",
                   "#5500aa","#660099","#770088","#880077","#990066","#aa0055","#bb0044","#cc0033","#dd0022","#ee0011",
                   "#ff0000","#ee1100","#dd2200","#cc3300","#bb4400","#aa5500","#996600","#887700","#778800","None"};


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

   
   fprintf(out,"\/* XPM *\/\nstatic char *ensa_xpm[] = {\n\"%d %d 41 1\"\n",ancho,alto);
   fprintf(out,"\"       c None\",\n");
     for (i = 0; i < 40; i++)
    {
       fprintf(out,"\"%s      c %s\",\n",letras[i],colores[i]);
       //fprintf(out,"\"%s      c #%2.2X00%2.2X\",\n",letras[i],255-(int)i*255/40,(int)i*255/40);
    }

  for (i = 0; i < alto; i++)
    {
      fprintf(out,"\"");
      for (j = 0; j < ancho; j++)
        {
          fprintf(out,"%s", letras[(int)(39*(matriz[i * ancho + j]-min)/(max-min))]  );
        }
      if(i!=alto-1)
        {fprintf(out,"\",\n");}
      else
        {fprintf(out,"\"};\n");}

    }
    fclose(out);
  }

/*
   printf("\"0      c #ffffff\",\n");
   printf("\"1      c #ff0000\",\n");
   printf("\"2      c #ffff00\",\n");
   printf("\"3      c #ff00ff\",\n");
   printf("\"4      c #00ffff\",\n");
   printf("\"5      c #ff00aa\",\n");
   printf("\"6      c #ffaa00\",\n");
   printf("\"7      c #ffaaaa\",\n");
   printf("\"8      c #ffaaff\",\n");
   printf("\"9      c #ffffaa");


   for (j=0;j<alto;j++)
   {
     printf("\",\n\"");
     for (i=0;i<ancho;i++)
     {
       printf("%.0f",matras[j*ancho+i]);
     }

   }
   printf("\"\};\n");
  */ 
   return TRUE;
 }
/*
 int convert_mat2xpm (double *matras, char **mat_xpm, int m, int n)
 {
   int i,j;
   double max,min;
   FILE *out;

   char *letras[40] ={
                   "a","b","c","d","e","f","g","h","i","j",
                   "k","l","m","n","o","p","q","r","s","t",
                   "u","v","w","x","y","z","A","B","C","D",
                   "E","F","G","H","I","J","K","L","M"," "
                  };

   char *colores[40]={
                   "#000000","#000011","#000022","#000033","#000044","#000055","#000066","#000077","#000088","#000099",
                   "#0000aa","#0000bb","#0000cc","#0000dd","#0000ee","#0000ff","#1100ee","#2200dd","#3300cc","#4400bb",
                   "#5500aa","#660099","#770088","#880077","#990066","#aa0055","#bb0044","#cc0033","#dd0022","#ee0011",
                   "#ff0000","#ee1100","#dd2200","#cc3300","#bb4400","#aa5500","#996600","#887700","#778800","None"};


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


   fprintf(out,"\/* XPM *\/\nstatic char *ensa_xpm[] = {\n\"%d %d 41 1\"\n",ancho,alto);
   fprintf(out,"\"       c None\",\n");
     for (i = 0; i < 40; i++)
    {
       fprintf(out,"\"%s      c %s\",\n",letras[i],colores[i]);
       //fprintf(out,"\"%s      c #%2.2X00%2.2X\",\n",letras[i],255-(int)i*255/40,(int)i*255/40);
    }

  for (i = 0; i < alto; i++)
    {
      fprintf(out,"\"");
      for (j = 0; j < ancho; j++)
        {
          fprintf(out,"%s", letras[(int)(39*(matriz[i * ancho + j]-min)/(max-min))]  );
        }
      if(i!=alto-1)
        {fprintf(out,"\",\n");}
      else
        {fprintf(out,"\"};\n");}

    }
    fclose(out);
  }

 }
         
*/
