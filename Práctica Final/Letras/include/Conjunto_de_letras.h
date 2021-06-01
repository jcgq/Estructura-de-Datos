


#include <set>
#include "Letra.h"

#ifndef CONJUNTO_DE_LETRAS_H
#define CONJUNTO_DE_LETRAS_H

using namespace std;

class ConjLetras{
    private:
        set<Letra> conjunto;
    public:   
        /**
         * @brief Constructor sin parametros 
         */
        ConjLetras();
        
        /**
         * @brief Constructor con parametros
         * @param _conjunto
         */
        ConjLetras(set<Letra> _conjunto);
        
        /**
         * @brief Inserta la letra en el conjunto
         * @param letra
         */
        void setLetraConjunto(Letra letra);
        
        /**
         * @brief Obtenemos la letra almacenada en la posicion pos
         * @param pos
         * @return 
         */
        Letra getLetraConjunto(int pos) const;
        
        /**
         * @brief devuelve el set
         * @return conjunto
         */
        set<Letra> getConjLetras() const;

        /**
         * @brief Devuelve el tamanio de un conjunto
         * @return 
         */
        int tamanio() const;
        
        /**
         * @brief calcula la puntuacion 
         * @param palabra
         * @return puntuacion
         */
        int calcularPuntuacion(string palabra);
};
 std::istream& operator>> (std::istream &flujo, ConjLetras &leido);

#include "Conjunto_de_letras.cpp"
#endif /* CONJUNTO_DE_LETRAS_H */

