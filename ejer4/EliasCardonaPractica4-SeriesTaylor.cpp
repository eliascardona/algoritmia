/*
	Lic. en Informática 4°A - Algoritmia computacional
	Alumno: Elias Eduardo Cardona Rodríguez
	UNIDAD II - Ejercicios de Series de Taylor
	Fecha: 26/marzo/2024
*/
#include <stdlib.h>
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

#define maxTerminos 50

double calcularExponencial(double x, int n);
void calcularSerie(double terminoAnterior);
double calcularError();
void mostrarSerie();
void opciones();

double sumasArr[maxTerminos];
double terminosArr[maxTerminos];


int main() {
	int op=100;
	double terminoUtil = 1.0;

	while(1) {
		opciones();		
		cin>>op;
		switch(op) {
			case 1:
				calcularSerie(terminoUtil);
			break;

			case 2:
				mostrarSerie();
			break;

			case 10:
				exit(0);
			break;

			default:
				cout<<"opcion no valida"<<endl;
		}
	}

	return 0;
}


double calcularExponencial(double x, int n) {
    double suma = 1.0; // El primer término es siempre 1
    double termino = 1.0;

    for (int i=0; i<n; i++) {
        termino *= x / i; // Cálculo del siguiente término basado en el anterior
        suma += termino; // Sumar el término al resultado acumulado
    }

    return suma;
}


void calcularSerie(double terminoAnterior) {
    double x = 10.0; // Valor de x
    double aux = 2.0; // Operador auxiliar
    double suma = 2.0; // Valor de la suma
    double valorExacto = exp(x); // Valor exacto calculado con la función exp(x)

    // Calcular la serie de McLaurin y mostrar los resultados
    for(int i=0; i<=maxTerminos; i++) {
		if(i<1) {
	        suma = calcularExponencial(x, i);
			sumasArr[0] = suma;
			terminosArr[0] = 1.0;
		} else {
			suma = calcularExponencial(x, i);
			sumasArr[i] = suma;

			terminoAnterior = sumasArr[i] - sumasArr[i-1];
			terminosArr[i] = terminoAnterior;

		}
		// else {
	    //     suma = calcularExponencial(x, i);
		// 	sumasArr[i] = suma;			

		// 	aux = sumasArr[i] - sumasArr[i-1];
		// 	terminoAnterior = sumasArr[i-1] + aux;

		// 	terminosArr[i] = terminoAnterior;

		// }

        if(i > 0 && suma == calcularExponencial(x, i-1)) {
            cout << "Se alcanzo la precision deseada." << endl;
            break;
        }
    }
}

double calcularError() {
    double x = 10.0;
    double valorExacto = exp(x);
	double error = 2.0;
	double aux = 2.0;

	aux = calcularExponencial(x, maxTerminos);

    error = abs(valorExacto - aux);

	return error;
}

void mostrarSerie() {
	double errorFunc = 2.0;
	errorFunc = calcularError();

	cout<<endl<<" "<<"i"<<"\t"<<"Termino"<<"\t\t"<<"Suma"<<endl;
    for(int i = 0; i <= maxTerminos; i++) {
        cout<<" "<<i<<"      "<<setw(8)<<setprecision(6)<<fixed<< terminosArr[i] <<"     "<<setw(8)<<setprecision(6)<<fixed<< sumasArr[i] <<endl;
	}

	cout << endl << "El error de la aproximacion es: " << errorFunc << endl;
}


void opciones() {
	cout<<endl<<       "---"<<endl;
	cout<<endl<< "op. 1    calcular serie"<<endl;
	cout<<       "op. 2    mostrar serie"<<endl;
	cout<<       "op. 10   salir"<<endl;
	cout<<       "digite una opcion: ";
}






