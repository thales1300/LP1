GCC = g++
GCC_FLAGS = -std=c++11 -I include -g -c
PROGRAMA = supermercado

all: $(PROGRAMA)

supermercado : main.o Cliente.o Estabelecimento.o
	$(GCC) -o $(PROGRAMA) main.o Cliente.o Estabelecimento.o
main.o: src/main.cpp
	$(GCC) $(GCC_FLAGS) src/main.cpp
Cliente.o: src/Cliente.cpp
	$(GCC) $(GCC_FLAGS) src/Cliente.cpp
Estabelecimento.o: src/Estabelecimento.cpp
	$(GCC) $(GCC_FLAGS) src/Estabelecimento.cpp
clean: 
	rm -f *.o
	rm -f $(PROGRAMA)
