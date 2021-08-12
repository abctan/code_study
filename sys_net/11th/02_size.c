#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <share.h>
#include <pwd.h>
#include <grp.h>
#include <shadow.h>
#include <time.h>
#include <dirent.h>
#include <sys/wait.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <signal.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <arpa/inet.h>

struct op_t{
	sa_family_t a;
	u_int16_t b;
	u_int32_t c;
};

int main(int argc, char *argv[])
{

	printf("sizeof(struct op_t) = %d\n", sizeof(struct op_t));
	printf("sizeof(struct sockaddr_in) = %d\n", sizeof(struct sockaddr_in));

    /*
	 *typedef unsigned short int sa_family_t; => 2
	 *unsigned short int => 2
	 *typedef unsigned int u_int32_t; => 4
     */
/*
 *    struct sockaddr_in {
 *        sa_family_t    sin_family; [> address family: AF_INET <]
 *        u_int16_t      sin_port;   [> port in network byte order <]
 *        struct in_addr sin_addr;   [> internet address <]
 *    };
 *
 *    [> Internet address. <]
 *    struct in_addr {
 *        u_int32_t      s_addr;     [> address in network byte order <]
 *    };
 */

	return 0;
}
