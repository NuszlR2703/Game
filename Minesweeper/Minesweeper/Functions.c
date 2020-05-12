#include "Functions.h"

matrix Create1(){
	matrix m;
	for (int i = 0; i < 12; ++i) {
		for (int j = 0; j < 12; ++j) {
			m.mat[i][j] = 'O';
		}
	}
	int k = 100;
	return m;
}
matrix Create2(int nehezseg) {
	matrix m;
	int k = 100;
	for (int i = 0; i < 12; ++i) {
		for (int j = 0; j < 12; ++j) {
			m.mat[i][j] = 'O';
		}
	}
	srand(time(NULL));
	int s, o, z;
	m.ossz = 0;
	int rossz;
	for (int i = 1; i <= nehezseg;++i) {
		rossz = 0;
		s = 2 + rand() % 8;
		o = 2 + rand() % 8;
		if (m.mat[s][o] == 'O') {
			m.mat[s][o] = 'B';
		}
		else {
			rossz = 1;
			while(rossz) {
				s = 2 + rand() % 8;
				o = 2 + rand() % 8;
				if (m.mat[s][o]=='O') {
					m.mat[s][o] = 'B';
					rossz = 0;
				}
			}
		}
		++m.ossz;
	}
	return m;
}

matrix Jeloles(matrix palya, matrix hatter, char l[2]) {
	int j = l[0] - 16 - 47;
	int i = l[1] - 47;
	char sz;
	palya.mat[i][j] = 'I';
	if (hatter.mat[i][j]=='B') {
		--palya.ossz;
	}
	return palya;
}
matrix Tippelos(matrix palya, matrix hatter, char l[2]){
	int j = l[0]-16-47;
	int i = l[1]-47;
	char sz;
	
	if (hatter.mat[i][j] == 'B') {
		gameover();
	}
	else {
		sz = 48;
		if (hatter.mat[i - 1][j - 1] == 'B') {
			++sz;
		}
		if (hatter.mat[i - 1][j] == 'B') {
			++sz;
		}
		if (hatter.mat[i - 1][j + 1] == 'B') {
			++sz;
		}
		if (hatter.mat[i][j - 1] == 'B') {
			++sz;
		}
		if (hatter.mat[i][j + 1] == 'B') {
			++sz;
		}
		if (hatter.mat[i + 1][j - 1] == 'B') {
			++sz;
		}
		if (hatter.mat[i + 1][j] == 'B') {
			++sz;
		}
		if (hatter.mat[i + 1][j + 1] == 'B') {
			++sz;
		}
		if (sz > 48) {
			palya.mat[i][j] = sz;
		}
		else {
			palya.mat[i][j] = '0';

			sz = 48;
			if (hatter.mat[i][j - 2] == 'B') {
				++sz;
			}
			if (hatter.mat[i - 1][j - 2] == 'B') {
				++sz;
			}
			if (hatter.mat[i - 2][j - 2] == 'B') {
				++sz;
			}
			if (hatter.mat[i - 2][j - 1] == 'B') {
				++sz;
			}
			if (hatter.mat[i - 2][j] == 'B') {
				++sz;
			}
			palya.mat[i - 1][j - 1] = sz;

			sz = 48;
			if (hatter.mat[i - 2][j - 1] == 'B') {
				++sz;
			}
			if (hatter.mat[i - 2][j] == 'B') {
				++sz;
			}
			if (hatter.mat[i - 2][j + 1] == 'B') {
				++sz;
			}
			palya.mat[i - 1][j] = sz;


			sz = 48;
			if (hatter.mat[i - 2][j] == -'B') {
				++sz;
			}
			if (hatter.mat[i - 2][j + 1] == 'B') {
				++sz;
			}
			if (hatter.mat[i - 2][j + 2] == 'B') {
				++sz;
			}
			if (hatter.mat[i - 1][j + 2] == 'B') {
				++sz;
			}
			if (hatter.mat[i][j + 2] == 'B') {
				++sz;
			}
			palya.mat[i - 1][j + 1] = sz;

			sz = 48;
			if (hatter.mat[i - 1][j + 2] == 'B') {
				++sz;
			}
			if (hatter.mat[i][j + 2] == 'B') {
				++sz;
			}
			if (hatter.mat[i + 1][j + 2] == 'B') {
				++sz;
			}
			palya.mat[i][j + 1] = sz;

			sz = 48;
			if (hatter.mat[i - 1][j - 2] == 'B') {
				++sz;
			}
			if (hatter.mat[i][j - 2] == 'B') {
				++sz;
			}
			if (hatter.mat[i + 1][j - 2] == 'B') {
				++sz;
			}
			palya.mat[i][j - 1] = sz;

			sz = 48;
			if (hatter.mat[i][j - 2] == 'B') {
				++sz;
			}
			if (hatter.mat[i + 1][j - 2] == 'B') {
				++sz;
			}
			if (hatter.mat[i + 2][j - 2] == 'B') {
				++sz;
			}
			if (hatter.mat[i + 2][j - 1] == 'B') {
				++sz;
			}
			if (hatter.mat[i + 2][j] == 'B') {
				++sz;
			}
			palya.mat[i + 1][j - 1] = sz;

			sz = 48;
			if (hatter.mat[i + 2][j - 1] == 'B') {
				++sz;
			}
			if (hatter.mat[i + 2][j] == 'B') {
				++sz;
			}
			if (hatter.mat[i + 2][j + 1] == 'B') {
				++sz;
			}
			palya.mat[i + 1][j] = sz;

			sz = 48;
			if (hatter.mat[i][j + 2] == 'B') {
				++sz;
			}
			if (hatter.mat[i + 1][j + 2] == 'B') {
				++sz;
			}
			if (hatter.mat[i + 2][j + 2] == 'B') {
				++sz;
			}
			if (hatter.mat[i + 2][j + 1] == 'B') {
				++sz;
			}
			if (hatter.mat[i + 2][j] == 'B') {
				++sz;
			}
			palya.mat[i + 1][j + 1] = sz;
		}
	}
	return palya;
}

