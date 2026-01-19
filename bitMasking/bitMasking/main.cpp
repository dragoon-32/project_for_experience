#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAXSIZE 12500000

int main(void) {
	FILE* result = fopen("result.txt", "w");
	char* field = new char[MAXSIZE];
	char masks[8] = {
	'\x01',	//0000 0001
	'\x02',	//0000 0010
	'\x04',	//0000 0100
	'\x08',	//0000 1000
	'\x10',	//0001 0000
	'\x20',	//0010 0000
	'\x40',	//0100 0000
	'\x80'	//1000 0000
	};

	int cnt;

	//initalize
	for (cnt = 0; cnt < MAXSIZE; cnt++) {
		field[cnt] = 0;
	}
	field[0] = 1;
	char point = 1;

	for (cnt = 0; cnt <= MAXSIZE/2; point++) {
		int number = 1 + point + cnt * 8;
		if (!(field[cnt] & masks[point])) {
			for (int i = number*2; i <= MAXSIZE * 8; i += number) {
				field[(i - 1) / 8] |= masks[(i - 1) % 8];
			}
		}
		if (point >= 8) {
			cnt++;
			point = 0;
		}
	}

	int no = 0;
	//print
	for (cnt = 0; cnt < MAXSIZE; cnt++) {
		char c = field[cnt];
		for (int i = 1; i <= 8; i++) {
			if (!(c & masks[i - 1])) {
				no++;
				fprintf(result, "%d - %d¹øÂ°\n", (cnt * 8 + i), no);
			}
		}
	}

	fclose(result);
	delete(field);
	return 0;
}