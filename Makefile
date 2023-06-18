CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
BONUS = checker
HEADERS= ./includes/push_swap.h ./includes/get_next_line.h 
MAIN = ./src/main.o
SOURCES =  ./src/util/utils.o ./src/util/ft_split.o ./src/util/ft_atoi.o ./src/util/ft_putstr_fd.o ./src/llists/new.o \
./src/llists/add_back.o ./src/llists/last.o ./src/llists/add_front.o ./src/llists/size.o ./src/llists/clear.o \
./src/llists/delone.o ./src/instructions/swap.o ./src/instructions/push.o \
./src/instructions/rotate.o ./src/instructions/rev_rotate.o ./src/instructions/ss.o ./src/instructions/rr.o \
./src/instructions/rrr.o ./src/parsing/check.o ./src/parsing/pars_err.o ./src/sorting/main_sorts.o  \
./src/sorting/best_move.o ./src/sorting/global_utils.o ./src/sorting/best_move_utils.o

SRC_BNS = ./src/bonus/bonus_main.o ./src/bonus/bonus_utils.o  ./src/bonus/gnl/get_next_line.o ./src/bonus/gnl/get_next_line_utils.o

all : $(NAME)

$(NAME) : $(SOURCES) $(MAIN)
	$(CC) $(CFLAGS) $(SOURCES) $(MAIN) -o $(NAME)

%.o : %.c $(HEADERS)
	$(CC) $(CFLAGS) -I./includes -c $< -o $@

bonus : $(BONUS) 

$(BONUS) : $(SRC_BNS) $(SOURCES)
	$(CC) $(CFLAGS) $(SRC_BNS) $(SOURCES) -o $(BONUS)

clean :
	rm -f $(SOURCES) $(MAIN) $(SRC_BNS) 

fclean : 
	rm -f $(SOURCES) $(MAIN) $(SRC_BNS) $(NAME) $(BONUS) 

re : fclean all

.PHONY: fclean clean re all