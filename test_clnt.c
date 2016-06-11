#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

typedef struct A {
	int num;
	char message[512];
} A;

int main(int argc, char* argv[])
{
	int s;
	struct sockaddr_in a;
	A t;
	s = socket(PF_INET, SOCK_STREAM, 0);
	memset(&a, 0, sizeof(a));
	a.sin_family = AF_INET;
	a.sin_port = htons(atoi(argv[2]));
	a.sin_addr.s_addr = inet_addr(argv[1]);

	connect(s, (struct sockaddr*)&a, sizeof(a));
	t.num = 30;
	sprintf(t.message, "%s", "Hi");
	send(s, (char*)&t, sizeof(A), 0);
	return 0;
}
