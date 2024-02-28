/*
	Elias Eduardo Cardona Rodríguez
			Lic. en Informárica 4°A
						27/feb/2024
*/
#include <stdio.h>
#include <float.h>

int main() {
	double epsilon_double = 1.0;

	while((1.0 + epsilon_double) != 1.0) {
		epsilon_double /= 2.0;
	}

	printf("El valor epsilon en esta maquina es: %e\n", epsilon_double);

	return 0;
}



