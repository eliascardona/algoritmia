/*
	Lic. en Informárica 4°A - Algoritmia computacional
	UNIDAD I - Ejercicio de conversion de valores entre sistemas numéricos
	Fecha: 12/feb/2024
	Alumno: Elias Eduardo Cardona Rodríguez
*/
#include <stdio.h>

void convertirBase(double numero, int base);
void opciones();


int main() {
    double numeroDecimal=20.0;
    int base=20;
    int op=20;

	while(1) {
		opciones();
		scanf("%d", &op);

		switch(op) {
			case 1: {
				printf("\n  Ingrese un numero: ");
				scanf("%lf", &numeroDecimal);
				printf("  Base a la que deseas convertir: ");
				scanf("%d", &base);
				/*
					@func       convertirBase
					@params     (double numeroDecimal, int base)
					@return     func (params) : void
				*/
				convertirBase(numeroDecimal, base);

			}
			break;

			case 10:
				printf("\n  saliendo...\n");
				break;

            default:
				printf("Opcion no valida\n");

		}
		if(op==10) {
			break;
		}
	}
    return 0;
}


void convertirBase(double numero, int base) {
    int parteEntera = (int)numero;
    int residuos[100];
    int iter = 0;
    while(parteEntera > 0) {
        residuos[iter++] = parteEntera % base;
        parteEntera /= base;
    }
    printf("\n  Cantidad representada en base %d: ", base);
    for(int i = iter - 1; i >= 0; i--) {
        if (residuos[i] < 10) {
            printf("%d", residuos[i]);
        } else {
            printf("%c", 'A' + residuos[i] - 10); // Utilizamos letras del alfabeto para dígitos mayores que 9
        }
    }
    // Manejar la parte decimal del número
    double parteDecimal = numero - (int)numero;
    if(parteDecimal != 0) {
        printf(".");
        iter = 0;
        while(iter < 10 && parteDecimal != 0) { // Considerar solo 10 lugares decimales
            parteDecimal *= base;
            int entero = (int)parteDecimal;
            if (entero < 10) {
                printf("%d", entero);
            } else {
                printf("%c", 'A' + entero - 10);
            }
            parteDecimal -= entero;
            iter++;
        }
    }
    printf("\n\n");
}


void opciones() {
	printf("\n");
	printf("  ----   ALGORITMO DE CONVERSION DE VALORES ENTRE SISTEMAS NUMERICOS  ----  \n\n");
	printf("  1.     Conversion numerica \n");

	printf("  10.     Salir\n");
	printf("  Digite una opcion: ");
}

