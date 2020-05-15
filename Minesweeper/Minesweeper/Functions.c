#include "Functions.h"

jatekpalya szintvalasztoangol() {
	jatekpalya aux;
	char v;
	do {
		printf("\n	Choose a difficulty level!\n");
		green();
		printf("		EASY()");
		reset();
		printf("   MEDIUM(M)");
		red();
		printf("   HARD(H)");
		reset();
		printf("\n			    ");
		v = getch();
		if (v == 'E') {
			aux.hatter = Create2(8, 8, 10);
			aux.palya = Create1(8, 8);
		}
		else if (v == 'M') {
			aux.hatter = Create2(16, 16, 40);
			aux.palya = Create1(16, 16);
		}
		else if (v == 'H') {
			aux.hatter = Create2(25, 25, 60);
			aux.palya = Create1(25, 25);
		}
	} while (v != 'E' && v != 'M' && v != 'H');
	return aux;
}

jatekpalya szintvalasztomagyar() {
	jatekpalya aux;
	char v;
	do {
		printf("\n Valassz nehezsegi szintet!\n");
		green();
		printf("	  EGYSZERU(E)");
		reset();
		printf("   KOZEPES(K)");
		red();
		printf("   NEHEZ(N)");
		reset();
		printf("\n			    ");
		v = getch();
		if (v == 'E') {
			aux.hatter = Create2(8, 8, 10);
			aux.palya = Create1(8, 8);
		}
		else if (v == 'K') {
			aux.hatter = Create2(16, 16, 40);
			aux.palya = Create1(16, 16);
		}
		else if (v == 'N') {
			aux.hatter = Create2(25, 25, 60);
			aux.palya = Create1(25, 25);
		}
	} while (v != 'E' && v != 'K' && v != 'N');
	return aux;
}

matrix Create1(int x, int y){
	matrix m;
	m.mat = (char**)malloc(x+2*sizeof(char*));
	for (int i = 0; i < x + 2; ++i) {
		m.mat[i] = (char*)malloc(x + 2 * sizeof(char));
	}
	m.meret = x+2;
	x += 2;
	y += 2;
	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < y; ++j) {
			m.mat[i][j] = 'O';
		}
	}
	return m;
}

matrix Create2(int x, int y, int nehezseg) {
	matrix m;
	m.mat = (char**)malloc(x + 2 * sizeof(char*));
	for (int i = 0; i < x + 2; ++i) {
		m.mat[i] = (char*)malloc(x + 2 * sizeof(char));
	}
	m.meret = x;
	x += 2;
	y += 2;
	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < y; ++j) {
			m.mat[i][j] = 'O';
		}
	}
	srand(time(NULL));
	int s, o, z;
	m.ossz = 0;
	int rossz;
	for (int i = 1; i <= nehezseg; ++i) {
		rossz = 0;
		s = 2 + rand() % m.meret;
		o = 2 + rand() % m.meret;
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

void cimkiir() {
	FILE* fin;
	fin = fopen("cim.txt", "r");
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
		printf("			%s\n", cim);
	}
	fclose(fin);
	reset();
}

