#include <stdio.h>

void towersOfHanoi(int n, char frompeg, char topeg, char auxpeg)
{
	if (n == 1)
	{
		printf("���� 1�� ���� %c�κ��� ���� %c�� �ű��.", frompeg, topeg);
		return;
	}
	towersOfHanoi(n - 1, frompeg, auxpeg, topeg);
	printf("\n���� %d�� ���� %c�κ��� ���� %c�� �ű��.", n, frompeg, topeg);
	towersOfHanoi(n - 1, auxpeg, topeg, frompeg);
}
void main(void)
{
	towersOfHanoi(3, 'A', 'B', 'C');
}