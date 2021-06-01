#include "Lista_de_palabras.h"
#include "Conjunto_de_letras.h"
#include "BolsaLetras.h"
#include <string.h>
#include <cstdlib>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {

    if (argc!=4){
      cout<<"Sintaxis: <lista_palabras> <letras> <fichero salida>"<<endl;
      return 0;
   }

   ifstream f (argv[1]); //fichero lista_palabras
   ifstream fl (argv[2]); //fichero letras
   ofstream salida;
   salida.open(argv[3]);
    
   if (!f){
    cout<<"No puedo abrir el fichero  "<<argv[1]<<endl;
    return 0;
   }
   if (!fl){
    cout<<"No puedo abrir el fichero  "<<argv[2]<<endl;
    return 0;
   }
   
   ListaPalabras lp;
   f >> lp;
   
   ConjLetras l;
   fl>>l;
   
   double frecuencias[26];
   lp.CalcularFrecuenciaLetras(frecuencias);
   
   salida << "#Letra Cantidad" << endl;
   for(int i=0; i<26; i++){
       char letra=toupper(i+97);
       if(letra!='K' && letra!='W'){
            salida << letra;
            salida << "      " << frecuencias[i] << endl;  
        }
   }
   
   salida.close();
   
    
    return 0;
}

