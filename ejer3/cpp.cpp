#include <iostream>
#include <iomanip>
#include <cmath>

void muestraHexa() {
    float valor_real;
    std::cout << "Ingrese un valor real: ";
    std::cin >> valor_real;

    unsigned int valor_entero = *(reinterpret_cast<unsigned int*>(&valor_real));
    std::cout << "El equivalente hexadecimal de " << valor_real << " es: " << std::hex << valor_entero << std::endl;
}

void comparaIgual() {
    float resultado_suma = 20.08 + 2.01;
    if (fabs(resultado_suma - 22.09) < 0.0001) {
        std::cout << "20.08 + 2.01 es igual a 22.09" << std::endl;
    } else {
        std::cout << "La suma es diferente" << std::endl;
    }
}

void Suma() {
    float acumulador = 0.0;
    for (int i = 0; i < 100000000; ++i) {
        acumulador += 1e-5;
    }
    std::cout << "El resultado de la suma es: " << acumulador << std::endl;
}

int main() {
    muestraHexa();
    comparaIgual();
    Suma();
    return 0;
}



