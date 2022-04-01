#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int XOR = 11;

void Xor(char* c) {
	for (int i = 0; i < 50; i++) {
		if (c[i] != '\0')
			c[i] ^= XOR;
		else return;
	}
}
int kal(char *n, char* word) {
	int flag = 0;
	n[0] = '\0';
	scanf("%s", n);
	int sz1 = strlen(n), sz2 = strlen(word);
	if (sz1 != sz2) {
		
		return 1;
	}
	for (int i = 0; i < sz1; i++) {
		if ((word[i] ^ XOR) == n[i]);
		else {
			flag = 1;
			return 1;
		}
	}
	if (!flag)return 0;
}
void password() {
	int flag = 0;
	char n[50];
	FILE* file;
	file = fopen("pas.txt", "r");
	char word[50]; // pas
	fscanf(file, "%s", word );
	Xor(word);
	while(1) {
		if (kal(n, word) == 1) {
			printf("wrong!\n");
		}
		else {
			printf("nice!\n");
			system("pause");
			exit(0);
		}
	}
	

}
int main() {

	printf("enter the password:\n");
	password();
	return EXIT_SUCCESS;
}