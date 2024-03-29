// Arayüz.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//Tufan Anıl Kanca 170201034 - Saadettin Ayyıldız 170201123

#include "pch.h"
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

void Okla();
int  Onay();
void Yon();
int Fonk();

//Nesne tanımları
ALLEGRO_KEYBOARD_STATE klavye;
ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_BITMAP  *yol1 = NULL;
ALLEGRO_BITMAP  *yol2 = NULL;
ALLEGRO_BITMAP  *secim = NULL;
ALLEGRO_BITMAP  *yon = NULL;
ALLEGRO_BITMAP  *saat = NULL;
ALLEGRO_BITMAP  *ters = NULL;
ALLEGRO_BITMAP  *harf = NULL;
ALLEGRO_BITMAP  *as = NULL; // a saat yönü
ALLEGRO_BITMAP  *bs = NULL; // b saat yönü
ALLEGRO_BITMAP  *cs = NULL; // c saat yönü
ALLEGRO_BITMAP  *ds = NULL; // d saat yönü
ALLEGRO_BITMAP  *at = NULL; // a saat yönü tersi
ALLEGRO_BITMAP  *bt = NULL; // b saat yönü tersi
ALLEGRO_BITMAP  *ct = NULL; // c saat yönü tersi
ALLEGRO_BITMAP  *dt = NULL; // d saat yönü tersi
ALLEGRO_BITMAP  *sag = NULL;
ALLEGRO_BITMAP  *sol = NULL;
ALLEGRO_BITMAP  *giris = NULL;
ALLEGRO_BITMAP  *ony = NULL;
ALLEGRO_BITMAP  *tm = NULL;

int yona = 0, yonb = 0, yonc = 0, yond = 0, yone = 0;
int sec = 0;
int giriscikisX = 2, giriscikisY = 2, giriscikisZ = 2, giriscikisT = 2;
int yol = 0;
int hata = 0;
int matris1[8][9], matris2[9][10];

