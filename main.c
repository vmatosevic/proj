#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include "data_type.h"
#include "funkcije.h"

int main(void) {

	FILE* pF = fopen("klijenti.bin", "wb");
	fclose(pF);

	int uvijet = 1;

	while (uvijet) {
		uvijet = izbornik();
	}
	printf("Zavrsetak programa!\n");
	return 0;
}