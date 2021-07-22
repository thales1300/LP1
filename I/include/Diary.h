#ifndef DIARY_H
#define DIARY_H

#include "Message.h"

#include <iostream>
#include <string>
#include <vector>

struct Diary {
    
    Diary(const std::string& filename);

    std::string filename;
    std::vector<Message> messages;
    std::vector<Message>::iterator iterator;

    void add(const std::string& message);
    void write();
    std::vector<Message*> search(const std::string& term);

};
#endif
