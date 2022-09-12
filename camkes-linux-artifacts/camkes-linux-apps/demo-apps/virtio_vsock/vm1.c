#include <sys/socket.h>
#include <linux/vm_sockets.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

#define VM0_CID 3

int main()
{
	int s = socket(AF_VSOCK, SOCK_STREAM, 0);

	struct sockaddr_vm addr;
	memset(&addr, 0, sizeof(struct sockaddr_vm));
	addr.svm_family = AF_VSOCK;
	addr.svm_port = 1234;
	addr.svm_cid = VM0_CID;

    int err;

    printf("VSOCK LINUX: connecting\n");
	err = connect(s, &addr, sizeof(struct sockaddr_vm));
    if (err) {
        printf("Error connecting\n");
        return -1;
    }

    printf("VSOCK LINUX: sending\n");
	err = send(s, "Hello, world!", 13, 0);
    assert(err == 13);

	close(s);

	return 0;
}