#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>

#include "Vetor.hpp"
#include "Estabelecimento.hpp"

class cliente {
    private:
    float saldo;
    vetor <std::string> sacola;
    int numCliente;
    
    public:
    cliente();
    ~cliente();
    
    void setnumCliente(int numCliente);
    void addSaldo(float saldo);
    void removeSaldo(float saldo);
    float getSaldo();
    void comprar(std::string nome,float preco,int cod, estabelecimento& est);
    void verSacola();
    void registro();
};

#endif