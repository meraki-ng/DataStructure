#include <stdio.h>

/*
**************************
	Table 정적 - 배열
**************************
*/

struct dnsTableHeader {
	char ipHeader[20];
	char dnsHeader[30];
};
struct dnsTableHeader tableHeader[4] =
{ { "8.8.8.8", "example.www.google.com"}, {"8.8.4.4","example.www.kt.co.kr"},{"192.0.0.0","example.www.home.com"}, {"192.168.0.0","example.www.test.com"} };