#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <chrono>

using namespace std;

struct Solucion{
    int NumConcatenaciones;
    int Indice;
    string A, B;
    int k, p, q;
};

int Dividir(int p, int q){
  return (round((p+q)/2))+1;
}

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

bool Pequeno(int p, int q, string B){
    if ((((q)-p)/2) < (int) B.size()){
        return true;
    }
    else return false;
}

Solucion Combinar(Solucion solucion1, Solucion solucion2)
{
    Solucion solucionFinal;

    cout << solucion1.p << endl;
    cout << solucion1.q << endl;
    cout << solucion1.A << endl;
    cout << solucion1.B << endl;

    cout << solucion2.p << endl;
    cout << solucion2.q << endl;
    cout << solucion2.A << endl;
    cout << solucion2.B << endl;

    cout << Dividir(solucion1.p, solucion2.q) << endl;
    int sol = solucion1.B.size();
    cout << sol << endl;

    Solucion NuevaSolucionIzq = SolucionDirecta(solucion1.p, Dividir(solucion1.p, solucion2.q)+(solucion1.B.size())-1, solucion1.A, solucion1.B);
    Solucion NuevaSolucionDer = SolucionDirecta(solucion2.p, solucion2.q, solucion2.A, solucion2.B);

    cout << NuevaSolucionIzq.p << endl;
    cout << NuevaSolucionIzq.q << endl;
    cout << NuevaSolucionIzq.A << endl;
    cout << NuevaSolucionIzq.B << endl;

    cout << NuevaSolucionDer.p << endl;
    cout << NuevaSolucionDer.q << endl;
    cout << NuevaSolucionDer.A << endl;
    cout << NuevaSolucionDer.B << endl;

    if (NuevaSolucionIzq.NumConcatenaciones >= NuevaSolucionDer.NumConcatenaciones)
    {
        solucionFinal.NumConcatenaciones = NuevaSolucionIzq.NumConcatenaciones;
        solucionFinal.Indice = NuevaSolucionIzq.Indice;
        return solucionFinal;
    }
    else
    {
        solucionFinal.NumConcatenaciones = NuevaSolucionDer.NumConcatenaciones;
        solucionFinal.Indice = NuevaSolucionDer.Indice;
        return solucionFinal;
    }
}

 Solucion DivideVenceras(int p, int q, string A, string B){
    int k;
    if (Pequeno(p, q, B)){
        return SolucionDirecta(p, q, A, B);
    }
    else {
        k = Dividir(p, q);
        return Combinar(DivideVenceras(p, k, A, B), DivideVenceras(k+1, q, A, B));
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
    string A, B;
    cout << "Introduce A: ";
    cin >> A;
    cout << "Introduce B: ";
    cin >> B;

    int p = 0;
   // int q = (int) sizeof(PalabraGenerada.cadenaA);
   // int base = (int) sizeof(PalabraGenerada.cadenaB);
    int q = A.size()-1;

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
