
using namespace std;
#include <fstream>
#include <iostream>
#include "Lista_de_palabras.h"
#include "Conjunto_de_letras.h"

ListaPalabras::ListaPalabras(){
   
}

int ListaPalabras::size() const{
    return datos.size();
}

bool ListaPalabras::Esta(string palabra){
    bool resul=false,salir=false;
    
    set<string>::iterator it=datos.begin();
    for(it; it!=datos.end() && !resul; it++){
        if(palabra==*it){
            resul=true;
        }
    }
    return resul;
}

string ListaPalabras::getPalabra(int pos) const{
    set<string>::iterator it=datos.begin();
    for(int i=0; i<pos; i++){
        it++;
    }
    return *it;
}

set<string> ListaPalabras::getConjunto() const{
    return datos;
}

vector<string> ListaPalabras::palabras_longitud(int longitud){
    vector<string> final;
    
    set<string>::const_iterator it=datos.begin();
    for(it; it!=datos.end(); it++){
        if((*it).length()==longitud){
            final.push_back((*it));
        }
    }
    return final;
}


istream & operator>>(istream & is, ListaPalabras &D){
    string dato;
    while(!is.eof()){
        getline(is,dato);
        
        D.datos.insert(dato);
    }
    return is;
}

ostream & operator<<(ostream & os, const ListaPalabras &D){
    
    set<string>::const_iterator it=D.datos.begin();
    
    for(it; it!=D.datos.end(); it++){
        os << (*it) << endl;
    }
    return os;
}

void ListaPalabras::CalcularFrecuenciaLetras(double frecuencias[]){
   
    set<string>::iterator it=datos.begin();
    bool entrar;
    for(int i=0; i<26; i++){
        frecuencias[i]=0;
    }
    
    for(it; it!=datos.end(); it++){
        entrar=true;
        for(int i=0; i<(*it).length(); i++){
            if((*it).operator [](i)=='k' || (*it).operator [](i)=='w')
                entrar=false;
        }
        if(entrar){
            for(int i=0; i<(*it).length(); i++){
                int letra=(*it).operator [](i);
                frecuencias[letra-97]++;
            }
        }
    }
    
    double TotalLetras=0;
    for(int i=0; i<26; i++){
       TotalLetras+=frecuencias[i];
    }
    
    for(int i=0; i<26; i++){
       frecuencias[i]=(frecuencias[i]*100)/TotalLetras;
    }
    
}

bool ListaPalabras::SolucionCorrecta(string palabra, vector<char> LetrasSacadas){
    bool resul=false;
    bool esta;
    bool palabracorrecta=true;
    vector<char>::iterator itl;
    vector<char> letraEliminada;
    if(Esta(palabra)){
        
        for(int j=0; j<palabra.length(); j++){
            esta=false;
            for(itl=LetrasSacadas.begin(); itl!=LetrasSacadas.end() && !esta; itl++){
                if(palabra[j]==tolower((*itl))){
                    esta=true;
                    letraEliminada.push_back(*itl);
                    LetrasSacadas.erase(itl);
                }
            }
            if(!esta)
                palabracorrecta=false;
        }
        if(palabracorrecta)
            resul=true;
        else
            resul=false;
        
    }
    else
        resul=false;
     
    
    return resul;
}




