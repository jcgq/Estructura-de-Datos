#include "vector_dinamico.h"
#include "diccionario.h"
#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

Diccionario::Diccionario(){
    conj_definiciones=0;
}

Diccionario::Diccionario(Vector_Dinamico<Termino> _conj_definiciones){
    conj_definiciones=_conj_definiciones;
    Ordenar();
    
    
}

Diccionario::Diccionario(const Diccionario& original){
    if(original.getNumeroTerminos()>0)
    {
        conj_definiciones.resize(original.conj_definiciones.size());
        for(int i=0; i<original.conj_definiciones.size(); i++)
        {
            conj_definiciones[i]=original.conj_definiciones[i];
        }
    }
    Ordenar();
}

int Diccionario::getNumeroTerminos() const{
    return conj_definiciones.size();
}

void Diccionario::setTermino(Termino t){
    conj_definiciones.resize(conj_definiciones.size()+1);
    conj_definiciones[conj_definiciones.size()-1]=t;
    Ordenar();
}

Vector_Dinamico<Termino> Diccionario::getConjDefiniciones()const {
    return conj_definiciones;
}

void Diccionario::getDefiniciones(std::string palabra)const {
    for(int i=0; i<conj_definiciones.size(); i++)
    {
        if(palabra==conj_definiciones[i].getPalabra())
        {
            cout << conj_definiciones[i];
        }
    }
}

void Diccionario::EliminarTermino(Termino t){
    for(int i=0; i<conj_definiciones.size(); i++)
    {
        if(t.getPalabra()==conj_definiciones[i].getPalabra())
        {
            for(int j=i; j<conj_definiciones.size()-1; j++){
                Termino aux;
                aux=conj_definiciones[j];
                conj_definiciones[j]=conj_definiciones[j+1];
                conj_definiciones[j+1]=aux;
            }
        }
        conj_definiciones.resize(conj_definiciones.size()-1);
    }
}



void Diccionario::Ordenar(){
    Termino aux;
    for(int i=0; i< getNumeroTerminos()-1; i++)
    {
        for(int j=0; j< getNumeroTerminos()-1; j++)
        {
            if(conj_definiciones[j].getPalabra() > conj_definiciones[j+1].getPalabra()){
                aux=conj_definiciones[j];
                conj_definiciones[j]=conj_definiciones[j+1];
                conj_definiciones[j+1]=aux;
            }
        }
        
    }
}


Diccionario Diccionario::Intervalo(char inicio, char final){
    Diccionario subconjunto;
    inicio=tolower(inicio);
    final=tolower(final);
    
    if((inicio<=final)&&(inicio>='a'&&inicio<='z')&&(final>='a'&&final<='z')){
       for(int i=0; i<this->getNumeroTerminos(); i++)
       {
        if(conj_definiciones[i].getPalabra()[0]>=inicio && conj_definiciones[i].getPalabra()[0] <= final)
        {
            subconjunto.setTermino(conj_definiciones[i]);
        }
        
    }
    
    }
    else
        cout << "Error al introducir el intervalo" << endl;
    return subconjunto; 
}


void Diccionario::Recuento(){
    double total=0.0, maximo=0.0, promedio=0.0;
    
    for(int i=0; i<getNumeroTerminos(); i++){
        total=total+conj_definiciones[i].getNumeroDefiniciones();
    }
    
    for(int i=0; i<getNumeroTerminos(); i++){
        if(maximo<conj_definiciones[i].getNumeroDefiniciones())
            maximo=conj_definiciones[i].getNumeroDefiniciones();
    }
    
    promedio=total/this->getNumeroTerminos();
    cout << "Número total de definiciones = " << total << endl;
    cout << "Máximo de definiciones por término = " << maximo << endl;
    cout << "Promedio de definiciones por palabra = " << promedio << endl;
    
}
   
Diccionario Diccionario::FiltroClave(std::string clave){
    Diccionario *reducido=new Diccionario();
    
    for(int i=0; i<conj_definiciones.size(); i++){
        Termino aux;
        
        for(int j=0; j<conj_definiciones[i].getNumeroDefiniciones(); j++){
            aux.setPalabra(conj_definiciones[i].getPalabra());
            if(conj_definiciones[i].getDefinicionExacta(j).find(clave) != string::npos){
                aux.setDefinicion(conj_definiciones[i].getDefinicionExacta(j));
            }
            
        }   
        if(aux.getNumeroDefiniciones()>0)
                reducido->setTermino(aux);
    }

  return (*reducido);
}  

std::istream& operator>> (std::istream &flujo, Diccionario &leido){
    std::string palabra="";
    std::string definicion="";
    getline(flujo,palabra, ';');
    
    while(!flujo.eof()){
        Termino aux;
        
        getline(flujo,definicion);
        aux.setPalabra(palabra);
        aux.setDefinicion(definicion);
        
        getline(flujo,palabra,';');
        
        while(palabra==aux.getPalabra() && !flujo.eof()){
            getline(flujo,definicion);
            aux.setDefinicion(definicion);
            getline(flujo,palabra,';');
        }
        
        leido.setTermino(aux);
    }
    
    
    return flujo;
    
}

std::ostream& operator<< (std::ostream &flujo,const  Diccionario &leido){
    for(int i=0; i<leido.getNumeroTerminos(); i++){
        flujo << leido.getConjDefiniciones()[i] << endl; 
    }
    return flujo;
}













