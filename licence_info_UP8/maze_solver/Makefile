NAME = maze
CC = cc
CFLAGS = -Wall -Wextra -Werror 
SRCS = srcs/maze.c \
	srcs/is_map_valid.c \
	srcs/init_print_err.c \
	srcs/DFS_algo.c \

OBJ = $(SRCS:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) 

%.o: %.c 
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(NAME) $(OBJ)
