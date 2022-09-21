#include "ping.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

static void async_ping()
{
	pthread_t thread;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcast-function-type"
	if (pthread_create(&thread, NULL, (void *(*) (void *) ) sync_ping, NULL) != 0)
	{
		perror("cannot create thread");
		exit(EXIT_FAILURE);
	}
#pragma GCC diagnostic pop

	if (pthread_detach(thread) != 0)
	{
		perror("cannot detach thread");
		exit(EXIT_FAILURE);
	}
}

int main(int argc, char **argv)
{

	context_init(argc, argv);
	signal_init();

	async_ping();
	sync_pong();
}
