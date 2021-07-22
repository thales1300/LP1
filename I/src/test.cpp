#include "Diary.h"
#include "GetDateTime.h"

#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char* argv[]){
    Message m;
    m.content = "message";
    
    std::string date = get_current_date();
    m.date = m.date.set_date_from_string(date);
    
    std::string time = get_current_time();
    m.time = m.time.set_time_from_string(time);

    std::cout << m.date.day << std::endl;
    std::cout << m.content << std::endl;
    std::cout << m.time.hour << std::endl;

    return 0;
}
