#include <gtk/gtk.h>
#include <sys/types.h>
#include <string.h>

static bool establish_connection(){
    size_t accept_connect = 1;
    if (accept_connect > 0) return true;
    else return false;
}

static void wipe_machine(){
    size_t kill_response = kill(getpid(), SIGKILL); //just a test that button works but would be replaced with emergency wipe of attacted machine 
}

static void remote_console(){
    execv("/bin/konsole", NULL); // Should be edited after I find the best way to connect to another machine
}

static void activate(GtkApplication *app, gpointer data){
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW (window), "Kernel delirium");
    gtk_window_set_default_size (GTK_WINDOW (window), 1200, 800);
    
    GtkWidget *kill_image = gtk_image_new_from_file("icon.png");
    GtkWidget *console_image = gtk_image_new_from_file("console.png");

    //Kill button setup
    GtkWidget *kill_button = gtk_button_new();
    gtk_button_set_child(GTK_BUTTON (kill_button), kill_image);
    gtk_widget_set_halign(kill_button, GTK_ALIGN_END);
    gtk_widget_set_valign(kill_button, GTK_ALIGN_CENTER);
    g_signal_connect(GTK_BUTTON(kill_button), "clicked", G_CALLBACK(wipe_machine), NULL);
    
    //Console spawn button setup
    GtkWidget *console_button = gtk_button_new();
    gtk_button_set_child(GTK_BUTTON (console_button), console_image);
    gtk_widget_set_halign(console_button, GTK_ALIGN_END);
    gtk_widget_set_valign(console_button, GTK_ALIGN_CENTER);
    g_signal_connect(GTK_BUTTON(console_button), "clicked", G_CALLBACK(remote_console), NULL);

    GtkWidget *connect_button = gtk_button_new();
    //gtk_button_set_child(GTK_BUTTON(connect_button), console_image);
    gtk_widget_set_halign(connect_button, GTK_ALIGN_END);
    g_signal_connect(GTK_BUTTON(connect_button), "clicked", G_CALLBACK(establish_connection), NULL);
    //Box setup
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_box_append(GTK_BOX(box), kill_button);
    gtk_box_append(GTK_BOX(box), console_button);
    gtk_box_append(GTK_BOX(box), connect_button);

    //Window setup
    gtk_window_set_child(GTK_WINDOW(window), box);
    gtk_window_present (GTK_WINDOW (window));
}

int main(int argc, char **argv){
    GtkApplication *app;
    app = gtk_application_new("org.gtk.kernel-delirium", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK (activate), NULL);
    size_t app_status = g_application_run(G_APPLICATION(app), argc, argv); 
    return app_status;
}

