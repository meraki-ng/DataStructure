#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100
#define IP_SIZE 20
#define DOMAIN_SIZE 30
/*
**************************
	Table 정적 - 배열
**************************
*/

struct dnsTable {
	char ip[IP_SIZE];
	char dns[DOMAIN_SIZE];
};

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

linkedList_h* createLinkedList_h();
void freeLinkedList_h(linkedList_h* L);
void insertLastNode(linkedList_h *L, char*, char*);

int main(void)
{
	int count = 0;
	char input_address[DOMAIN_SIZE];
	struct dnsTable table[TABLE_SIZE] =
	{ { "8.8.8.8", "example.www.google.com"}, {"8.8.4.4","example.www.kt.co.kr"},{"192.0.0.0","example.www.test.com"}, {"192.0.0.1","example.www.test1.com"}, {"192.0.0.2","example.www.test2.com"} };

	printf("주소를 입력하세요 : ");
	scanf("%s", input_address);
	fflush(stdin);
	
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		printf("%s %s\n", table[i].ip, table[i].dns);
	}
	printf("------------------");

	for (int i = 0; i < TABLE_SIZE; i++)
	{
		if (!strcmp(table[i].dns, input_address))
		{
			printf(" [ %s %s ]", table[i].ip, table[i].dns);
			count++;
		}
	}
	if (count == 0)
	{
		char *s1 = malloc(sizeof(char) * DOMAIN_SIZE);
		strcpy(s1, input_address);
		linkedList_h *L;
		L = createLinkedList_h();
		insertLastNode(L,s1, "192.0.0.5");
		freeLinkedList_h(L);
	}

	for (int i = 0; i < TABLE_SIZE; i++)
	{
		printf("%s %s\n", table[i].ip, table[i].dns);
	}
	printf("------------------");

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
	printf("\n\nfunction!");
	printf("\n%s %s\n\n", newNode->ip, newNode->domain);
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