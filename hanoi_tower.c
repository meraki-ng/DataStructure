#include <stdio.h>

void towersOfHanoi(int n, char frompeg, char topeg, char auxpeg)
{
	if (n == 1)
	{
		printf("원반 1을 막대 %c로부터 막대 %c로 옮긴다.", frompeg, topeg);
		return;
	}
	towersOfHanoi(n - 1, frompeg, auxpeg, topeg);
	printf("\n원반 %d를 막대 %c로부터 막대 %c로 옮긴다.", n, frompeg, topeg);
	towersOfHanoi(n - 1, auxpeg, topeg, frompeg);
}
void main(void)
{
	towersOfHanoi(3, 'A', 'B', 'C');
}