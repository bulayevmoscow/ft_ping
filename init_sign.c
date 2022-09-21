#include "ping.h"
#include <math.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

extern ping_context_t ping_ctx;
static void break_ping()
{
	struct timeval end_time;
	if (gettimeofday(&end_time, NULL) != 0)
	{
		perror("cannot get end time");
		exit(EXIT_FAILURE);
	}

	printf("\n--- %s ping statistics ---\n", ping_ctx.canon_dest);

	const float loss_percentage = (1 - (float) ping_ctx.count_messages_received / (float) ping_ctx.count_messages_sent) * 100;
	printf("%zu packets transmitted, %zu received, ",
		   ping_ctx.count_messages_sent, ping_ctx.count_messages_received);
	if (ping_ctx.count_error_messages_received != 0)
	{
		printf("+%zu errors, ", ping_ctx.count_error_messages_received);
	}
	printf("%.2f%% packet loss, time %ums\n",
		   loss_percentage,
		   time_diff(&ping_ctx.start_time, &end_time) / MICROSECONDS_IN_MILLISECOND);

	if (ping_ctx.stats_count != 0)
	{
		const uint64_t avg = ping_ctx.accept_time_1 / ping_ctx.stats_count;
		const uint64_t avg2 = ping_ctx.accept_time_2 / ping_ctx.stats_count;
		const uint64_t mdev = sqrt(avg2 - avg * avg);

		printf("rtt MIN/avg/MAX/mdev = %ld.%03ld/%ld.%03ld/%ld.%03ld/%ld.%03ld ms\n",
			   ping_ctx.min_time / 1000, ping_ctx.min_time % 1000,
			   avg / 1000, avg % 1000,
			   ping_ctx.max_time / 1000, ping_ctx.max_time % 1000,
			   mdev / 1000, mdev % 1000);
	}

	exit(EXIT_SUCCESS);
}

void signal_init()
{
	if (signal(SIGALRM, break_ping) == SIG_ERR)
	{
		perror("signal alarm error");
		exit(EXIT_FAILURE);
	}
	if (signal(SIGINT, break_ping) == SIG_ERR)
	{
		perror("signal break_ping error");
		exit(EXIT_FAILURE);
	}
	if (ping_ctx.flags[PING_W])
	{
		alarm(ping_ctx.seconds_to_work);
	}
}
