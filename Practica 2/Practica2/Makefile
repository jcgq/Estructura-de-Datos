
SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c

all: $(BIN)/pruebadiccionario
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************


$(BIN)/pruebadiccionario: $(OBJ)/main.o $(OBJ)/diccionario.o $(OBJ)/termino.o
	g++ $(OBJ)/main.o $(OBJ)/diccionario.o $(OBJ)/termino.o -o $(BIN)/pruebadiccionario
$(OBJ)/diccionario.o:$(SRC)/diccionario.cpp
	g++ $(CPPFLAGS) $(SRC)/diccionario.cpp -o $(OBJ)/diccionario.o
$(OBJ)/termino.o: $(SRC)/termino.cpp
	g++ $(CPPFLAGS) $(SRC)/termino.cpp -o $(OBJ)/termino.o
$(OBJ)/main.o: $(SRC)/main.cpp
	g++ $(CPPFLAGS) $(SRC)/main.cpp -o $(OBJ)/main.o
	



# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
