CC = cc
FLAGS = -Wall -Wextra -Werror -Iinclude -g -Wno-format-security
VAL = valgrind -q --leak-check=full --show-leak-kinds=all

TESTS = 
SRC_DIR = src
TEST_DIR = .
UTILS = utils

LIBPATH = ..
LIBFTPRINTF = $(LIBPATH)/libftprintf.a

LINK_ALLTIME = check.c
SPECIFIERS = c s p d u x e

all: default

default: fclean $(SPECIFIERS)
	@echo "\n\n[!] See '$$(pwd)/ft_printf.log'\n"
	@make -C $(LIBPATH) fclean
	@make clean

$(SPECIFIERS): ft_printf.log $(LIBFTPRINTF)
	@$(CC) $(FLAGS) $(LINK_ALLTIME) test_$@.c $(LIBFTPRINTF) -o $@ && $(VAL) ./$@

ft_printf.log:
	@touch ft_printf.log

$(LIBFTPRINTF):
	@make -C $(LIBPATH) all clean

clean:
	@rm -rf $(SPECIFIERS)

fclean: clean
	@rm -rf ft_printf.log
