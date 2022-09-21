#ifndef FT_PING_PING_H
#define FT_PING_PING_H

#include <limits.h>
#include <netdb.h>
#include <netinet/ip_icmp.h>
#include <stdbool.h>
#include <stddef.h>

#define PING_ARG_FLAGS "vhs:ac:Dw:Vi:nqt:"
#define PING_V 'v'
#define PING_H 'h'
#define PING_S 's'
#define PING_A 'a'
#define PING_C 'c'
#define PING_D 'D'
#define PING_W 'w'
#define PING_VER 'V'
#define PING_I 'i'
#define PING_N 'n'
#define PING_Q 'q'
#define PING_TTL 't'

#define PING_MIN_PAYLOAD_SZ 0
#define PING_MAX_PAYLOAD_SZ 127992
#define PING_TTL_MIN 0
#define PING_TTL_MAX 255
#define PING_INTERVAL_MIN 0
#define PING_INTERVAL_MAX 10000
#define PING_RESPONSE_COUNT_MIN 1
#define PING_RESPONSE_COUNT_MAX INT_MAX
#define PING_LIFETIME_SEC_MIN 1
#define PING_LEFETIME_SEC_MAX 1000000
#define PING_IPV4_DEFAULT_TTL_PATH "/proc/sys/net/ipv4/ip_default_ttl"
#define PING_VERSION_STR "ft_ping v0.0.1"
#define MICROSECONDS_IN_SECOND 1000000
#define MICROSECONDS_IN_MILLISECOND 1000
#define MINIMUM_WAIT_MICROSECONDS 10000

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

static const size_t ip_hdr_size = sizeof(struct iphdr);
static const size_t icmp_hdr_size = sizeof(struct icmphdr);

struct ping_context_s {
	bool flags[256];
	const char *dest;
	char canon_dest[NI_MAXHOST];
	int icmp_sock;
	in_addr_t dest_address;
	in_addr_t src_address;
	int sizeof_payload;
	size_t response_count_limit;
	size_t seconds_to_work;
	int echo_interval;
	int ttl;
	size_t count_messages_sent;
	size_t count_messages_received;
	size_t count_error_messages_received;

	struct timeval start_time;
	size_t stats_count;

	uint64_t min_time;
	uint64_t max_time;
	uint64_t accept_time_1;
	uint64_t accept_time_2;
};


typedef struct ping_context_s ping_context_t;

void sync_ping();

void sync_pong();

void context_init(int argc, char **argv);

void signal_init();

int send_icmp_msg_v4(
		int sock,
		uint16_t id,
		uint8_t ttl,
		uint8_t icmp_type,
		uint16_t icmp_seq_num,
		size_t payload_size,
		in_addr_t source_ip,
		in_addr_t dest_ip);

int get_ip_address(const char *name, in_addr_t *out, char *canon_name,
				   size_t canon_name_size);

int get_dns_record(in_addr_t ip, char *host, size_t host_len);

unsigned time_diff(struct timeval *begin, struct timeval *end);


#endif
