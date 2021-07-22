#include "../include/Cliente.hpp"
#include "../include/Estabelecimento.hpp"

#include <iostream>
#include <fstream>

cliente::cliente(){
    saldo = 0;
}
cliente::~cliente(){
    registro();
}
void cliente::verSacola(){
    if(sacola.empty()){
        std::cout << "Sacola vazia" << "\n";
        return;
    }
    for (std::vector<std::string>::iterator it = sacola.begin();it != sacola.end(); it++){
        std::cout << (*it) << "\n";
    }
}
void cliente::registro(){
    std::string nomeArquivo = "Cliente_";
    nomeArquivo += std::to_string(numCliente); 
    nomeArquivo += ".txt";
    std::ofstream arquivo_saida(nomeArquivo, std::ios::app);
  
    if(!arquivo_saida.is_open()){
        std::cerr << "error creating file " <<"\n";
        return;
    }

    for (std::vector<std::string>::iterator it = sacola.begin();it != sacola.end(); it++){
        arquivo_saida << "-" <<  (*it) << "\n";
    }

}
void cliente::comprar(std::string nome,float preco, int cod, estabelecimento& est){

    if(saldo < preco){
        std::cout << "Saldo insuficiente" << "\n";
    } else{
        if(est.venda(cod) == true){
            this -> saldo -= preco;
            sacola.push_back(nome);
            est.venda(nome);
            std::cout << "Compra efetuada" << "\n";
        } 
    }
}