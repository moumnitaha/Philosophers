# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/24 11:36:52 by tmoumni           #+#    #+#              #
#    Updated: 2023/06/24 12:09:37 by tmoumni          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
HEADER = philo.h

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = philo.c init_philo.c init_args.c ft_get_time.c ft_atoi/ft_atoi.c ft_atoi/ft_isalnum.c\
		ft_atoi/ft_isdigit.c ft_atoi/ft_isalpha.c
OBJS=$(SRCS:%.c=%.o)

all: $(NAME)
	@echo "philo created successfully !"

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiling" $< to $@ ...

$(NAME): $(OBJS) $(SRCS) $(HEADER)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -f $(OBJS)

fclean:
	@rm -f $(OBJS) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re