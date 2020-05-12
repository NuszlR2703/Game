#include "Functions.h"

int main() {
	kezdokepernyo();
	jatekpalya P = szintvalaszto();
	P.palya.ossz = P.hatter.ossz;
	Print(P.palya);
	printf("\n\n");
	kor(P.palya,P.hatter);
	return 0;
}