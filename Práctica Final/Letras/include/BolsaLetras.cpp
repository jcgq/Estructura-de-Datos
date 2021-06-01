#include"BolsaLetras.h"

BolsaLetras::BolsaLetras(){
}

BolsaLetras::BolsaLetras(list<char> _bolsa){
   
}

void BolsaLetras::RellenarBolsa(ConjLetras _conjunto){
    
    for(int i=0; i<_conjunto.tamanio(); i++){
        for(int j=0; j< _conjunto.getLetraConjunto(i).getCantidad(); j++){
            bolsa.push_back( _conjunto.getLetraConjunto(i).getLetra());
        }
    }
}

int BolsaLetras::Size() const{
    return bolsa.size();
}

char BolsaLetras::SacarLetra(int pos) const{
    
    list<char>::const_iterator it=bolsa.begin();
    for(int i=0; i<pos; i++){
        it++;
    }
    
    return (*it);
}
