


#ifndef LETRA_H
#define LETRA_H

class Letra{
private:
    char caracter;
    int cantidad;
    int puntuacion;
public:
    /**
     * @brief Constructor sin parámetros
     */
    Letra();
    /**
     * @brief Devuelve la letra
     * @return letra
     */
    char getLetra() const;
    /**
     * @brief Devuelve la cantidad
     * @return cantidad
     */
    int getCantidad() const;
    /**
     * @brief Devuelve la puntuación
     * @return puntuacion
     */
    int getPuntuacion() const;
    /**
     * @brief Establece la letra
     */
    void setLetra(char _caracter);
    /**
     * @brief Establece la cantidad
     */
    void setCantidad(int _cantidad);
    /**
     * @brief Establece la puntuacion
     */
    void setPuntuacion(int _puntuacion);
    /**
     *@brief Sobrecarga del operador < entre dos letras
     */
    bool operator<(const Letra& _letra) const;
};



#include "Letra.cpp"
#endif /* LETRA_H */

