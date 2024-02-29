
SRC =\
	main.c\
	t_stack_utils0.c\
	t_stack_utils1.c\
	t_stack_utils2.c\
	ft_swap.c\
	ft_push.c\
	ft_rotate.c\
	ft_reverse_rotate.c\
	targets.c\
	mekherbo_sort.c
SRC_BONUS =\
	main_bonus.c\
	t_stack_utils0.c\
	t_stack_utils1.c\
	t_stack_utils2.c\
	ft_push.c\
	ft_rotate.c\
	ft_reverse_rotate.c\
	ft_swap.c\
	execute.c

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(notdir $(basename $(SRC)))))
OBJ_BONUS = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(notdir $(basename $(SRC_BONUS)))))

NAME = push_swap
NAME_BONUS = checker

CSFLAGS = -Wall -Werror -Werror 

all : $(NAME)

bonus : $(NAME_BONUS)

libft/libft.a :
	cd libft/ ; make

$(OBJ_DIR) :
	mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.c
	cc -g3 $(CFLAGS) -o $@ -c $< -Ilibft/

$(NAME) : $(OBJ_DIR) $(OBJ) libft/libft.a
	cc -g3 -o $(NAME) $(OBJ) -Llibft/ -lft

$(NAME_BONUS) : $(OBJ_BONUS) $(OBJ) libft/libft.a
	cc -g3 -o $(NAME_BONUS) $(OBJ_BONUS) -Llibft/ -lft

clean :
	rm $(OBJ) || true
	rm $(OBJ_BONUS) || true

fclean : clean
	rm $(NAME) || true
	rm ./checker || true

re : fclean all
