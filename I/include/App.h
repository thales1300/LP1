#ifndef APP_H
#define APP_H

#include "Diary.h"

#include <string>

struct App {
    Diary diary;

    App(const std::string& filename);
    int run(int argc, char* argv[],std::string default_format);
    int show_usage(const std::string& filerun);
    void interactive();
    void add();
    void add(const std::string message);
    void list_messages(std::string default_format);
    void search();
    void search(const std::string term);

};
#endif
