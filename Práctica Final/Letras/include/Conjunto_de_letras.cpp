#include"Conjunto_de_letras.h"
#include <string.h>

ConjLetras::ConjLetras(){
  
}

ConjLetras::ConjLetras(set<Letra> _conjunto){
}

void ConjLetras::setLetraConjunto(Letra letra){
    conjunto.insert(letra);
}

Letra ConjLetras::getLetraConjunto(int pos) const{
    set<Letra>::const_iterator it=conjunto.begin();
    for(int i=0; i<pos; i++){
        it++;
    }
    return (*it);
}

set<Letra> ConjLetras::getConjLetras() const{
    return conjunto;
}

int ConjLetras::tamanio() const{
    return conjunto.size();
}

std::istream& operator>> (std::istream &flujo, ConjLetras &leido){
    std::string primeraFrase; 
    char car;
    int punt, cant;
    bool salir =false;
    
    getline(flujo, primeraFrase);
    
    while(!flujo.eof() && !salir){
        Letra aux;
        
        flujo >> car;
        flujo >> cant;
        flujo >> punt;
        
        aux.setLetra(car);
        aux.setCantidad(cant);
        aux.setPuntuacion(punt);
        
        leido.setLetraConjunto(aux);
      
    }
    return flujo;
}


int ConjLetras::calcularPuntuacion(string palabra){
    int puntuacion=0;
    set<Letra>::iterator it;
    for(int i=0; i<palabra.length(); i++){
        for(it=conjunto.begin(); it!=conjunto.end(); it++){
            if(tolower((*it).getLetra())==palabra[i])
                puntuacion+=(*it).getPuntuacion();
        }
    }
    
    return puntuacion;
}
