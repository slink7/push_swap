
SRC =\
	main.c\
	t_stack0.c\
	t_stack1.c\

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
	cd libft/ ; make clean

fclean : clean
	rm $(NAME)
	cd libft/ ; make fclean

re : fclean all

TEST :
	./push_swap 2 1 | ./checker_linux "2 1"
	./push_swap 3 5 2 1 | ./checker_linux "3 5 2 1"
	./push_swap 2 | ./checker_linux "2"
	./push_swap 2 99999 1 | ./checker_linux "2 99999 1"
	./push_swap 2 1 3 | ./checker_linux "2 1 3"
	./push_swap 2 1 | ./checker_linux "2 1"
	./push_swap 2 1 | ./checker_linux "2 1"
	./push_swap 2 1 | ./checker_linux "2 1"
	./push_swap 2 1 | ./checker_linux "2 1"
	./push_swap 2 1 | ./checker_linux "2 1"
	./push_swap 2 1 | ./checker_linux "2 1"
	./push_swap 2 1 | ./checker_linux "2 1"
	./push_swap 2 1 | ./checker_linux "2 1"
	./push_swap 2 1 | ./checker_linux "2 1"
	./push_swap 2 1 | ./checker_linux "2 1"