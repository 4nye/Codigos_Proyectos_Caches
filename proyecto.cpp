#include <iostream>
#include <sstream>
#include <fstream>
#define NOMBRE_ARCHIVO "clears.csv"
using namespace std;

int main()
{
    ifstream archivo(NOMBRE_ARCHIVO);
    string linea, dato, id, tag, block[16];
    char delimitador = '\t';
    int nb=0, band=0, nd=0, a=0, f=0, mrk=-1, total=0, porc=0;
    // Leemos la primer línea para descartarla, pues es el encabezado
    getline(archivo, linea);
    // Leemos todas las líneas


    while (getline(archivo, linea)){
        // Convertir la cadena a un stream
        stringstream stream(linea); 
       
        
        // empleamos un bucle principal que controle la extraccion de los datos de la linea recojida  
      while(nd<2){
        // Extraer todos los valores requeridos de la linea que se encuentran separados por una tabulacion
        getline(stream, dato, delimitador);
         
         //evalua si se encuentra o no en la cache
         while(band!=1 && nb<17){
            //si se encuentra cambia el valor de la bandera y suma 1 a los aciertos
            if(block[nb]==dato){
              band=1;
              a++;
            }
            nb++;
         }

         //si por el contrario falla asigna el valor del dato correspondiente al valor de la cache y asigna el va;pr de; fallo
         if(band!=1){
           block[mrk%16]=dato;
           mrk++;
           f++;
         }
 
        nd++;
        nb=0;
        band=0;

        }
        nd=0;

      }
        total= a+f;
          porc=((a*100)/total);
        cout<<"hubieron "<<a<<" aciertos"<<endl;
         cout<<"hubieron "<<f<<" fallos"<<endl;
         cout<<" con un porcentaje del "<<porc<<"%"<<endl;
        // Imprimir
     archivo.close();
    }

  
