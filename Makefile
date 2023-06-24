# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/24 11:36:52 by tmoumni           #+#    #+#              #
#    Updated: 2023/06/24 12:17:25 by tmoumni          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BOLD = \033[1m
GREEN = \033[1;32m
RED=\033[1;31m
CYAN = \033[1;36m
END = \033[0m

NAME = philo
HEADER = philo.h

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = philo.c init_philo.c init_args.c ft_get_time.c ft_atoi/ft_atoi.c ft_atoi/ft_isalnum.c\
		ft_atoi/ft_isdigit.c ft_atoi/ft_isalpha.c
OBJS=$(SRCS:%.c=%.o)

all: $(NAME)
	@echo "\n$(GREEN)[[ philo created successfully! ]]$(END)\n"

$(NAME): $(OBJS) $(SRCS) $(HEADER)
	@echo "\nCreating $(GREEN)philo...$(END)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	@$(CC) -c $< $(CFLAGS) -o $@
	@echo "$(CYAN)Compiling:$(END)" $< "..."

clean:
	@rm -f $(OBJS)

fclean:
	@rm -f $(OBJS) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re