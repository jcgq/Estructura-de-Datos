
#include <set>
#include <string>
#include <vector>
#include "Conjunto_de_letras.h"
using namespace std;

#ifndef LISTA_DE_PALABRAS_H
#define LISTA_DE_PALABRAS_H

class ListaPalabras{
    
    private:
        set<string> datos;
    public:
        
        /**
        @brief Construye un lista_palabras vacío.
        **/
        ListaPalabras();
        
        /**
         * @brief Devuelve la palabra almacenada en pos
         * @param pos
         * @return 
         */
        string getPalabra(int pos) const;
        
        /**
         * @brief Obtenemos el set
         * @return datos
         */
        set<string> getConjunto() const;
        
        /**
        @brief Devuelve el numero de palabras en el lista_palabras
        **/
        int size() const;
        
        /**
        @brief Obtiene todas las palabras en el lista_palabras de una longitud dada
        @param longitud la longitud de las palabras de salida
        @return un vector con las palabras de longitud especificada en el parámetro de entrada
        **/
        vector<string> palabras_longitud(int longitud);
        
        /**
         * @brief Obtiene todas las palabras en el lista_palabras de las puntuaciones en el rango [puntuacionmax,puntuacionmin)
         * @param puntuacion
         * @param conj
         * @return vector con las palabras de esa puntuacion
         */
        vector<string> palabras_puntuacion(int puntuacionmax,int puntuacionmin,ConjLetras conj);
 
        /**
        @brief Indica si una palabra está en el lista_palabras o no
        @param palabra la palabra que se quiere buscar
        @return true si la palabra esta en el lista_palabras. false en caso contrario
        **/
        bool Esta(string palabra);
        
        /**
         * @brief Calcula el porcentaje de veces que aparece una letra en la lista
         * @param frecuencias, un vector con las frecuencias asociadas a cada letra
         */
        void CalcularFrecuenciaLetras(double frecuencias[]);
        
        /**
         * @brief Este método comprueba que la solución dada es correcta para el conjunto de letras que pasamos como argumento
         * @param palabra
         * @param LetrasSacadas
         * @return correcto o incorrecto
         */
        bool SolucionCorrecta(string palabra,vector<char> LetrasSacadas);
        
        /**
         * @brief Algoritmo para calcular las mejores soluciones de una longitud superior a la longitudSolucion. Se devuelven hasta un máximo de 10 palabras de longitud superior a la solucion propuesta
         * Están ordenadas por su longitud
         * @param letrasSacadas
         * @param longitudMaxima
         * @param longitudSolucion
         */
        void CalcularSolucionesL(vector<char> letrasSacadas, int longitudMaxima, int longitudSolucion);
       
        
        /**
         * @brief Algoritmo para calcular las mejores soluciones de una puntuacion superior a la puntuacionSolucion. Se devuelven hasta un máximo de 10 palabras de puntuacion superior a la solucion propuesta
         * Están en orden alfabético.
         * @param l Conjunto de Letras necesario para calcular las puntuaciones de las palabras
         * @param letrasSacadas
         * @param puntuacionMaxima
         * @param puntuacionSolucion
         */
        void CalcularSolucionesP(ConjLetras l, vector<char> letrasSacadas, int puntuacionMaxima, int puntuacionSolucion);
        
        /**
        @brief Lee de un flujo de entrada un lista_palabras
        @param is flujo de entrada
        @param D el objeto donde se realiza la lectura.
        @return el flujo de entrada
        **/
        friend istream & operator>>(istream & is, ListaPalabras &D);
        
        /**
        @brief Escribe en un flujo de salida un lista_palabras
        @param os flujo de salida
        @param D el objeto lista_palabras que se escribe
        @return el flujo de salida
        **/
        friend ostream & operator<<(ostream & os, const ListaPalabras &D);
};
#include "Lista_de_palabras.cpp"
#endif /* LISTA_DE_PALABRAS_H */

