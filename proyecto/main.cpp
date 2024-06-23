#include <iostream>
using namespace std;

void calcularDiferenciasDivididas(double x[], double y[], double diferenciasDivididas[], int n);
double evaluarPolinomio(double x[], double diferenciasDivididas[], int n, double punto);


int main() {
    int n;
    cout << " ******** MODELO DE INTERPOLACION PARA SIMULACION DE CAIDA LIBRE ********\n\n";
    cout << "Ingrese la cantidad de puntos de datos: ";
    cin >> n;

    // crear arrays para almacenar los puntos de datos
    double x[n], y[n];

    // pedir al usuario que ingrese los puntos de datos
    cout << "Ingrese los puntos de datos (x y) separados por un espacio:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Punto " << i + 1 << ": ";
        cin >> x[i] >> y[i];
    }

    // array para almacenar las diferencias divididas
    double diferenciasDivididas[n];

    // calcular las diferencias divididas
    calcularDiferenciasDivididas(x, y, diferenciasDivididas, n);

    // mostrar las diferencias divididas
    cout << "\nDiferencias divididas:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Diferencia dividida " << i << ": " << diferenciasDivididas[i] << endl;
    }

    // pedir al usuario que ingrese un punto para evaluar el polinomio
    double punto;
    cout << "\nIngrese un punto para evaluar el polinomio de interpolacion: ";
    cin >> punto;

    // evaluar el polinomio en el punto dado
    double resultado = evaluarPolinomio(x, diferenciasDivididas, n, punto);

    // mostrar el resultado
    cout << "\nEl valor del polinomio de interpolacion en el punto " << punto << " es: " << resultado << endl;

    return 0;
}


// función para calcular las diferencias divididas
void calcularDiferenciasDivididas(double x[], double y[], double diferenciasDivididas[], int n) {
    for (int i = 0; i < n; i++) {
        diferenciasDivididas[i] = y[i];
    }
    for (int j = 1; j < n; j++) {
        for (int i = n - 1; i >= j; i--) {
            diferenciasDivididas[i] = (diferenciasDivididas[i] - diferenciasDivididas[i - j]) / (x[i] - x[i - j]);
        }
    }
}

// funcion para evaluar el polinomio de interpolacion en un punto dado
double evaluarPolinomio(double x[], double diferenciasDivididas[], int n, double punto) {
    double resultado = diferenciasDivididas[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        resultado = resultado * (punto - x[i]) + diferenciasDivididas[i];
    }
    return resultado;
}








