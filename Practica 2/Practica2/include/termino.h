

#include <string>
#ifndef TERMINO_H
#define TERMINO_H
#include "vector_dinamico.h"
class Termino{
private:
    std::string palabra;
    Vector_Dinamico<std::string> definiciones;
public: 
/**
 * @brief Constructor sin parámetros
 */
    Termino();
/**
 * @brief Constructor con parámetros. Nosostros ordenamos el diccionario de forma alfabética
 * @param _deiniciones: Conjunto de definiciones asociadas a la _palabra
 * @param _palabra: Nueva palabra
 */  
    Termino(std::string _palabra, Vector_Dinamico<std::string> _definiciones);
/**
 * @brief Constructor por copia
 * @pre Se necesita que el tamaño del original sea mayor que cero
 * @param original de forma constante: evitamos que sea modificado
 */
    Termino(const Termino &original);
/**
 * @brief Devuelve una palabra
 * @return Devuelve la palabra
 */  
    std::string getPalabra() const;
 /**
 * @brief Devuelve las definiciones asociadas a una palabra
 * @return Devuelve las definiciones 
 */ 
    Vector_Dinamico<std::string> getDefiniciones() const; 
 /**
 * @brief Devuelve el numer de definiciones asociadas a una palabra
 * @return Devuelve el número de definiciones
 */    
    int getNumeroDefiniciones() const;
/**
 * @brief Establece una nueva palabra
 * @param _palabra: Palabra nueva
 */   
    void setPalabra(std::string _palabra);
/**
 * @brief Establece una nueva definición
 * @param _definicion: Definición nueva
 * @pre Se necesita que el tamaño del original sea mayor que cero
 */    
    void setDefinicion(std::string _definicion);
 /**
 * @brief Devuelve la definición requerida
 * @param i definición exacta
 * @pre Se necesita que la i sea maypr que el tamaño de las definiciones. En caso de no cumplirse, esa definición se muestra vacía.
 */    
    std::string getDefinicionExacta(int i) const;  
};

std::ostream& operator<< (std::ostream &flujo,const  Termino &salida);

#endif /* TERMINO_H */

