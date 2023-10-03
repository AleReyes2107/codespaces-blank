/**
 * @file burbuja.cpp
 * @author Alejandro Reyes Lira (correo: alerey.lira@gmail.com) (Boleta: 2023640272)
 * @brief Crea y ordena un arreglo usando burbuja.
 * @version 0.1
 * @date 2023-10-03
 * 
 * @copyright GPL v3
 * 
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


/**
 * @brief Aplica el algoritmo de la burbuja en un arreglo de tamanio n
 * 
 * @param arr Arreglo  
 * @param n Entradas del arreglo
 */
void burbuja(int arr[], int n);

int main()
{
    int n = 0, i = 0;
    cout << "**** Numeros aleatorios ***\n";
    cout << "Cantidad de valores: ";
    cin >> n;

    int arr[n];
    srand(time(nullptr));

    for (i = 0; i < n; i++)
    {
        arr[i] = rand() % 251 + 50;
    }

    cout << "\nArreglo con numeros aleatorios: [";
    for (i = 0; i < n; i++)
    {
        cout << " " << arr[i] << " ";
    }
    cout << "]";

    burbuja(arr, n);

    cout << "\nArreglo ordenado de mayor a menor: [";
    for (i = 0; i < n; i++)
    {
        cout << " " << arr[i] << " ";
    }
    cout << "]\n";

    return 0;
}


void burbuja(int arr[], int n)
{
    int i = 0, j = 0, cont = 0;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                cont = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = cont;
            }
        }
    }
}