

#===CONFIGURATION===
NAME = push_swap
NAME_BONUS = checker

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
	main_checker.c\
	t_stack_utils0.c\
	t_stack_utils1.c\
	t_stack_utils2.c\
	ft_push.c\
	ft_rotate.c\
	ft_reverse_rotate.c\
	ft_swap.c\
	execute.c

CFLAGS = -Wall -Werror -Wextra

LIBS = \
	libft/libft.a\

INCLUDES = -Ilibft/

OBJ_DIR = obj

#===AUTOMATIC VARS===

OBJ = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(notdir $(basename $(SRC)))))
OBJ_BONUS = $(addprefix $(OBJ_DIR)/, $(addsuffix _bonus.o, $(notdir $(basename $(SRC_BONUS)))))

LIB_FLAGS = $(addprefix -L, $(dir $(LIBS))) $(addprefix -l, $(patsubst lib%.a, %, $(notdir $(LIBS))))

#===TARGETS===
all : $(NAME)

bonus : $(NAME_BONUS)

#===COMPILING===
$(OBJ_DIR) :
	$(shell mkdir -p $(OBJ_DIR))
$(OBJ_DIR)/%.o : %.c
	cc $(CFLAGS) -o $@ -c $< $(INCLUDES)
$(OBJ_DIR)/%_bonus.o : %.c
	cc $(CFLAGS) -o $@ -c $< $(INCLUDES)
%.a :
	make -C $(dir $@)

#===LINKING===
$(NAME_BONUS) : $(OBJ_DIR) $(LIBS) $(OBJ_BONUS)
	cc -o $(NAME_BONUS) $(OBJ_BONUS) $(LIB_FLAGS)
$(NAME) : $(OBJ_DIR) $(LIBS) $(OBJ)
	cc -o $(NAME) $(OBJ) $(LIB_FLAGS)

#===CLEAN===
clean :
	rm -rf $(OBJ_DIR) || true

#===FCLEAN===
fclean : clean
	rm -f $(NAME) $(NAME_BONUS) || true

#===RE===
re : fclean all

e :
	echo $(OBJ)

.PHONY : re fclean clean all default bonus