int main() {
	
	Fonk();
	Basa: Fonk();
	if (yol == 1) {
		// X a b düğümü yön bilgisi alınıyor.				
		if (yona == 2 && yonb == 1 && giriscikisX == 1) {
			printf("\n\nHATA!!! YANLIS YON GIRDINIZ!!! a ve b yonlerini tekrar giriniz.");
			yona = 0; yonb = 0; yonc = 0; yond = 0; sec = 0; giriscikisX = 2; giriscikisY = 2; giriscikisZ = 2; giriscikisT = 2; yol = 0;
			goto Basa;
		}
		if (yona == 1 && yonb == 2 && giriscikisX == 2) {
			printf("\n\nHATA!!! YANLIS YON GIRDINIZ!!! a ve b yonlerini tekrar giriniz.");
			yona = 0; yonb = 0; yonc = 0; yond = 0; sec = 0; giriscikisX = 2; giriscikisY = 2; giriscikisZ = 2; giriscikisT = 2; yol = 0;
			goto Basa;
		}

		// Y b d dugumu icin yon bilgisi aliniyor.
		if (yond == 2 && yonb == 1 && giriscikisY == 2) {
			printf("\n\nHATA!!! YANLIS YON GIRDINIZ!!! a ve b yonlerini tekrar giriniz.");
			yona = 0; yonb = 0; yonc = 0; yond = 0; sec = 0; giriscikisX = 2; giriscikisY = 2; giriscikisZ = 2; giriscikisT = 2; yol = 0;
			goto Basa;
		}
		if (yonb == 2 && yond == 1 && giriscikisY == 1) {
			printf("\n\nHATA!!! YANLIS YON GIRDINIZ!!! a ve b yonlerini tekrar giriniz.");
			yona = 0; yonb = 0; yonc = 0; yond = 0; sec = 0; giriscikisX = 2; giriscikisY = 2; giriscikisZ = 2; giriscikisT = 2; yol = 0;
			goto Basa;
		}
		// Z c d dugumu icin.
		if (yonc == 2 && yond == 1 && giriscikisZ == 2) {
			printf("\n\nHATA!!! YANLIS YON GIRDINIZ!!! a ve b yonlerini tekrar giriniz.");
			yona = 0; yonb = 0; yonc = 0; yond = 0; sec = 0; giriscikisX = 2; giriscikisY = 2; giriscikisZ = 2; giriscikisT = 2; yol = 0;
			goto Basa;
		}
		if (yonc == 1 && yond == 2 && giriscikisZ == 1) {
			printf("\n\nHATA!!! YANLIS YON GIRDINIZ!!! a ve b yonlerini tekrar giriniz.");
			yona = 0; yonb = 0; yonc = 0; yond = 0; sec = 0; giriscikisX = 2; giriscikisY = 2; giriscikisZ = 2; giriscikisT = 2; yol = 0;
			goto Basa;
		}
		//T a c dugumu icin.
		if (yona == 1 && yonc == 2 && giriscikisT == 1) {
			printf("\n\nHATA!!! YANLIS YON GIRDINIZ!!! a ve b yonlerini tekrar giriniz.");
			yona = 0; yonb = 0; yonc = 0; yond = 0; sec = 0; giriscikisX = 2; giriscikisY = 2; giriscikisZ = 2; giriscikisT = 2; yol = 0;
			goto Basa;
		}
		if (yona == 2 && yonc == 1 && giriscikisT == 2) {
			printf("\n\nHATA!!! YANLIS YON GIRDINIZ!!! a ve b yonlerini tekrar giriniz.");
			yona = 0; yonb = 0; yonc = 0; yond = 0; sec = 0; giriscikisX = 2; giriscikisY = 2; giriscikisZ = 2; giriscikisT = 2; yol = 0;
			goto Basa;
		}

		// Yon bilgilerinin alinmasi ve denetlenmesi burada bitiyor. -----------------------------------------------------------

// Arac sayilari aliniyor. En az birinin -1 olup olmadığı denetleniyor.
		int aracX, aracY, aracZ, aracT, aracA, aracB, aracC, aracD, denetciAracSayisi = 0;
		printf("\nSizden arac sayilarini girmeniz istenecek. Bilinmeyen sayi icin -1 girilecek. En az bir tanesi -1 girilmek zorunda.\n\n");

		do {

			if (denetciAracSayisi != 0)
				printf("\n\nHATA!!! En az bir deger -1 girilmeli. Lutfen tekrar giriniz!\n\n");
			denetciAracSayisi++;
			printf("X yolu icin arac sayisini giriniz :");
			scanf_s("%d", &aracX);
			printf("\nY yolu icin arac sayisini giriniz :");
			scanf_s("%d", &aracY);
			printf("\nZ yolu icin arac sayisini giriniz :");
			scanf_s("%d", &aracZ);
			printf("\nT yolu icin arac sayisini giriniz :");
			scanf_s("%d", &aracT);
			printf("\nA yolu icin arac sayisini giriniz :");
			scanf_s("%d", &aracA);
			printf("\nB yolu icin arac sayisini giriniz :");
			scanf_s("%d", &aracB);
			printf("\nC yolu icin arac sayisini giriniz :");
			scanf_s("%d", &aracC);
			printf("\nD yolu icin arac sayisini giriniz :");
			scanf_s("%d", &aracD);
		} while (aracX != -1 && aracY != -1 && aracZ != -1 && aracT != -1 && aracA != -1 && aracB != -1 && aracC != -1 && aracD != -1);

		// Matrisin butun degerlerine 0 atıyoruz.
		int i, j;
		for (i = 0; i < 8; i++) {
			for (j = 0; j < 9; j++) {
				matris1[i][j] = 0;

			}
		}

		// Birinci satiri atiyoruz.

		if (yona == 1 && yonb == 1 && giriscikisX == 1) {
			matris1[0][0] = (-1)*aracA;
			matris1[0][1] = aracB;
			matris1[0][4] = aracX;
		}
		if (yona == 1 && yonb == 1 && giriscikisX == 2) {
			matris1[0][0] = aracA;
			matris1[0][1] = (-1)*aracB;
			matris1[0][4] = aracX;
		}
		if (yona == 1 && yonb == 2 && giriscikisX == 1) {
			matris1[0][0] = aracA;
			matris1[0][1] = aracB;
			matris1[0][4] = (-1)*aracX;
		}
		if (yona == 2 && yonb == 1 && giriscikisX == 2) {
			matris1[0][0] = aracA;
			matris1[0][1] = aracB;
			matris1[0][4] = (-1)*aracX;
		}
		if (yona == 2 && yonb == 2 && giriscikisX == 1) {
			matris1[0][0] = aracA;
			matris1[0][1] = (-1)*aracB;
			matris1[0][4] = aracX;
		}
		if (yona == 2 && yonb == 2 && giriscikisX == 2) {
			matris1[0][0] = (-1)*aracA;
			matris1[0][1] = aracB;
			matris1[0][4] = aracX;
		}

		// Ikinci satiri atiyoruz.

		if (yonb == 1 && yond == 1 && giriscikisY == 1) {
			matris1[1][1] = (-1)*aracB;
			matris1[1][3] = aracD;
			matris1[1][5] = aracY;
		}
		if (yonb == 1 && yond == 1 && giriscikisY == 2) {
			matris1[1][1] = aracB;
			matris1[1][3] = (-1)*aracD;
			matris1[1][5] = aracY;
		}
		if (yonb == 1 && yond == 2 && giriscikisY == 1) {
			matris1[1][1] = aracB;
			matris1[1][3] = aracD;
			matris1[1][5] = (-1)*aracY;
		}
		if (yonb == 2 && yond == 1 && giriscikisY == 2) {
			matris1[1][1] = aracB;
			matris1[1][3] = aracD;
			matris1[1][5] = (-1)*aracY;
		}
		if (yonb == 2 && yond == 2 && giriscikisY == 1) {
			matris1[1][1] = aracB;
			matris1[1][3] = (-1)*aracD;
			matris1[1][5] = aracY;
		}
		if (yonb == 2 && yond == 2 && giriscikisY == 2) {
			matris1[1][1] = (-1)*aracB;
			matris1[1][3] = aracD;
			matris1[1][5] = aracY;
		}

		// Ucuncu satiri atiyoruz.

		if (yonc == 1 && yond == 1 && giriscikisZ == 1) {
			matris1[2][2] = aracC;
			matris1[2][3] = (-1)*aracD;
			matris1[2][6] = aracZ;
		}
		if (yonc == 1 && yond == 1 && giriscikisZ == 2) {
			matris1[2][2] = (-1)*aracC;
			matris1[2][3] = aracD;
			matris1[2][6] = aracZ;
		}
		if (yonc == 1 && yond == 2 && giriscikisZ == 2) {
			matris1[2][2] = aracC;
			matris1[2][3] = aracD;
			matris1[2][6] = (-1)*aracZ;
		}
		if (yonc == 2 && yond == 1 && giriscikisZ == 1) {
			matris1[2][2] = aracC;
			matris1[2][3] = aracD;
			matris1[2][6] = (-1)*aracZ;
		}
		if (yonc == 2 && yond == 2 && giriscikisZ == 1) {
			matris1[2][2] = (-1)*aracC;
			matris1[2][3] = aracD;
			matris1[2][6] = aracZ;
		}
		if (yonc == 2 && yond == 2 && giriscikisZ == 2) {
			matris1[2][2] = aracC;
			matris1[2][3] = (-1)*aracD;
			matris1[2][6] = aracZ;
		}

		// Dorduncu satiri atiyoruz.

		if (yona == 1 && yonc == 1 && giriscikisT == 1) {
			matris1[3][0] = aracA;
			matris1[3][2] = (-1)*aracC;
			matris1[3][7] = aracT;
		}
		if (yona == 1 && yonc == 1 && giriscikisT == 2) {
			matris1[3][0] = (-1)*aracA;
			matris1[3][2] = aracC;
			matris1[3][7] = aracT;
		}
		if (yona == 1 && yonc == 2 && giriscikisT == 1) {
			matris1[3][0] = aracA;
			matris1[3][2] = aracC;
			matris1[3][7] = (-1)*aracT;
		}
		if (yona == 2 && yonc == 1 && giriscikisT == 1) {
			matris1[3][0] = aracA;
			matris1[3][2] = aracC;
			matris1[3][7] = (-1)*aracT;
		}
		if (yona == 2 && yonc == 2 && giriscikisT == 1) {
			matris1[3][0] = (-1)*aracA;
			matris1[3][2] = aracC;
			matris1[3][7] = aracT;
		}
		if (yona == 2 && yonc == 2 && giriscikisT == 2) {
			matris1[3][0] = aracA;
			matris1[3][2] = (-1)*aracC;
			matris1[3][7] = aracT;
		}

		// Besinci satiri atiyoruz.

		if (giriscikisX == 1 && giriscikisY == 1 && giriscikisZ == 2 && giriscikisT == 2) {
			matris1[4][4] = aracX;
			matris1[4][5] = aracY;
			matris1[4][6] = (-1)*aracZ;
			matris1[4][7] = (-1)*aracT;
		}
		if (giriscikisX == 1 && giriscikisY == 2 && giriscikisZ == 1 && giriscikisT == 2) {
			matris1[4][4] = aracX;
			matris1[4][5] = (-1)*aracY;
			matris1[4][6] = aracZ;
			matris1[4][7] = (-1)*aracT;
		}
		if (giriscikisX == 1 && giriscikisY == 2 && giriscikisZ == 2 && giriscikisT == 1) {
			matris1[4][4] = aracX;
			matris1[4][5] = (-1)*aracY;
			matris1[4][6] = (-1)*aracZ;
			matris1[4][7] = aracT;
		}
		if (giriscikisX == 2 && giriscikisY == 1 && giriscikisZ == 1 && giriscikisT == 2) {
			matris1[4][4] = (-1)*aracX;
			matris1[4][5] = aracY;
			matris1[4][6] = aracZ;
			matris1[4][7] = (-1)*aracT;
		}
		if (giriscikisX == 2 && giriscikisY == 1 && giriscikisZ == 2 && giriscikisT == 1) {
			matris1[4][4] = (-1)*aracX;
			matris1[4][5] = aracY;
			matris1[4][6] = (-1)*aracZ;
			matris1[4][7] = aracT;
		}
		if (giriscikisX == 2 && giriscikisY == 2 && giriscikisZ == 1 && giriscikisT == 1) {
			matris1[4][4] = (-1)*aracX;
			matris1[4][5] = (-1)*aracY;
			matris1[4][6] = aracZ;
			matris1[4][7] = aracT;
		}

		// Matrisi yazdır.
		printf("\n\n");
		printf("Girilen arac sayisina gore olusan matris :\n");
		for (i = 0; i < 8; i++) {
			for (j = 0; j < 8; j++) {
				printf("  %d       ", matris1[i][j]);

			}
			printf("\n\n");
		}
		// Girilen arac sayilarini toplayip saga atiyoruz.

		int toplam = 0;
		for (i = 0; i < 8; i++) {
			for (j = 0; j < 9; j++) {
				if (matris1[i][j] != -1 && matris1[i][j] != 0 && matris1[i][j] != 1) {
					toplam = toplam + matris1[i][j];
					matris1[i][j] = 0;

				}
				if (j == 8) matris1[i][j] = toplam;
			}
			toplam = 0;
		}

		printf("\n\n");
		printf("Eselon form oncesi matrisin son hali :\n");
		for (i = 0; i < 8; i++) {
			for (j = 0; j < 9; j++) {
				printf("  %d       ", matris1[i][j]);

			}
			printf("\n\n");
		}
		//--------------------------------------------------Eşalon Form Baslangic--------------------------------------------------------------------------


	   //--------------------------------------------------Eşalon Form Son-----------------------------------------------------------------------
	}
	if (yol == 2) {
		// X a b düğümü yön bilgisi alınıyor.				
		if (yona == 2 && yonb == 1 && giriscikisX == 1) {
			printf("\n\nHATA!!! YANLIS YON GIRDINIZ!!! a ve b yonlerini tekrar giriniz.");
			yona = 0; yonb = 0; yonc = 0; yond = 0; sec = 0; giriscikisX = 2; giriscikisY = 2; giriscikisZ = 2; giriscikisT = 2; yol = 0;
			goto Basa;
		}
		if (yona == 1 && yonb == 2 && giriscikisX == 2) {
			printf("\n\nHATA!!! YANLIS YON GIRDINIZ!!! a ve b yonlerini tekrar giriniz.");
			yona = 0; yonb = 0; yonc = 0; yond = 0; sec = 0; giriscikisX = 2; giriscikisY = 2; giriscikisZ = 2; giriscikisT = 2; yol = 0;
			goto Basa;
		}

		// Y b d e dugumu icin yon bilgisi aliniyor.
		if (yond == 2 && yonb == 1 && giriscikisY == 2 && yone == 2) {
			printf("\n\nHATA!!! YANLIS YON GIRDINIZ!!! a ve b yonlerini tekrar giriniz.");
			yona = 0; yonb = 0; yonc = 0; yond = 0; sec = 0; giriscikisX = 2; giriscikisY = 2; giriscikisZ = 2; giriscikisT = 2; yol = 0;
			goto Basa;
		}
		if (yonb == 2 && yond == 1 && giriscikisY == 1 && yone == 1) {
			printf("\n\nHATA!!! YANLIS YON GIRDINIZ!!! a ve b yonlerini tekrar giriniz.");
			yona = 0; yonb = 0; yonc = 0; yond = 0; sec = 0; giriscikisX = 2; giriscikisY = 2; giriscikisZ = 2; giriscikisT = 2; yol = 0;
			goto Basa;
		}
		// Z c d dugumu icin.
		if (yonc == 2 && yond == 1 && giriscikisZ == 2) {
			printf("\n\nHATA!!! YANLIS YON GIRDINIZ!!! a ve b yonlerini tekrar giriniz.");
			yona = 0; yonb = 0; yonc = 0; yond = 0; sec = 0; giriscikisX = 2; giriscikisY = 2; giriscikisZ = 2; giriscikisT = 2; yol = 0;
			goto Basa;
		}
		if (yonc == 1 && yond == 2 && giriscikisZ == 1) {
			printf("\n\nHATA!!! YANLIS YON GIRDINIZ!!! a ve b yonlerini tekrar giriniz.");
			yona = 0; yonb = 0; yonc = 0; yond = 0; sec = 0; giriscikisX = 2; giriscikisY = 2; giriscikisZ = 2; giriscikisT = 2; yol = 0;
			goto Basa;
		}
		//T a c e dugumu icin.
		if (yona == 1 && yonc == 2 && giriscikisT == 1 && yone == 2) {
			printf("\n\nHATA!!! YANLIS YON GIRDINIZ!!! a ve b yonlerini tekrar giriniz.");
			yona = 0; yonb = 0; yonc = 0; yond = 0; sec = 0; giriscikisX = 2; giriscikisY = 2; giriscikisZ = 2; giriscikisT = 2; yol = 0;
			goto Basa;
		}
		if (yona == 2 && yonc == 1 && giriscikisT == 2 && yone == 1) {
			printf("\n\nHATA!!! YANLIS YON GIRDINIZ!!! a ve b yonlerini tekrar giriniz.");
			yona = 0; yonb = 0; yonc = 0; yond = 0; sec = 0; giriscikisX = 2; giriscikisY = 2; giriscikisZ = 2; giriscikisT = 2; yol = 0;
			goto Basa;
		}
		// Arac sayilari aliniyor. En az birinin -1 olup olmadığı denetleniyor.
		int aracX, aracY, aracZ, aracT, aracA, aracB, aracC, aracD, aracE, denetciAracSayisi = 0;
		printf("\nSizden arac sayilarini girmeniz istenecek. Bilinmeyen sayi icin -1 girilecek. En az bir tanesi -1 girilmek zorunda.\n\n");

		do {

			if (denetciAracSayisi != 0)
				printf("\n\nHATA!!! En az bir deger -1 girilmeli. Lutfen tekrar giriniz!\n\n");
			denetciAracSayisi++;
			printf("X yolu icin arac sayisini giriniz :");
			scanf_s("%d", &aracX);
			printf("\nY yolu icin arac sayisini giriniz :");
			scanf_s("%d", &aracY);
			printf("\nZ yolu icin arac sayisini giriniz :");
			scanf_s("%d", &aracZ);
			printf("\nT yolu icin arac sayisini giriniz :");
			scanf_s("%d", &aracT);
			printf("\nA yolu icin arac sayisini giriniz :");
			scanf_s("%d", &aracA);
			printf("\nB yolu icin arac sayisini giriniz :");
			scanf_s("%d", &aracB);
			printf("\nC yolu icin arac sayisini giriniz :");
			scanf_s("%d", &aracC);
			printf("\nD yolu icin arac sayisini giriniz :");
			scanf_s("%d", &aracD);
			printf("\nE yolu icin arac sayisini giriniz :");
			scanf_s("%d", &aracE);
		} while (aracX != -1 && aracY != -1 && aracZ != -1 && aracT != -1 && aracA != -1 && aracB != -1 && aracC != -1 && aracD != -1);

		// Matrisin butun degerlerine 0 atıyoruz.
		int i, j;
		for (i = 0; i < 9; i++) {
			for (j = 0; j < 10; j++) {
				matris2[i][j] = 0;

			}
		}

		// Birinci satiri atiyoruz.

		if (yona == 1 && yonb == 1 && giriscikisX == 1) {
			matris2[0][0] = (-1)*aracA;
			matris2[0][1] = aracB;
			matris2[0][5] = aracX;
		}
		if (yona == 1 && yonb == 1 && giriscikisX == 2) {
			matris2[0][0] = aracA;
			matris2[0][1] = (-1)*aracB;
			matris2[0][5] = aracX;
		}
		if (yona == 1 && yonb == 2 && giriscikisX == 1) {
			matris2[0][0] = aracA;
			matris2[0][1] = aracB;
			matris2[0][5] = (-1)*aracX;
		}
		if (yona == 2 && yonb == 1 && giriscikisX == 2) {
			matris2[0][0] = aracA;
			matris2[0][1] = aracB;
			matris2[0][5] = (-1)*aracX;
		}
		if (yona == 2 && yonb == 2 && giriscikisX == 1) {
			matris2[0][0] = aracA;
			matris2[0][1] = (-1)*aracB;
			matris2[0][5] = aracX;
		}
		if (yona == 2 && yonb == 2 && giriscikisX == 2) {
			matris2[0][0] = (-1)*aracA;
			matris2[0][1] = aracB;
			matris2[0][5] = aracX;
		}

		// Ikinci satiri atiyoruz.

		if (yonb == 1 && yond == 1 && yone == 1 && giriscikisY == 1) {
			matris2[1][1] = (-1)*aracB;
			matris2[1][3] = aracD;
			matris2[1][4] = aracE;
			matris2[1][6] = aracY;
		}
		if (yonb == 1 && yond == 1 && yone == 1 && giriscikisY == 2) {
			matris2[1][1] = aracB;
			matris2[1][3] = (-1)*aracD;
			matris2[1][4] = (-1)*aracE;
			matris2[1][6] = aracY;
		}
		if (yonb == 1 && yond == 1 && yone == 2 && giriscikisY == 1) {
			matris2[1][1] = aracB;
			matris2[1][3] = (-1)*aracD;
			matris2[1][4] = aracE;
			matris2[1][6] = (-1)*aracY;
		}
		if (yonb == 1 && yond == 1 && yone == 2 && giriscikisY == 2) {
			matris2[1][1] = aracB;
			matris2[1][3] = (-1)*aracD;
			matris2[1][4] = aracE;
			matris2[1][6] = aracY;
		}
		if (yonb == 1 && yond == 2 && yone == 1 && giriscikisY == 1) {
			matris2[1][1] = aracB;
			matris2[1][3] = aracD;
			matris2[1][4] = (-1)*aracE;
			matris2[1][6] = (-1)*aracY;
		}
		if (yonb == 1 && yond == 2 && yone == 1 && giriscikisY == 2) {
			matris2[1][1] = aracB;
			matris2[1][3] = aracD;
			matris2[1][4] = (-1)*aracE;
			matris2[1][6] = aracY;
		}
		if (yonb == 1 && yond == 2 && yone == 2 && giriscikisY == 1) {
			matris2[1][1] = aracB;
			matris2[1][3] = aracD;
			matris2[1][4] = aracE;
			matris2[1][6] = (-1)*aracY;
		}
		if (yonb == 2 && yond == 1 && yone == 1 && giriscikisY == 2) {
			matris2[1][1] = aracB;
			matris2[1][3] = aracD;
			matris2[1][4] = aracE;
			matris2[1][6] = (-1)*aracY;
		}
		if (yonb == 2 && yond == 1 && yone == 2 && giriscikisY == 1) {
			matris2[1][1] = aracB;
			matris2[1][3] = aracD;
			matris2[1][4] = (-1)*aracE;
			matris2[1][6] = aracY;
		}
		if (yonb == 2 && yond == 1 && yone == 2 && giriscikisY == 2) {
			matris2[1][1] = aracB;
			matris2[1][3] = aracD;
			matris2[1][4] = (-1)*aracE;
			matris2[1][6] = (-1)*aracY;
		}
		if (yonb == 2 && yond == 2 && yone == 1 && giriscikisY == 1) {
			matris2[1][1] = aracB;
			matris2[1][3] = (-1)*aracD;
			matris2[1][4] = aracE;
			matris2[1][6] = aracY;
		}
		if (yonb == 2 && yond == 2 && yone == 1 && giriscikisY == 2) {
			matris2[1][1] = aracB;
			matris2[1][3] = (-1)*aracD;
			matris2[1][4] = aracE;
			matris2[1][6] = (-1)*aracY;
		}
		if (yonb == 2 && yond == 2 && yone == 2 && giriscikisY == 1) {
			matris2[1][1] = aracB;
			matris2[1][3] = (-1)*aracD;
			matris2[1][4] = (-1)*aracE;
			matris2[1][6] = aracY;
		}
		if (yonb == 2 && yond == 2 && yone == 2 && giriscikisY == 2) {
			matris2[1][1] = (-1)*aracB;
			matris2[1][3] = aracD;
			matris2[1][4] = aracE;
			matris2[1][6] = aracY;
		}

		// Ucuncu satiri atiyoruz.

		if (yonc == 1 && yond == 1 && giriscikisZ == 1) {
			matris2[2][2] = aracC;
			matris2[2][3] = (-1)*aracD;
			matris2[2][7] = aracZ;
		}
		if (yonc == 1 && yond == 1 && giriscikisZ == 2) {
			matris2[2][2] = (-1)*aracC;
			matris2[2][3] = aracD;
			matris2[2][7] = aracZ;
		}
		if (yonc == 1 && yond == 2 && giriscikisZ == 2) {
			matris2[2][2] = aracC;
			matris2[2][3] = aracD;
			matris2[2][7] = (-1)*aracZ;
		}
		if (yonc == 2 && yond == 1 && giriscikisZ == 1) {
			matris2[2][2] = aracC;
			matris2[2][3] = aracD;
			matris2[2][7] = (-1)*aracZ;
		}
		if (yonc == 2 && yond == 2 && giriscikisZ == 1) {
			matris2[2][2] = (-1)*aracC;
			matris2[2][3] = aracD;
			matris2[2][7] = aracZ;
		}
		if (yonc == 2 && yond == 2 && giriscikisZ == 2) {
			matris2[2][2] = aracC;
			matris2[2][3] = (-1)*aracD;
			matris2[2][7] = aracZ;
		}

		// Dorduncu satiri atiyoruz.

		if (yona == 1 && yonc == 1 && yone == 1 && giriscikisT == 1) {
			matris2[1][0] = aracA;
			matris2[1][2] = (-1)*aracC;
			matris2[1][4] = (-1)*aracE;
			matris2[1][8] = aracT;
		}
		if (yona == 1 && yonc == 1 && yone == 1 && giriscikisT == 2) {
			matris2[1][0] = (-1)*aracA;
			matris2[1][2] = aracC;
			matris2[1][4] = aracE;
			matris2[1][8] = aracT;
		}
		if (yona == 1 && yonc == 1 && yone == 2 && giriscikisT == 1) {
			matris2[1][0] = aracA;
			matris2[1][2] = (-1)*aracC;
			matris2[1][4] = aracE;
			matris2[1][8] = aracT;
		}
		if (yona == 1 && yonc == 1 && yone == 2 && giriscikisT == 2) {
			matris2[1][0] = aracA;
			matris2[1][2] = (-1)*aracC;
			matris2[1][4] = aracE;
			matris2[1][8] = (-1)*aracT;
		}
		if (yona == 1 && yonc == 2 && yone == 1 && giriscikisT == 1) {
			matris2[1][0] = aracA;
			matris2[1][2] = aracC;
			matris2[1][4] = (-1)*aracE;
			matris2[1][8] = aracT;
		}
		if (yona == 1 && yonc == 2 && yone == 1 && giriscikisT == 2) {
			matris2[1][0] = aracA;
			matris2[1][2] = aracC;
			matris2[1][4] = (-1)*aracE;
			matris2[1][8] = (-1)*aracT;
		}
		if (yona == 1 && yonc == 2 && yone == 2 && giriscikisT == 2) {
			matris2[1][0] = aracA;
			matris2[1][2] = aracC;
			matris2[1][4] = aracE;
			matris2[1][8] = (-1)*aracT;
		}
		if (yona == 2 && yonc == 1 && yone == 1 && giriscikisT == 1) {
			matris2[1][0] = aracA;
			matris2[1][2] = aracC;
			matris2[1][4] = aracE;
			matris2[1][8] = (-1)*aracT;
		}
		if (yona == 2 && yonc == 1 && yone == 2 && giriscikisT == 1) {
			matris2[1][0] = aracA;
			matris2[1][2] = aracC;
			matris2[1][4] = (-1)*aracE;
			matris2[1][8] = (-1)*aracT;
		}
		if (yona == 2 && yonc == 1 && yone == 2 && giriscikisT == 2) {
			matris2[1][0] = aracA;
			matris2[1][2] = aracC;
			matris2[1][4] = (-1)*aracE;
			matris2[1][8] = (-1)*aracT;
		}
		if (yona == 2 && yonc == 2 && yone == 1 && giriscikisT == 1) {
			matris2[1][0] = aracA;
			matris2[1][2] = (-1)*aracC;
			matris2[1][4] = aracE;
			matris2[1][8] = (-1)*aracT;
		}
		if (yona == 2 && yonc == 2 && yone == 1 && giriscikisT == 2) {
			matris2[1][0] = aracA;
			matris2[1][2] = (-1)*aracC;
			matris2[1][4] = aracE;
			matris2[1][8] = aracT;
		}
		if (yona == 2 && yonc == 2 && yone == 2 && giriscikisT == 1) {
			matris2[1][0] = (-1)*aracA;
			matris2[1][2] = aracC;
			matris2[1][4] = aracE;
			matris2[1][8] = aracT;
		}
		if (yona == 2 && yonc == 2 && yone == 2 && giriscikisT == 2) {
			matris2[1][0] = aracA;
			matris2[1][2] = (-1)*aracC;
			matris2[1][4] = (-1)*aracE;
			matris2[1][8] = aracT;
		}

		// Besinci satiri atiyoruz.

		if (giriscikisX == 1 && giriscikisY == 1 && giriscikisZ == 2 && giriscikisT == 2) {
			matris2[4][5] = aracX;
			matris2[4][6] = aracY;
			matris2[4][7] = (-1)*aracZ;
			matris2[4][8] = (-1)*aracT;
		}
		if (giriscikisX == 1 && giriscikisY == 2 && giriscikisZ == 1 && giriscikisT == 2) {
			matris2[4][5] = aracX;
			matris2[4][6] = (-1)*aracY;
			matris2[4][7] = aracZ;
			matris2[4][8] = (-1)*aracT;
		}
		if (giriscikisX == 1 && giriscikisY == 2 && giriscikisZ == 2 && giriscikisT == 1) {
			matris2[4][5] = aracX;
			matris2[4][6] = (-1)*aracY;
			matris2[4][7] = (-1)*aracZ;
			matris2[4][8] = aracT;
		}
		if (giriscikisX == 2 && giriscikisY == 1 && giriscikisZ == 1 && giriscikisT == 2) {
			matris2[4][5] = (-1)*aracX;
			matris2[4][6] = aracY;
			matris2[4][7] = aracZ;
			matris2[4][8] = (-1)*aracT;
		}
		if (giriscikisX == 2 && giriscikisY == 1 && giriscikisZ == 2 && giriscikisT == 1) {
			matris2[4][5] = (-1)*aracX;
			matris2[4][6] = aracY;
			matris2[4][7] = (-1)*aracZ;
			matris2[4][8] = aracT;
		}
		if (giriscikisX == 2 && giriscikisY == 2 && giriscikisZ == 1 && giriscikisT == 1) {
			matris2[4][5] = (-1)*aracX;
			matris2[4][6] = (-1)*aracY;
			matris2[4][7] = aracZ;
			matris2[4][8] = aracT;
		}

		// Matrisi yazdır.
		printf("\n\n");
		printf("Girilen arac sayisina gore olusan matris :\n");
		for (i = 0; i < 9; i++) {
			for (j = 0; j < 9; j++) {
				printf("  %d       ", matris2[i][j]);

			}
			printf("\n\n");
		}
		// Girilen arac sayilarini toplayip saga atiyoruz.

		int toplam = 0;
		for (i = 0; i < 9; i++) {
			for (j = 0; j < 10; j++) {
				if (matris2[i][j] != -1 && matris2[i][j] != 0 && matris2[i][j] != 1) {
					toplam = toplam + matris2[i][j];
					matris2[i][j] = 0;

				}
				if (j == 9) matris2[i][j] = toplam;
			}
			toplam = 0;
		}

		printf("\n\n");
		printf("Eselon form oncesi matrisin son hali :\n");
		for (i = 0; i < 9; i++) {
			for (j = 0; j < 10; j++) {
				printf("  %d       ", matris2[i][j]);

			}
			printf("\n\n");
		}
	}
}

