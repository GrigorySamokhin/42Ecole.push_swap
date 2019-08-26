# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/18 15:59:40 by gmeizo            #+#    #+#              #
#    Updated: 2019/07/18 15:59:46 by gmeizo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_C = 	./source/error_parse_pivot_pb_pa.c \
      		./source/min_max_sa_sb_check.c \
      		./source/rrr_rra_rrb_ra_rb.c \
      		./source/set_fill.c \
      		./source/sort_large.c \
      		./source/sort_one_two.c \
      		./source/add_func.c \

SCR_PUSH = source/push_swap.c

SCR_CHECK = source/checker.c

OBJ_PUSH = source/push_swap.o

OBJ_CHECK = source/checker.o

OBJ = $(patsubst %.c, %.o, $(notdir $(SRC_C)))

PUSH_NAME = push_swap

CHECK_NAME = checker

all: $(CHECK_NAME) $(PUSH_NAME)

$(PUSH_NAME): $(SRC_C)
	make -C includes/libft/
	gcc -Wall -Wextra -Werror -I includes/libft/includes/ -I includes -c $(SCR_PUSH) $(SRC_C)
	gcc $(SCR_PUSH) -o $(PUSH_NAME) $(OBJ) -I includes -I includes/libft/includes -L includes/libft/ -lft

$(CHECK_NAME): $(SRC_C)
	make -C includes/libft/
	gcc -Wall -Wextra -Werror -I includes/libft/includes/ -I includes -c $(SCR_CHECK) $(SRC_C)
	gcc $(SCR_CHECK) -o $(CHECK_NAME) $(OBJ) -I includes -I includes/libft/includes -L includes/libft/ -lft

clean:
	make -C includes/libft/ clean
	rm -rf $(OBJ)
	rm -rf $(notdir $(OBJ_CHECK))
	rm -rf $(notdir $(OBJ_PUSH))


fclean: clean
	make -C includes/libft/ fclean
	rm -rf $(PUSH_NAME)
	rm -rf $(CHECK_NAME)

re: fclean all