void Print(matrix m) {
	clrscr();
	red();
	printf("Megmaradt aknak szama: %d\n\n     ", m.ossz);
	cyan();
	for (char i = 'A'; i < 'I'; ++i) {
		printf("|%c| ",i);
	}
	printf("\n\n");
	for (int i = 2; i < 10; ++i) {
		cyan();
		printf("|%d| ",i-1);
		reset();
		for (int j = 2; j < 10; ++j) {
			if (m.mat[i][j] == 'O') {
				magenta();
				printf(" %c%c ", 219,219);
			}
			else if (m.mat[i][j] == 'I') {
				cyan();
				printf(" %c%c ", 219, 219);
			}
			else {
				red();
				printf(" %c  ",m.mat[i][j]);
			}
		}
		printf("\n\n");
	}
}

void clrscr(){
	system("@cls||clear");
}
void red() {
	printf("\033[1;31m");
}

void yellow(){
  printf("\033[1;33m");
}
void cyan() {
	printf("\033[0;36m");
}

void green(){
	printf("\033[0;32m");
}

void magenta(){
	printf("\033[0;35m");
}

void boldmagenta(){
	printf("\033[1;35m");
}

void boldgreen(){
	printf("\033[0;32m");
}

void reset() {
	printf("\033[0m");
}

