#include <stdlib.h>
#include <gtk/gtk.h>

static void new_classic_game (GtkWidget *widget, gpointer data)
{
  GtkWidget *window=gtk_window_new(GTK_WINDOW_TOPLEVEL);

  gtk_window_set_title(GTK_WINDOW(window), "Classic Mode");
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

  gtk_container_set_border_width(GTK_CONTAINER(window), 200);
  g_signal_connect(G_OBJECT(window),"destroy",G_CALLBACK(gtk_main_quit), NULL);

  GtkWidget *button=gtk_button_new_with_label("Quit");
  g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_widget_destroy), window);

  gtk_container_add(GTK_CONTAINER(window), button);

  gtk_widget_show(button);

  gtk_widget_show(window);

  gtk_main();

}

static void new_custome_game (GtkWidget *widget, gpointer data)
{
  GtkWidget *window=gtk_window_new(GTK_WINDOW_TOPLEVEL);

  gtk_window_set_title(GTK_WINDOW(window), "Custom Mode");
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

  gtk_container_set_border_width(GTK_CONTAINER(window), 200);
  g_signal_connect(G_OBJECT(window),"destroy", G_CALLBACK(gtk_main_quit), NULL);

  GtkWidget *button=gtk_button_new_with_label("Quit");
  g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_widget_destroy), window);

  gtk_container_add(GTK_CONTAINER(window), button);

  gtk_widget_show(button);

  gtk_widget_show(window);

  gtk_main();

}

static void activate (GtkApplication *app, gpointer user_data)
{
  GtkWidget *window;
  GtkWidget *grid;
  GtkWidget *button1;
  GtkWidget *button2;
  GtkWidget *button3;

  window = gtk_application_window_new (app);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_title (GTK_WINDOW (window), "Memory Game ");
  gtk_container_set_border_width (GTK_CONTAINER (window), 100);

  grid = gtk_grid_new ();

  gtk_container_add (GTK_CONTAINER (window), grid);

  button1 = gtk_button_new_with_label ("Create classic game");
  g_signal_connect (button1, "clicked", G_CALLBACK (new_classic_game), NULL);
  g_signal_connect_swapped (button1, "clicked", G_CALLBACK (gtk_widget_destroy), window);

  gtk_grid_attach (GTK_GRID (grid), button1, 0, 0, 1, 1);

  button2 = gtk_button_new_with_label ("Create custom game");
  g_signal_connect (button2, "clicked", G_CALLBACK (new_custome_game), NULL);
  g_signal_connect_swapped (button2, "clicked", G_CALLBACK (gtk_widget_destroy), window);
  
  gtk_grid_attach (GTK_GRID (grid), button2, 1, 0, 1, 1);

  button3 = gtk_button_new_with_label ("Quit");
  g_signal_connect_swapped (button3, "clicked", G_CALLBACK (gtk_widget_destroy), window);
  
  gtk_grid_attach (GTK_GRID (grid), button3, 0, 1, 2, 1);

  gtk_widget_show_all (window);

}

int main (int argc, char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}