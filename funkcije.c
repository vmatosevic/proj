#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "data_type.h"


static int brojac = 0;

void NoviKor() {

	FILE* pF = fopen("klijenti.bin", "rb+");
	if (pF == NULL) {
		perror("Dodavanje klijenata u datoteke klijenti.bin");               //19
		exit(EXIT_FAILURE);
	}
	fread(&brojac, sizeof(int), 1, pF);

	KLIJENT temp = { 0 };
	temp.id = brojac;

	printf("Unesite ime klijenta!\n");
	scanf("%s", &temp.ime);

	printf("Unesite prezime klijenta!\n");
    scanf("%s", &temp.prezime);

	printf("Unesite broj mobitela klijenta!\n");
    scanf("%d", &temp.brojMob);

	printf("Unesite tip sisanja klijenta!\n");
    scanf("%d", &temp.tipSisanja);



	fseek(pF, sizeof(KLIJENT) * brojac + sizeof(int), SEEK_SET);
	fwrite(&temp, sizeof(KLIJENT), 1, pF);
	rewind(pF);
	brojac++;
	fwrite(&brojac, sizeof(int), 1, pF);
	fclose(pF);

}

void* ucitavanje() {
	FILE* pF = fopen("klijenti.bin", "rb");
	if (pF == NULL) {
		perror("Ucitavanje klijenata iz datoteke klijenti.bin");
		return NULL;
	}

	fread(&brojac, sizeof(int), 1, pF);


	KLIJENT* polje = (KLIJENT*)calloc(brojac, sizeof(KLIJENT));                 //14
	if (polje == NULL) {
		perror("Zauzimanje memorije za studente");
		return NULL;
	}

	fread(polje, sizeof(KLIJENT), brojac, pF);

	return polje;
}

void ispis(const KLIJENT* const polje) {
	if (polje == NULL) {
		printf("Polje klijenata je prazno!\n");
		return;
	}
	int i;
	for (i = 0; i < brojac; i++)
	{
		printf("Clan\nID: %d\nime: %s\nprezime: %s\nbroj mobitela: %d\ntip sisanja: %d\n",

			(polje + i)->id,
			(polje + i)->ime,
			(polje + i)->prezime,
			(polje + i)->brojMob,
			(polje + i)->tipSisanja
		);
	}
}


void pretrazivanje(KLIJENT* const polje) {
	if (polje == NULL) {
		printf("Polje klijenata je prazno!\n");
		return;
	}
	int i;
	int trazenid;
	printf("Unesite id klijenta.\n");

	scanf("%d", &trazenid);
	for (i = 0; i < brojac; i++)
	{

		if (trazenid == (polje + i)->id) {
			printf("Klijent je pronaden!\n");
			printf("Klijent\nID: %d\nime: %s\nprezime: %s\nbroj mobitela: %d\ntip sisanja: %d\n",

				(polje + i)->id,
				(polje + i)->ime,
				(polje + i)->prezime,
				(polje + i)->brojMob,
				(polje + i)->tipSisanja
			);
		}
	}

}

                                                                   //4
int izlazIzPrograma(KLIJENT* poljeKlijenata) {
	char c[10] = "";
	char s[] = "ne";
	free(poljeKlijenata);
	printf("Da li ste sigurni kako zelite zavrsiti program?\nda/ne\n");
	scanf("%s", c);
	if (!strcmp(c, s)) {

		return 1;
	}
	else {

		return 0;
	}



}


