# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/12 14:41:37 by gafreita          #+#    #+#              #
#    Updated: 2022/10/19 16:07:12 by gafreita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex00

SRC = megaphone.cpp

CC = c++

INC = -I .

FLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -f

COLOUR_GREEN=\033[1;32m
COLOUR_YELLOW=\033[1;33m
COLOUR_GREY=\033[1;30m
COLOUR_END=\033[0m

$(NAME): $(OBJS)
		@ $(CC) $(FLAGS) $(INC) $(SRC) $(LIB) -o $(NAME)
		@echo "$(COLOUR_GREEN) >> $(NAME) is ready to use $(COLOUR_END)"

all : $(NAME)

clean:
		@ $(RM) $(NAME)
		@echo "$(COLOUR_YELLOW) >> $(NAME) cleaned $(COLOUR_END)"

exe: clean all
		@echo "$(COLOUR_GREY) >> ./$(NAME) $(COLOUR_END)"
		@./$(NAME)

valgrind: clean all
		valgrind ./$(NAME)

valgrindfull: re
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

re: clean all

.PHONY: clean all re valgrind valgrindfull


