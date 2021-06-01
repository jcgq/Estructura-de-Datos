#include "vector_dinamico.h"
#include <iostream>
#include <cassert>
using namespace std;

Vector_dinamico::Vector_dinamico(int _n){
    assert(_n>=0);
    if(_n>0){
        datos= new std::string[_n];
    }
    n=_n;
}

Vector_dinamico::Vector_dinamico(const Vector_dinamico& original){
    n=original.n;
    
    if(n>0){
        datos=new std::string[n];
        for(int i=0; i<n; i++)
            datos[i]=original.datos[i];
    }
    else 
        n=0;
}
Vector_dinamico::~Vector_dinamico(){
    if (n>0)
        delete []datos;
}

int Vector_dinamico::size() const{
    return n;
}

void Vector_dinamico::resize(int _n){
    assert(_n>=0);
    if (_n != n){
        if(_n!=0){
            std::string* nuevos_datos = new std::string[_n];
            if(n>0){
                int minimo = _n<n?_n:n;
                for(int i=0; i<minimo; i++)
                    nuevos_datos[i]=datos[i];
                delete [] datos;
            }
            n=_n;
            datos=nuevos_datos;
        }
        else{  //si n==0
            if(n>0){
                delete[] datos;
            }
            datos=0;
            n=0;
        }
    }
}

std::string & Vector_dinamico::operator [](const int i) const{
    assert(i>=0 && i<n);
    return datos[i];
}

Vector_dinamico & Vector_dinamico::operator =(const Vector_dinamico& original){
    if(this != &original)
        if(n>0){
            delete[] datos;
        }
        n=original.n;
        if (n>0){
            datos=new std::string[n];
            for(int i=0; i<n; i++)
                datos[i]=original.datos[i];
        }
        return *this;       
}