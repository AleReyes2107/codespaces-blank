/**
 * @file matrices.cpp
 * @author Alejandro Reyes Lira (correo: alerey.lira@gmail.com) (Boleta: 2023640272)
 * @brief Crea 2 matrices y opera entre ellas.
 * @version 0.1
 * @date 2023-10-03
 * 
 * @copyright GPL v3
 * 
 */

#include<iostream>

using namespace std;

int main()
{
    int A[3][3], B[3][3], MSUM[3][3], MRES[3][3], MMLT[3][3];
    int i = 0, j = 0, k = 0;

    cout << "Valores matriz A (3x3): \n";
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            int aux1 = i + 1;
            int aux2 = j + 1;
            cout << "Posicion [" << aux1 << "," << aux2 << "] = ";
            cin >> A[i][j];
        }
    }

    cout << "\nValores matriz B (3x3): \n";
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            int aux1 = i + 1;
            int aux2 = j + 1;
            cout << "Posicion [" << aux1 << "," << aux2 << "] = ";
            cin >> B[i][j];
        }
    }

    cout << "\nLa suma de la matriz A y la matriz B es:  \n";
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            MSUM[i][j] = A[i][j] + B[i][j];
            cout << MSUM[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\nLa resta de la matriz A y la matriz B es:  \n";
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            MRES[i][j] = A[i][j] - B[i][j];
            cout << MRES[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\nEl producto de la matriz A y la matriz B es:  \n";
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            MMLT[i][j] = 0;
            for (k = 0; k < 3; k++)
            {
                MMLT[i][j] = MMLT[i][j] + A[i][k] * B[k][j];
            }
            cout << MMLT[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}