SRCS = main.cpp myMot.cpp
OBJS = $(addprefix ${OBJDIR}/,${SRCS:.cpp=.o})
NAME = myMot
DEPF = -MMD -MP
DEP = ${OBJS:.o=.d}
OBJDIR = helper_files
CC = c++
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
all: ${NAME}

$(NAME)	: ${OBJS}
	${CC} ${CFLAGS} ${DEPF} ${OBJS} -o $@

${OBJDIR}/%.o:%.cpp
	@mkdir -p ${@D}
	${CC} ${CFLAGS} ${DEPF} -c $< -o $@

clean:
	rm -rf ${OBJDIR}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re

-include ${DEP}
