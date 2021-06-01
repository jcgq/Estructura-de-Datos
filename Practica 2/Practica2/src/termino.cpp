#include "termino.h"
#include <iostream>
#include <cassert>
using namespace std;

Termino::Termino(){
    palabra="Unknown";
    definiciones=0;
}

Termino::Termino(std::string _palabra, Vector_Dinamico<std::string> _definiciones){
    palabra=_palabra;
    definiciones.operator =(_definiciones);
}

Termino::Termino(const Termino& original){
    this->palabra=original.palabra;
    if(original.definiciones.size()>0){
        definiciones.resize(original.definiciones.size());
        for(int i=0; i<original.definiciones.size(); i++ )
            definiciones[i]=original.definiciones[i];
    }
    else
        definiciones=0;
}

std::string Termino::getPalabra()const{
    return palabra;
}

Vector_Dinamico<std::string> Termino::getDefiniciones() const{
    return definiciones;
}

int Termino::getNumeroDefiniciones() const{
    return definiciones.size();
}

void Termino::setPalabra(std::string _palabra){
    palabra=_palabra;
}

void Termino::setDefinicion(std::string _definicion){
    definiciones.resize(definiciones.size()+1);
    definiciones.operator [](definiciones.size()-1)=_definicion;
}

std::string Termino::getDefinicionExacta(int i) const{
    std::string definicionExacta="";
    if(i< definiciones.size())
        definicionExacta=definiciones[i];
    return definicionExacta;
}



std::ostream& operator<< (std::ostream &flujo,const  Termino &salida){
    
    
    for(int i=0; i<salida.getNumeroDefiniciones(); i++)
    {
        flujo << salida.getPalabra()<<";";
        flujo<<salida.getDefinicionExacta(i) << endl;
    }
    return flujo;
}