void kezdokepernyo(){
	cimkiir();
	printf("\n\n\n");
	printf("Szabalyok!\n");
	reset();
	printf("A 8 * 8 as palyan talalhato 10 darab akna.Ezek helye rejtett eloled, de ne aggodj\n van lehetoseged tulelni.Ha odafigyelsz akkor konnyen gyozhetsz!\n");
	printf("Minden korben van lehetoseged donteni hogy mit akarsz csinalni: \n		");
	printf("	1- Kiprobalni egy mezot, hogy akna van e rajta\n		");
	printf("	2- Zaszlocskaval megjelolni egy mezot\n		");
	printf("Fontos tudni, hogy melyik jeloles mit jeent: \n		");
	printf("A 'O' -val jelolt helyen ismeretlen mezo van\n		");
	printf("A 'I' -vel jelolt helyen ismeretlen mezo van\n		");
	printf("0- tol 8 ig a szamjegyek azt muatjak, hogy a mezo kozvetlen kozeleben hany akna talalhato\n");
	green();
	printf("	Akkor nyersz, ha megtalalod az osszes SZABAD MEZOT!\n\n");
	red();
	char v;
	reset();
	printf("			PLEASE INSERT OPTION:\n  ");
	reset();
	printf("			-->");
	green();
	printf("PRESS ANY KEY TO START\n  ");
	reset();
	printf("			-->");
	red();
	printf("<ESC> TO  QUIT\n				");
	v = getch();
	if (v == '\x1b') {
		exit(0);
	}
	return 0;
}
void gameover() {
	clrscr();
	for (int i = 0; i < 50; ++i) {
		overkiir();
		clrscr();
	}
	printf("Press Any Key to Continue\n");
	getchar();
	exit(0);
	return 0;
}
void congratuation() {
	clrscr();
	green();
	printf("						YOU");
	magenta();
	printf("W");
	cyan();
	printf("IN\n");
	printf("Press Any Key to Continue\n");
	getchar();
	exit(0);
	return 0;
}
void cimkiir(){
	FILE* fin;
	fin = fopen("cim.txt", "r");
	if (!fin){
		printf("HIBA");
		return 1;
	}
	int i;
	char cim[500];
	srand(time(NULL));
	i = rand() % 4+1;
	switch (i) {
		case 1: {
			green();
			break;
		}
		case 2: {
			cyan();
			break;
		}
		case 3: {
			red();
			break;
		}
		case 4: {
			magenta();
			break;
		}
		default: {
			break;
		}
	}
	while (fscanf(fin, "%[^\n]\n", &cim) != EOF){
		printf("\t  %s\n", cim);
	}
	fclose(fin);
	reset();
}
void overkiir() {
	FILE* fin;
	fin = fopen("gmvr.txt", "r");
	if (!fin) {
		printf("HIBA");
		return 1;
	}
	int i;
	char cim[500];
	srand(time(NULL));
	i = rand() % 4 + 1;
	switch (i) {
		case 1: {
			green();
			break;
		}
		case 2: {
			cyan();
			break;
		}
		case 3: {
			red();
			break;
		}
		case 4: {
			magenta();
			break;
		}
		default: {
			break;
		}
	}
	while (fscanf(fin, "%[^\n]\n", &cim) != EOF) {
		printf("\t  %s\n", cim);
	}
	reset();
}
matrix szintvalaszto(){
	char v;
	do {
		printf("\n	Milyen szinten szeretnel jatszani a jatekkal?\n");
		green();
		printf("		EASY()");
		reset();
		printf("   MEDIUM(M)");
		red();
		printf("   HARD(H)");
		reset();
		v = getch();
		printf("\n");
		if (v == 'E') {
			return Create2(6);
		}
		else if (v == 'M') {
			return Create2(10);
		}
		else if (v == 'H') {
			return Create2(20);
		}
	} while (v != 'E' && v != 'M' && v != 'H');
}
void kor(matrix palya, matrix hatter, int szint) {
	int sz, szamlalo;
	char l[2];
	szamlalo = 0;
	char v;
	for (int z = 0;; z++) {
		printf("\n");
		szamlalo = 0;
		if (szamlalo == 64-hatter.ossz) {
			congratuation();
			break;
		}
		do {
			reset();
			printf("	Mit szeretnel csinalni?\n");
			red();
			printf("1. Raprobalni		");
			cyan();
			printf("2. Megjelolni\n\n");
			printf("                 ");
			green();
			v = getch();
			printf("\n");
			if (v == '1') {
				printf("	     Raprobalas\n");
				reset();
				printf("	Melyik mezot valasztod?\n	     (BETU+SZAM)\n");
				printf("                 ");
				green();
				scanf("%s", l);
				reset();
				palya = Tippelos(palya, hatter, l);
				Print(palya);
			}
			if (v == '2') {
				printf("	     Megjeloles\n");
				reset();
				printf("	Melyik mezot valasztod?\n	     (BETU+SZAM)\n");
				printf("                 ");
				green();
				scanf("%s", &l);
				reset();
				palya = Jeloles(palya, hatter, l);
				Print(palya);
			}
			else {
				clrscr();
				Print(palya);
			}
		} while (v != '1' && v != '2');

		for (int i = 2; i < 10; ++i) {
			for (int j = 2; j < 10; ++j) {
				if (palya.mat[i][j] >= 0 && palya.mat[i][j] < 9) {
					szamlalo++;
				}
			}
		}
	}
}