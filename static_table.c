#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dnsTable {
	char ip[20];
	char domain[30];
};

int main(void)
{
	struct dnsTable *ptr = (struct dnsTable *)malloc(sizeof(struct dnsTable));
	strcpy(ptr->ip, "8.8.8.8");
	strcpy(ptr->domain, "www.google.com");
	strcpy(ptr->ip, "8.8.4.4");
	strcpy(ptr->domain, "www.kt.co.kr");
	for (int i = 0; i < 2; i++)	printf("[ %s %s ]",ptr[i].ip, ptr[i].domain);

	free(ptr);
	return 0;
}