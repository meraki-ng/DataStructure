#include <stdio.h>
#include <string.h>
#include <math.h>
#define KEY 42 //Ű�� �ڿ���
#define SPACE 26

/*
	���� ��ȣ (ASCII CODE 127)
	������ �� : 
	inverse_gcd2Euclid ���� ���ϰ� 
	decoding �Լ� �����ϱ�
*/
void encoding_func(char[], char*, int, int);
void decoding_func(char[], char*, int, int);
int each_other(int, int); //�������
void error_check(); //������� error üũ
double inverse_gcd2Euclid(int, int); //���� ���ϱ�

int main()
{
	char plainText[] = { "hi, where are you from~?	" };
	const  int input_size = strlen(plainText);
	char decoding[sizeof(plainText)] = { 0, }, encoding[sizeof(plainText)] = { 0, };
	encoding_func(plainText, encoding, KEY, input_size);
	error_check();
	return 0;
}

void decoding_func(char encoding[], char *decoding, int key, int size)
{

}

void encoding_func(char plainText[], char *encoding, int key, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		*(encoding + i) = ((plainText[i]) * key) % SPACE;
	}
}

double inverse_gcd2Euclid(int key, int space)
{
	if(key < space)
	{
	if ((space%key) == 0)	return (pow((space / key), -1));
	space = (space / key) * key + (space%key);
	return inverse_gcd2Euclid((space % key), ((space - (space % key)) / (space / key)));
	}
	else
	{
		if ((key%space) == 0)	return (pow((key / space), -1));
		key = (key / space) * space + (key%space);
		return inverse_gcd2Euclid((key % space), ((key - (key % space)) / (key / space)));
	}
}
int each_other(int key, int space)
{
	if (space > key)	return (space % key) == 0 ;
	else return (key % space) == 0;
}

void error_check()
{
	if (each_other(KEY, SPACE))	inverse_gcd2Euclid(KEY, SPACE);
	else printf("����Դϴ�.�ٽü����ϼ���.");
}