#  |  |  ___ \    \  |         |
#  |  |     ) |  |\/ |   _  |  |  /   _ 
# ___ __|  __/   |   |  (   |    <    __/ 
#    _|  _____| _|  _| \__,_| _|\_\ \___|
#                              by jcluzet
################################################################################
#                                     CONFIG                                   #
################################################################################

NAME        := push_swap
CC        := cc
FLAGS    := -Wall -Wextra -Werror
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        :=      push_swap.c ft_split.c operations.c operations2.c tool_lib.c list_lib.c sort_lib.c debug.c

OBJS        := $(addprefix objs/, $(SRCS:.c=.o))

.c.o:
	@${CC} ${FLAGS} -c $< -o ${<:.c=.o}

################################################################################
#                                  Makefile  objs                              #
################################################################################

CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

objs/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) -c $< -o $@

${NAME}:	${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			@${CC} ${FLAGS} -o ${NAME} ${OBJS}
			@echo "$(GREEN)$(NAME) created $(GREEN)✔️${CLR_RMV}"

all:		${NAME}

bonus:		all

clean:
			@ ${RM} *.o */*.o */*/*.o
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs $(GREEN)✔️"
			@ rm -rf objs

fclean:		clean
			@ ${RM} ${NAME}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary $(GREEN)✔️"

re:			fclean all

e:	fclean

m:	${NAME}
	@ ./${NAME} ${M}

args := "--1" "1 2 3a" "1 2 1" "" "1" "3 4 2 5 1" "2 1 3 6 5 8"

run: ${NAME}
	@for arg in $(args); do \
		echo "${BLUE}Running: $$arg$(CLR_RMV)" && ./${NAME} $$arg; \
	done
	@for arg in $(args); do \
		echo "${BLUE}Running: \"$$arg\"$(CLR_RMV)" && ./${NAME} "$$arg"; \
	done

check_leaks: ${NAME}
	@for arg in $(args); do \
		output=$$(valgrind --leak-check=full ./${NAME} $$arg 2>&1); \
		if echo "$$output" | grep -Eqi 'freed|0 errors'; then \
			echo "${BLUE}Testing with: $$arg" && echo "$(GREEN)No leaks/errors found! ✔️$(CLR_RMV)"; \
		else \
			echo "${CYAN}Testing with: $$arg$(RED)" && echo "$$output" | grep -Ei 'total|ERROR S' | sed 's/^[^ ]* //'; \
		fi; \
	done
	@for arg in $(args); do \
		output=$$(valgrind --leak-check=full ./${NAME} "$$arg" 2>&1); \
		if echo "$$output" | grep -Eqi 'freed|0 errors'; then \
			echo "${BLUE}Testing with: \"$$arg\"" && echo "$(GREEN)No leaks/errors found! ✔️$(CLR_RMV)"; \
		else \
			echo "${CYAN}Testing with: \"$$arg\"$(RED)" && echo "$$output" | grep -Ei 'total|ERROR S' | sed 's/^[^ ]* //'; \
		fi; \
	done

.PHONY:		all clean fclean re e m run check_leaks
