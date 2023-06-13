#---------------------------------------------------------------------
# Arquivo		: Makefile
# Conteúdo	: Compilar o programa
# Autor			: André Luiz Alves Costa (andrelac963@gmail.com)
# Histórico	: 2023-00-00 - arquivo criado
#---------------------------------------------------------------------
# Opções	: make all - compila tudo e executa exemplo
#					: make clean - remove objetos e executável
#---------------------------------------------------------------------

CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/fecho.o $(OBJ)/stack.o $(OBJ)/point.o $(OBJ)/jarvis.o $(OBJ)/graham.o
HDRS = $(INC)/stack.hpp $(INC)/point.hpp $(INC)/jarvis.hpp $(INC)/graham.hpp
CFLAGS = -Wall -c -I$(INC)

EXE = $(BIN)/fecho

all:  $(EXE)
	$(EXE) ENTRADA10.txt
	$(EXE) ENTRADA100.txt
	$(EXE) ENTRADA1000.txt

$(BIN)/fecho: $(OBJS)
	$(CC) -g -o $(BIN)/fecho $(OBJS) $(LIBS)

$(OBJ)/fecho.o: $(HDRS) $(SRC)/fecho.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/fecho.o $(SRC)/fecho.cpp

$(OBJ)/stack.o: $(HDRS) $(SRC)/stack.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/stack.o $(SRC)/stack.cpp

$(OBJ)/point.o: $(HDRS) $(SRC)/point.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/point.o $(SRC)/point.cpp

$(OBJ)/jarvis.o: $(HDRS) $(SRC)/jarvis.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/jarvis.o $(SRC)/jarvis.cpp

$(OBJ)/graham.o: $(HDRS) $(SRC)/graham.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/graham.o $(SRC)/graham.cpp
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out
