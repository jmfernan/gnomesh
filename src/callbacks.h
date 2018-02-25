#include <gtk/gtk.h>



void
on_nuevo1_activate                     (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_abrir1_activate                     (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_guardar1_activate                   (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_guardar_como1_activate              (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_salir1_activate                     (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_cortar1_activate                    (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_copiar1_activate                    (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_pegar1_activate                     (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_borrar1_activate                    (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_about1_activate                     (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_window1_destroy                     (GtkObject       *object,
                                        gpointer         user_data);

gboolean
on_drawingarea1_configure_event        (GtkWidget       *widget,
                                        GdkEventConfigure *event,
                                        gpointer         user_data);

gboolean
on_drawingarea1_expose_event           (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

gboolean
on_drawingarea1_motion_notify_event    (GtkWidget       *widget,
                                        GdkEventMotion  *event,
                                        gpointer         user_data);

gboolean
on_drawingarea1_button_press_event     (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data);

void
on_fileselection1_destroy              (GtkObject       *object,
                                        gpointer         user_data);

void
on_fileselection1_close                (GtkDialog       *dialog,
                                        gpointer         user_data);

void
on_fileselection1_response             (GtkDialog       *dialog,
                                        gint             response_id,
                                        gpointer         user_data);

void
on_open_button_activate                (GtkButton       *button,
                                        gpointer         user_data);

void
on_fileselection1_ok_button1_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_fileselection1_cancel_button1_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_window1_configure_event             (GtkWidget       *widget,
                                        GdkEventConfigure *event,
                                        gpointer         user_data);


//int
//initiate_common_var (struct common_var *variable);
                                        
                                        




gboolean
on_drawingarea2_configure_event        (GtkWidget       *widget,
                                        GdkEventConfigure *event,
                                        gpointer         user_data);

gboolean
on_drawingarea2_expose_event           (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

gboolean
on_drawingarea2_motion_notify_event    (GtkWidget       *widget,
                                        GdkEventMotion  *event,
                                        gpointer         user_data);

gboolean
on_drawingarea2_button_press_event     (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data);

void
on_button4_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_interpolate_clicked          (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_drawingarea3_configure_event        (GtkWidget       *widget,
                                        GdkEventConfigure *event,
                                        gpointer         user_data);

gboolean
on_drawingarea3_expose_event           (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

gboolean
on_drawingarea3_motion_notify_event    (GtkWidget       *widget,
                                        GdkEventMotion  *event,
                                        gpointer         user_data);

gboolean
on_drawingarea3_button_press_event     (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data);

gboolean
on_drawingarea4_configure_event        (GtkWidget       *widget,
                                        GdkEventConfigure *event,
                                        gpointer         user_data);

gboolean
on_drawingarea4_expose_event           (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

gboolean
on_drawingarea4_motion_notify_event    (GtkWidget       *widget,
                                        GdkEventMotion  *event,
                                        gpointer         user_data);

gboolean
on_drawingarea4_button_press_event     (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data);

void
on_togglebutton_mesh_addhline_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);


void
on_button_mesh_addhline_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_mesh_addvline_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_mesh_delhline_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_mesh_delvline_clicked        (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_drawingarea5_configure_event        (GtkWidget       *widget,
                                        GdkEventConfigure *event,
                                        gpointer         user_data);

gboolean
on_drawingarea5_expose_event           (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

gboolean
on_drawingarea5_motion_notify_event    (GtkWidget       *widget,
                                        GdkEventMotion  *event,
                                        gpointer         user_data);

gboolean
on_drawingarea5_button_press_event     (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data);

void
on_button_defmesh_genmesh_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_raster_cell_properties_button_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_mesh_properties_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
create_change_cell_properties   (int ix, int iy, double *matrix, int m, int n);
void
on_cell_properties_depth_entry_changed (GtkEditable     *editable,
                                        gpointer         user_data);

gboolean
on_cell_properties_depth_entry_configure_event
                                        (GtkWidget       *widget,
                                        GdkEventConfigure *event,
                                        gpointer         user_data);

gboolean
on_cell_properties_cxc_entry_expose_event
                                        (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

gboolean
on_cell_properties_cyc_entry_expose_event
                                        (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

gboolean
on_cell_properties_xc_entry_expose_event
                                        (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

gboolean
on_cell_properties_yc_entry_expose_event
                                        (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

gboolean
on_cell_properties_depth_entry_expose_event
                                        (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

void
on_cell_properties_depth_entry_activate
                                        (GtkEntry        *entry,
                                        gpointer         user_data);

void
on_button_mesh_check_courant_clicked   (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_courant_dt_property_entry_expose_event
                                        (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

gboolean
on_courant_speed_property_entry_expose_event
                                        (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

gboolean
on_courant_dx_property_entry_expose_event
                                        (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

void
on_courant_properties_ok_button_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_courant_dt_property_entry_activate  (GtkEntry        *entry,
                                        gpointer         user_data);

void
on_courant_speed_property_entry_activate
                                        (GtkEntry        *entry,
                                        gpointer         user_data);

void
on_courant_dx_property_entry_activate  (GtkEntry        *entry,
                                        gpointer         user_data);

void
on_raster_brush_button_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_brush_level_entry_activate          (GtkEntry        *entry,
                                        gpointer         user_data);

gboolean
on_brush_level_entry_expose_event      (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

gboolean
on_drawingarea2_event                  (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data);

void
on_fileselection2_ok_button1_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_defmesh_export_elcom_clicked (GtkButton       *button,
                                        gpointer         user_data);

void
on_fileselection_export_elcom_ok_button2_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_window1_destroy                     (GtkObject       *object,
                                        gpointer         user_data);

gboolean
on_window1_configure_event             (GtkWidget       *widget,
                                        GdkEventConfigure *event,
                                        gpointer         user_data);

void
on_nuevo1_activate                     (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_abrir1_activate                     (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_guardar1_activate                   (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_guardar_como1_activate              (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_salir1_activate                     (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_cortar1_activate                    (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_copiar1_activate                    (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_pegar1_activate                     (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_borrar1_activate                    (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_about1_activate                     (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_open_button_activate                (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_drawingarea1_configure_event        (GtkWidget       *widget,
                                        GdkEventConfigure *event,
                                        gpointer         user_data);

gboolean
on_drawingarea1_expose_event           (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

gboolean
on_drawingarea1_motion_notify_event    (GtkWidget       *widget,
                                        GdkEventMotion  *event,
                                        gpointer         user_data);

gboolean
on_drawingarea1_button_press_event     (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data);

void
on_raster_brush_button_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_button4_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_raster_cell_properties_button_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_drawingarea2_configure_event        (GtkWidget       *widget,
                                        GdkEventConfigure *event,
                                        gpointer         user_data);

gboolean
on_drawingarea2_expose_event           (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

gboolean
on_drawingarea2_motion_notify_event    (GtkWidget       *widget,
                                        GdkEventMotion  *event,
                                        gpointer         user_data);

gboolean
on_drawingarea2_button_press_event     (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data);

void
on_button_interpolate_clicked          (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_drawingarea3_configure_event        (GtkWidget       *widget,
                                        GdkEventConfigure *event,
                                        gpointer         user_data);

gboolean
on_drawingarea3_expose_event           (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

gboolean
on_drawingarea3_motion_notify_event    (GtkWidget       *widget,
                                        GdkEventMotion  *event,
                                        gpointer         user_data);

gboolean
on_drawingarea3_button_press_event     (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data);

void
on_button_mesh_addhline_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_mesh_addvline_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_mesh_delhline_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_mesh_delvline_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_mesh_properties_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_mesh_check_courant_clicked   (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_drawingarea4_configure_event        (GtkWidget       *widget,
                                        GdkEventConfigure *event,
                                        gpointer         user_data);

gboolean
on_drawingarea4_expose_event           (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

gboolean
on_drawingarea4_motion_notify_event    (GtkWidget       *widget,
                                        GdkEventMotion  *event,
                                        gpointer         user_data);

gboolean
on_drawingarea4_button_press_event     (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data);

void
on_button_defmesh_genmesh_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_defmesh_export_elcom_clicked (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_drawingarea5_configure_event        (GtkWidget       *widget,
                                        GdkEventConfigure *event,
                                        gpointer         user_data);

gboolean
on_drawingarea5_expose_event           (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

gboolean
on_drawingarea5_motion_notify_event    (GtkWidget       *widget,
                                        GdkEventMotion  *event,
                                        gpointer         user_data);

gboolean
on_drawingarea5_button_press_event     (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data);

void
on_fileselection1_destroy              (GtkObject       *object,
                                        gpointer         user_data);

void
on_fileselection1_close                (GtkDialog       *dialog,
                                        gpointer         user_data);

void
on_fileselection1_response             (GtkDialog       *dialog,
                                        gint             response_id,
                                        gpointer         user_data);

void
on_fileselection1_ok_button1_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_fileselection1_cancel_button1_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_cell_properties_cxc_entry_expose_event
                                        (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

gboolean
on_cell_properties_cyc_entry_expose_event
                                        (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

gboolean
on_cell_properties_xc_entry_expose_event
                                        (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

gboolean
on_cell_properties_yc_entry_expose_event
                                        (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

void
on_cell_properties_depth_entry_changed (GtkEditable     *editable,
                                        gpointer         user_data);

gboolean
on_cell_properties_depth_entry_configure_event
                                        (GtkWidget       *widget,
                                        GdkEventConfigure *event,
                                        gpointer         user_data);

gboolean
on_cell_properties_depth_entry_expose_event
                                        (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

void
on_cell_properties_depth_entry_activate
                                        (GtkEntry        *entry,
                                        gpointer         user_data);

gboolean
on_courant_dt_property_entry_expose_event
                                        (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

void
on_courant_dt_property_entry_activate  (GtkEntry        *entry,
                                        gpointer         user_data);

gboolean
on_courant_speed_property_entry_expose_event
                                        (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

void
on_courant_speed_property_entry_activate
                                        (GtkEntry        *entry,
                                        gpointer         user_data);

gboolean
on_courant_dx_property_entry_expose_event
                                        (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

void
on_courant_dx_property_entry_activate  (GtkEntry        *entry,
                                        gpointer         user_data);

void
on_courant_properties_ok_button_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_brush_level_entry_activate          (GtkEntry        *entry,
                                        gpointer         user_data);

gboolean
on_brush_level_entry_expose_event      (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

void
on_fileselection2_ok_button1_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_fileselection_export_elcom_ok_button2_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_map_properties_xmin_entry_activate  (GtkEntry        *entry,
                                        gpointer         user_data);

gboolean
on_map_properties_xmin_entry_expose_event
                                        (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

void
on_map_properties_xmax_entry_activate  (GtkEntry        *entry,
                                        gpointer         user_data);

gboolean
on_map_properties_xmax_entry_expose_event
                                        (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

void
on_map_properties_xcells_entry_activate
                                        (GtkEntry        *entry,
                                        gpointer         user_data);

gboolean
on_map_properties_xcells_entry_expose_event
                                        (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

void
on_map_properties_landvalue_entry_activate
                                        (GtkEntry        *entry,
                                        gpointer         user_data);

gboolean
on_map_properties_landvalue_entry_expose_event
                                        (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

void
on_map_properties_ymin_entry_activate  (GtkEntry        *entry,
                                        gpointer         user_data);

gboolean
on_map_properties_ymin_entry_expose_event
                                        (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

void
on_map_properties_ymax_entry_activate  (GtkEntry        *entry,
                                        gpointer         user_data);

gboolean
on_map_properties_ymax_entry_expose_event
                                        (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

void
on_map_properties_ycells_entry_activate
                                        (GtkEntry        *entry,
                                        gpointer         user_data);

gboolean
on_map_properties_ycells_entry_expose_event
                                        (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

void
on_map_properties_openvalue_entry_activate
                                        (GtkEntry        *entry,
                                        gpointer         user_data);

gboolean
on_map_properties_openvalue_entry_expose_event
                                        (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

void
on_map_properties_zmin_entry_activate  (GtkEntry        *entry,
                                        gpointer         user_data);

gboolean
on_map_properties_zmin_entry_expose_event
                                        (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

void
on_map_properties_zmax_entry_activate  (GtkEntry        *entry,
                                        gpointer         user_data);

gboolean
on_map_properties_zmax_entry_expose_event
                                        (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

void
on_map_properties_zlayers_entry_activate
                                        (GtkEntry        *entry,
                                        gpointer         user_data);

gboolean
on_map_properties_zlayers_entry_expose_event
                                        (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

void
on_button3_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_map_properties_interpolation_precision_entry_activate
                                        (GtkEntry        *entry,
                                        gpointer         user_data);

gboolean
on_map_properties_interpolation_precision_entry_expose_event
                                        (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

void
on_map_properties_interpolation_maxiter_entry_activate
                                        (GtkEntry        *entry,
                                        gpointer         user_data);

gboolean
on_map_properties_interpolation_maxiter_entry_expose_event
                                        (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

/*
void
on_button3_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_map_properties_xmin_entry_activate  (GtkEntry        *entry,
                                        gpointer         user_data);

gboolean
on_map_properties_xmin_entry_expose_event
                                        (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

void
on_map_properties_xmax_entry_activate  (GtkEntry        *entry,
                                        gpointer         user_data);

gboolean
on_map_properties_xmax_entry_expose_event
                                        (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

void
on_map_properties_xcells_entry_activate
                                        (GtkEntry        *entry,
                                        gpointer         user_data);

gboolean
on_map_properties_xcells_entry_expose_event
                                        (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

void
on_map_properties_landvalue_entry_activate
                                        (GtkEntry        *entry,
                                        gpointer         user_data);

gboolean
on_map_properties_landvalue_entry_expose_event
                                        (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

void
on_map_properties_ymin_entry_activate  (GtkEntry        *entry,
                                        gpointer         user_data);

gboolean
on_map_properties_ymin_entry_expose_event
                                        (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

void
on_map_properties_ymax_entry_activate  (GtkEntry        *entry,
                                        gpointer         user_data);

gboolean
on_map_properties_ymax_entry_expose_event
                                        (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

void
on_map_properties_ycells_entry_activate
                                        (GtkEntry        *entry,
                                        gpointer         user_data);

gboolean
on_map_properties_ycells_entry_expose_event
                                        (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

void
on_map_properties_openvalue_entry_activate
                                        (GtkEntry        *entry,
                                        gpointer         user_data);

gboolean
on_map_properties_openvalue_entry_expose_event
                                        (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

void
on_map_properties_zmin_entry_activate  (GtkEntry        *entry,
                                        gpointer         user_data);

gboolean
on_map_properties_zmin_entry_expose_event
                                        (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

void
on_map_properties_zmax_entry_activate  (GtkEntry        *entry,
                                        gpointer         user_data);

gboolean
on_map_properties_zmax_entry_expose_event
                                        (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

void
on_map_properties_zlayers_entry_activate
                                        (GtkEntry        *entry,
                                        gpointer         user_data);

gboolean
on_map_properties_zlayers_entry_expose_event
                                        (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

void
on_map_properties_interpolation_precision_entry_activate
                                        (GtkEntry        *entry,
                                        gpointer         user_data);

gboolean
on_map_properties_interpolation_precision_entry_expose_event
                                        (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

void
on_map_properties_interpolation_maxiter_entry_activate
                                        (GtkEntry        *entry,
                                        gpointer         user_data);

gboolean
on_map_properties_interpolation_maxiter_entry_expose_event
                                        (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);
*/

gboolean
on_vruler2_configure_event             (GtkWidget       *widget,
                                        GdkEventConfigure *event,
                                        gpointer         user_data);

gboolean
on_drawingarea6_configure_event        (GtkWidget       *widget,
                                        GdkEventConfigure *event,
                                        gpointer         user_data);

gboolean
on_drawingarea6_expose_event           (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);


gboolean
on_vruler1_configure_event             (GtkWidget       *widget,
                                        GdkEventConfigure *event,
                                        gpointer         user_data);


gboolean
on_hruler1_configure_event             (GtkWidget       *widget,
                                        GdkEventConfigure *event,
                                        gpointer         user_data);

gboolean
on_drawingarea9_configure_event        (GtkWidget       *widget,
                                        GdkEventConfigure *event,
                                        gpointer         user_data);

gboolean
on_drawingarea9_expose_event           (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

gboolean
on_drawingarea10_configure_event       (GtkWidget       *widget,
                                        GdkEventConfigure *event,
                                        gpointer         user_data);

gboolean
on_drawingarea10_expose_event          (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

gboolean
on_drawingarea11_configure_event       (GtkWidget       *widget,
                                        GdkEventConfigure *event,
                                        gpointer         user_data);

gboolean
on_drawingarea11_expose_event          (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

gboolean
on_vruler3_configure_event             (GtkWidget       *widget,
                                        GdkEventConfigure *event,
                                        gpointer         user_data);

gboolean
on_hruler2_configure_event             (GtkWidget       *widget,
                                        GdkEventConfigure *event,
                                        gpointer         user_data);

gboolean
on_vruler6_configure_event             (GtkWidget       *widget,
                                        GdkEventConfigure *event,
                                        gpointer         user_data);

gboolean
on_vruler9_configure_event             (GtkWidget       *widget,
                                        GdkEventConfigure *event,
                                        gpointer         user_data);

gboolean
on_vruler16_configure_event            (GtkWidget       *widget,
                                        GdkEventConfigure *event,
                                        gpointer         user_data);

gboolean
on_vruler17_configure_event            (GtkWidget       *widget,
                                        GdkEventConfigure *event,
                                        gpointer         user_data);

gboolean
on_vruler18_configure_event            (GtkWidget       *widget,
                                        GdkEventConfigure *event,
                                        gpointer         user_data);

gboolean
on_vruler19_configure_event            (GtkWidget       *widget,
                                        GdkEventConfigure *event,
                                        gpointer         user_data);

gboolean
on_vruler20_configure_event            (GtkWidget       *widget,
                                        GdkEventConfigure *event,
                                        gpointer         user_data);

gboolean
on_vruler24_configure_event            (GtkWidget       *widget,
                                        GdkEventConfigure *event,
                                        gpointer         user_data);

gboolean
on_drawingarea17_configure_event       (GtkWidget       *widget,
                                        GdkEventConfigure *event,
                                        gpointer         user_data);

gboolean
on_drawingarea17_expose_event          (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

gboolean
on_drawingarea18_configure_event       (GtkWidget       *widget,
                                        GdkEventConfigure *event,
                                        gpointer         user_data);

gboolean
on_drawingarea18_expose_event          (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

gboolean
on_drawingarea7_configure_event        (GtkWidget       *widget,
                                        GdkEventConfigure *event,
                                        gpointer         user_data);

gboolean
on_drawingarea7_expose_event           (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

gboolean
on_drawingarea8_configure_event        (GtkWidget       *widget,
                                        GdkEventConfigure *event,
                                        gpointer         user_data);

gboolean
on_drawingarea8_expose_event           (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

gboolean
on_drawingarea13_configure_event       (GtkWidget       *widget,
                                        GdkEventConfigure *event,
                                        gpointer         user_data);

gboolean
on_drawingarea13_expose_event          (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

gboolean
on_drawingarea15_configure_event       (GtkWidget       *widget,
                                        GdkEventConfigure *event,
                                        gpointer         user_data);

gboolean
on_drawingarea15_expose_event          (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

gboolean
on_drawingarea14_configure_event       (GtkWidget       *widget,
                                        GdkEventConfigure *event,
                                        gpointer         user_data);

gboolean
on_drawingarea14_expose_event          (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

gboolean
on_drawingarea12_configure_event       (GtkWidget       *widget,
                                        GdkEventConfigure *event,
                                        gpointer         user_data);

gboolean
on_drawingarea12_expose_event          (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

gboolean
on_drawingarea16_configure_event       (GtkWidget       *widget,
                                        GdkEventConfigure *event,
                                        gpointer         user_data);

gboolean
on_drawingarea16_expose_event          (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

gboolean
on_drawingarea19_configure_event       (GtkWidget       *widget,
                                        GdkEventConfigure *event,
                                        gpointer         user_data);

gboolean
on_drawingarea19_expose_event          (GtkWidget       *widget,
                                        GdkEventExpose  *event,
                                        gpointer         user_data);

gboolean
on_hruler3_configure_event             (GtkWidget       *widget,
                                        GdkEventConfigure *event,
                                        gpointer         user_data);

gboolean
on_vruler4_configure_event             (GtkWidget       *widget,
                                        GdkEventConfigure *event,
                                        gpointer         user_data);

gboolean
on_hruler5_configure_event             (GtkWidget       *widget,
                                        GdkEventConfigure *event,
                                        gpointer         user_data);

gboolean
on_vruler7_configure_event             (GtkWidget       *widget,
                                        GdkEventConfigure *event,
                                        gpointer         user_data);

gboolean
on_hruler8_configure_event             (GtkWidget       *widget,
                                        GdkEventConfigure *event,
                                        gpointer         user_data);

gboolean
on_vruler10_configure_event            (GtkWidget       *widget,
                                        GdkEventConfigure *event,
                                        gpointer         user_data);

gboolean
on_vruler12_configure_event            (GtkWidget       *widget,
                                        GdkEventConfigure *event,
                                        gpointer         user_data);

gboolean
on_hruler7_configure_event             (GtkWidget       *widget,
                                        GdkEventConfigure *event,
                                        gpointer         user_data);

void
on_button_interpolation_properties_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);
