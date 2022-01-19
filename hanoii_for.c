#include <stdio.h>
#include <math.h>

void main(void)
{
	int num;
	printf("원반 수를 입력하세요 : ");
	scanf_s("%d", &num);
	fflush(stdin);

	int i, count = 0;
	char A = 'A'; // 1번 원반
	char B = 'B'; //2번 원반
	char C = 'C'; //3번 원반

	for (i = 0; i < pow(2, num) - 1; i++)
	{
		if (i == pow(2, num) - 2) //마지막 가장 큰 원반 위치 조회
		{
			printf("마지막  %.lf  가장 큰 원반 이동\n", pow(2, num) - 1); //가장 큰 원반 이동
			printf("%c -> %c로\n", A, C);
		}
		else 
		{
			//점화식 넣기
			printf("%d번째 이동\n", ++count);
		}
	}
}