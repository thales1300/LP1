GCC = g++
GCC_FLAGS = -std=c++11 -I include -g -c
PROGRAMA = supermercado

all: $(PROGRAMA)

supermercado : main.o Cliente.o Estabelecimento.o Fornecedor.o
	$(GCC) -o $(PROGRAMA) main.o Cliente.o Estabelecimento.o Fornecedor.o
main.o: src/main.cpp
	$(GCC) $(GCC_FLAGS) src/main.cpp
Cliente.o: src/Cliente.cpp
	$(GCC) $(GCC_FLAGS) src/Cliente.cpp
Estabelecimento.o: src/Estabelecimento.cpp
	$(GCC) $(GCC_FLAGS) src/Estabelecimento.cpp
Fornecedor.o: src/Fornecedor.cpp
	$(GCC) $(GCC_FLAGS) src/Fornecedor.cpp
clean: 
	rm -f *.o
	rm -f $(PROGRAMA)
