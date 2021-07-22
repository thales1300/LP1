#include "../include/Fornecedor.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

fornecedor::fornecedor(){
std::ifstream arquivo_entrada("fornecedor.csv");
    
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
        converter >> produto.nome;
        getline(stream, recebe);
        std::stringstream converter2 (recebe);
        converter2 >> quantidade;

        for (size_t i = 1; i <= quantidade; i++){
            produtosF.addBack(produto);
        }
    }
}
fornecedor::~fornecedor(){
    std::ofstream arquivo_saida("fornecedor.csv");

    if(!arquivo_saida.is_open()){
        std::cerr << "error creating file " <<"\n";
        return;
    }
    int contador = 0;
    arquivo_saida << "PRODUTO,QUANTIDADE"<< "\n";
    for (size_t i = 0;i < produtosF.getSize(); i++){
        
        std::string nome = produtosF.getVetor(i).nome;
        i++;
        if( produtosF.getVetor(i).nome == nome){
            contador ++;
            i--;
        }else if (produtosF.getVetor(i).nome != nome){
            i--;
            arquivo_saida <<produtosF.getVetor(i).nome<< ","<< ++contador << "\n";
            contador = 0;
        }
        
    }

}
void fornecedor::listarProdutos(){
    if(produtosF.getSize() == 0){
        std::cout << "Fornecedor sem produto" << "\n";
        return;
    }
    int contador = 0;
    for (size_t i = 0;i < produtosF.getSize(); i++){
        
        std::string nome = produtosF.getVetor(i).nome;
        i++;
        if( produtosF.getVetor(i).nome == nome){
            contador ++;
            i--;
        }else if (produtosF.getVetor(i).nome != nome){
            i--;
            std::cout << " Nome: "<<produtosF.getVetor(i).nome << " Quantidade: " << ++contador <<"\n";
            contador = 0;
        }
        
    }
}
void fornecedor::repassarProdutos(std::string nome,int qt,estabelecimento& est){
    
    int quantidade = 0;
    for (size_t i = 0; i <= produtosF.getSize(); i++){
        if (produtosF.getVetor(i).nome == nome){
            quantidade ++;
        }else if (i == produtosF.getSize() && quantidade == 0 ){
            std::cout << "Produto não encontrado" << "\n";
            return;
        }
    }
    if (quantidade >= qt){
        for (size_t i = 0; i < qt; i++){
            for (size_t i = 0; i <= produtosF.getSize(); i++){
                if(produtosF.getVetor(i).nome == nome){
                    produtosF.remove(i);
                    break;
                }
            }
        }

        est.reabastecer(nome,qt);
    }else if (quantidade < qt){
        std::cout << "Fornecedor não tem essa quantidade" << "\n";
    }else{
        std::cerr << "error" <<"\n";
    }
    
}