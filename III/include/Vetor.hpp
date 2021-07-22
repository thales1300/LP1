#ifndef VETORSUP_H
#define VETORSUP_H

#include <string>
#include "../include/Produto.hpp"

template <class type>

class vetor {
    private:
    type* vetor1;
    int size = 0;
    int capacity = 10;
    
    public:
    vetor(){
        vetor1 = new type[capacity];
    }
    ~vetor(){
        delete[] vetor1;
    }
    void newVetor(){
        capacity *= 2;
        type* new_array = new type[capacity];

        for (size_t i = 0; i < size; i++){
            new_array[i] = vetor1[i];
        }
    
        delete[] vetor1;
        vetor1 = new_array;
    }
    int getSize(){
        return size;
    }
    void addBack(type t){
        if (size >= capacity) {
            newVetor();
        }
        vetor1[size] = t;
        size ++;
    }
    void remove(int size){
        for (size_t i = size; i < this->size; i++){
            vetor1[i] = vetor1[1+i];
        }
    }
    type getVetor(int size){
        return vetor1[size];
    }
    void addMid(int size,type t){
        if (size >= capacity) {
            newVetor();
        }
        for (size_t i = this->size; i >= size; i--){
            vetor1[1+i] = vetor1[i];
            if(i == size){
                vetor1[size] = t;
            }
        }
        this->size ++;
    }

};

#endif