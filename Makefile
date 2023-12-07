
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