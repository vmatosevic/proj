#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

#include "data_type.h"
#include "funkcije.h"

                                                              //8
int izbornik() {
	printf("====================");
	printf("Odaberite jednu od ponudenih opcija:");
	printf("====================\n");
	printf("\t\t\tOpcija 1: dodavanje klijenata!\n");
	printf("\t\t\tOpcija 2: citanje klijenata!\n");
	printf("\t\t\tOpcija 3: ispis klijenata!\n");
	printf("\t\t\tOpcija 4: pretrazivanje klijenata!\n");
	printf("\t\t\tOpcija 5: zavrsetak programa!\n");
	printf("======================================\
======================================\n");


	int uvijet = 1;
	static KLIJENT* polje = NULL;
	static KLIJENT* proclan = NULL;
	scanf("%d", &uvijet);
	switch (uvijet) {
	case 1:
		NoviKor();
		break;
	case 2:
		if (polje != NULL) {
			free(polje);
			polje = NULL;
		}
		polje = (KLIJENT*)ucitavanje();
		if (polje == NULL) {
			exit(EXIT_FAILURE);
		}

		break;
	case 3:
		ispis(polje);
		break;
	case 4:
		pretrazivanje(polje);
		break;
	case 5:
		uvijet = izlazIzPrograma(polje);
		break;
	default:
		uvijet = 0;
	}
	return uvijet;
}