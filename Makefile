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
		src/destroy_my_ressources.c	\
		src/draw_my_sprites.c	\
		src/check_args.c	\
		src/create_my_ressources.c	\
		src/create_my_sounds.c	\
		src/create_my_sprites.c	\
		src/create_my_window.c	\
		src/close_my_window.c	\
		src/init_my_ressources.c	\
		src/move_barry.c	\
		src/move_env.c	\
		src/move_laser.c	\
		src/move_missile.c	\
		src/move_obstacles.c	\
		src/spawn_obstacles.c \
		src/play_sounds.c	\
		lib/file_to_array.c	\
		lib/my_str_to_line_array.c	\
		lib/my_strlen.c	\
		lib/my_strncpy.c	\
		lib/read_me.c

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

debug:	fclean
	$(CC) -o $(NAME) $(MAIN) $(SRC) $(CSFML) $(CFLAGS) -g3 -Wall -Wextra

# tests_run: re
# 	 $(CC) -o $(CRIT) $(SRC) $(TESTSRC) $(CRITFLAGS) $(CSFML) $(CFLAGS)
# 	 ./$(CRIT)

clean:
#	$(RMF) $(GCOVR)

fclean:	clean
	$(RMF) $(NAME)
#	$(RMF) $(CRIT)

re:	fclean all
