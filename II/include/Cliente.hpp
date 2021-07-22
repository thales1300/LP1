#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <vector>

#include <Estabelecimento.hpp>

class cliente {
    public:
    float saldo;
    std::vector <std::string> sacola;
    int numCliente;

    cliente();
    ~cliente();

    void comprar(std::string nome,float preco,int cod, estabelecimento& est);
    void verSacola();
    void registro();
};

#endif