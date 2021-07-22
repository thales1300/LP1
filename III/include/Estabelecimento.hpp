#ifndef ESTABELECIMENTO_H
#define ESTABELECIMENTO_H

#include <string>

#include "Vetor.hpp"
#include "Produto.hpp"

class estabelecimento {
    public:
    static vetor<produto> produtos;
    static vetor<std::string> vendas;
    static float totalVendas;

    
    estabelecimento(std::string& name);
    ~estabelecimento();

    void listar ();
    bool venda (int cod);
    void caixa ();
    void venda (std::string nome);
    void reabastecer(std::string nome,int qt);
};

#endif