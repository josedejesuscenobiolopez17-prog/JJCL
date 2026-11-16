#include <stdio.h>

int main() {
	int A;
	int B;
	int* aptr = &A;
	char texto[] = "Jose de Jesus";
	*aptr = 20;
	B = 15;
	printf("El valor de A es %d y su direccion de memoria es %x\n", A, (unsigned int)aptr);
	aptr = &B;
	printf("El valor de B es %d y su direccion de memoria es %x\n", *aptr, (unsigned int)aptr);
	for(int i=0; i < 13; i++) {
		printf("%C y su dirrecion %x\n", *(texto + i), (unsigned int)(texto + i));
	    }
		return 0;
}