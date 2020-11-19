# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgelin <rgelin@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/19 12:26:15 by rgelin            #+#    #+#              #
#    Updated: 2020/11/19 16:18:49 by rgelin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC          =       gcc -c
CFLAGS      =       -Wall -Wextra -Werror
SRCS        =       *.c
OBJS        =       *.o
NAME        =       libft.a
all:        ${NAME}
${NAME}:    compile
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}
compile:
	${CC} ${CFLAGS} ${SRCS}
clean:
	rm -f ${OBJS}
fclean:     clean
	rm -f ${NAME}
re:		fclean all
.PHONY: all clean fclean re compile
