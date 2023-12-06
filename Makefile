
SRC = main.c

OBJ = $(addsuffix .o, $(notdir $(basename $(SRC))))

NAME = push_swap

CSFLAGS = -Wall -Werror -Werror

all : $(NAME)

libft/libft.a :
	cd libft/ ; make all

%.o : %.c
	cc $(CFLAGS) -o $@ -c $< -Ilibft/

$(NAME) : $(OBJ) libft/libft.a
	cc -o $(NAME) $(OBJ) -Llibft/ -lft

clean :
	rm $(OBJ)
	cd libft/ ; make clean

fclean : clean
	rm $(NAME)
	cd libft/ ; make fclean

re : fclean all