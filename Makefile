# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/15 07:36:15 by dtelnov           #+#    #+#              #
#    Updated: 2023/02/15 07:39:50 by dtelnov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

INCLUDE		= includes
SRC_DIR		= src/
OBJ_DIR		= objs/
FT_PRINTF	= ft_printf

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

SRC_FILES_S	=	push_swap

OBJF		=	.cache_exists

SRC_S 		= 	${addprefix ${SRC_DIR}, ${addsuffix .c, ${SRC_FILES_S}}}
OBJ_S 		= 	${addprefix ${OBJ_DIR}, ${addsuffix .o, ${SRC_FILES_S}}}

all:		${NAME}

bonus:		all

${NAME}:
			${MAKE} -C ${FT_PRINTF}
			${MAKE} push

push:		${OBJ_S}
			@${CC} ${OBJ_S} -L ${FT_PRINTF} -lftprintf -o push

${OBJ_DIR}%.o: ${SRC_DIR}%.c | ${OBJF}
			@${CC} ${CFLAGS} -I ${INCLUDE} -I ${FT_PRINTF}/includes -c $< -o $@

${OBJF}:
			@mkdir -p ${OBJ_DIR}

clean:
			@${RM} -r ${OBJ_DIR}

fclean:		clean
			make fclean -C ${FT_PRINTF}
			@${RM} push

re:			fclean all

.PHONY:		all clean fclean re