int Fonk()
{
	if (!al_init()) {
		printf("failed to initialize allegro!\n");
		return -1;
	}

	if (!al_init_image_addon()) {
		printf("Failed to initialize al_init_image_addon!");
		return 0;
	}

	if (!al_install_keyboard()) {
		printf("failed to initialize keybord!\n");
		return -1;
	}

	display = al_create_display(1200, 800);

	if (!display) {
		printf("failed to create display!\n");
		return -1;
	}
	//Nesnelerin Yolları
	yol1 = al_load_bitmap("images/yol1.png");
	yol2 = al_load_bitmap("images/yol2.png");
	secim = al_load_bitmap("images/secim.png");
	yon = al_load_bitmap("images/yon.png");
	saat = al_load_bitmap("images/saat.png");
	ters = al_load_bitmap("images/ters.png");
	harf = al_load_bitmap("images/harf.png");
	as = al_load_bitmap("images/as.png");
	bs = al_load_bitmap("images/bs.png");
	cs = al_load_bitmap("images/cs.png");
	ds = al_load_bitmap("images/ds.png");
	at = al_load_bitmap("images/at.png");
	bt = al_load_bitmap("images/bt.png");
	ct = al_load_bitmap("images/ct.png");
	dt = al_load_bitmap("images/dt.png");
	sag = al_load_bitmap("images/sag.png");
	sol = al_load_bitmap("images/sol.png");
	giris = al_load_bitmap("images/giris.png");
	ony = al_load_bitmap("images/ony.png");
	tm = al_load_bitmap("images/tm.png");

	al_set_window_title(display, "Created by ANIL and Saadettin!");
	al_get_keyboard_state(&klavye); //Klavye durumu

	while (!al_key_down(&klavye, ALLEGRO_KEY_ESCAPE))
	{
		al_get_keyboard_state(&klavye);

		al_clear_to_color(al_map_rgb(255, 255, 255)); //Görüntüyü beyaza boyar

		if (yol == 0) {
			al_get_keyboard_state(&klavye);
			if (al_key_down(&klavye, ALLEGRO_KEY_1)) yol = 1;
			if (al_key_down(&klavye, ALLEGRO_KEY_2)) yol = 2;
		}

		if (yol == 1) {
			al_draw_bitmap(yol1, 300, 0, 0);

			if (yona == 0) {
				al_draw_bitmap(yon, 0, 601, 0);
				al_draw_bitmap(harf, 475, 222, 0);
				Okla();
				yona = Onay();
			}
			else if (yonb == 0) {
				al_draw_bitmap(yon, 0, 601, 0);
				al_draw_bitmap(harf, 705, 222, 0);
				Okla();
				yonb = Onay();
			}
			else if (yonc == 0) {
				al_draw_bitmap(yon, 0, 601, 0);
				al_draw_bitmap(harf, 500, 435, 0);
				Okla();
				yonc = Onay();
			}
			else if (yond == 0) {
				al_draw_bitmap(yon, 0, 601, 0);
				al_draw_bitmap(harf, 685, 432, 0);
				Okla();
				yond = Onay();
			}
			else if (sec == 0) {
				Yon();
			}
			else if (sec = !0) {
				if (sec == 1) {
					giriscikisX = 1;
					giriscikisY = 1;
				}
				else if (sec == 2) {
					giriscikisX = 1;
					giriscikisZ = 1;
				}
				else if (sec == 3) {
					giriscikisX = 1;
					giriscikisT = 1;
				}
				else if (sec == 4) {
					giriscikisY = 1;
					giriscikisZ = 1;
				}
				else if (sec == 5) {
					giriscikisY = 1;
					giriscikisT = 1;
				}
				else if (sec == 6) {
					giriscikisZ = 1;
					giriscikisT = 1;
				}
				break;
			}
		}
		
		else if (yol == 2) {
			al_draw_bitmap(yol2, 300, 0, 0);

			if (yona == 0) {
				al_draw_bitmap(yon, 0, 601, 0);
				Okla();
				yona = Onay();
				al_draw_bitmap(harf, 470, 200, 0);
			}
			else if (yonb == 0) {
				al_draw_bitmap(yon, 0, 601, 0);
				Okla();
				yonb = Onay();
				al_draw_bitmap(harf, 700, 205, 0);
			}
			else if (yonc == 0) {
				al_draw_bitmap(yon, 0, 601, 0);
				Okla();
				yonc = Onay();
				al_draw_bitmap(harf, 495, 420, 0);
			}
			else if (yond == 0) {
				al_draw_bitmap(yon, 0, 601, 0);
				Okla();
				yond = Onay();
				al_draw_bitmap(harf, 685, 420, 0);
			}
			else if (yone == 0) {
				al_draw_bitmap(yon, 0, 601, 0);
				Okla();
				yone = Onay();
				al_draw_bitmap(harf, 580, 305, 0);
			}
			else if (sec == 0) {
				Yon();
			}
			else if (sec = !0) {
				if (sec == 1) {
					giriscikisX = 1;
					giriscikisY = 1;
				}
				else if (sec == 2) {
					giriscikisX = 1;
					giriscikisZ = 1;
				}
				else if (sec == 3) {
					giriscikisX = 1;
					giriscikisT = 1;
				}
				else if (sec == 4) {
					giriscikisY = 1;
					giriscikisZ = 1;
				}
				else if (sec == 5) {
					giriscikisY = 1;
					giriscikisT = 1;
				}
				else if (sec == 6) {
					giriscikisZ = 1;
					giriscikisT = 1;
				}
				break;
			} 
		}
		else {
			al_draw_bitmap(yol1, 0, 0, 0);
			al_draw_bitmap(yol2, 600, 5, 0);
			al_draw_bitmap(secim, 0, 601, 0);
		}

		Okla();

		al_flip_display();

	}
	al_draw_bitmap(tm, 0, 601, 0);
	Okla();
    al_flip_display();
	al_rest(2.0);
	al_destroy_display(display);

	return 0;
}

