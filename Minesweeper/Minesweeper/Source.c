#include "Functions.h"

int main() {
	kezdokepernyo();
	if (nyelv==0) {
		jatekpalya P = szintvalasztoangol();
		P.palya.ossz = P.hatter.ossz;
		Print(P.palya);
		printf("\n\n");
		korangol(P.palya, P.hatter);
	}
	else if (nyelv==1){
		jatekpalya P = szintvalasztomagyar();
		P.palya.ossz = P.hatter.ossz;
		Print(P.palya);
		printf("\n\n");
		kormagyar(P.palya, P.hatter);
	}
	return 0;
}