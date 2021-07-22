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
    if(sacola.getSize() == 0 ){
        std::cout << "Sacola vazia" << "\n";
        return;
    }
    for (size_t i = 0; i < sacola.getSize(); i++){
        std::cout << sacola.getVetor(i) << "\n";
    }
    
}
void cliente::registro(){
    std::string nomeArquivo = "Cliente_";
    nomeArquivo += std::to_string(numCliente); 
    nomeArquivo += ".txt";
    std::ofstream arquivo_saida(nomeArquivo);
  
    if(!arquivo_saida.is_open()){
        std::cerr << "error creating file " <<"\n";
        return;
    }

    for (size_t i = 0; i < sacola.getSize(); i++){
        arquivo_saida << "-" <<  sacola.getVetor(i) << "\n";
    }

}
void cliente::comprar(std::string nome,float preco, int cod, estabelecimento& est){

    if(saldo < preco){
        std::cout << "Saldo insuficiente" << "\n";
    } else if (saldo >= preco){
        if(est.venda(cod) == true){
            this -> saldo -= preco;
            sacola.addBack(nome);
            est.venda(nome);
            std::cout << "Compra efetuada" << "\n";
        } 
    }else{
        std::cout << "Erro" << "\n";
    }
}
void cliente::setnumCliente(int numCliente){
   this->numCliente = numCliente; 
}
void cliente::addSaldo(float saldo){
    this->saldo = this->saldo + saldo;
}
void cliente::removeSaldo(float saldo){
    if(this->saldo - saldo < 0){
        this->saldo = 0;
    }
    this->saldo = this->saldo - saldo;
}
float cliente::getSaldo(){
    return saldo;
}