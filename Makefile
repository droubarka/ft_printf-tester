TESTS = 
CC = gcc
FLAGS = -Wall -Werror -Wextra  -Iinclude -g
VAL = valgrind -q --leak-check=full --show-leak-kinds=all
SRC_DIR = src
TEST_DIR = .
UTILS = utils
LIBPATH = ..
LIBFTPRINTF = $(LIBPATH)/libftprintf.a
LINK_ALLTIME = check.c 
SPECIFIERS = c d s u x e
all: $(SPECIFIERS)



		
$(SPECIFIERS) : ft_printf.log
	echo $@
	echo $(LINK_ALLTIME)
	$(CC) $(FLAGS) $(LINK_ALLTIME) test_$@.c  $(LIBFTPRINTF) -o $@ && $(VAL) ./$@

ft_printf.log : 
	touch ft_printf.log
fclean:
	rm -rf $(SPECIFIERS) ft_printf.log

