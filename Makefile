
SRC =\
	main.c\
	t_stack0.c\
	t_stack1.c\
	t_stack2.c\
	ft_swap.c\
	ft_push.c\
	ft_rotate.c\
	ft_reverse_rotate.c\
	gitan_sort.c\
	run_sort.c\
	ft_ordered_pb.c\
	ft_ordered_pa.c\
	ft_puttop.c

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(notdir $(basename $(SRC)))))

NAME = push_swap

CSFLAGS = -Wall -Werror -Werror 

all : $(NAME)

libft/libft.a :
	cd libft/ ; make bonus

$(OBJ_DIR) :
	mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.c
	cc -g3 $(CFLAGS) -o $@ -c $< -Ilibft/

$(NAME) : $(OBJ_DIR) $(OBJ) libft/libft.a
	cc -g3 -o $(NAME) $(OBJ) -Llibft/ -lft

clean :
	rm $(OBJ)

fclean : clean
	rm $(NAME)
	cd libft/ ; make fclean

re : fclean all

CHECKER = ../checker_linux

spec :
	printf "./push_swap %s > err.txt\n" {0..4}\ {0..4}\ {0..4}\ {0..4}\ {0..4} > script.sh
	bash -x script.sh

TEST : all
	@cd push_swap_tester ; make
	@echo "\n\t\e[100mTEST 3\e[0m"
	@cd push_swap_tester ; ./complexity 3 100 3 $(CHECKER) || true
	@echo "\n\t\e[100mTEST 5\e[0m"
	@cd push_swap_tester ; ./complexity 5 100 12 $(CHECKER) || true
	@echo "\n\t\e[100mTEST 100\e[0m"
	@cd push_swap_tester ; ./complexity 100 100 1500 $(CHECKER) || true
	@echo "\n\t\e[100mTEST 500\e[0m"
	@cd push_swap_tester ; ./complexity 500 100 5500 $(CHECKER) || true

st : all
	@echo "\n\t\e[100mTEST 100\e[0m"
	@cd push_swap_tester ; ./complexity 100 100 800 $(CHECKER) > tmp.txt ; tail -n 4 tmp.txt
	@echo "\n\t\e[100mTEST 3\e[0m"
	@cd push_swap_tester ; ./complexity 3 100 3 $(CHECKER) > tmp.txt ; tail -n 4 tmp.txt
	@echo "\n\t\e[100mTEST 5\e[0m"
	@cd push_swap_tester ; ./complexity 5 100 12 $(CHECKER) > tmp.txt ; tail -n 4 tmp.txt