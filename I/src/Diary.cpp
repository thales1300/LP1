#include "Diary.h"
#include "GetDateTime.h"

#include <fstream>

Diary::Diary(const std::string& name) : filename(name){
    
    std::ifstream arquivo_entrada(filename);

    if(!arquivo_entrada.is_open()){
        std::cerr << "file does not exist, after adding it will be created" <<"\n";
        return;
    }
    std::string mensagemArquivo;
    Message m;

    while(!arquivo_entrada.eof()){

        getline(arquivo_entrada, mensagemArquivo);

        if (mensagemArquivo.size() == 0){
            continue;
        }
        
        if (mensagemArquivo[0] == '#'){
      	    m.date.set_date_from_string(mensagemArquivo.substr(2,-1));
            continue;
        }
        if (mensagemArquivo[0] == '-'){
            m.time.set_time_from_string(mensagemArquivo.substr(2,9));
            m.content = mensagemArquivo.substr(11,-1);
        }

        messages.push_back(m);
    } 


}


void Diary::add(const std::string& message){

    Message m;
    m.content = message;
    
    std::string date = get_current_date();
    m.date.set_date_from_string(date);
    
    std::string time = get_current_time();
    m.time.set_time_from_string(time);
    
    messages.push_back(m);
    
    write();
}

void Diary::write(){
    
    std::ofstream arquivo_saida(filename, std::ios::app);
  
    if(!arquivo_saida.is_open()){
        std::cerr << "error creating file " <<"\n";
        return;
    }
  
    std::ifstream arquivo_entrada(filename);
    
    if(!arquivo_entrada.is_open()){
        std::cerr << "error opening file" <<"\n";
        return;
    }
    
    std::string mensagemArquivo;
    iterator = messages.end()-1;
    
    while(!arquivo_entrada.eof()){
    
        getline(arquivo_entrada, mensagemArquivo);
  
        if (mensagemArquivo == "# "+  (*iterator).date.date_to_string((*iterator).date) ){
            arquivo_saida << "- " <<  (*iterator).time.time_to_string((*iterator).time) << " " <<  (*iterator).content << "\n";
            return;
        }else if (arquivo_entrada.eof()){
            arquivo_saida << "# " <<  (*iterator).date.date_to_string((*iterator).date) << "\n";
            arquivo_saida << "- " <<  (*iterator).time.time_to_string((*iterator).time) << " " <<  (*iterator).content << "\n";
        }
    }  
}

std::vector<Message*> Diary::search(const std::string& term){

    std::vector<Message*> message_search;

    for (iterator = messages.begin();  iterator != messages.end() ; iterator++){
        if(std::string::npos != (*iterator).content.find(term)){
            message_search.push_back( &(*iterator) );
        }
    }

    return message_search;
}