void ListaPalabras::CalcularSolucionesL(vector<char> letrasSacadas, int longitudMaxima, int longitudSolucion){
    
    vector<char>::iterator itl;
    vector<char>::iterator ite;
    vector<string>::iterator it;
    bool palabracorrecta=true;
    bool esta=false;
    vector<char> letraEliminada;
    int contadorSoluciones=0;
    pair<string,int> Mejor;
    
    Mejor.first="Tu solución es la mejor. Enhorabuena!";
    Mejor.second=longitudSolucion;
    
        for(int i=longitudMaxima; i>longitudSolucion && contadorSoluciones<10; i--){
            vector<string> soluciones=palabras_longitud(i);
            for(it=soluciones.begin(); it!=soluciones.end() && contadorSoluciones<10; it++){
                palabracorrecta=true;
                if(letrasSacadas.size()<longitudMaxima){
                    for(ite=letraEliminada.end(); ite!=letraEliminada.begin() && contadorSoluciones<10;ite--){
                        letrasSacadas.push_back(letraEliminada.back());
                        letraEliminada.pop_back();
                    }
                }
                    for(int j=0; j<(*it).length()&& contadorSoluciones<10; j++){
                        esta=false;
                       for(itl=letrasSacadas.begin(); itl!=letrasSacadas.end() && !esta; itl++){
                           if((*it).operator [](j)==tolower((*itl))){
                               esta=true;
                               letraEliminada.push_back(*itl);
                               letrasSacadas.erase(itl);  
                           }
                       }
                       if(!esta)
                           palabracorrecta=false;
                    }
                if(palabracorrecta){
                    cout << (*it) << "  " << "Puntuacion: " << i << endl;
                    if(i>Mejor.second){
                        Mejor.first=(*it);
                        Mejor.second=i;
                    }
                        
                    contadorSoluciones++;
                }            
            }
           
        }
    cout << "Mejor Solucion: " << Mejor.first << endl;    
}


vector<string> ListaPalabras::palabras_puntuacion(int puntuacionmax,int puntuacionmin,ConjLetras conj){
    
    vector<string> final;
    
    set<string>::iterator it=datos.begin();
    for(it; it!=datos.end(); it++){
        if(conj.calcularPuntuacion((*it))<=puntuacionmax && conj.calcularPuntuacion((*it))>puntuacionmin){
            final.push_back((*it));
        }
    }
    return final;
    
}

void ListaPalabras::CalcularSolucionesP(ConjLetras l,vector<char> letrasSacadas, int puntuacionMaxima, int puntuacionSolucion){
    
    int longitudMaxima=letrasSacadas.size();
    vector<char>::iterator itl;
    vector<char>::iterator ite;
    vector<string>::iterator it;
    bool palabracorrecta=true;
    bool esta=false;
    vector<char> letraEliminada;
    int contadorSoluciones=0;
    pair<string,int> Mejor;
    
    Mejor.first="Tu solución es la mejor. Enhorabuena!";
    Mejor.second=puntuacionSolucion;
    
            vector<string> soluciones=palabras_puntuacion(puntuacionMaxima,puntuacionSolucion,l);
            
                for(it=soluciones.begin(); it!=soluciones.end() && contadorSoluciones<10; it++){
                    palabracorrecta=true;
                    if(letrasSacadas.size()<longitudMaxima){
                        for(ite=letraEliminada.end(); ite!=letraEliminada.begin() && contadorSoluciones<10;ite--){
                            letrasSacadas.push_back(letraEliminada.back());
                            letraEliminada.pop_back();
                        }
                    }
                        for(int j=0; j<(*it).length()&& contadorSoluciones<10; j++){
                            esta=false;
                           for(itl=letrasSacadas.begin(); itl!=letrasSacadas.end() && !esta; itl++){
                               if((*it).operator [](j)==tolower((*itl))){
                                   esta=true;
                                   letraEliminada.push_back(*itl);
                                   letrasSacadas.erase(itl);
                               }
                           }
                           if(!esta)
                               palabracorrecta=false;
                        }
                    if(palabracorrecta){
                        cout << (*it) << "  " << "Puntuacion: " <<l.calcularPuntuacion((*it))  << endl;
                        if(l.calcularPuntuacion((*it))>Mejor.second){
                            Mejor.first=(*it);
                            Mejor.second=l.calcularPuntuacion((*it));
                        }

                        contadorSoluciones++;
                    }
                }

    cout << "Mejor Solucion: " << Mejor.first << endl;   
}