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

class PalabrasGenerador(){
  string cadenaA;
  string cadenaB;
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

PalabrasGenerador GeneradorDePalabras(){
  PalabrasGenerador PalabraGenerada;
  string CadenaLarga;
  string CadenaCorta;
  int numRandLarga;
  int numRandCorta;
  char Alfabeto[26];

  for (int i=0; i<26; i++){
    alfabeto[i] = a;
    a++;
  }

  numRandLarga = rand();
  numRandCorta = (rand() % 10) + 1;

  for (int j = 0; j < numRandLarga; j++){
    
  }

  
  
}

int main(int argc, char *argv[]){
  GeneradorDePalabras
}
