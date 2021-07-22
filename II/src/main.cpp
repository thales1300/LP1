#include <iostream>

#include "../include/Estabelecimento.hpp"
#include "../include/Cliente.hpp"

int main(int argc, char* argv[]){

    std::string option;
    int contadorCliente = 1;
    std::string nomeArquivo = "estoque.csv";
    cliente *x = new cliente();

    estabelecimento est (nomeArquivo);
    
    while (true){
        
        std::cin.clear();

        std::cout << "Select an action:" << "\n"
        << "1 - Add Saldo" << "\n" << "2 - Remover Saldo" << "\n"
        << "3 - Ver Sacola" << "\n" << "4 - Listar produtos da loja" << "\n" 
        << "5 - Comprar"<< "\n" << "6 - Caixa" <<"\n"<<"7 - Finalizar Compras" << "\n";
        std::getline(std::cin, option);
        
        if (option == "1") {
            float saldo = 0;
            std::cout << "Digite o valor do saldo a ser adcionado" << "\n";
            std::cin >> saldo;
            if(std::cin.fail()){
                std::cout << "Saldo errado, tente novamente" << "\n";
                continue;
            }else{
                std::cin.ignore();
                x -> saldo += saldo;
                std::cout << "Adcionado " << "Saldo atual: " << x -> saldo << "\n";
            }
            
        }else if (option == "2") {
            float saldo;
            std::cout << "Digite o valor do saldo a ser removido" << "\n";
            std::cin >> saldo;
            if(std::cin.fail()){
                std::cout << "Saldo errado, tente novamente" << "\n";
                continue;
            }else{
                std::cin.ignore();
                x -> saldo -= saldo;
                std::cout << "Removido " << "Saldo atual: " << x -> saldo <<  "\n";
            }
        }else if(option == "3"){
            (*x).verSacola();
        }else if(option == "4"){
            est.listar();
        }else if (option == "5"){
            int codigo;
            std::cout << "Digite o codigo do produto" << "\n";
            std::cin >> codigo;
            if(std::cin.fail()){
                std::cout << "Codigo errado, tente novamente" << "\n";
                continue;
            }else{
                std::cin.ignore();
                for (auto it = est.produtos.begin() ;it != est.produtos.end(); it++){
                    if( codigo == (*it).cod){
                        (*x).comprar((*it).nome,(*it).preco,(*it).cod,est);
                        break;
                    }
                    else{
                        std::cout << "Produto não encontrado"<< "\n";
                    }
                }
            }
            
        }else if(option == "6"){
            est.caixa();
        }else if (option == "7"){
            std::cout << "Select an action:" << "\n" 
            << "1 - Novo Cliente" << " 2 - finalizar programa" << "\n";
            std::getline(std::cin ,option);
            if (option == "1"){
                x ->numCliente = contadorCliente;
                delete x;
                cliente *x = new cliente();
                contadorCliente ++;
                std::cout << "Novo cliente iniciado" << "\n";
            }else if ("2"){
                break;
            }else{
                std::cout << "Função invalida" << "\n";
            }
        }else{
                std::cout << "Função invalida" << "\n";
        }
    }
    
    x -> numCliente = contadorCliente;
    delete x;
    return 0;
}