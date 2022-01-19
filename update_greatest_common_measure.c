#include <stdio.h>
#include <string.h>
#define KEY 13
#define SPACE 127
/*
	µ¡¼À¾ÏÈ£(rot 13) (ASCII CODE 127)
*/
void encoding_func(char[], char*, int, int);
void decoding_func(char[], char*, int, int);

int main()
{
	char plainText[] = { "hi, where are you from~?	" };
	const  int input_size = strlen(plainText);
	char decoding[sizeof(plainText)] = { 0, }, encoding[sizeof(plainText)] = { 0, };
	encoding_func(plainText, encoding, KEY, input_size);
	decoding_func(encoding, decoding, KEY, input_size);

	return 0;
}

void decoding_func(char encoding[], char *decoding, int key, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		*(decoding + i) = (encoding[i] - key) < 0 ? ((encoding[i] - key) + SPACE) % SPACE : (encoding[i] - key) % SPACE;
	}
}

void encoding_func(char plainText[], char *encoding, int key, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		*(encoding + i) = ((plainText[i]) + key) % SPACE;
	}
}
