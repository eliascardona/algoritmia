/*
	Lic. en Informárica 4°A - Algoritmia computacional
	UNIDAD I - Ejercicio de conversion de valores entre sistemas numéricos
	Fecha: 12/feb/2024
	Alumno: Elias Eduardo Cardona Rodríguez
*/
#include <stdio.h>
#include <stdlib.h>

void opciones();

/*int Divide(int n) {
	int bit = n%2;
}

bool StopDividing(int a, int b) {
	if(a/b == 0 && a%b == 1) {
		return true;
	} else {
		return false;
	}
}*/

void DecimalABinario(int numero) {
    int bits[32];
    int indice = 0;

    while (numero > 0) {
        bits[indice++] = numero % 2;
        numero /= 2;
    }

    printf("El numero en binario es: ");
    for (int i = indice - 1; i >= 0; i--) {
        printf("%d", bits[i]);
    }
    printf("\n");
}

int main() {
	int op = 20;
	int base10 = 1;
	int cn = 0;
	int arreglo[20] = {};
	int aux = 0;

	while(1) {
		opciones();
		scanf("%d", &op);

		switch(op) {
			case 1: {
				printf("Ingrese un numero en base 10:");
				scanf("%d", &base10);
				DecimalABinario(base10);
			}
			/*{
				printf("Ingrese un numero en base 10:");
				scanf("%d", &base10);

				for(int i=0; i<40; i++) {
					   @func       Divide
					   @params     (int n)
					   @return     func (params) : int bit
					
					int resto = Divide(base10);
					cn++;
					arreglo[cn] = resto;
					aux = arreglo[cn];
					
					   @func       KeepDividing
					   @params     (int a, int b)
					   @return     func (params) : bool any
					
					bool status = StopDividing(aux, 2);
					if(status==true)
						break;
				}
			}*/
			break; // end of case 1

			case 2: {
				printf("Obtuvimos el siguiente byte:");
			}
			/*{
				for(int i=0; i<20; i++) {
					if(i<12) {
						printf("%d  ", arreglo[i]);
					} else {
						printf("n  ");
					}
				}
			}*/
			break; // end of case 2


			case 10: {
				exit(0);
			}
            default:
				printf("Opcion no valida\n");
        }// fin del switch
    }   // fin del while

	return 0;
}


void opciones() {
	printf("\n");
	printf("  ----   ALGORITMO DE CONVERSION DE VALORES ENTRE SISTEMAS NUMERICOS  ----  \n\n");
	printf("  1.     Conversion a binario         \n");
	printf("  2.     Pintado de la conversion     \n");

	printf("  10.     Salir\n");
	printf("  Digite una opcion: ");
}

