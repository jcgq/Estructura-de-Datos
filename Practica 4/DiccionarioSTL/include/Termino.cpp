#include "Termino.h"

Termino::iterator Termino::begin(){
    return termino.second.begin();
}

Termino::const_iterator Termino::begin() const{
    return termino.second.begin();
}

Termino::iterator Termino::end(){
    return termino.second.end();
}

Termino::const_iterator Termino::end() const{
    return termino.second.end();
}

Termino::Termino(){
}

Termino::Termino(std::string _palabra, vector<std::string> _definiciones){
    termino.first=_palabra;
    termino.second=_definiciones;
}
//set<Termino> el set ordena, no sabe ordenar terminos (da error) hay que decirle como se ordena, sobrecargar operador de menor en termino

Termino::Termino(const Termino& original){
    termino.first=original.termino.first;
    if(original.termino.second.size()>0){
        termino.second.resize(original.termino.second.size());
        for(int i=0; i < original.termino.second.size(); i++){
            termino.second[i]=original.termino.second[i];
        }
    }
    //else definiciones=0;
    
}

std::string Termino::getPalabra() const{
    return termino.first;
}

vector<std::string> Termino::getDefiniciones() const{
    return termino.second;
}

int Termino::getNumeroDefiniciones() const{
    return termino.second.size();
}

void Termino::setPalabra(std::string _palabra){
    termino.first=_palabra;
}

void Termino::setDefinicion(std::string _definicion){
    termino.second.resize(termino.second.size()+1);
    termino.second[termino.second.size()-1]=_definicion;
}

std::string Termino::getDefinicionExacta(int i) const{
    return termino.second[i];
}

std::ostream& operator<< (std::ostream & flujo, const Termino &salida){
    Termino::const_iterator it;
    for(it = salida.begin(); it != salida.end(); it++){
        flujo << salida.getPalabra() << "-->" << (*it) << endl;
    }
    return flujo;
}

bool Termino::operator <(const Termino& _termino)const {
    bool menor=false;
    if(termino.first<_termino.termino.first){
        menor=true;
    }
    return menor;
}
























