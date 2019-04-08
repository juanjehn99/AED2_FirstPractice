#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string.h>

using namespace std;

struct Solucion{
    int NumConcatenaciones;
    int Indice;
    string A, B;
    int k, p, q;
};


Solucion SolucionDirecta(int p, int q, string A, string B){
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
        while (contador < (int)(B.size())) {
            if (A[i]==B[j]) {
                if (contador==(int)(B.size()-1)) {
                    repeticion++;
                    i++;
                    j = 0;
                    contador = 0;
                    if (anterior == false) {
                        indice = (i+1) - B.size();
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
                contador = B.size();
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
    solucion.p = p;
    solucion.q = q;
    solucion.A = A;
    solucion.B = B;

    return solucion;
}

int Dividir(int p, int q){
  return round(((q-p)/2)+p);
}

bool Pequeno(int p, int q, string B){
  if ((q-p)/2 < (int) B.size()){
    return true;
  }
  else return false;
}

Solucion Combinar(Solucion solucion1, Solucion solucion2)
{
    Solucion solucionFinal;
    string NuevoString;

    for (int w = 0; w < ((int)(solucion1.k + solucion1.B.size() - 2)); w++)
    {
           NuevoString[w] = solucion1.A[w];
    }

    Solucion NuevaSolucion = SolucionDirecta(solucion1.p, solucion1.k + solucion1.B.size() - 2, NuevoString, solucion1.B);

    if (NuevaSolucion.NumConcatenaciones >= solucion2.NumConcatenaciones)
    {
        solucionFinal.NumConcatenaciones = NuevaSolucion.NumConcatenaciones;
        solucionFinal.Indice = NuevaSolucion.Indice;
        return solucionFinal;
    }
    else
    {
        solucionFinal.NumConcatenaciones = solucion2.NumConcatenaciones;
        solucionFinal.Indice = solucion2.Indice;
        return solucionFinal;
    }
}

 Solucion DivideVenceras(int p, int q, string A, string B){
  int k;
  Solucion solucion;
  if (Pequeno(p, q, B)){
      solucion = SolucionDirecta(p, q, A, B);
      return solucion;
  }
  else {
    k = Dividir(p, q);
    solucion.k = k;
    solucion = Combinar(DivideVenceras(p, k-1, A, B), DivideVenceras(k, q, A, B));
    return solucion;
  }
}

/*PalabrasGenerador GeneradorDePalabras(){
  PalabrasGenerador PalabraGenerada;
    int tamanoN;
    int tamanoM;
    cout << "Introduce el tamaño de N: ";
    cin >> tamanoN;
    cout << "Introduce el tamaño de M: ";
    cin >> tamanoM;

    char alfabeto[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

    for (int j = 0; j < tamanoN; j++){
        int numLetra = (rand() % 25);
        PalabraGenerada.cadenaA[j] = alfabeto[numLetra];
        cout << PalabraGenerada.cadenaA[j];
    }
    cout << endl;
    for (int k = 0; k < tamanoM; k++){
        int numLetra = (rand() % 25);
        PalabraGenerada.cadenaB[k] = alfabeto[numLetra];
        cout << PalabraGenerada.cadenaA[k];
    }
    cout << endl;
  return PalabraGenerada;
}*/

int main(int argc, char *argv[]){
    //PalabrasGenerador PalabraGenerada = GeneradorDePalabras();
    int tamanoN, tamanoM;
    string A, B;

    cout << "Introduce el tamaño de N: ";
    cin >> tamanoN;
    cout << "Introduce el tamaño de M: ";
    cin >> tamanoM;
    cout << "Introduce A: ";
    cin >> A;
    cout << "Introduce B: ";
    cin >> B;

    int p = 0;
   // int q = (int) sizeof(PalabraGenerada.cadenaA);
   // int base = (int) sizeof(PalabraGenerada.cadenaB);
    int q = tamanoN;

    Solucion SolucionProblema = DivideVenceras(p, q, A, B);
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
