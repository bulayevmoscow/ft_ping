cmake_minimum_required(VERSION 3.10)
project(ft_ping_my C)

set(CMAKE_C_STANDARD 99)

add_executable(ft_ping_my ./lib/ft_printf/src/check_flags.c
        ./lib/ft_printf/src/check_flags_extra.c
        ./lib/ft_printf/src/ft_itoa_external.c
        ./lib/ft_printf/src/ft_str_concat.c
        ./lib/ft_printf/src/norm.c
        ./lib/ft_printf/src/parse.c
        ./lib/ft_printf/src/parse_extra.c
        ./lib/ft_printf/src/printf.c
        ./lib/ft_printf/src/pusher_c_s_p.c
        ./lib/ft_printf/src/pusher_c_s_p_extra.c
        ./lib/ft_printf/src/pusher_diuox.c
        ./lib/ft_printf/src/pusher_f.c
        ./lib/ft_printf/src/stars_manager.c
        ./lib/get_next_line/get_next_line.c
        ./lib/libft/ft_abs.c
        ./lib/libft/ft_atoi.c
        ./lib/libft/ft_bzero.c
        ./lib/libft/ft_isalnum.c
        ./lib/libft/ft_isalpha.c
        ./lib/libft/ft_isascii.c
        ./lib/libft/ft_isdigit.c
        ./lib/libft/ft_isprint.c
        ./lib/libft/ft_itoa.c
        ./lib/libft/ft_list_size.c
        ./lib/libft/ft_lstadd.c
        ./lib/libft/ft_lstdel.c
        ./lib/libft/ft_lstdelone.c
        ./lib/libft/ft_lstiter.c
        ./lib/libft/ft_lstmap.c
        ./lib/libft/ft_lstnew.c
        ./lib/libft/ft_max.c
        ./lib/libft/ft_memalloc.c
        ./lib/libft/ft_memccpy.c
        ./lib/libft/ft_memchr.c
        ./lib/libft/ft_memcmp.c
        ./lib/libft/ft_memcpy.c
        ./lib/libft/ft_memdel.c
        ./lib/libft/ft_memmove.c
        ./lib/libft/ft_memset.c
        ./lib/libft/ft_memswap.c
        ./lib/libft/ft_putchar.c
        ./lib/libft/ft_putchar_fd.c
        ./lib/libft/ft_putendl.c
        ./lib/libft/ft_putendl_fd.c
        ./lib/libft/ft_putnbr.c
        ./lib/libft/ft_putnbr_fd.c
        ./lib/libft/ft_putstr.c
        ./lib/libft/ft_putstr_fd.c
        ./lib/libft/ft_sqrt.c
        ./lib/libft/ft_strcat.c
        ./lib/libft/ft_strchr.c
        ./lib/libft/ft_strclr.c
        ./lib/libft/ft_strcmp.c
        ./lib/libft/ft_strcpy.c
        ./lib/libft/ft_strdel.c
        ./lib/libft/ft_strdup.c
        ./lib/libft/ft_strequ.c
        ./lib/libft/ft_striter.c
        ./lib/libft/ft_striteri.c
        ./lib/libft/ft_strjoin.c
        ./lib/libft/ft_strlcat.c
        ./lib/libft/ft_strlen.c
        ./lib/libft/ft_strmap.c
        ./lib/libft/ft_strmapi.c
        ./lib/libft/ft_strncat.c
        ./lib/libft/ft_strncmp.c
        ./lib/libft/ft_strncpy.c
        ./lib/libft/ft_strnequ.c
        ./lib/libft/ft_strnew.c
        ./lib/libft/ft_strnstr.c
        ./lib/libft/ft_strrchr.c
        ./lib/libft/ft_strrev.c
        ./lib/libft/ft_strsplit.c
        ./lib/libft/ft_strstr.c
        ./lib/libft/ft_strsub.c
        ./lib/libft/ft_strtrim.c
        ./lib/libft/ft_tolower.c
        ./lib/libft/ft_toupper.c
        src/main.c headers/header.h)
