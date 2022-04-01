#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void password() {
	//char* n = (char*)malloc(sizeof(char));
	char n[50];
	FILE* file;
	file = fopen("pas.txt", "r");
	char word[50];
	//char *word= (char*)malloc(sizeof(char));;
	
	fscanf(file, "%s", word );
	while(1) {
		n[0] = '\0';
		scanf("%s", n);
		if (!strcmp(n, word))break;
		printf("wrong one!\n");
	}
	printf("nice!\n");

}
int main() {

	printf("enter the password:\n");
	password();
	system("pause");
	return EXIT_SUCCESS;
}