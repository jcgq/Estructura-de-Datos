#include "Letra.h"
#include <iostream>

Letra::Letra(){
    caracter=NULL;
    puntuacion=0;
    cantidad=0;
}

int Letra::getCantidad() const{
    return cantidad;
}
int Letra::getPuntuacion() const{ 
    return puntuacion;
} 

char Letra::getLetra() const{
    return caracter;
}

void Letra::setCantidad(int _cantidad){
    if(_cantidad>0)
        cantidad=_cantidad;
}

void Letra::setPuntuacion(int _puntuacion){
    if(_puntuacion>0)
        puntuacion=_puntuacion;
}

void Letra::setLetra(char _caracter){
    if(_caracter!=NULL)
        caracter=_caracter;
}

bool Letra::operator<(const Letra& _letra)const {
    bool menor=false;
    if(caracter<_letra.getLetra()){
        menor=true;
    }
    return menor;
}