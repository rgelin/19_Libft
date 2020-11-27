# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgelin <rgelin@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/19 12:26:15 by rgelin            #+#    #+#              #
#    Updated: 2020/11/27 13:56:25 by rgelin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC          =       gcc

CFLAGS      =       -Wall -Wextra -Werror

SRCS        =       ft_atoi.c \
					ft_bzero.c \
					ft_calloc.c \
					ft_isalnum.c \
					ft_isalpha.c \
					ft_isascii.c \
					ft_isdigit.c \
					ft_isprint.c \
					ft_itoa.c \
					ft_memccpy.c \
					ft_memchr.c \
					ft_memcmp.c \
					ft_memcpy.c \
					ft_memmove.c \
					ft_memset.c \
					ft_putchar_fd.c \
					ft_putendl_fd.c \
					ft_putnbr_fd.c \
					ft_putstr_fd.c \
					ft_split.c \
					ft_strchr.c \
					ft_strdup.c \
					ft_strjoin.c \
					ft_strlcat.c \
					ft_strlcpy.c \
					ft_strlen.c \
					ft_strmapi.c \
					ft_strncmp.c \
					ft_strnstr.c \
					ft_strrchr.c \
					ft_strtrim.c \
					ft_substr.c \
					ft_tolower.c \
					ft_toupper.c 
					
BSRCS		=		ft_lstadd_back.c \
					ft_lstadd_front.c \
					ft_lstclear.c \
					ft_lstdelone.c \
					ft_lstiter.c \
					ft_lstlast.c \
					ft_lstmap.c \
					ft_lstnew.c \
					ft_lstsize.c 
					
OBJS        =       $(SRCS:%.c=%.o)

BOBJS		=		$(BSRCS:%.c=%.o)

REMOVE		=		rm -f

NAME        =       libft.a

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
			
all:		$(NAME)

$(NAME):	$(OBJS)
			@ar rc  $(NAME) $(OBJS)
			@ranlib $(NAME)

clean:
			@$(REMOVE) $(OBJS) $(BOBJS)

fclean:		clean
			@$(REMOVE) $(NAME)

re:			fclean all

bonus:		$(OBJS) $(BOBJS)
			@ar rc $(NAME) $(OBJS) $(BOBJS)

.PHONY: all clean fclean re compile
