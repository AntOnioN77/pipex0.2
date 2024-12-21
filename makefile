NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I. -I/libft/headers
DBGFLAGS = -g3
LDFLAGS = -L ./libft -lft
SOURCES = pipex.c exec_cmd.c ft_splitqu.c redirections.c
OBJECTS = $(SOURCES:.c=.o)
HEADERS = libft/headers/libft.h pipex.h

all: $(NAME)
debug: CFLAGS += $(DBGFLAGS)
debug: fclean libft/libft.a $(OBJECTS) $(HEADERS)
	$(CC) $(CFLAGS) $(CPPFLAGS) -I/trace_tools $(OBJECTS) $(LDFLAGS) -L./trace_tools/ -ltrace_tools -o $(NAME)
$(NAME): libft/libft.a $(OBJECTS) $(HEADERS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJECTS) $(LDFLAGS) -o $(NAME)
nowall: libft/libft.a $(OBJECTS) $(HEADERS)
	$(CC) $(CPPFLAGS) $(OBJECTS) $(LDFLAGS) -o $(NAME)
libft/libft.a:
	make extra -C libft
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
.PHONY: clean fclean all
clean:
	rm -f $(OBJECTS)
	make clean -C libft
fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a
re: fclean all