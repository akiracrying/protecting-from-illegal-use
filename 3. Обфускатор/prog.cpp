/*#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>  
#include <set>
#include <stack>
#include <deque>
using namespace std;

int main() {
	FILE* file;
	char c;
	file = fopen("proga.txt", "r");
	string programm;
	while (fscanf(file, "%c", &c) != EOF) programm.push_back(c);
	for (auto var : programm) cout << var;
	return 0;
}*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>

int size;
int n;
int size2;

void comments(char* text, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		if (text[i] == '/' && text[i + 1] == '/')
		{
			int counter = i;
			while (text[counter] != '\n')
			{
				counter++;
			}

			int buf = i;
			while (counter < size) {
				text[buf] = text[counter];
				buf++;
				counter++;
			}

			while (buf < size)
				text[buf++] = 0;
		}

		if (text[i] == '/' && text[i + 1] == '*')
		{
			int counter = i;
			while (!(text[counter - 1] == '*' && text[counter] == '/'))
			{
				counter++;
			}
			counter++;

			int buf = i;
			while (counter < size) {
				text[buf] = text[counter];
				buf++;
				counter++;
			}

			while (buf < size)
			{
				text[buf] = 0;
				buf++;
			}
		}
	}
}

void NewLine(char* text, int size)
{
	int flag = 0;
	for (int i = 0; i < size; i++)
	{
		if (text[i] == '#')
			flag++;
		if (text[i] == '\n') if (flag == 0)
			text[i] = ' ';
		else
			flag--;
	}
}

void Tabs(char* text, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (text[i] == '\t')
			text[i] = ' ';
	}
}

/*void ChangeString(char *text, int size)
{
	for (int i = 0; i < size;)
	{
		if (text[i] == '"')
		{
			int counter = i + 1;

			while (text[counter] != '"')
			{
				text[counter]--;
				counter++;
				if (counter > size)
					return;
			}
			i = counter + 8;
		}
		else { i++; }
	}
}*/

char* ChangeName(char* text, int size)
{
	bool check;
	FILE* name = fopen("variables.txt", "r");
	char* nemas = (char*)malloc(size * sizeof(char));
	int flag = 0;
	char newperemen[15];
	int k = 0;
	int raznica;
	size2 = size;

	for (int i = 0; i < size;)
	{
		if (text[i] == 'i' && text[i + 1] == 'n' && text[i + 2] == 't' && text[i + 3] == ' ' && text[i + 4] == 'm' && text[i + 5] == 'a' && text[i + 6] == 'i' && text[i + 7] == 'n' && text[i + 8] == '(' && text[i + 9] == ')')
		{
			for (int j = 0; j <= 10; j++)
			{
				nemas[flag + j] = text[i + j];
			}
			i = i + 12; //переместились на имя
			flag = flag + 12;
			check = 1;
		}

		if (text[i] == 'i' && text[i + 1] == 'n' && text[i + 2] == 't' && text[i + 3] == ' ')
		{
			for (int j = 0; j <= 3; j++)
			{
				nemas[flag + j] = text[i + j];
			}
			i = i + 4; //переместились на имя
			flag = flag + 4;
			if (text[i] == '*')
			{
				nemas[flag] = text[i];
				i++;
				flag++;
			}
			check = 1;
		}
		else if (text[i] == 'c' && text[i + 1] == 'h' && text[i + 2] == 'a' && text[i + 3] == 'r' && text[i + 4] == ' ')
		{
			for (int j = 0; j <= 4; j++)
			{
				nemas[flag + j] = text[i + j];
			}
			i = i + 5;
			flag = flag + 5;
			if (text[i] == '*')
			{
				nemas[flag] = text[i];
				i++;
				flag++;
			}
			check = 1;
		}
		else if (text[i] == 'f' && text[i + 1] == 'l' && text[i + 2] == 'o' && text[i + 3] == 'a' && text[i + 4] == 't' && text[i + 5] == ' ')
		{
			for (int j = 0; j <= 5; j++)
			{
				nemas[flag + j] = text[i + j];
			}
			i = i + 6;
			flag = flag + 6;
			if (text[i] == '*')
			{
				nemas[flag] = text[i];
				i++;
				flag++;
			}
			check = 1;
		}
		else if (text[i] == 'b' && text[i + 1] == 'o' && text[i + 2] == 'o' && text[i + 3] == 'l' && text[i + 4] == ' ')
		{
			for (int j = 0; j <= 4; j++)
			{
				nemas[flag + j] = text[i + j];
			}
			i = i + 5;
			flag = flag + 5;
			if (text[i] == '*')
			{
				nemas[flag] = text[i];
				i++;
				flag++;
			}
			check = 1;
		}
		else if (text[i] == 'F' && text[i + 1] == 'I' && text[i + 2] == 'L' && text[i + 3] == 'E' && text[i + 4] == ' ')
		{
			for (int j = 0; j <= 4; j++)
			{
				nemas[flag + j] = text[i + j];
			}
			i = i + 5;
			flag = flag + 5;
			if (text[i] == '*')
			{
				nemas[flag] = text[i];
				i++;
				flag++;
			}
			check = 1;
		}
		else if (text[i] == 'd' && text[i + 1] == 'o' && text[i + 2] == 'u' && text[i + 3] == 'b' && text[i + 4] == 'l' && text[i + 5] == 'e' && text[i + 6] == ' ')
		{
			for (int j = 0; j <= 6; j++)
			{
				nemas[flag + j] = text[i + j];
			}
			i = i + 7;
			flag = flag + 7;
			if (text[i] == '*')
			{
				nemas[flag] = text[i];
				i++;
				flag++;
			}
			check = 1;
		}
		else
		{
			nemas[flag] = text[i];
			flag++;
			i++;
			check = 0;
		}

		int savei = i;
		int saveflag = flag;
		int razmer = 0;
		char* peremen = (char*)malloc(razmer * sizeof(char));

		if (check == 1)
		{
			k = 0;
			razmer = 0;
			while (text[i] != ' ' && text[i] != '[' && text[i] != '(' && text[i] != ',' && text[i] != ';' && text[i] != ')')
			{
				peremen = (char*)realloc(peremen, (razmer + 1) * sizeof(char));
				peremen[razmer] = text[i];
				i++;
				razmer++;
			}
			fgets(newperemen, 15, name);
			raznica = 10 - razmer;
			int kontrol;

			nemas = (char*)realloc(nemas, (size + raznica) * sizeof(char));
			for (int a = 0; a < 10; a++)
			{
				nemas[flag] = newperemen[a];
				flag++;
			}
			k++;

			for (int j = i; j < size; j++)
			{
				kontrol = 0;
				for (int a = 0; a < razmer; a++)
				{
					if (text[j + a] == peremen[a])
					{
						kontrol = 1;
					}
					else
					{
						kontrol = 0;
						break;
					}
				}

				if (kontrol == 1 && (text[j + razmer] == ' ' || text[j + razmer] == '[' || text[j + razmer] == '(' || text[j + razmer] == ')' || text[j + razmer] == '+' || text[j + razmer] == ',' || text[j + razmer] == ';' || text[j + razmer] == ']'))
				{
					k++;
					nemas = (char*)realloc(nemas, (size + raznica * k) * sizeof(char));
					for (int a = 0; a < 10; a++)
					{
						nemas[flag] = newperemen[a];
						flag++;
					}
					j = j + razmer - 1;
				}
				else
				{
					nemas[flag] = text[j];
					flag++;
				}
			}
			size2 = size + raznica * k;

			text = (char*)realloc(text, size2 * sizeof(char));
			memcpy(text, nemas, size2);
			size = size2;
		}


		i = savei + razmer;
		flag = saveflag + razmer;
		i = flag;
	}
	fclose(name);
	return nemas;
}

