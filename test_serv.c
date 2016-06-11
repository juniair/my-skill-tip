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
	int s, c;
	struct sockaddr_in s_a, c_a;
	socklen_t c_a_s;
	int str_len;
	char message [sizeof(A)];
	A* t;

	s = socket(PF_INET, SOCK_STREAM, 0);
	memset(&s_a, 0, sizeof(s_a));
	s_a.sin_family = AF_INET;
	s_a.sin_addr.s_addr = htonl(INADDR_ANY);
	s_a.sin_port = htons(atoi(argv[1]));

	bind(s, (struct sockaddr*)&s_a, sizeof(s_a));
	listen(s, 5);
	c_a_s = sizeof(c_a);
	c = accept(s, (struct sockaddr*)&c_a, &c_a_s);
	str_len = recv(c, message, sizeof(A), 0);
	printf("len %d, size A %d\n", str_len, sizeof(A));
	message[str_len] ='\0';
	t =(A*) message;
//	sprintf(message, "%s", t.message);
//	t->message = (char*) message[5];
	printf("%d, %s\n", t->num, t->message);
	return 0;
}
