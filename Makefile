NAME	= 	push_swap

SRCS	= 	parsing/arg_check_fts.c \
			parsing/conversion_fts.c \
			moves/execute_moves_fts.c \
			moves/order_fts.c \
			moves/push_moves.c \
			moves/swap_moves.c \
			moves/rotate_moves.c \
			moves/reverse_moves.c \
			list_creation/list_fts.c \
			list_creation/new_list_fts.c \
			cost_algorithms/new_struct_fts.c \
			cost_algorithms/struct_fts.c \
			cost_algorithms/target_fts.c \
			push_swap.c \
			 

OBJS    := ${SRCS:.c=.o}

LIBFT = libft/

CC	= clang

RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror -g

all:	$(NAME)

$(NAME):    compiling $(OBJS)
			@make all -C $(LIBFT)
			@$(CC) $(CFLAGS) $(OBJS) $(LIB) -L$(LIBFT) -lft -o $(NAME)

$%.o: %.c
            @echo "$(BLUE)Compiling: $(RESET)$(notdir $<)"
			@$(CC) $(CFLAGS) -c $< -o $@

compiling:
			@echo "$(YELLOW)Compiling push_swap!$(RESET)"

clean:
			@make clean -C $(LIBFT)
			@rm -rf $(OBJS)
			@echo "$(RED)Cleaning LIBFT.$(RESET)"
            
fclean:
			@make fclean -C $(LIBFT)
			@rm -rf $(OBJS)
			@rm -rf $(NAME)
			@echo "$(RED)Fcleaning LIBFT.$(RESET)"

re:			fclean all

.PHONY:		all clean fclean re