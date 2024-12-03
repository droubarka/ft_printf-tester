#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define RST "\x1B[0m"
int ft_printf(const char *format, ...);

int check(int ft_return, int dprintf_return, char *format);
void reopen(void);
void print_title(char *format, ...);