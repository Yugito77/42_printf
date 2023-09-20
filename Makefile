# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/13 18:41:42 by hcherpre          #+#    #+#              #
#    Updated: 2021/12/14 10:16:28 by hcherpre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a

LINKER =	ar rcs

CC =	gcc

RM =	rm -rf

SRCS =	printf.c\
	putchar.c\
	putnbr_base_unsigned.c\
	putnbr_base.c\
	putnbr_ptr.c\
	putstr.c


OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Werror -Wextra

$(NAME): ${OBJS}
		${LINKER} ${NAME} ${OBJS}

all:	${NAME}

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
		${RM} ${OBJS}
fclean: clean
		${RM} ${NAME}

re : fclean all

	
		