void korangol(matrix palya, matrix hatter, int szint) {
	int sz, szamlalo;
	char l[3];
	szamlalo = 0;
	char v;
	for (int z = 0;; z++) {
		printf("\n");
		szamlalo = 0;
		if (szamlalo == (palya.meret - 2) * (palya.meret - 2) - hatter.ossz) {
			congratuation();
			break;
		}
		do {
			reset();
			printf("	WHAT DO YOU WANT TO DO?\n");
			red();
			printf("1. TRY				");
			cyan();
			printf("2. MARK\n\n");
			printf("                 ");
			green();
			v = getch();
			printf("\n");
			if (v == '1') {
				printf("		  TRY\n");
				reset();
				printf("	WHICH FIELD DO YOU CHOOSE?\n	     (LETTER+NUMBER)\n");
				printf("                 ");
				green();
				scanf("%s", l);
				reset();
				palya = Tippelos(palya, hatter, l);
				Print(palya);
			}
			if (v == '2') {
				printf("	       MARK\n");
				reset();
				printf("	WHICH FIELD DO YOU CHOOSE?\n	     (LETTER+NUMBER)\n");
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

		for (int i = 2; i < palya.meret; ++i) {
			for (int j = 2; j < palya.meret; ++j) {
				if (palya.mat[i][j] >= 48 && palya.mat[i][j] < 57) {
					szamlalo++;
				}
			}
		}
	}
}

void kormagyar(matrix palya, matrix hatter, int szint) {
	int sz, szamlalo;
	char l[3];
	szamlalo = 0;
	char v;
	for (int z = 0;; z++) {
		printf("\n");
		szamlalo = 0;
		if (szamlalo == (palya.meret - 2) * (palya.meret - 2) - hatter.ossz) {
			congratuation();
			break;
		}
		do {
			reset();
			printf("	Mit szeretnel csinalni?\n");
			red();
			printf("1. RAPROBALNI		");
			cyan();
			printf("2. MEGJELOLNI\n\n");
			printf("                 ");
			green();
			v = getch();
			printf("\n");
			if (v == '1') {
				printf("	     RAPROBALAS\n");
				reset();
				printf("	MELYIK MEZOT VALASZTOD?\n	     (BETU+SZAM)\n");
				printf("                 ");
				green();
				scanf("%s", l);
				reset();
				palya = Tippelos(palya, hatter, l);
				Print(palya);
			}
			if (v == '2') {
				printf("	     MEGJELOLES\n");
				reset();
				printf("	MELYIK MEZOT VALASZTOD?\n	     (BETU+SZAM)\n");
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
		for (int i = 2; i < palya.meret; ++i) {
			for (int j = 2; j < palya.meret; ++j) {
				if (palya.mat[i][j] >= 48 && palya.mat[i][j] < 57) {
					szamlalo++;
				}
			}
		}
	}
}

void Print(matrix m) {
	clrscr();
	red();
	if (nyelv == 0) {
		printf("Number of bombs remaining: %d\n\n     ", m.ossz);
	}
	else {
		printf("Megmaradt aknak szama: %d\n\n     ", m.ossz);
	}
	cyan();
	if (m.meret == 10) {
		for (char i = 'A'; i < 'I'; ++i) {
			printf("|%c| ", i);
		}
	}
	else if (m.meret == 18) {
		for (char i = 'A'; i < 'Q'; ++i) {
			printf("|%c| ", i);
		}
	}
	else if (m.meret == 27) {
		for (char i = 'A'; i < 'Z'; ++i) {
			printf("|%c| ", i);
		}
	}
	printf("\n\n");
	for (int i = 2; i < m.meret; ++i) {
		cyan();
		if (i - 1 < 10) {
			printf("|%d|  ", i - 1);
		}
		else {
			printf("|%d| ", i - 1);
		}
		reset();
		for (int j = 2; j < m.meret; ++j) {
			if (m.mat[i][j] == 'O') {
				reset();
				printf(" %c%c ", 219, 219);
			}
			else if (m.mat[i][j] == 'I') {
				cyan();
				printf(" %c%c ", 219, 219);
			}
			else if (m.mat[i][j] == 'B') {
				red();
				printf(" %c  ", m.mat[i][j]);
			}
			else {
				green();
				printf(" %c  ", m.mat[i][j]);
			}
		}
		printf("\n\n");
	}
}

matrix Jeloles(matrix palya, matrix hatter, char l[23]) {
	int s1 = 0;
	int s2 = 0;
	int j = l[0] - 16 - 47;
	s1 = l[1] - 48;
	s2 = l[2] - 48;
	int i;
	if (s2 < 0) {
		i = s1 + 1;
	}
	else {
		i = s1 * 10 + s2 + 1;
	}
	printf("%d", i);
	char sz;
	palya.mat[i][j] = 'I';
	if (hatter.mat[i][j]=='B') {
		--palya.ossz;
	}
	return palya;
}

matrix Tippelos(matrix palya, matrix hatter, char l[3]){
	int s1 = 0;
	int s2 = 0;
	int j = l[0]-16-47;
    s1 = l[1] - 48;
	s2 = l[2] - 48;
	int i;
	if (s2<0) {
		i = s1+1;
	}
	else {
		i = s1 * 10 + s2+1;
	}
	char sz;
	if (hatter.mat[i][j] == 'B') {
		palya.mat[i][j] = 'B';
		Print(palya);
		delay(3);
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

void clrscr() {
	system("@cls||clear");
}

void delay(int sec){ 
	int milli_seconds = 1000 * sec;
	clock_t start_time = clock(); 
	while (clock() < start_time + milli_seconds);
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
	red();
	printf("			ENGLISH (E)					MAGYAR (M)\n\n							");
	char v;
	v = getch();
	if ((v == 'E') || (v=='e')) {
		nyelv = 0;
		angol();
	}
	else if ((v == 'M') || (v == 'm')) {
		nyelv = 1;
		magyar();
	}
	return 0;
}

void angol() {
	clrscr();
	cimkiir();
	printf("\n\nRULES!\n\n");
	yellow();
	printf("PRESS THE CAPS LOCK FOR BETTER PLAY QUALITY!\n\n");
	reset();
	printf("This game has three levels! EASY, MEDIUM, HARD\n");
	printf("There are 10 mines on the EASY, 40 on the MEDIUM and 60 on the HARD level.\n");
	printf("You can choose what do you want to do (TRY OR MARK).\n	");
	printf("If you choose TRY, you can choose a field. If the field hide a mine, you loose and the game ends,\n	  else if there are bombs around the field it shows how many there are.\n	");
	printf("If you choose MARK, you can choose a field and the field will be highlighted.\n	   If the field hide a mine, the number of bombs from the top left corner decrease.\n	");
	green();
	printf("If you find all the free fields, YOU WIN!\n\n");
	reset();
	char v;
	printf("\nPLEASE INSERT OPTION:\n  ");
	reset();
	printf("	-->");
	green();
	printf("PRESS ANY KEY TO START\n  ");
	reset();
	printf("	-->");
	red();
	printf("<ESC> TO  QUIT\n	");
	v = getch();
	if (v == '\x1b') {
		exit(0);
	}
	return 0;
}

void magyar() {
	clrscr();
	cimkiir();
	printf("\n\nSZABALYOK!\n\n");
	yellow();
	printf("NYOMD MEG CAPS LOCK GOMBOT EGY JOBB JATEKELMENYERT!\n\n");
	reset();
	printf("A jateknak harom nehezsegi szintje van! EGYSZERU, KOZEPES, NEHEZ\n");
	printf("Van 10 akna az EGYSZERU SZINTEN, 40 a KOZEPES SZINTEN es 60 a nehez szinten.\n");
	printf("Valaszthatsz, hogy mit szeretnel csinalni (RAPROBALNI VAGY MEGJELOLNI).\n	");
	printf("Ha a RAPROBALAST VALASZTOD, akkor valaszthatsz egy mezot. Ha a mezo egy aknat rejt, vesztettel \n	  es a jatek veget er, kulonben ha bombak vannak a mezo \n	  korul akkor megjelenik hany van pontosan.\n	");
	printf("Ha a MEGJELOLEST valasztootad, akkor valaszthatsz egy mezot.\n	   Ha a mezo bombat rejt, akkor a bombak szama csokkenni fog a bal felso sarokban.\n	");
	green();
	printf("Ha megtalalod az oszes szabad mezot, akkor NYERSZ!\n\n");
	reset();
	char v;
	printf("\nVALASSZ EGY OPCIOT:\n  ");
	reset();
	printf("	-->");
	green();
	printf("NYOMJ MEG EGY GOMBOT A KEZDESHEZ\n  ");
	reset();
	printf("	-->");
	red();
	printf("<ESC> KILEPES A JATEKBOL\n	");
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
	if (nyelv==0) {
		printf("Press Any Key to Continue\n");
	}
	else if (nyelv==1) {
		printf("Nyomj le egy billentyut a tovabblepeshez\n");
	}
	getchar();
	exit(0);
	return 0;
}

void congratuation() {
	clrscr();
	for (int i = 0; i < 50; ++i) {
		congratkiir();
		clrscr();
	}
	if (nyelv == 0) {
		printf("Press Any Key to Continue\n");
	}
	else if (nyelv == 1) {
		printf("Nyomj le egy billentyut a tovabblepeshez\n");
	}
	getchar();
	exit(0);
	return 0;
}

void overkiir() {
	FILE* fin;
	if (nyelv==0) {
		fin = fopen("gmvra.txt", "r");
		if (!fin) {
			printf("ERROR");
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
	else if(nyelv==1) {
		fin = fopen("gmvrm.txt", "r");
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
}

void congratkiir() {
	FILE* fin;
	if (nyelv == 0) {
		fin = fopen("wina.txt", "r");
		if (!fin) {
			printf("ERROR");
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
	else if (nyelv == 1) {
		fin = fopen("winm.txt", "r");
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
}