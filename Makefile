NAME		=	so_long
SRC 		= $(wildcard *.c)
OBJ			= $(SRC:.c=.o)
FLAGS 		= -Wall -Wextra -Werror
RM 			= rm -f
CC 			= cc
AR 			= ar rcs

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@ 

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -lmlx -framework OpenGl -framework AppKit -o so_long

clean : 
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re