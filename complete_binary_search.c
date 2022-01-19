#include <stdio.h>
#include <math.h>
#include <stdlib.h> 
#include <time.h>

//��ó : C & �ڷᱸ�� ����

/*
	����Ž������
	���� ���� :  �ѹ��� ã�Ƴ����� ���մϴ�.
	���� : �Ϸ�!
*/

#define MAX_SIZE 10000 // �迭 ������
#define RANDOM_NUMBER 1000 // �����߻�
#define SWAP(x,y,t) ((t) = (x), (x) = (y), (y) = (t)) // select_sort SWAP
#define CONDITION_TERMINAL 0

void select_sort(int list[], int n); // binary_search ���� �������� ���� ����� (selectSorting)
int binary_search(int[], int, int, int);
int compare(int middle_num, int searchnum);
int binary_search_input(int list[], int searchnum, int array_size);

void main(void)
{
	int i, searchnum, binary_input_res;
	int list[MAX_SIZE];
	srand(time(NULL));

	for (i = 0; i < MAX_SIZE; i++)  list[i] = rand() % (RANDOM_NUMBER + 1); // 1~1000

	clock_t st, et;

	st = clock();
	select_sort(list, MAX_SIZE);
	et = clock();

	printf("%d ms", et - st);

	do {
		printf("\nã�� ��ȣ�� �˻��� �ּ��� : (�������� : 0)  : ");
		scanf_s("%d", &searchnum);
		binary_input_res = binary_search_input(list, searchnum, (MAX_SIZE - 1));

		switch (binary_input_res)
		{
		case -1:
			printf("���� �Ǿ����ϴ�.\n");
			break;
		case 1:
			printf("�˻� ����� �����ϴ�. �ٽ� �õ����ּ���! \n");
			break;
		default:
			printf("binary_search ��� : %d", list[binary_input_res]);
			break;
		}
	} while (searchnum); // searchnum_res == CONDITION_TERMINAL
}

int binary_search(int list[], int searchnum, int left, int right)
{
	/*search list[0] <= list[1] <= . . . <= list[n-1]
	for n, return its position if found. Otherwise return -1*/
	int middle;
	while (left <= right)
	{
		middle = (left + right) / 2;
		switch (compare(list[middle], searchnum))
		{
		case -1: return binary_search(list, searchnum, middle + 1, right); // middle < target
		case 0: return middle; //middle == target
		case 1:  return binary_search(list, searchnum, left, middle - 1); // middle > target
		}
	}
	return -1; // (left > right)
}

int binary_search_input(int list[], int searchnum, int array_size)
{
	int searchnum_res;
	if (searchnum != CONDITION_TERMINAL)
	{
		searchnum_res = binary_search(list, searchnum, 0, array_size); // list[], searchnum, left, right
		if (searchnum == list[searchnum_res]) return searchnum_res;
		else return 1;
	}
	else return -1; // searchnum == CONDITION_TERMINAL
}
void select_sort(int list[], int n)
{
	int i, min, temp, j = 0;

	for (i = 0; i < n; i++)
	{
		min = j;
		for (j = i; j < n - 1; j++)
		{
			if (list[j] < list[min])	min = j;
		}
		SWAP(list[i], list[min], temp);
	}
}
int compare(int middle_num, int searchnum)
{
	if (middle_num < searchnum) return -1;
	else if (middle_num == searchnum) return 0;
	else return 1;
}