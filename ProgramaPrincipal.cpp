#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

class Solucion{
  public:
    int NumConcatenaciones;
    int Indice;
};

class PalabrasGenerador{
  public:
    char cadenaA[];
    char cadenaB[];
};

Solucion ResolucionDirecta(int p, int q, int base, char A[], char B[]){
  Solucion solucion;
    int i, j;
    bool anterior;
    int contador, repeticion, inicio, maxi, indice, indicemax;

    contador = 0;
    repeticion = 0;
    maxi = 0;
    anterior = false;
    i = 0;
    indicemax = 0;

    while (i < (q-p)) {
        j = 0;
        contador = 0;
        while ((A[i]!=B[j]) && (i < (q-p))) {
            i++;
            repeticion = 0;
            anterior = false;
        }
        i++;
        j++;
        contador++;
        while (contador<base) {
            if (A[i]==B[j]) {
                if (contador==base-1) {
                    repeticion++;
                    i++;
                    j = 0;
                    contador = 0;
                    if (anterior == false) {
                        indice = (i+1) - base;
                    }
                    anterior = true;
                }
                else {
                    contador++;
                    j++;
                    i++;
                }
            }
            else {
                contador = base;
            }
        }
        if (repeticion > maxi) {
            maxi = repeticion;
            repeticion = 0;
            indicemax = indice;
        }
    }
    inicio = indicemax;
    solucion.NumConcatenaciones = maxi;
    solucion.Indice = inicio;

    return solucion;
}

Solucion Combinar(){
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

 Solucion DivideVenceras(int p, int q, int base, char A[], char B[]){
  int k;
  Solucion solucion;
  if (Pequeno(p, q, base)){
      solucion = ResolucionDirecta(p, q, base, A, B);
  }
  else {
    k = Dividir(p, q);
    solucion = Combinar(DivideVenceras(p, k-1, base, A, B), DivideVenceras(k, q, base, A, B));
  }
}

PalabrasGenerador GeneradorDePalabras(){
  PalabrasGenerador PalabraGenerada;
  int numRandLarga;
  int numRandCorta;
  char alfabeto[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

  numRandLarga = rand();
  numRandCorta = (rand() % 10) + 1;

  for (int j = 0; j < numRandLarga; j++){
    int numLetra = (rand() % 25);
    PalabraGenerada.cadenaA[j] = alfabeto[numLetra];
  }

  for (int k = 0; k < numRandCorta; k++){
    int numLetra = (rand() % 25);
    PalabraGenerada.cadenaB[k] = alfabeto[numLetra];
  }

  return PalabraGenerada;
}

int main(int argc, char *argv[]){
    PalabrasGenerador PalabraGenerada = GeneradorDePalabras();
    int p = 0;
    int q = sizeof(PalabraGenerada.cadenaA);
    int base = sizeof(PalabraGenerada.cadenaB);
    Solucion SolucionProblema = DivideVenceras(p, q, base, PalabraGenerada.cadenaA , PalabraGenerada.cadenaB);
    cout << "El mayor num de concatenaciones de B en A es: " << SolucionProblema.NumConcatenaciones << endl;
    if (SolucionProblema.NumConcatenaciones == 0)
    {
        cout << "No hay indice posible" << endl;
    }
    else
    {
        cout << "El valor de inicio de la concatenacion mas grande es: " << SolucionProblema.Indice << endl;
    }
}
