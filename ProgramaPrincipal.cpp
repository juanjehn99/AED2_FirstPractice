#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

class Solucion{
  int NumConcatenaciones;
  int Indice;
}

Solucion ResolucionDirecta(){
  
}

int Dividir(int p, int q){
  return round((q-p)/2);
}

bool Pequeno(int p, int q, int base){
  if ((q - p) <= base){
    return true;
  }
  else return false;
}

void DivideVenceras(int p, int q, int base){
  int k;
  Solucion solucion;
  if Pequeno(p, q, base){
       solucion = ResolucionDirecta();
  }
  else {
    k = Dividir(p, q, base);
    solucion = Combinar(DivideVenceras(p, k-1, base), DivideVenceras(k, q));
  }
}

int main(int argc, char *argv[]){
  
}
