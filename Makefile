CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
HEADERS= ./includes/push_swap.h
SOURCES = ./src/main.o ./src/util/utils.o ./src/util/ft_split.o ./src/util/ft_atoi.o ./src/util/ft_putstr_fd.o ./src/llists/new.o \
./src/llists/add_back.o ./src/llists/last.o ./src/llists/add_front.o ./src/llists/size.o ./src/llists/clear.o ./src/llists/delone.o ./src/instructions/swap.o ./src/instructions/push.o \
./src/instructions/rotate.o ./src/instructions/rev_rotate.o ./src/instructions/rr.o ./src/instructions/rrr.o ./src/parsing/check.o ./src/sorting/main_sorts.o ./src/sorting/best_move_utils.o

all : $(NAME)

$(NAME) : $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(NAME)

%.o : %.c $(HEADERS)
	$(CC) $(CFLAGS) -I./includes -c $< -o $@

clean :
	rm -f $(SOURCES)

fclean :
	rm -f $(SOURCES) $(NAME)

re : fclean all

.PHONY: fclean clean re all