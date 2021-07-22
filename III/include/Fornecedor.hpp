#ifndef FORNECEDOR_H
#define FORNECEDOR_H

#include <string>

#include "Vetor.hpp"
#include "Estabelecimento.hpp"

class fornecedor {
    private:
    vetor <produto> produtosF;
    
    public:
    fornecedor();
    ~fornecedor();
    void listarProdutos();
    void repassarProdutos(std::string nome,int qt,estabelecimento& est);

};

#endif