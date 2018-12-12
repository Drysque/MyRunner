##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for My Runner
##

CC	=	gcc

RMF     =       rm -f

CFLAGS	=	-I./include/

SRC	=	src/my_runner.c	\
		src/check_args.c	\
		src/create_my_window.c	\
		src/close_my_window.c

MAIN	=	src/main.c

# TESTSRC	=	tests/test_my_runner.c

NAME	=	my_runner

# CRIT	=	unit_tests

CSFML	=	-l csfml-graphics -l csfml-system -l csfml-window -l csfml-audio

# CRITFLAGS	=	--coverage -lcriterion

# GCOVR	=	*.gc*

all:	$(NAME)

$(NAME):
	$(CC) -o $(NAME) $(MAIN) $(SRC) $(CSFML) $(CFLAGS)

# tests_run: re
# 	 $(CC) -o $(CRIT) $(SRC) $(TESTSRC) $(CRITFLAGS) $(CSFML) $(CFLAGS)
# 	 ./$(CRIT)

clean:
	$(RMF) $(GCOVR)

fclean:	clean
	$(RMF) $(NAME)
	$(RMF) $(CRIT)

re:	fclean all
