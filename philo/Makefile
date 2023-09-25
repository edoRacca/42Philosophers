### VARIABLES ###

NAME = philo
PRNAME = philo

DIR = src/
FILES = actions.c checker.c destroy.c init.c main.c \
		parse.c threads.c utils.c

SRC = $(addprefix $(DIR),$(FILES))

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3 -pthread

RM = rm -rf
AR = ar rcs

OBJ = $(SRC:.c=.o)

### COLORS ###

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

### FUNCTIONS ###

all: $(NAME)

$(NAME): start $(OBJ)
	@$(CC) $(CFLAGS) -o $(PRNAME) $(OBJ)

clean:
	@echo "$(CYAN)Oh no, a lot of tr4sh!1!$(DEF_COLOR)"
	@sleep 0.2
	$(RM) $(OBJ)
	@echo "$(CYAN)All $(PRNAME) objects removed!$(DEF_COLOR)"

fclean: clean
	@$(RM) $(PRNAME)
	@echo "$(CYAN)And also $(PRNAME) executable!$(DEF_COLOR)"

re: fclean all

start:
	@echo "$(YELLOW)Let's compile $(PRNAME) project!$(DEF_COLOR)"
	@sleep 0.5

.PHONY: all clean fclean re start
