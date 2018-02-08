#include <math.h>

int LongeurNombre(int nombre){
	int i = 0;

	double i1 = 0, i2 = 10;

	while(!(nombre >= i1 && nombre < i2)){
		i++;
		i1 = pow(10, i);
		i2 = pow(10, i+1);
	}

	return i+1;
}

int GetChiffre(int nombre, int chiffre){
	if(chiffre >= 0 && chiffre <= LongeurNombre(nombre)){
		chiffre++;
		double i1 = pow(10, chiffre);
		double i2 = pow(10, chiffre-1);
		return (nombre % (int)i1 - nombre % (int)i2) / i2;
	}
	return 0;
}

int main()
{
	int *s1 = malloc(1000 * sizeof(int));
	int *s3 = malloc(1000 * sizeof(int));
	int *s2 = malloc(1000 * sizeof(int));
	char c;

	for (int pos = 0; pos < 1000; pos++) {
		s1[pos] = pos;
		free(s2);
		s2 = malloc(1000 * sizeof(int));
		free(s3);
		s3 = malloc(1000 * sizeof(int));
		for(int i=LongeurNombre(pos)-1; i>=0; i--){
			c =  GetChiffre(pos, i) + 48;
			write(1, &c, 1);
		}
		write(1, "\n", 1);
	}
	malloc(0);
	return (0);
}
