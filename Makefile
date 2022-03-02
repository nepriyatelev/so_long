# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: modysseu <modysseu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/27 20:51:10 by modysseu          #+#    #+#              #
#    Updated: 2022/01/06 20:04:13 by modysseu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

LIST	=	so_long.c \
			./library_functions/ft_split.c \
			./library_functions/ft_strjoin.c\
			./library_functions/ft_strlen.c\
			./library_functions/ft_substr.c\
			./library_functions/ft_itoa.c\
			read_map.c\
			error_processing.c\
			map_dawing.c\
			handling_keystrokes.c\
			render_map.c\
			init_img.c

HEADER	=	so_long.h
			
OBJ = $(LIST:.c=.o)

FLAGS = -Wall -Wextra -Werror -c

all : $(NAME)

$(NAME) : $(OBJ)
	gcc $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c $(HEADER) Makefile
	gcc $(FLAGS) -Imlx -c $< -o $@
	
clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)
	
bonus : $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus