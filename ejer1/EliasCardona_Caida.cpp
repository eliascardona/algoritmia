/*
	Lic. en Informárica 4°A - Algoritmia computacional
	UNIDAD I - Primer ejercicio
	Fecha: 08/feb/2024
	Alumno: Elias Eduardo Cardona Rodríguez
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define GRAV 9.8

double arregloGlobal_Func[10]={};
double arregloGlobal_Inc[10]={};

void PintarTabla(int numeroCorridas);
double ObtenerVel_Anterior(int pos);
double velcidadFunc(float coef, float masa, float diferenciaTiempo, int iterador);
double velcidadInc(float coef, float masa, float diferenciaTiempo, int iterador);
void opciones();


int main() {
	int op=100;
	float masaSujeto=3.00;
	float dif=3.00;
	float resistencia=12.00;
	int nCorridas=2;

	while(1) {
		opciones();
		scanf("%d", &op);

		switch(op) {
			case 1: {
				printf("\n\nIngrese la masa del sujeto:");
				scanf("%f", &masaSujeto);

				printf("Ingrese el coeficiente de resistencia:");
				scanf("%f", &resistencia);

				printf("Ingrese la diferencia entre tiempo (seg):");
				scanf("%f", &dif);

				printf("Ingrese el numero de corridas para calcular:");
				scanf("%d", &nCorridas);

				for(int iter=0; iter<nCorridas; iter++) {
					/*
					   velocidadFunc (params) : float coef, float masa, float diferenciaTiempo, int iterador
					   velocidadInc (params) : float coef, float masa, float diferenciaTiempo, int iterador
					*/
					double velFunc = velcidadFunc(resistencia, masaSujeto, dif, iter);
					arregloGlobal_Func[iter] = velFunc;

					double velInc = velcidadInc(resistencia, masaSujeto, dif, iter);
					arregloGlobal_Inc[iter] = velInc;
				}
			}
			break;

			case 2: {
				printf("Ingrese el numero de corridas a imprimir:");
				scanf("%d", &nCorridas);

				PintarTabla(nCorridas);
			}
			break;


			case 10: {
				exit(0);
			}
            default:
				printf("Opcion no valida\n");
        }// fin del switch
    }   // fin del while

	return 0;
}


void PintarTabla(int numeroCorridas) {
	double diferencia = 1.00;
	printf("------------------------------------------------------------------------------------------\n");
	printf("|    Tiempo\t |\t   Velocidad     |    Incremento      \t |    Diferencia     \t|\n");
	printf("------------------------------------------------------------------------------------------\n");
	for(int i=0; i<numeroCorridas; i++) {
		diferencia = arregloGlobal_Func[i] - arregloGlobal_Inc[i];
		printf("|\t  %d  \t |\t   %lf \t |\t   %lf \t |\t   %lf \t |\n", i, arregloGlobal_Func[i], arregloGlobal_Inc[i], diferencia);
	}
	printf("------------------------------------------------------------------------------------------\n\n");
}


double ObtenerVel_Anterior(int pos) {
	double valor = 1.00;
	valor = arregloGlobal_Inc[pos];
	return valor;
}


double velcidadFunc(float coef, float masa, float diferenciaTiempo, int iterador) {
	double vel_func = 1.00;
	float tiempo = 0.00;
	double expoVal = 1.00;
	double gmc1 = 1.00;
	double gmc2 = 1.00;
	gmc1 = (GRAV*masa/coef);

	if(iterador==0) {
		tiempo = tiempo+0;
	} else {
		tiempo = iterador*diferenciaTiempo;
	}
	expoVal = coef*tiempo/masa;
	gmc2 = (GRAV*masa/coef)*exp(-expoVal);
	vel_func = gmc1 - gmc2;


	return vel_func;
}


double velcidadInc(float coef, float masa, float diferenciaTiempo, int iterador) {
	double vel_inc = 1.00;
	float tiempo = 0.00;
	double mg = 1.00;
	double mgcv = 1.00;
	double ResistV = 1.00;

	mg = masa*GRAV;

	for(int i=0; i<=iterador; i++) {
		if(i==0) {
			tiempo = tiempo+0;
		} else {
			tiempo += diferenciaTiempo;
		}
	}
	int indice_ant = iterador-1;
	double vel_ant = ObtenerVel_Anterior(indice_ant);


	ResistV = coef*vel_ant;
	mgcv = ((mg-ResistV)/masa);
	vel_inc = mgcv*(tiempo) + vel_ant;


	return vel_inc;
}


void opciones() {
	printf("\n");
	printf("  ----  ALGORITMO PARA COMPARAR VELOCIDADES EXACTAS VS. VELOCIDADES APROXIMADAS  ----  \n\n");
	printf("  1.     Calculo de velocidad en func. del tiempo (ambas soluciones)\n");
	printf("  2.     Impresion de los calculos \n");

	printf("  10.     Salir\n");
	printf("  Digite una opcion: ");
}


