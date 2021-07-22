#include "App.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

App::App(const std::string& filename) : diary(filename){
}

int App::run(int argc, char* argv[],std::string default_format){
    if (argc == 1) {
        return show_usage(argv[0]);
    }

    std::string action = argv[1];

    if (action == "add") {
        if (argc == 2) {
            add();
        } else {
            add(argv[2]);
        }
    } else if (action == "list") {
        if(argc == 2){
            list_messages(default_format);
        }else{
            list_messages(argv[2]);
        }
    }else if(action == "search"){
        if (argc == 2) {
            search();
        } else {
            search(argv[2]);
        }
        
    }else if (action == "interactive"){
        interactive();
    }else{
        return show_usage(argv[0]);
    }

    return 0;
}

void App::add(){
    std::string message;
    std::cout << "Enter your message:" << std::endl;
    std::getline(std::cin, message);

    add(message);
}

void App::add(const std::string message){
    diary.add(message);
}

void App::list_messages(std::string default_format){

    for (diary.iterator = diary.messages.begin();  diary.iterator != diary.messages.end() ; diary.iterator++){
        std::stringstream stream(default_format);
        std::string value;
        char test;
        stream << std::noskipws;
        while(stream >> test){
            if(test == '%'){
                stream >> test;
                while (test == '%'){
                    value += test;
                    stream >> test;
                }
                if(test == 'd'){
                    value += (*diary.iterator).date.date_to_string((*diary.iterator).date);
                }else if(test == 't'){
                    value += (*diary.iterator).time.time_to_string((*diary.iterator).time);
                }else if(test == 'm'){
                    value += (*diary.iterator).content;
                }else{
                    value += "%";
                    value += test;
                }
                
            }else{
                value += test;
            }
            
        }
        std::cout << value << "\n";
    }
}
void App::search(){
    std::string message;
    std::cout << "Enter your term: " << std::endl;
    std::getline(std::cin, message);

    search(message);
}
void App::search (const std::string term){
    std::vector<Message*> message_search;
    message_search = diary.search(term);
    std::cout << "Were found " << message_search.size() << " messages with that term " << "\n";
    if(message_search.size() == 0){
        return;
    }
    for (size_t i = 0; i < message_search.size(); i++){
        std::cout << message_search[i]->content << "\n";
    }
    

}

void App::interactive(){
    std::string option ;
    do{
        
        std::cout << "Select an action:" << "\n"
        << "0 - Finish" << "\n" << "1 - Add" << "\n"
        << "2 - List" << "\n" << "3 - Search" << "\n";
        std::getline(std::cin, option);
    
        
        if (option == "0") {
            std::cout << "Finishing..." << "\n";
            return;
        } else if (option == "1") {
            add();
        }else if(option == "2"){
            list_messages("%d %t: %m");
        }else if (option == "3"){
            search();
        }else{
            std::cout << "invalid function" << "\n";
        }
    } while (option != "0");
    

}

int App::show_usage(const std::string& filerun){
    std::cout << "Uso: " << filerun << "\n" << "add <message>" << "\n" 
    <<"list <%d - to date %t - to time %m - to message>" << "\n" << "search <term>" << "\n"  << "interactive";
    return 1;
}
