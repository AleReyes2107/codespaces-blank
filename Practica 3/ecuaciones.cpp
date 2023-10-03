/**
 * @file matrices.cpp
 * @author Alejandro Reyes Lira (correo: alerey.lira@gmail.com) (Boleta: 2023640272)
 * @brief Obtiene los valores de un sistema de ecuaciones y lo resuelve.
 * @version 0.1
 * @date 2023-10-03
 * 
 * @copyright GPL v3
 * 
 */

#include <iostream>

using namespace std;

int main() {

    float A[3][3], B[3][1], X[3][1], MADJ[3][3], MTRS[3][3], MINV[3][3], MRES[3][1];
    float det = 0.0;
    int i = 0, j = 0;

    cout << "Coeficientes de tu sistema de ecuaciones 3x3: \n";
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            int aux1 = i + 1;
            int aux2 = j + 1;
            cout << "Posicion [" << aux1 << "," << aux2 << "] = ";
            cin >> A[i][j];
        }
    }

    cout << "Resultados de tu sistema de ecuaciones : \n";
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 1; j++) {
            int aux1 = i + 1;
            int aux2 = j + 1;
            cout << "Posicion [" << aux1 << "," << aux2 << "] = ";
            cin >> B[i][j];
        }
    }

    // Cálculo de determinante de A con Regla de Sarrus
    det = (A[0][0] * A[1][1] * A[2][2] + A[1][0] * A[2][1] * A[0][2] + A[2][0] * A[0][1] * A[1][2]) -
          (A[2][0] * A[1][1] * A[0][2] + A[0][0] * A[2][1] * A[1][2] + A[1][0] * A[0][1] * A[2][2]);

    cout << "Determinante  de A es: " << det << endl;

    if (det != 0) {

        // Transpuesta de la matriz A
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                MTRS[j][i] = A[i][j];
            }
        }

        // Matriz adjunta de la transpuesta de A
        MADJ[0][0] = ((+1) * (MTRS[1][1] * MTRS[2][2] - MTRS[2][1] * MTRS[1][2]));
        MADJ[1][0] = ((-1) * (MTRS[0][1] * MTRS[2][2] - MTRS[2][1] * MTRS[0][2]));
        MADJ[2][0] = ((+1) * (MTRS[0][1] * MTRS[1][2] - MTRS[1][1] * MTRS[0][2]));
        MADJ[0][1] = ((-1) * (MTRS[1][0] * MTRS[2][2] - MTRS[2][0] * MTRS[1][2]));
        MADJ[1][1] = ((+1) * (MTRS[0][0] * MTRS[2][2] - MTRS[2][0] * MTRS[0][2]));
        MADJ[2][1] = ((-1) * (MTRS[0][0] * MTRS[1][2] - MTRS[1][0] * MTRS[0][2]));
        MADJ[0][2] = ((+1) * (MTRS[1][0] * MTRS[2][1] - MTRS[2][0] * MTRS[1][1]));
        MADJ[1][2] = ((-1) * (MTRS[0][0] * MTRS[2][1] - MTRS[2][0] * MTRS[0][1]));
        MADJ[2][2] = ((+1) * (MTRS[0][0] * MTRS[1][1] - MTRS[1][0] * MTRS[0][1]));

        // Calcular la matriz inversa
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                MINV[i][j] = ((1.0 / det) * MADJ[i][j]);
            }
        }

        // Imprimir la matriz inversa
        cout << "\nLa matriz inversa es:\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << MINV[i][j] << "    ";
            }
            cout << endl;
        }

        // Multiplicar la matriz inversa por los resultados de la ecuación para los valores de x
        for (i = 0; i < 3; i++) {
            MRES[i][0] = 0;
            for (j = 0; j < 3; j++) {
                MRES[i][0] = MRES[i][0] + MINV[i][j] * B[j][0];
            }
        }

        // Imprimir la solución
        cout << "Las soluciones son:\n";
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 1; j++) {
                cout << MRES[i][j] << " ";
            }
            cout << endl;
        }

        return 0;

    } else {
        cout << "La matriz A no es invertible, no se puede operar\n";
        return 1;
    }
}
