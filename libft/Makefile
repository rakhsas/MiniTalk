# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/12 18:03:18 by rakhsas           #+#    #+#              #
#    Updated: 2022/10/31 19:14:43 by rakhsas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC 		= 	ft_isalnum.c  	\
				ft_isalpha.c  	\
				ft_isdigit.c   	\
				ft_isprint.c  	\
				ft_memchr.c		\
				ft_memcmp.c		\
				ft_memmove.c	\
				ft_strlen.c		\
				ft_memset.c		\
				ft_isascii.c	\
				ft_bzero.c		\
				ft_memcpy.c		\
				ft_toupper.c	\
				ft_tolower.c	\
				ft_strchr.c		\
				ft_strrchr.c	\
				ft_strncmp.c	\
				ft_strlcpy.c	\
				ft_strlcat.c	\
				ft_strnstr.c	\
				ft_atoi.c		\
				ft_calloc.c		\
				ft_strdup.c		\
				ft_substr.c		\
				ft_strjoin.c	\
				ft_strtrim.c	\
				ft_split.c		\
				ft_itoa.c		\
				ft_strmapi.c	\
				ft_striteri.c	\
				ft_putchar_fd.c	\
				ft_putstr_fd.c	\
				ft_putendl_fd.c	\
				ft_putnbr_fd.c

BONUS_FILES = 	ft_lstnew.c			\
				ft_lstadd_front.c	\
				ft_lstsize.c		\
				ft_lstlast.c		\
				ft_lstadd_back.c	\
				ft_lstdelone.c		\
				ft_lstclear.c		\
				ft_lstiter.c

GCC = cc

CFLAGS = -Wall -Wextra -Werror 

OBJS = $(SRC:.c=.o)

BONUS_O = $(BONUS_FILES:.c=.o)

RM = rm -f

LIB = ar -rcs

all : $(NAME)

$(NAME) : $(OBJS)
	$(LIB) $(NAME) $(OBJS)

bonus : $(BONUS_O)
	$(LIB) $(NAME) $(BONUS_O)

# .c.o : 
# 	$(GCC) $(CFLAGS) -c $<

clean : 
	$(RM) $(OBJS) $(BONUS_O)

fclean : clean
			$(RM) $(NAME)

re : fclean all