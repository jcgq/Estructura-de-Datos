
#include<list>
#include "Conjunto_de_letras.h"


#ifndef BOLSALETRAS_H
#define BOLSALETRAS_H

class BolsaLetras{
    private:
       list<char> bolsa;
    public:
        /**
         * @brief Constructor por defecto
         */
        BolsaLetras();
        /**
         * @brief Constructor con parametros
         * @param _bolsa
         */
        BolsaLetras(list<char> _bolsa);
        /**
         * @brief Rellena la bolsa con las letras
         * @param _conjunto
         */
        void RellenarBolsa(ConjLetras _conjunto);  
        /**
         * @brief Obtiene el tamaño de la bolsa
         * @return tamaño
         */
        int Size() const;
        /**
         * @brief Saca la letra de esa posicion
         * @param pos
         * @return letra 
         */
        char SacarLetra(int pos) const;
        
};
#include "BolsaLetras.cpp"
#endif /* BOLSALETRAS_H */