char* musor(char* text, int size)
{
	FILE* musor = fopen("musor.txt", "r");
	char* newmas = (char*)malloc(size * sizeof(char));
	int flag = 0;
	n = 0;
	for (int i = 0; i < size;)
	{
		if (text[i] == '{')
		{
			n++;
			newmas[flag] = text[i];
			char mu[30];
			fgets(mu, 30, musor);

			newmas = (char*)realloc(newmas, (size + 26 * n) * sizeof(char));

			for (int j = 1; j <= 26; j++)
			{
				newmas[flag + j] = mu[j - 1];
			}

			flag = flag + 26;
			i++;
		}
		else
		{
			newmas[flag] = text[i];
			flag++;
			i++;
		}
	}
	size = size + 25 * n;

	fclose(musor);
	return newmas;
}

char* musorfunc(char* text, int size)
{
	size2 = size + 433;
	char* mas = (char*)malloc(size2 * sizeof(char));

	int flag = 0;
	for (;;)
	{
		if (text[flag] == '#')
		{
			while (text[flag] != '\n')
			{
				mas[flag] = text[flag];
				flag++;
			}
			mas[flag] = text[flag];
			flag++;


			if (text[flag] != '#')
			{
				int j = flag;
				FILE* file = fopen("musorfunc.txt", "r");
				char c;

				for (int i = 0; i < 433; i++)
				{
					fscanf(file, "%c", &c);
					mas[flag] = c;
					flag++;
				}

				for (int k = j; k <= size; k++)
				{
					mas[flag] = text[k];
					flag++;
				}
				return mas;
			}
		}
	}
}

int main()
{
	/*SetConsoleCP(1251); //
	SetConsoleOutputCP(1251); //распознование кириллицы в консоли*/

	FILE* file = fopen("proga.txt", "r");
	if (file == NULL) {
		printf("Error");
		return 0;
	}

	char c;
	c = fgetc(file);

	int i = 0;
	char* text = (char*)malloc(sizeof(char)); //преобразование типа
	text[i] = c;
	i++;
	while (!feof(file)) //запись текста в массив
	{
		c = fgetc(file);
		text = (char*)realloc(text, (i + 1) * sizeof(char)); //изменение длины массива на 1
		text[i] = c; //запись файла в массив
		i++;
	}
	text[i - 1] = '\0';
	size = i - 1; //размер файла

	fclose(file);

	int a;
	printf("delete comments?");
	scanf_s("%d", &a);
	if (a == 1)
	{
		comments(text, size);
	}
	printf("change var names?");
	scanf_s("%d", &a);
	if (a == 1)
	{
		text = ChangeName(text, size);
		size = size2;
	}
	printf("add useless vars?");
	scanf_s("%d", &a);
	if (a == 1)
	{
		text = musor(text, size);
		size = size + 25 * n;
	}
	printf("add useless funcs?");
	scanf_s("%d", &a);
	if (a == 1)
	{
		text = musorfunc(text, size);
		size = size + 433;
	}
	/*printf("Поменять закавыченный текст?");
	scanf_s("%d", &a);
	if (a == 1)
	{
		ChangeString(text, size);
	}*/
	printf("remove \\n?");
	scanf_s("%d", &a);
	if (a == 1)
	{
		NewLine(text, size);
	}
	printf("remove tabs?");
	scanf_s("%d", &a);
	if (a == 1)
	{
		Tabs(text, size);
	}

	FILE* finish = fopen("obfuscation.txt", "w");
	int j = 0;
	while (j != size)
	{
		printf("%c", text[j]);
		fprintf(finish, "%c", text[j]);
		j++;
	}
	fclose(finish);

	_getch();
	system("pause");
	return 0;
}