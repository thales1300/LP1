#include "../include/Estabelecimento.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

vetor<produto> estabelecimento::produtos;
vetor<std::string> estabelecimento::vendas;
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

        for (size_t i = 1; i <= quantidade; i++){
            produtos.addBack(produto);
        }

    }
}

estabelecimento::~estabelecimento(){
    std::ofstream arquivo_saida("caixa.csv", std::ios::app);
  
    if(!arquivo_saida.is_open()){
        std::cerr << "error creating file " <<"\n";
        return;
    }

    arquivo_saida << "Total de vendas: " << totalVendas << "\n";
    arquivo_saida.close();

    std::ofstream arquivo_saida2("estoque.csv");
  
    if(!arquivo_saida2.is_open()){
        std::cerr << "error creating file " <<"\n";
        return;
    }
    int contador = 0;
    arquivo_saida2 << "COD,PRODUTO,UNIDADE DE MEDIDA,PREÇO,QUANTIDADE" <<"\n";
    for (size_t i = 0;i < produtos.getSize(); i++){
        
        int cod = produtos.getVetor(i).cod;
        i++;
        if( produtos.getVetor(i).cod == cod){
            contador ++;
            i--;
        }else if (produtos.getVetor(i).cod != cod){
            i--;
            arquivo_saida2 << produtos.getVetor(i).cod << ',' <<produtos.getVetor(i).nome 
            << ',' << produtos.getVetor(i).unidadeMedida << ',' 
            <<'"'<< "R$ " <<produtos.getVetor(i).preco<< '"' << ','
            << ++contador <<"\n";
            contador = 0;
        }

    }
}
void estabelecimento::listar(){

    if(produtos.getSize() == 0){
        std::cout << "Estabelecimento sem produto" << "\n";
        return;
    }
    int contador = 0;
    for (size_t i = 0;i < produtos.getSize(); i++){
        
        int cod = produtos.getVetor(i).cod;
        i++;
        if( produtos.getVetor(i).cod == cod){
            contador ++;
            i--;
        }else if (produtos.getVetor(i).cod != cod){
            i--;
            std::cout << "Cod: " << produtos.getVetor(i).cod << " Nome: "<<produtos.getVetor(i).nome << " Preço: " << produtos.getVetor(i).preco << " Quantidade: " << ++contador <<"\n";
            contador = 0;
        }

    }
}

void estabelecimento::caixa(){
    for (size_t i = 0;i < vendas.getSize(); i++){
        std::cout << "-" <<  vendas.getVetor(i) << "\n";
    }
    std::cout << "Total de vendas: R$ " << totalVendas << "\n";
}
bool estabelecimento::venda(int cod){
    for (size_t i = 0;i < produtos.getSize(); i++){
        if(produtos.getVetor(i).cod == cod){
            vendas.addBack(produtos.getVetor(i).nome);
            totalVendas += produtos.getVetor(i).preco;
            produtos.remove(i);
            return true;
        }
    }

    std::cout <<"Produto em falta"<<"\n";
    return false;
}

void estabelecimento::venda(std::string nome){
    std::ofstream arquivo_saida("caixa.csv", std::ios::app);
  
    if(!arquivo_saida.is_open()){
        std::cerr << "error creating file " <<"\n";
        return;
    }

    arquivo_saida << "- " << nome << "\n";

}

void estabelecimento::reabastecer(std::string nome,int qt){
    produto aux;
    int aux1;
    for (size_t i = 0;i < produtos.getSize(); i++){
        if(produtos.getVetor(i).nome == nome){
           aux.cod = produtos.getVetor(i).cod;
           aux.preco = produtos.getVetor(i).preco;
           aux.unidadeMedida = produtos.getVetor(i).unidadeMedida;
           aux1 = i;
           break;
        }
    }
    for (size_t i = 0; i < qt; i++){
        produtos.addMid(aux1,aux);
    }
    
    
}