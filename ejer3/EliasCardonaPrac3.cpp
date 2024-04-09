/*
	Elias Eduardo Cardona Rodríguez
			Lic. en Informárica 4°A
						27/feb/2024
*/
#include <stdio.h>
#include <math.h>
void muestraHexa();
void comparaIgual();
//void sumar();
void opciones();

int main() {
    int op=20;

	while(1) {
		opciones();
		scanf("%d", &op);

		switch(op) {
			case 1:
				// @prototype -> func (params) : void
				muestraHexa();
			break;

			case 2:
				// @prototype -> func (params) : void
				comparaIgual();
			break;

			/*case 3:
				// @prototype -> func (params) : void
				sumar();
			break;*/

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


void muestraHexa() {
	float valor_real;
	printf("  Ingrese un valor real: ");
	scanf("%f", &valor_real);

	unsigned int rep = *(reinterpret_cast<unsigned int*>(&valor_real));

	printf("\n  La representacion HEX de %0.4f es: 0x%X \n", valor_real, rep);
}


void comparaIgual() {
	float res = 20.08 + 2.01;

	if(res == 22.09) {
		printf("\n  20.08 + 2.01 == 22.09  \n");
	} else {
		printf("\n  --- La suma es diferente a la constante\n");
	}
}


/*void sumar() {
	int i = 0;
	long double suma = 0.0;

	for(i=0; i<100e6; i++) {
		suma+=1e-5;
	}

	printf("\n  suma igual a %LG \n", suma);
}*/



void opciones() {
	printf("\n");
	printf("==========================================================\n\n");
	printf("  1.  Representacion hexadecimal \n");
	printf("  2.  Igualdad de valores        \n");

	printf("  10.  Salir\n");
	printf("  Digite una opcion: ");
}




