#include "../headers/header.h"
#include "../lib/includes/libftfull.h"

void error_output_and_exit(char *message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void resolveDNS


		char
		parseFlags(int argc, char **argv) {
	if (argc == 1) {
		return 1;
	}
	for (int i = 1; i < argc; i++) {
		if (ft_strequ(argv[i], "-h") != 0 || ft_strequ(argv[i], "-H") != 0) {
			ping.flags.flag_h = true;
			return 1;
		} else if (ft_strequ(argv[i], "-v") != 0 || ft_strequ(argv[i], "-V") != 0) {
			ping.flags.flag_v = true;
		}
	}
	ft_strcpy(ping.flags.flag_host, argv[argc - 1]);

	ping.ttl = 64;
	ping.process_id = getpid();
	ping.seq = 1;
	ping.socket_fd = -1;


	return 0;
}


void createSocket() {
	int socketFD;
	struct timeval timeout;

	timeout.tv_sec = 1;
	timeout.tv_usec = 0;
	if ((socketFD = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) == -1) {
		error_output_and_exit(ERR_SOCKET);
	}
	if ((setsockopt(socketFD, IPPROTO_IP, IP_TTL, &(ping.ttl), sizeof(ping.ttl))) == -1) {
		error_output_and_exit(ERR_SET_SOCKET_FLAG);
	}
	if ((setsockopt(socketFD, SOL_SOCKET, SO_RCVTIMEO, (const void *) &timeout, sizeof(timeout))) == -1) {
		error_output_and_exit(ERR_SET_SOCKET_SETTING);
	}
}


int main(int argc, char **argv) {
	//	debug
	t_ping *test = &ping;
	//	end debug
	printf("---- Start! ----\n");

	if (parseFlags(argc, argv)) {
		printf(MSG_HELP);
		//	exit(0);
	}
	createSocket();
	ft_printf("\nEnd!");
	return 0;
}
