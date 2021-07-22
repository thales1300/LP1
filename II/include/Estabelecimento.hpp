#ifndef ESTABELECIMENTO_H
#define ESTABELECIMENTO_H

#include <string>
#include <list>

#include <Produto.hpp>

class estabelecimento {
    public:
    static std::list<produto> produtos;
    static std::list<std::string> vendas;
    static float totalVendas;

    estabelecimento(std::string& name);
    ~estabelecimento();

    void listar ();
    bool venda (int cod);
    void caixa ();
    void venda (std::string nome);

};

#endif