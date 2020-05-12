#include "Functions.h"

int main() {
	kezdokepernyo();
	
	matrix palya = Create1();
	matrix hatter = szintvalaszto();
	palya.ossz = hatter.ossz;
	Print(palya);
	printf("\n\n");
	kor(palya,hatter);
	return 0;
}