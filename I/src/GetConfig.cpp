#include "GetConfig.h"

#include <fstream>

std::unordered_map<std::string, std::string> config (){
    
    std::unordered_map<std::string, std::string> config1;
    std::string mensagemArquivo;
    std::string key;
    std::string value;
    std::size_t found;

    std::ifstream arquivo_entrada("diary.config");

    if(!arquivo_entrada.is_open()){
        std::cerr << "file does not exist, a pattern will be created " <<"\n";
        createconfig();
        config1 = config();
        return config1;
    }
    
    while(!arquivo_entrada.eof()){
        
        getline(arquivo_entrada, mensagemArquivo);
        found = mensagemArquivo.find("path");
        
        if (found != std::string::npos){
            key = mensagemArquivo.substr(found , 4);

            for (size_t i = found+4 ; i < mensagemArquivo.size(); i++){
                if(mensagemArquivo[i] != ' ' && mensagemArquivo[i] != '='){
                    value = mensagemArquivo.substr(i , -1);
                    break;
                }
            }

            config1 [key] = value;
        }

        found = mensagemArquivo.find("default_format");
        
        if (found != std::string::npos){
            key = mensagemArquivo.substr(found , 14);

            for (size_t i = found+14 ; i < mensagemArquivo.size(); i++){
                if(mensagemArquivo[i] != ' ' && mensagemArquivo[i] != '='){
                    value = mensagemArquivo.substr(i , -1);
                    break;
                }
            }

            config1 [key] = value;
            
        }

    }
    arquivo_entrada.close();
    return config1;

}
void createconfig (){
    std::ofstream arquivo_saida("diary.config");
  
    if(!arquivo_saida.is_open()){
        std::cerr << "error creating file " <<"\n";
    }
    arquivo_saida << "path=diary.md" << "\n";
    arquivo_saida << "default_format=%d %t: %m" << "\n";
    arquivo_saida.close();
}