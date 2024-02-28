/*
	Elias Eduardo Cardona Rodríguez
			Lic. en Informárica 4°A
						27/feb/2024
*/

#include <cstdio>
#include <cmath>

// Función para mostrar el valor en hexadecimal
void muestraHexa() {
    float valor_real;
    printf("Ingrese un valor real: ");
    scanf("%f", &valor_real);

    unsigned int valor_entero = *(reinterpret_cast<unsigned int*>(&valor_real));
    printf("El equivalente hexadecimal de %.2f es: %X\n", valor_real, valor_entero);
}

// Función para comparar la igualdad de la suma
void comparaIgual() {
    float resultado_suma = 20.08 + 2.01;
    if (fabs(resultado_suma - 22.09) < 0.0001) {
        printf("20.08 + 2.01 es igual a 22.09\n");
    } else {
        printf("La suma es diferente\n");
    }
}

// Función para realizar la suma repetida
void Suma() {
    float acumulador = 0.0;
    for (int i = 0; i < 100000000; ++i) {
        acumulador += 1e-5;
    }
    printf("El resultado de la suma es: %.10f\n", acumulador);
}

int main() {
    muestraHexa();
    comparaIgual();
    Suma();
    return 0;
}


