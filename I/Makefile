GCC = g++
GCC_FLAGS = -std=c++11 -I include -g
PROGRAMA = diary

all: $(PROGRAMA)

diary: main.o Diary.o App.o Date.o GetDateTime.o Time.o GetConfig.o
	$(GCC) -o diary main.o Diary.o App.o Date.o GetDateTime.o Time.o GetConfig.o -std=c++11
main.o: src/main.cpp
	$(GCC) $(GCC_FLAGS) -c src/main.cpp
Diary.o: src/Diary.cpp include/Diary.h
	$(GCC) $(GCC_FLAGS) -c src/Diary.cpp
App.o: src/App.cpp include/App.h
	$(GCC) $(GCC_FLAGS) -c src/App.cpp
GetDateTime.o: src/GetDateTime.cpp include/GetDateTime.h
	$(GCC) $(GCC_FLAGS) -c src/GetDateTime.cpp
Time.o: src/Time.cpp include/Time.h
	$(GCC) $(GCC_FLAGS) -c src/Time.cpp
Date.o: src/Date.cpp include/Date.h
	$(GCC) $(GCC_FLAGS) -c src/Date.cpp
GetConfig.o: src/GetConfig.cpp include/GetConfig.h
	$(GCC) $(GCC_FLAGS) -c src/GetConfig.cpp
doc.pdf: diary.md
	pandoc -f markdown -t latex -o doc.pdf
clean: 
	rm -f *.o
	rm -f $(PROGRAMA)
