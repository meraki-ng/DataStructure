#include <stdio.h>
#include <math.h>

void main(void)
{
	int num;
	printf("���� ���� �Է��ϼ��� : ");
	scanf_s("%d", &num);
	fflush(stdin);

	int i, count = 0;
	char A = 'A'; // 1�� ����
	char B = 'B'; //2�� ����
	char C = 'C'; //3�� ����

	for (i = 0; i < pow(2, num) - 1; i++)
	{
		if (i == pow(2, num) - 2) //������ ���� ū ���� ��ġ ��ȸ
		{
			printf("������  %.lf  ���� ū ���� �̵�\n", pow(2, num) - 1); //���� ū ���� �̵�
			printf("%c -> %c��\n", A, C);
		}
		else 
		{
			//��ȭ�� �ֱ�
			printf("%d��° �̵�\n", ++count);
		}
	}
}