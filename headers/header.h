//
// Created by Kudzu Psylocke on 10/16/21.
//

#ifndef FT_PING_MY_HEADER_H
#define FT_PING_MY_HEADER_H

#include "stdio.h"
#include <arpa/inet.h>
#include <errno.h>
#include <math.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

#define MSG_HELP "usage: ./ft_ping [-h help] [-v verbose] host"
#define ERR_SOCKET "Error: Socket operation not permitted"
#define ERR_SET_SOCKET_FLAG "Error: Cant resolve setsockopt"
#define ERR_SET_SOCKET_SETTING "Error: Cant resolve setsockopt config"

typedef struct s_ping_flags {
	bool flag_v;
	bool flag_h;
	char flag_host[255];
} t_ping_flags;

typedef struct s_ping {
	t_ping_flags flags;
	unsigned int ttl;
	unsigned int count;
	pid_t process_id;
	int socket_fd;
	int sent_packets;
	int received_packets;
	int error_packets;
	int seq;
	struct sockaddr_in sockaddr;
	struct timeval starting_time;
	struct timeval ending_time;
	double min_time;
	double max_time;
	double sum_time;
	double square_sum_time;


} t_ping;

t_ping ping;


#endif//FT_PING_MY_HEADER_H
