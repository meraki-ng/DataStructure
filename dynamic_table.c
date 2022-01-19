/*
***************************
	Table 추가 <- 리스트
***************************
	 개선할 점 :
   파일로 읽고 쓰기 <- 저장
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IP_SIZE 20
#define DOMAIN_SIZE 30

typedef struct ListNode
{
	char ip[IP_SIZE];
	char domain[DOMAIN_SIZE];
	struct ListNode* link;
}listNode;

typedef struct
{
	listNode* head;
}linkedList_h;

void insert(linkedList_h *L);
linkedList_h* createLinkedList_h();
void freeLinkedList_h(linkedList_h* L);
void insertLastNode(linkedList_h *L, char*, char*);

int main(void)
{
	int count = 0;
	char input_address[DOMAIN_SIZE];
	linkedList_h *L = createLinkedList_h();
	insert(L);

	printf("주소를 입력하세요 : ");
	scanf("%s", input_address);
	fflush(stdin);

	listNode *i;
	for (i = L->head; i != NULL; i = i->link)
	{
		if (!strcmp(i->domain, input_address))
		{
			printf("찾았습니다.[ %s %s ] ", i->ip, i->domain);
			count++;
		}
	}
	if (count == 0)
	{
		char *s = malloc(sizeof(char) * DOMAIN_SIZE);
		strcpy(s, input_address);
		insertLastNode(L, "192.0.0.*", s);
		free(s);
	}

	/*
	//등록 되었을경우, 추가됨을 확인
	for (i = L->head; i != NULL; i = i->link)	printf("\n[%s - %s]", i->ip, i->domain);
	*/
	freeLinkedList_h(L);
	return 0;
}

linkedList_h* createLinkedList_h()
{
	linkedList_h * L;
	L = (linkedList_h*)malloc(sizeof(linkedList_h));
	L->head = NULL;
	return L;
}

void insertLastNode(linkedList_h *L, char *newip, char *newdomain)
{
	listNode* newNode;
	listNode* temp;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->ip, newip);
	strcpy(newNode->domain, newdomain);
	newNode->link = NULL;
	if (L->head == NULL)
	{
		L->head = newNode;
		return;
	}
	temp = L->head;
	while (temp->link != NULL) temp = temp->link;
	temp->link = newNode;
}

void insert(linkedList_h *L)
{
	insertLastNode(L, "192.0.0.0", "www.test0.com");
	insertLastNode(L, "192.0.0.1", "www.test1.com");
	insertLastNode(L, "192.0.0.2", "www.test2.com");
	insertLastNode(L, "192.0.0.3", "www.test3.com");
	insertLastNode(L, "192.0.0.4", "www.test4.com");
	insertLastNode(L, "192.0.0.5", "www.test5.com");
	insertLastNode(L, "192.0.0.6", "www.test6.com");
	insertLastNode(L, "192.0.0.7", "www.test7.com");
	insertLastNode(L, "192.0.0.8", "www.test8.com");
	insertLastNode(L, "192.0.0.9", "www.test9.com");
}

void freeLinkedList_h(linkedList_h* L)
{
	listNode* p;
	while (L->head != NULL)
	{
		p = L->head;
		L->head = L->head->link;
		free(p);
		p = NULL;
	}
}