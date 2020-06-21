# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybakker <ybakker@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/01 10:51:58 by ybakker           #+#    #+#              #
#    Updated: 2020/06/21 19:16:54 by haachtch      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRC		=	ft_memset ft_bzero ft_memcpy ft_memccpy ft_memmove ft_putnbr_fd\
	ft_memchr ft_calloc ft_putchar_fd ft_putendl_fd ft_putstr_fd\
	ft_strlen ft_strlcpy ft_strlcat ft_strrchr ft_strnstr ft_itoa\
	ft_split ft_strchr ft_strdup ft_strjoin ft_strmapi ft_strtrim\
	ft_substr ft_memcmp ft_strncmp ft_atoi ft_isalpha ft_isalnum\
	ft_isascii ft_isprint ft_toupper ft_tolower ft_isdigit\
	ft_atoi_at_index ft_iswhitespace ft_strdup2
CFILES	=	$(SRC:%=%.c)
OFILES	=	$(SRC:%=%.o)
FLAGS	=	-Wall -Wextra -Werror
AR_COMMAND	=	ar rsv

all: $(NAME)

$(NAME): $(OFILES)
	$(AR_COMMAND) $(NAME) $(OFILES)

%.o: %.c
	@gcc -o $@ -c $< $(FLAGS)

clean:
	rm -f $(OFILES) $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all
