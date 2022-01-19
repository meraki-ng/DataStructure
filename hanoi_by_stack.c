/*
******************************************************************************
	참고 자료 : 다양한 예제로 학습하는 데이터 구조와 알고리즘 - 인사이트
	 하노이탑(기둥 개수 : 3개, 원반 개수 : 사용자 입력) - 스택으로 구현
******************************************************************************
			개선할 점 : 동적할당 <- 에러처리
				동적할당 <- 상수처리
				러처리 <- 상수처리
		큰 원반이 작은 원반 위로 올라가지 않도록 하기!
*/
#include <stdio.h>
#include <stdlib.h>

#define SMALL_LETTEL 97
#define HANOI_NUM 3
#define SIGNAL1 1 //1번 기둥 신호
#define SIGNAL2 2 //2번 기둥 신호
#define SIGNAL3 3 //3번 기둥 신호

struct arrayStack
{
	int top;
	int capacity;
	char *array; //1번 기둥
	char *array2; //2번 기둥
	char *array3; //3번 기둥
};

struct arrayStack *createStack(int num, int hanoiDisk)
{
	struct arrayStack *S = malloc(sizeof(struct arrayStack));
	if (!S)	return NULL;
	S->capacity = 1;
	S->top = -1;

	switch (num)
	{
	case 1:
		S->array = malloc(S->capacity*sizeof(char)*hanoiDisk);
		if (!S->array)	return NULL;
		break;
	case 2:
		S->array2 = malloc(S->capacity*sizeof(char)*hanoiDisk);
		if (!S->array2)	return NULL;
		break;
	case 3:
		S->array3 = malloc(S->capacity*sizeof(char)*hanoiDisk);
		if (!S->array3)	return NULL;
		break;
	}
	return S;
}

int isEmptyStack(struct arrayStack *);
int isFullStack(struct arrayStack *);
void push(int, struct arrayStack *, char);
int pop(int, struct arrayStack *);
void hanoiTop(struct arrayStack *, struct arrayStack *, struct arrayStack*);
void deleteStack(int, struct arrayStack *);
void errorPrint();

void main(void)
{
	int i, hanoiDisk;
	printf("원반 개수를 입력하세요 : ");
	scanf_s("%d", &hanoiDisk);
	fflush(stdin);

	if (hanoiDisk > 0)
	{
		struct arrayStack *L = createStack(1, hanoiDisk);
		struct arrayStack *L2 = createStack(2, hanoiDisk);
		struct arrayStack *L3 = createStack(3, hanoiDisk);

		for (i = 0; i < hanoiDisk; i++)	push(1, L, SMALL_LETTEL + i);

		hanoiTop(L, L2, L3);

		deleteStack(1, L);
		deleteStack(2, L2);
		deleteStack(3, L3);
	}
	else errorPrint();
}

int isEmptyStack(struct arrayStack *S)
{
	return(S->top == -1);
}

int isFullStack(struct arrayStack *S)
{
	return(S->top == S->capacity - HANOI_NUM);
}

void push(int num, struct arrayStack *S, char data)
{
	if (isFullStack(S)) printf("Stack Overflow");
	else
	{
		switch (num)
		{
		case 1:
			S->array[++S->top] = data;
			break;
		case 2:
			S->array2[++S->top] = data;
			break;
		case 3:
			S->array3[++S->top] = data;
			break;
		}
	}
}

int pop(int num, struct arrayStack *S)
{
	if (isEmptyStack(S))
	{
		printf("Stack Empty");
		return 0;
	}
	else
	{
		switch (num)
		{
		case 1:
			return(S->array[S->top--]);
			break;
		case 2:
			return(S->array2[S->top--]);
			break;
		case 3:
			return(S->array3[S->top--]);
			break;
		}
	}
	return 0;
}

void hanoiTop(struct arrayStack *L, struct arrayStack *L2, struct arrayStack *L3)
{
	while (L->top > -1) {
		{
			if (L->top == 0)
			{
				push(SIGNAL2, L2, pop(SIGNAL1, L));
				printf("마지막 원반\n");
				break;
			}
			else
			{
				if ((L3->top) < (L2->top))
				{
					push(SIGNAL2, L2, pop(SIGNAL3, L3));
					printf("\n%d  ", L3->top);
					printf("C원반에서 B원반\n");
				}
				else if ((L3->top) < (L->top))
				{
					printf("\n%d  ", L3->top);
					push(SIGNAL1, L, pop(SIGNAL1, L3));
					printf("C원반에서 A원반\n");
				}
				else if ((L2->top) < (L3->top))
				{
					printf("\n%d  ", L2->top);
					push(SIGNAL2, L2, pop(SIGNAL3, L3));
					printf("C원반에서 B원반\n");
				}
				else  if ((L2->top) < (L->top))
				{
					printf("\n%d  ", L2->top);
					push(SIGNAL1, L, pop(SIGNAL3, L2));
					printf("A원반에서 B원반\n");
				}
				else if ((L->top) < (L2->top))
				{
					push(SIGNAL1, L, pop(SIGNAL3, L2));
					printf("B원반에서 A원반\n");
				}
				else if ((L->top) < (L3->top))
				{
					push(SIGNAL1, L, pop(SIGNAL3, L2));
					printf("C원반에서 A원반\n");
				}
			}
		};
	}
}

void errorPrint()
{
	fprintf(stderr,"원반의 개수는 자연수만 가능합니다.");
	exit(1);
}
void deleteStack(int num, struct arrayStack *S)
{
	if (S)
	{
		switch (num)
		{
		case 1:
			if (S->array)	free(S->array);
			break;
		case 2:
			if (S->array2)	free(S->array2);
			break;
		case 3:
			if (S->array3)	free(S->array3);
			break;
		}
		free(S);
	}
}