void Yon() { //Giris-Çıkış seçimini yapan fonksiyon
	al_draw_bitmap(giris, 0, 601, 0);
	Okla();
	al_flip_display;
		
	if (al_key_down(&klavye, ALLEGRO_KEY_1)) {

		al_draw_bitmap(ony, 0, 601, 0);
		Okla();
		al_flip_display();

		while (1) {

			al_get_keyboard_state(&klavye);

			if (al_key_down(&klavye, ALLEGRO_KEY_ENTER))
			{
				sec = 1; break;
			}
			else if (al_key_down(&klavye, ALLEGRO_KEY_ESCAPE))
				break;
		}
	}
	else if (al_key_down(&klavye, ALLEGRO_KEY_2)) {

		al_draw_bitmap(ony, 0, 601, 0);
		Okla();
		al_flip_display();

		while (1) {

			al_get_keyboard_state(&klavye);

			if (al_key_down(&klavye, ALLEGRO_KEY_ENTER))
			{
				sec = 2; break;
			}
			else if (al_key_down(&klavye, ALLEGRO_KEY_ESCAPE))
			{
				break;
			}
		}
	}
	else if (al_key_down(&klavye, ALLEGRO_KEY_3)) {

		al_draw_bitmap(ony, 0, 601, 0);
		Okla();
		al_flip_display();

		while (1) {

			al_get_keyboard_state(&klavye);

			if (al_key_down(&klavye, ALLEGRO_KEY_ENTER))
			{
				sec = 3; break;
			}
			else if (al_key_down(&klavye, ALLEGRO_KEY_ESCAPE))
			{
				break;
			}
		}
	}
	else if (al_key_down(&klavye, ALLEGRO_KEY_4)) {

		al_draw_bitmap(ony, 0, 601, 0);
		Okla();
		al_flip_display();

		while (1) {

			al_get_keyboard_state(&klavye);

			if (al_key_down(&klavye, ALLEGRO_KEY_ENTER))
			{
				sec = 4; break;
			}
			else if (al_key_down(&klavye, ALLEGRO_KEY_ESCAPE))
			{
				break;
			}
		}
	}
	else if (al_key_down(&klavye, ALLEGRO_KEY_5)) {

		al_draw_bitmap(ony, 0, 601, 0);
		Okla();
		al_flip_display();

		while (1) {

			al_get_keyboard_state(&klavye);

			if (al_key_down(&klavye, ALLEGRO_KEY_ENTER))
			{
				sec = 5; break;
			}
			else if (al_key_down(&klavye, ALLEGRO_KEY_ESCAPE))
			{
				break;
			}
		}
	}
	else if (al_key_down(&klavye, ALLEGRO_KEY_6)) {

		al_draw_bitmap(ony, 0, 601, 0);
		Okla();
		al_flip_display();

		while (1) {

			al_get_keyboard_state(&klavye);

			if (al_key_down(&klavye, ALLEGRO_KEY_ENTER))
			{
					sec = 6; break;
			}
			else if (al_key_down(&klavye, ALLEGRO_KEY_ESCAPE))
			{
				break;
			}
		}
	}
}

