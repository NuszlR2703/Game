#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include <windows.h>

int nyelv; //ebben taroljuk a nyelv valasztast
// matrix struktura (palya)

typedef struct matrix {
	char** mat;
	int ossz;
	int meret;
} matrix;

//jatek palya osszefogo
typedef struct jatekpalya {
	matrix palya;
	matrix hatter;
} jatekpalya;

//a szintvalasztas angolul tortenik
jatekpalya szintvalasztoangol();
//a szintvalasztas magyarul tortenik
jatekpalya szintvalasztomagyar();

//letrehozza a lathato palyat
matrix Create1(int x, int y);
//letrehozza a hatterben jatszodo palyat(ez felelos gyakorlatilag a jatekmechanikaert)
matrix Create2(int x, int y, int nehezseg);

//beolvassa es kiirja a cimet
void cimkiir();
//ha angol nyelvet valasztott a jatekos ez felel a jatekmenetert
void korangol(matrix palya, matrix hatter);
//ha magyar nyelvet valasztott a jatekos ez felel a jatekmenetert
void kormagyar(matrix palya, matrix hatter);
//kiirja a lathato palyat, illetve azt, hogy hany akna maradt meg a palyan

void Print(matrix m);

//ez az alprogram felelos azert, hogy a jeloles megtortenjen (kekre teszi a mezot amit kivalsztunk, es ha aknat rejt, akkor csokkenti az aknak szamat)
matrix Jeloles(matrix palya, matrix hatter,char l[3]);
//ez az alprogram felelos azert, hogy a raprobalas megtortenjen
matrix Tippelos(matrix palya, matrix hatter,char l[3]);

//letorli a kepernyot
void clrscr();

//kesleltetes (mikor a jatekos veszit, mielott bejon a vesztettel felirat, evvel kesleltetem a kepernyo torlest)
void delay(int sec);

//piros
void red();
//sarga
void yellow();
//cyan kek
void cyan();
//zold
void green();
//lilas rozsaszin
void magenta();
//sotet rozsaszin
void boldmagenta();
//sotetzold
void boldgreen();
//feher
void reset();

//ezzel kezdodik a jatek es itt valasztjuk ki a nyelvet
void kezdokepernyo();
//evvel valasztjuk az angol nyelvet es irjuk ki a szabalyzatot angolul
void angol();
//evvel valasztjuk a magyar nyelvet es irjuk ki a szabalyzatot magyarul
void magyar();

//vesztes jatek eseten jon be
void gameover();
//nyertes jatek eseten jon be
void congratuation();
//ez olvassa be majd irja ki a vesztettel feliratot
void overkiir();
//ez olvassa be majd irja ki a nyertel feliratot
void congratkiir();
#endif