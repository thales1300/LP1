#include "../include/Estabelecimento.hpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <iterator>

std::list<produto> estabelecimento::produtos;
std::list<std::string> estabelecimento::vendas;
float estabelecimento::totalVendas;

estabelecimento::estabelecimento(std::string& name){

    std::ifstream arquivo_entrada(name);
    
    if(!arquivo_entrada.is_open()){
        std::cerr << "file does not exist" <<"\n";
        return;
    }

    std::string mensagemArquivo;
    produto produto;
    int quantidade;
    
    getline(arquivo_entrada, mensagemArquivo);

    while(getline(arquivo_entrada, mensagemArquivo)){
        
        std::string recebe;
        std::stringstream stream(mensagemArquivo);
        
        
        getline(stream, recebe, ',');
        std::stringstream converter(recebe);
        converter >> produto.cod;
        getline(stream, recebe, ',');
        produto.nome = recebe;
        getline(stream, recebe, ',');
        produto.unidadeMedida = recebe;
        getline(stream, recebe, ',');
        std::stringstream converter1 (recebe);
        char discart;
        converter1 >> discart;
        converter1 >> discart;
        converter1 >> discart;
        converter1 >> produto.preco;
        getline(stream, recebe);
        std::stringstream converter2 (recebe);
        converter2 >> quantidade;

        for (size_t i = 0; i <= quantidade; i++){
            produtos.push_back(produto);
        }
    
    }
}

estabelecimento::~estabelecimento(){
    std::ofstream arquivo_saida("caix.csv", std::ios::app);
  
    if(!arquivo_saida.is_open()){
        std::cerr << "error creating file " <<"\n";
        return;
    }

    arquivo_saida << "Total de vendas: " << totalVendas << "\n";
}
void estabelecimento::listar (){

    if(produtos.empty()){
        std::cout << "Estabelecimento sem produto" << "\n";
        return;
    }
    int contador = 0;
    for (auto it = produtos.begin();it != produtos.end(); it++){
        
        int cod = (*it).cod;
        
        std::advance(it,1);
        if( (*it).cod == cod){
            contador ++;
            std::advance(it,-1);
        }else if ((*it).cod != cod){
            std::advance(it,-1);
            std::cout << "Cod: " <<(*it).cod << " Nome: "<<(*it).nome << " Preço: " <<(*it).preco << " Quantidade: " << contador <<"\n";
            contador = 0;
        }
        
        
    }
}

void estabelecimento::caixa(){
    for (auto it = vendas.begin();it != vendas.end(); it++){
        std::cout << "-" <<  (*it) << "\n";
    }
    std::cout << "Total de vendas: R$ " << totalVendas << "\n";
}
bool estabelecimento::venda(int cod){
    for (auto it = produtos.begin();it != produtos.end(); it++){
        if((*it).cod == cod){
            vendas.push_back((*it).nome);
            totalVendas += (*it).preco;
            produtos.erase(it);
            return true;
        }
    }

    std::cout <<"Produto em falta"<<"\n";
    return false;
}

void estabelecimento::venda(std::string nome){
    std::ofstream arquivo_saida("caix.csv", std::ios::app);
  
    if(!arquivo_saida.is_open()){
        std::cerr << "error creating file " <<"\n";
        return;
    }

    arquivo_saida << "- " << nome << "\n";

}