#include <sys/socket.h>
#include <linux/vm_sockets.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

#define VM2_CID 3

int main()
{
	int s = socket(AF_VSOCK, SOCK_STREAM, 0);

	struct sockaddr_vm addr;
	memset(&addr, 0, sizeof(struct sockaddr_vm));
	addr.svm_family = AF_VSOCK;
	addr.svm_port = 1234;
	addr.svm_cid = VM2_CID;

	bind(s, &addr, sizeof(struct sockaddr_vm));

	listen(s, 0);

	struct sockaddr_vm peer_addr;
	socklen_t peer_addr_size = sizeof(struct sockaddr_vm);
	printf("VSOCK HOST: waiting for client to connect...\n");
	int peer_fd = accept(s, &peer_addr, &peer_addr_size);

	char buf[64];
	size_t msg_len;
	printf("VSOCK HOST: waiting for client to send...\n");
	msg_len = recv(peer_fd, &buf, 64, 0);
	printf("Received %lu bytes: %.*s\n", msg_len, msg_len, buf);
	assert(msg_len == 13);

	return 0;
}