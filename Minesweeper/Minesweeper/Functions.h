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

typedef struct matrix {
	char mat[12][12];
	int ossz;
} matrix;

matrix Create1();
matrix Create2(int nehezseg);

void Print(matrix m);
matrix Jeloles(matrix palya, matrix hatter);
matrix Tippelos(matrix palya, matrix hatter,char l[2]);
void clrscr();
void red();
void yellow();
void cyan();
void green();
void magenta();
void boldmagenta();
void boldgreen();
void reset();
void kezdokepernyo();
void gameover();
void congratuation();
void cimkiir();
void overkiir();
void kor(matrix palya, matrix hatter);
matrix szintvalaszto();
#endif