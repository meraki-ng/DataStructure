#include <stdio.h>
#include <string.h>
#include <math.h>
#define KEY 42 //키는 자연수
#define SPACE 26

/*
	곰셈 암호 (ASCII CODE 127)
	개선할 점 : 
	inverse_gcd2Euclid 역수 리턴값 
	decoding 함수 구현하기
*/
void encoding_func(char[], char*, int, int);
void decoding_func(char[], char*, int, int);
int each_other(int, int); //배수관계
void error_check(); //배수관계 error 체크
double inverse_gcd2Euclid(int, int); //역원 구하기

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
	else printf("배수입니다.다시설정하세요.");
}