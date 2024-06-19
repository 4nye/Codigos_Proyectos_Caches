#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <ctime>

#define NOMBRE_ARCHIVO "clears.csv"
using namespace std;

int main(int argc, char *argv[]){
  
  unsigned t0, t1;
  char *addr, block[16];
  int nb=0, band=0, nd=0, a=0, f=0, mrk=-1, total=0, fd,porc=0;
  struct stat statbuf;
  
  t0=clock();
  fd = open(NOMBRE_ARCHIVO,O_RDWR); 
  fstat(fd, &statbuf);
 addr=  (char*)mmap(NULL,statbuf.st_size,PROT_READ,MAP_PRIVATE,fd,0);

while(nd<=statbuf.st_size){

          while(band!=1 && nb<17){
            //si se encuentra cambia el valor de la bandera y suma 1 a los aciertos
            if(block[nb]==addr[nd]){
              band=1;
              a++;
             }
            nb++;
         }
        //si por el contrario falla asigna el valor del dato correspondiente al valor de la cache y asigna el va;pr de; fallo
         if(band!=1&&addr[nd]!='"'&& addr[nd]!='\t' ){
            block[mrk%16]=addr[nd];
            mrk++;
            f++;
         }

         nd++;
         nb=0;
         band=0;
        
    }
     
    porc = (static_cast<double>(a) * 100)/nd ;
     cout<<"hubieron "<<a<<" aciertos"<<endl;
     cout<<"hubieron "<<f<<" fallos"<<endl;
     cout<<" con un porcentaje del "<<porc<<"%"<<endl;
     t1 = clock();
     double time = (double(t1-t0)/CLOCKS_PER_SEC);
     cout << "Execution Time: " << time << endl;
  return 0;
}

