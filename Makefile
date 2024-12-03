TESTS = 
CC = gcc
FLAGS = -Wall -Werror -Wextra  -Iinclude -g -Wno-format-security
VAL = valgrind -q --leak-check=full --show-leak-kinds=all
SRC_DIR = src
TEST_DIR = .
UTILS = utils
LIBPATH = ..
LIBFTPRINTF = $(LIBPATH)/libftprintf.a
LINK_ALLTIME = check.c 
SPECIFIERS = c d s u x e
all: $(SPECIFIERS)


		
$(SPECIFIERS) : ft_printf.log  $(LIBFTPRINTF)
	@$(CC) $(FLAGS) $(LINK_ALLTIME) test_$@.c  $(LIBFTPRINTF) -o $@ && $(VAL) ./$@

$(LIBFTPRINTF) :
	@make all -C $(LIBPATH)
ft_printf.log : 
	@touch ft_printf.log
fclean:
	@rm -rf $(SPECIFIERS) ft_printf.log

