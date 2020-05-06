#include "Functions.h"

int main() {
	kezdokepernyo();
	matrix palya = Create1();
	matrix hatter = Create2();
	palya.ossz = hatter.ossz;
	Print(palya);
	printf("\n\n");
	int  v, sz, szamlalo;
	char l[2];
	szamlalo = 0;
	for (int z = 0;;z++) {
		printf("\n\n");
		szamlalo = 0;
		if (szamlalo == 54) {
			congratuation();
			break;
		}
		reset();
		printf("			Mit szeretnel csinalni?\n");
		red();
		printf("	1. Raprobalni			");
		cyan();
		printf("	2. Megjelolni\n				  \n				  ");
		green();
		scanf("%d",&v);
		switch (v) {
			case 1: {
				reset();
				printf("			Melyik mezot valasztod? \n			    (BETU+SZAM)\n				");
				green();
				scanf("%s", l);
				reset();
				palya = Tippelos(palya,hatter,l);
				Print(palya);
				break;
			}
			case 2: {
				reset();
				printf("			Melyik mezot valasztod? \n			    (BETU+SZAM)\n				");
				green();
				scanf("%s", &l);
				reset();
				palya=Jeloles(palya,hatter,l);
				Print(palya);
				break;
			}
		}
		for (int i = 2; i < 10;++i) {
			for (int j = 2; j < 10; ++j) {
				if (palya.mat[i][j]>=0 && palya.mat[i][j] < 9) {
					szamlalo++;
				}
			}
		}
	}
	return 0;
}