#include <iostream>

#include "../include/Estabelecimento.hpp"
#include "../include/Cliente.hpp"
#include "../include/Fornecedor.hpp"

int main(int argc, char* argv[]){

    std::string option;
    std::string aux;
    int contadorCliente = 1;
    std::string nomeArquivo = "estoque.csv";
    cliente *x = new cliente();
    fornecedor f;

    estabelecimento est (nomeArquivo);
    
    while (true){

        std::cout << "Select an action:" << "\n"
        << "1 - Add Saldo" << "\n" << "2 - Remover Saldo" << "\n"
        << "3 - Ver Sacola" << "\n" << "4 - Listar produtos da loja" << "\n" 
        << "5 - Comprar"<< "\n" << "6 - Caixa" <<"\n"<<"7 - Finalizar Compras" << "\n"
        <<"8 - Listar produtos do fornecedor" << "\n" <<"9 - Reabastecer estoque" << "\n";
        std::getline(std::cin, option);
        
        if (option == "1") {
            std::cout << "Digite o valor do saldo a ser adcionado" << "\n";
            std::getline(std::cin, aux);
            (*x).addSaldo(std::stod( aux ));
            std::cout << "Adcionado. " << "Saldo atual: " << (*x).getSaldo() << "\n";
            
        }else if (option == "2") {
            float saldo;
            std::cout << "Digite o valor do saldo a ser removido" << "\n";
            std::getline(std::cin, aux);
            (*x).removeSaldo(std::stod( aux ));
            std::cout << "Removido. " << "Saldo atual: " << (*x).getSaldo() << "\n";

        }else if(option == "3"){
            (*x).verSacola();
        }else if(option == "4"){
            est.listar();
        }else if (option == "5"){
            std::cout << "Digite o nome do produto" << "\n";
            std::getline(std::cin, aux);

            for (size_t i = 0; i <= est.produtos.getSize() ; i++){
                if( aux == est.produtos.getVetor(i).nome){
                    (*x).comprar(est.produtos.getVetor(i).nome,est.produtos.getVetor(i).preco,est.produtos.getVetor(i).cod,est);
                    break;
                }else if (i == est.produtos.getSize()){
                    std::cout << "Produto não encontrado"<< "\n";
                }
            } 
        }else if(option == "6"){
            est.caixa();
        }else if (option == "7"){
            std::cout << "Select an action:" << "\n" 
            << "1 - Novo Cliente" << " 2 - finalizar programa" << "\n";
            std::getline(std::cin ,option);
            if (option == "1"){
                (*x).setnumCliente(contadorCliente);
                delete x;
                cliente *x = new cliente();
                contadorCliente ++;
                std::cout << "Novo cliente iniciado" << "\n";
            }else if ("2"){
                break;
            }else{
                std::cout << "Função invalida" << "\n";
            }
        }else if(option == "8"){
            f.listarProdutos();
        }else if(option == "9"){
            std::string aux2;
            std::cout << "Digite nome do produto" << "\n";
            std::getline(std::cin, aux2);
            std::cout << "Digite a quantidade" << "\n";
            std::getline(std::cin, aux);
            int a = std::stod( aux );
            f.repassarProdutos(aux2,a,est);
        }else{
            std::cout << "Função invalida" << "\n";
        }
    }
    
    (*x).setnumCliente(contadorCliente);
    delete x;
    return 0;
}