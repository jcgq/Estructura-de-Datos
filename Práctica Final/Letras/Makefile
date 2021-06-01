SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c


all1: $(BIN)/letras $(BIN)/cantidad_letras $(BIN)/testlista_palabras
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************
$(BIN)/letras:
	$(CXX) -o $(BIN)/letras $(SRC)/letras.cpp -I$(INC)

$(BIN)/cantidad_letras:
	$(CXX) -o $(BIN)/cantidad_letras $(SRC)/cantidad_letras.cpp -I$(INC)

$(BIN)/testlista_palabras:
	$(CXX) -o $(BIN)/testlista_palabras $(SRC)/testlista_palabras.cpp -I$(INC)


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
