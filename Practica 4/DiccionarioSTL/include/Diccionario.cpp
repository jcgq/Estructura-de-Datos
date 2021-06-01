#include "Diccionario.h"

Diccionario::iterator Diccionario::begin(){
    return diccionario.begin();
}

Diccionario::const_iterator Diccionario::begin() const{
    return diccionario.begin();
}

Diccionario::iterator Diccionario::end(){
    return diccionario.end();
}

Diccionario::const_iterator Diccionario::end() const{
    return diccionario.end();
}


Diccionario::Diccionario(){
}

Diccionario::Diccionario(set<Termino> _conj_definiciones){
    Diccionario::iterator it;
    for(it=_conj_definiciones.begin(); it!=_conj_definiciones.end(); it++)
        diccionario.insert(*it);
}


Diccionario::Diccionario(const Diccionario& original){   
    if(original.getNumeroTerminos()>0){
        set<Termino>::iterator it;
        for(it=original.begin(); it!=original.end(); it++)
            diccionario.insert(*it);
    }
}


void Diccionario::getDefiniciones(std::string palabra) const{
    Diccionario::iterator it;
    for(it=diccionario.begin(); it!=diccionario.end(); it++){
        if(palabra==(*it).getPalabra()){
            cout << *it << endl;
        }
    }
}

int Diccionario::getNumeroTerminos() const{
    return diccionario.size();
}

set<Termino> Diccionario::getConjDefiniciones() const{
    return diccionario;
}

void Diccionario::setTermino(Termino t){
    diccionario.insert(t);
}


void Diccionario::EliminarTermino(Termino t){
    Diccionario::iterator it;
    for(it=diccionario.begin(); it!=diccionario.end(); it++){
        if((*it).getPalabra()==t.getPalabra()){
            diccionario.erase(it);
        }
    }
}

Diccionario Diccionario::Intervalo(char inicio, char final){
    Diccionario subconjunto;
    inicio=tolower(inicio);
    final=tolower(final);
    Diccionario::iterator it;
    
    if((inicio<=final)&&(inicio>='a'&&inicio<='z')&&(final>='a'&&final<='z')){
       for(it=diccionario.begin(); it!=diccionario.end(); it++)
       {
        if((*it).getPalabra()[0]>=inicio && (*it).getPalabra()[0] <= final)
        {
            subconjunto.setTermino(*it);
        }
        
    }
    
    }
    else
        cout << "Error al introducir el intervalo" << endl;
    return subconjunto;
}
void Diccionario::Recuento(){
    double total=0.0, maximo=0.0, promedio=0.0;
    Diccionario::iterator it;
    
    
    for(it=diccionario.begin(); it!=diccionario.end(); it++){
        total=total+(*it).getNumeroDefiniciones();
    }

    
    for(it=diccionario.begin(); it!=diccionario.end(); it++){
        if(maximo<(*it).getNumeroDefiniciones())
            maximo=(*it).getNumeroDefiniciones();
    }
    
    promedio=total/this->getNumeroTerminos();
    cout << "Número total de definiciones = " << total << endl;
    cout << "Máximo de definiciones por término = " << maximo << endl;
    cout << "Promedio de definiciones por palabra = " << promedio << endl;
    
    
}
Diccionario Diccionario::FiltroClave(std::string clave){
    Diccionario *reducido=new Diccionario();
    Diccionario::iterator it;
    for(it=diccionario.begin(); it!=diccionario.end(); it++){
        Termino aux;
        
        for(int j=0; j<(*it).getNumeroDefiniciones(); j++){
            aux.setPalabra((*it).getPalabra());
            if((*it).getDefinicionExacta(j).find(clave) != string::npos){
                aux.setDefinicion((*it).getDefinicionExacta(j));
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


std::ostream& operator<< (std::ostream & os, const Diccionario & d){
    Diccionario::const_iterator it;
    for(it = d.begin(); it != d.end(); ++it){
        os << *it;
    }
    return os;
}












