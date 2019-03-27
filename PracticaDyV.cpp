#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    int i, j, n, m;
    bool anterior;
    int contador, repeticion, inicio, maxi, indice, indicemax;

    cout << "Introduce el tamaño maximo de n: ";
    cin >> n;
    cout << "Introduce el tamaño maximo de m: ";
    cin >> m;

    char A[n];
    char B[m];

    cout << "Escribe la cadena A: ";
    for( int w=0; w<n; w++)
    cin >> A[w];

    cout << "Escribe la cadena B: ";
    for( int v=0; v<m; v++)
    cin >> B[v];

    contador = 0;
    repeticion = 0;
    maxi = 0;
    anterior = false;
    i = 0;
    indicemax = 0;

    while (i < n)
    {
        j = 0;
        contador = 0;
        while ((A[i]!=B[j]) && (i < n))
        {
            i++;
            repeticion = 0;
            anterior = false;
        }
        i++;
        j++;
        contador++;
        while (contador<m)
        {
            if (A[i]==B[j])
            {
                if (contador==m-1)
                {
                    repeticion++;
                    i++;
                    j = 0;
                    contador = 0;
                    if (anterior == false)
                    {
                        indice = (i+1) - m;
                    }
                    anterior = true;
                }
                else
                {
                    contador++;
                    j++;
                    i++;
                }
            }
            else
            {
                contador = m;
            }
        }
        if (repeticion > maxi)
        {
            maxi = repeticion;
            repeticion = 0;
            indicemax = indice;
        }
    }
    inicio = indicemax;

    cout << "Numero de veces que aparece B es: " << maxi << endl;

    if (inicio == 0)
    {
        cout << "No hay indice posible" << endl;
    }
    else
    {
        cout << "El valor de inicio de la concatenacion mas grande es: " << inicio << endl;   }

    return 0;
}
