#include <cstdio>
#include <cmath>



int main() {

	double s = 300.0;

	for(int i=0; i<100e6; i++) {
		s+=1e-5;
	}

	printf("s igual a %lf", s);

	return 0;
}


