//
// Created by Kudzu Psylocke on 10/16/21.
//

#ifndef FT_PING_MY_HEADER_H
#define FT_PING_MY_HEADER_H

#include <stdbool.h>
#include "stdio.h"

#define MSG_HELP "usage: ./ft_ping [-h] [-v] host"


typedef struct s_ping_flags {
	bool flag_v;
	bool flag_h;
} t_ping_flags;

typedef struct s_ping {
	t_ping_flags flags;
} t_ping;

t_ping ping;

#endif//FT_PING_MY_HEADER_H
