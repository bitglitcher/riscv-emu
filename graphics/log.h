#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <gtk-3.0/gtk/gtk.h>
#include <gtk-3.0/gtk/gtkbuilder.h>
#include <gdk/gdk.h>

#define INFO_MSG    0
#define WARNING_MSG 1
#define ERROR_MSG   2

typedef struct message_t
{
    int type;
    std::string message;
    message_t(std::string message, int type) : message(message), type(type){};
} message_t;

//This will contains all log into
class log
{
    public:
        log();
        ~log();
        //Display warning message on log tab
        void warning(std::string message);
        //Display info message on log tab
        void info(std::string message);
        //Display error message on log tab
        void error(std::string message);
        //Save logged messages
        int save(std::string file);
        //Attach tab to notebook
        void attack_to_notebook(GtkNotebook* notebook);
        //Deattach tab to notebook
        void deattack_to_notebook(GtkNotebook* notebook);
    private:
        std::vector<message_t> msg_buffer;
        GtkWidget* tab_label;
        GtkTextTagTable* tagtable;
        GtkTextBuffer* buffer;
        GtkWidget* text_view;
};