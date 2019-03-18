#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    int maxi, indicemax, suma, i, k, elementos, l, j, n, m;
    char A[n];
    char B[m];

    cout << "Introduce el tamaño maximo de n: ";
    cin >> n;
    cout << "Introduce el tamaño maximo de m: ";
    cin >> m;

    cout << "Escribe la cadena A: ";
    for( int w=0; w<n; w++)
    cin >> A[w];

    cout << "Escribe la cadena B: ";
    for( int v=0; v<m; v++)
    cin >> B[v];

    int indices[n/m];
    k = 0;
    i = 0;
    elementos = 0;
    suma = 0;
    maxi = 0;
    l = 0;
    while (i < n)
    {
        j = 0;
        while (A[i] == B[j])
        {
            i++;
            elementos++;
            if (elementos == m)
            {
                k++;
                j = 0;
                indices[k] = i - m;
                elementos = 0;
            }
            else
            {
                if (j < m)
                {
                    j++;
                }
                else
                {
                    j = 0;
                }
            }
        }
        i++;
    }
    while (l < sizeof(indices))
    {
        while (indices[l + 1])
        {
            suma++;
            l++;
        }
        if (suma > maxi)
        {
            maxi = suma;
            indicemax = l - suma * m;
        }
        l++;
    }

    cout << "La max suma es: " << maxi;
    cout << "El indice del mas grandes es: " << indicemax;

    return 0;
}
