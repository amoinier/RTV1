# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/07 12:02:38 by amoinier          #+#    #+#              #
#    Updated: 2016/03/18 17:33:19 by amoinier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED =		\033[31m
GRE =		\033[32m
YEL =		\033[33m
BLU =		\033[34m
CYA =		\033[36m
STD =		\033[39m

NAME =		rtv1

IDIR =		./incs/

SDIR =		./srcs/
SRCS =		$(shell ls srcs/)

ODIR =		./objs/
OBJS =		$(SRCS:.c=.o)
OBCC =		$(addprefix $(ODIR),$(OBJS))

FLAG =		-g -O3 -Wall -Wextra -Werror -I$(IDIR)

all: $(NAME)

$(NAME): header $(OBCC)
	@echo "  ${BLU}+ Compilation program:${STD} $@"
	@make -C ./libft/
	@gcc $(FLAG) $(OBCC) ./libft/libft.a -I./incs/ -L/usr/local/lib/ -I/usr/local/include -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(ODIR)%.o: $(SDIR)%.c
	@echo "  ${GRE}+ Compilation:${STD} $^"
	@gcc $^ $(FLAG) -c -o $@

header:
	@mkdir -p $(ODIR)
	@echo "${YEL}"
	@echo "WOLF 3D"
	@echo "By: amoinier"
	@echo
	@echo "${STD}"

clean: header
	@echo "  ${RED}- Remove objects${STD}"
	@rm -rf $(OBCC)

fclean: clean
	@echo "  ${RED}- Remove $(NAME)${STD}"
	@make -C ./libft/ fclean
	@rm -f $(NAME)

.PHONY: all $(NAME) $(ODIR)%.o header norme clean fclean re

re: fclean all
