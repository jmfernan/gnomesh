## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = gnomesh

gnomesh_SOURCES = main.c main.h support.c support.h interface.c interface.h callbacks.c callbacks.h vec2ras.c vec2ras.h leer_archivo.c leer_archivo.h object_admin.c object_admin.h xpm_manager.c xpm_manager.h file_plot.c file_plot.h export_bathymetry_elcom.c export_bathymetry_elcom.h base_structures.h gtk_routines.c gtk_routines.h

gnomesh_LDADD = @PACKAGE_LIBS@ -lgd -lm

