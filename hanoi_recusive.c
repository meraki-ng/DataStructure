#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hanoi(int n, char, char, char);

void main(void)
{
	int hanoiDisk;
	printf("���� ������ �Է��ϼ��� : ");
	scanf_s("%d", &hanoiDisk);
	fflush(stdin);

	hanoi(hanoiDisk, 'A', 'B', 'C');
}
void hanoi(int n, char A, char B, char C)
{
	if (n == 1)
	{
		printf("������%d��° �̵�\n", n);
		printf("���� %d move %c -> %c ", n,  A, B);
		return;
	}
	else
	{
		hanoi(n-1, A, B, A);
		printf("%d��° �̵�\n", n);
		printf("board %d move %c -> %c ", n, A, C);
		hanoi(n - 1, B, C, A);
	}
}