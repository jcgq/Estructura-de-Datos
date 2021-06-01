#include "Termino.h"
#include <set>

#ifndef DICCIONARIO_H
#define DICCIONARIO_H

class Diccionario{
    private:
        set<Termino> diccionario;
    public: 
        typedef set<Termino>::iterator iterator;
        typedef set<Termino>::const_iterator const_iterator;
        Diccionario::iterator begin();
        Diccionario::const_iterator begin() const;
        Diccionario::iterator end();
        Diccionario::const_iterator end() const;
/**
 * @brief Constructor sin parámetros
 */
    Diccionario();
/**
 * @brief Constructor con parámetros. Nosostros ordenamos el diccionario de forma alfabética
 * @param _conj_definiciones: un conjunto de definiciones
 */    
    Diccionario( set<Termino>_conj_definiciones);
/**
 * @brief Constructor por copia
 * @pre Se necesita que el tamaño del original sea mayor que cero
 * @param original de forma constante: evitamos que sea modificado
 */
    Diccionario(const Diccionario &original);
 /**
 * @brief Devuelve las definiciones asociadas a una palabra
 * @param t: Término
 * @pre Para añadir las definiciones se necesitan que el término dado esté en el Diccionario
 * si no, no se puede añadir ninguna definición
 * @return Devuelve un vector dinámico con las definiciones
 */   
    void getDefiniciones(std::string palabra)const ;  
/**
 * @brief Devuelve las definiciones del diccionario en un vector
 * @return Devuelve las definiciones del diccionario
 */
    set<Termino> getConjDefiniciones()const ;
 /**
 * @brief Devuelve el número de términos del Diccionario
 * @return Devuelve el flujo de salida
 */
    int getNumeroTerminos() const ;
/**
 * @brief Establece un nuevo término (Palabra + definición)
 * @param t: Término nuevo
 */   
    void setTermino(Termino t);
/**
 * @brief Elimina del diccionario el término que se incluye como parámetro
 * @pre Se necesita que el termino a eliminar se encuentre dentro del Diccionario
 * @param t: Término que se quiere eliminar
 */    
    void EliminarTermino(Termino t);
/**
 * @brief Devuelve un diccionario que incluye sólo los terminos que se envuentran entre las letras dadas
 * @param inicio: Primera letra del nuevo diccionario
 * @param final: Última letra del nuevo dicionario 
 * @pre Se necesitan dos cosas:
 * Que la letra inicial vaya antes que la final, No existe un diccionario de la r a la d
 * Que haya una palabra con inicio y con final y que sea una letra de la A a la Z
 * @return Devuelve el nuevo Diccionario
 */
    Diccionario Intervalo(char inicio, char final);
/**
 * @brief Muestra por pantalla: Número total de definiciones, Promedio de definiciones por palabra y el máximo número de definiciones de una palabra
 */   
    void Recuento();
/**
 * @brief Crea un diccionario con los términos que contengan en su definicion la palabra clave, muestra solo las definiciones que CONTIENEN esa palabra
 * @param clave
 * @return Diccionario reducido
 */
   Diccionario FiltroClave(std::string clave);
};

std::istream& operator>> (std::istream &flujo, Diccionario &leido);
std::ostream& operator<< (std::ostream & os, const Diccionario & d);


#include "Diccionario.cpp"
#endif /* DICCIONARIO_H */

