
SRC =\
	main.c\
	t_stack0.c\
	t_stack1.c\
	t_stack2.c\
	ft_swap.c\
	ft_push.c\
	ft_rotate.c\
	ft_reverse_rotate.c\
	gitan_sort.c

OBJ = $(addsuffix .o, $(notdir $(basename $(SRC))))

NAME = push_swap

CSFLAGS = -Wall -Werror -Werror 

all : $(NAME)

libft/libft.a :
	cd libft/ ; make bonus

%.o : %.c
	cc -g3 $(CFLAGS) -o $@ -c $< -Ilibft/

$(NAME) : $(OBJ) libft/libft.a
	cc -g3 -o $(NAME) $(OBJ) -Llibft/ -lft

clean :
	rm $(OBJ)

fclean : clean
	rm $(NAME)
	cd libft/ ; make fclean

re : fclean all

CHECKER = ../checker_linux

TEST : all
	@echo "\n\tTEST 100"
	@cd push_swap_tester ; ./complexity 100 100 800 $(CHECKER) > tmp.txt ; tail -n 4 tmp.txt
	@echo "\n\tTEST 3"
	@cd push_swap_tester ; ./complexity 3 100 3 $(CHECKER) > tmp.txt ; tail -n 4 tmp.txt
	@echo "\n\tTEST 5"
	@cd push_swap_tester ; ./complexity 5 100 12 $(CHECKER) > tmp.txt ; tail -n 4 tmp.txt