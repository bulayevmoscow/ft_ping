#include "../headers/header.h"
#include "../lib/includes/libftfull.h"

//void parse



void init(int argc, char **argv){
	if (argc == 1){
		printf(MSG_HELP);
	}
}


int main(int argc, char **argv) {
	init(argc, argv);
	ping.flags.flag_h = true;
	ft_printf("\nEnd!");
	return 0;
}