int Onay() { //Yön seçimini yapan fonksiyon
	if (al_key_down(&klavye, ALLEGRO_KEY_S)) {

		al_draw_bitmap(saat, 0, 601, 0);
		Okla();
		al_flip_display();

		while (1) {

			al_get_keyboard_state(&klavye);

			if (al_key_down(&klavye, ALLEGRO_KEY_ENTER))
			{
				return 2;
			}
			else if (al_key_down(&klavye, ALLEGRO_KEY_R))
			{
				return 1;
			}
			else if (al_key_down(&klavye, ALLEGRO_KEY_ESCAPE))
				break;
		}
	}

	if (al_key_down(&klavye, ALLEGRO_KEY_T)) {

		al_draw_bitmap(ters, 0, 601, 0);
		Okla();
		al_flip_display();

		while (1) {

			al_get_keyboard_state(&klavye);

			if (al_key_down(&klavye, ALLEGRO_KEY_ENTER))
			{
				return 1;
			}
			else if (al_key_down(&klavye, ALLEGRO_KEY_R))
			{
				return 2;
			}
			else if (al_key_down(&klavye, ALLEGRO_KEY_ESCAPE))
			{
				break;
			}
		}
	}
}

void Okla() { //Okları çizen fonksiyon
	if (yona == 2)
	{
		al_draw_bitmap(as, 350, 50, 0);
	}
	else if (yona == 1)
	{
		al_draw_bitmap(at, 350, 50, 0);
	}

	if (yonb == 2)
	{
		al_draw_bitmap(bs, 750, 50, 0);
	}
	else if (yonb == 1)
	{
		al_draw_bitmap(bt, 750, 50, 0);
	}

	if (yonc == 2) {
		al_draw_bitmap(cs, 350, 450, 0);
	}
	else if (yonc == 1)
	{
		al_draw_bitmap(ct, 350, 450, 0);
	}

	if (yond == 2)
	{
		al_draw_bitmap(ds, 750, 450, 0);
	}
	else if (yond == 1)
	{
		al_draw_bitmap(dt, 750, 450, 0);
	}
	
	if (yone == 2)
	{
		al_draw_bitmap(sag, 565, 200, 0);
	}
	else if (yone == 1)
	{
		al_draw_bitmap(sol, 565, 340, 0);
	}
}

// Programı çalıştır: Ctrl + F5 veya Hata Ayıkla > Hata Ayıklamadan Başlat menüsü
// Programda hata ayıkla: F5 veya Hata Ayıkla > Hata Ayıklamayı Başlat menüsü

// Kullanmaya Başlama İpuçları: 
//   1. Dosyaları eklemek/yönetmek için Çözüm Gezgini penceresini kullanın
//   2. Kaynak denetimine bağlanmak için Takım Gezgini penceresini kullanın
//   3. Derleme çıktısını ve diğer iletileri görmek için Çıktı penceresini kullanın
//   4. Hataları görüntülemek için Hata Listesi penceresini kullanın
//   5. Yeni kod dosyaları oluşturmak için Projeye Git > Yeni Öğe ekle veya varolan kod dosyalarını projeye eklemek için Proje > Var Olan Öğeyi Ekle adımlarını izleyin
//   6. Bu projeyi daha sonra yeniden açmak için Dosya > Aç > Proje'ye gidip .sln uzantılı dosyayı seçin
