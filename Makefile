# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mreis <mreis@student.42prague.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 20:42:33 by mreis             #+#    #+#              #
#    Updated: 2024/01/15 19:45:03 by mreis            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
## ARGUMENTS

NAME 	= libftprintf.a
AR		= ar rc
CFLAGS 	= -Wall -Werror -Wextra
CC 		= cc
RM 		= rm -rf
SRC_DIR = src
INC		= -I inc/
BIN_DIR = bin

################################################################################
## COLORS

# Reset
END_COLOR	= \033[0m       # Text Reset

# Regular Colors
BLACK	= \033[0;30m        # Black
RED		= \033[0;31m          # Red
GREEN	= \033[0;32m        # Green
YELLOW	= \033[0;33m       # Yellow
BLUE	= \033[0;34m         # Blue
PURPLE	= \033[0;35m       # Purple
CYAN	= \033[0;36m         # Cyan
WHITE	= \033[0;37m        # White

################################################################################
## SOURCES

SRCS_FILES	= $(shell find ./src -type f -exec basename {} \; | rev | cut -d. -f2- | rev)

OBJ 		=	$(addprefix $(BIN_DIR)/, $(addsuffix .o, $(SRCS_FILES)))
SRC 		=	$(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRCS_FILES)))

################################################################################
## RULES

all:	$(NAME)

$(NAME):	$(OBJ)
		@$(AR) $(NAME) $(OBJ)
		@echo "$(GREEN)$(NAME) Compiled.$(END_COLOR)"

$(BIN_DIR)/%.o: $(SRC_DIR)/%.c Makefile | $(BIN_DIR)
		@$(CC) -c $(CFLAGS) $(INC) $< -o $@
		@echo "$(BLUE)Compiling... $(notdir $<)$(END_COLOR)"

$(BIN_DIR):
		@mkdir $(BIN_DIR)
		@echo "$(YELLOW)Object files created and moved to $(BIN_DIR)/ directory.$(END_COLOR)"

clean:
		@rm -rf $(BIN_DIR)
		@echo "$(PURPLE)Object files and bin/ cleaned.$(END_COLOR)"

fclean: 	clean
		@rm -f $(NAME)
		@echo "$(YELLOW)$(NAME) file cleaned.$(END_COLOR)"

re: 		fclean all
		@echo "$(GREEN)Cleaned all and rebuilt $(NAME) $(END_COLOR)"

test:
	@cc $(CFLAGS) $(LIB_INC) $(INC) test.c src/*.c
	@echo "$(CYAN)< Test compiled and ready to run a.out>$(END_COLOR)"

noflags:
	@cc $(LIB_INC) $(INC) test.c src/*.c
	@echo "$(CYAN)< Test compiled without flags and ready to run a.out>$(END_COLOR)"

################################################################################
## PHONY

.PHONY:		all clean fclean re test noflags