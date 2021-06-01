#include <cstdlib>
#include "Lista_de_palabras.h"
#include "Conjunto_de_letras.h"
#include "BolsaLetras.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    if (argc!=5){
      cout<<"Sintaxis: <lista_palabras> <letras> <Numero letras> <Modalidad Juego L/P>"<<endl;
      return 0;
    }

   ifstream f (argv[1]); //fichero lista_palabras
   ifstream fl (argv[2]); //fichero letras
   char argumento3=*argv[3];
   int NumeroVeces=argumento3-48;
   string respuesta;
   bool salir=false;
   
   
   cout << "Numero de veces: " << NumeroVeces << endl;
   
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
   
   BolsaLetras bolsa;
   bolsa.RellenarBolsa(l);
   
   vector<char> LetrasSacadas;
   
   
   while(!salir){
   
        cout << "Las letras son: ";
        for(int i=0; i<NumeroVeces; i++){
            int numero=rand()%bolsa.Size();
            cout << bolsa.SacarLetra(numero) << " ";
            LetrasSacadas.push_back(bolsa.SacarLetra(numero));
         }
        cout << endl;

        cout << "Dime tu respuesta: ";
        cin >> respuesta;
        

        if(*argv[4]=='L'){
            if(!lp.SolucionCorrecta(respuesta,LetrasSacadas)){
                cout << "Tu palabra no es válida" << endl;
                cout << "Mis Soluciones son:" << endl;
                lp.CalcularSolucionesL(LetrasSacadas, NumeroVeces,1);
            }
            else{
                cout << respuesta << " ";
                cout << "Puntuacion: " << respuesta.length() << endl << endl;
                
                cout << "Mis Soluciones son:" << endl;
                lp.CalcularSolucionesL(LetrasSacadas, NumeroVeces, respuesta.length());
            }
            
            
            char respuesta;
            cout << "¿Quieres volver a jugar? (s/n) ";
            cin >> respuesta;

            if(respuesta!='s')
                salir=true;
            else{
                vector<char>::iterator it;
                for(it=LetrasSacadas.end(); it!=LetrasSacadas.begin();it--)
                    LetrasSacadas.pop_back();
                
            } 
        } 
        else if(*argv[4]=='P'){
            int i=0;
            string palabramayorpuntuacion;
            vector<char>::iterator it;
            char letra;
            for(it=LetrasSacadas.begin(); it!=LetrasSacadas.end(); it++){
                letra=tolower(*it);
                palabramayorpuntuacion.push_back(letra);
                i++;
            }
            
            if(!lp.SolucionCorrecta(respuesta,LetrasSacadas)){
                cout << "Tu palabra no es válida" << endl;
                cout << "Mis Soluciones son:" << endl;
                lp.CalcularSolucionesP(l,LetrasSacadas, l.calcularPuntuacion(palabramayorpuntuacion),1);
            }
            else{
                cout << respuesta << " ";
                cout << "Puntuacion: " << l.calcularPuntuacion(respuesta) << endl << endl;
                
                cout << "Mis Soluciones son:" << endl;
                lp.CalcularSolucionesP(l,LetrasSacadas, l.calcularPuntuacion(palabramayorpuntuacion), l.calcularPuntuacion(respuesta));
            }
            
            char respuesta;
            cout << "¿Quieres volver a jugar? (s/n) ";
            cin >> respuesta;

            if(respuesta!='s')
                salir=true;
            else{
                vector<char>::iterator it;
                for(it=LetrasSacadas.end(); it!=LetrasSacadas.begin();it--)
                    LetrasSacadas.pop_back();
                
            } 
           
        }
        else
            cout << "Parámetro número 4 mal introducido: L/P" << endl;
    }
    
    return 0;
}

