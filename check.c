#include "test.h"
#include <stdarg.h>
#include <fcntl.h>
#define BUFFER_SIZE (1024 * 1024)
char ft_buffer[BUFFER_SIZE];
char dprintf_buffer[BUFFER_SIZE];
int ft_pipe[2] ={0,1};
int dprintf_pipe[2] ={2,3};
char ft_buffer[];
int ftstdout = 0;
int fd_log = 0;
int id = 1;
void reopen(void)
{
	if (ftstdout == 0)
		ftstdout = dup2(1,777);
	close(ft_pipe[0]);
	close(ft_pipe[1]);
	close(dprintf_pipe[0]);
	close(dprintf_pipe[1]);
	pipe(ft_pipe);
	pipe(dprintf_pipe);
	//dprintf(ftstdout, "%d\n", ft_pipe[0], ft_pipe[1]);
	assert((ft_pipe[0] == 0));
	assert((ft_pipe[1] == 1));
	assert((dprintf_pipe[0] == 2));
	assert((dprintf_pipe[1] == 3));
	if (fd_log == 0)
	{
		fd_log = open("ft_printf.log", O_WRONLY, 644);
		fd_log = dup2(fd_log,42);
		assert(fd_log == 42);
	}
	
	memset(ft_buffer, 0, BUFFER_SIZE);
	memset(dprintf_buffer, 0, BUFFER_SIZE);
}

void ft_assert(int condition)
{
	if (condition)
	{
		dprintf(ftstdout, "%s%s%s",GRN, "\a[OK]", RST);
	}
	else
	{
		dprintf(ftstdout, "%s%s%s", RED, "[KO]", RST);
	}
}
int check(int ft_return, int dprintf_return, const char *format)
{
	int return_match;
	int output_match;
	write(1, " ", 1);
	write(3, " ", 1);
	read(0, ft_buffer, BUFFER_SIZE);
	read(2, dprintf_buffer, BUFFER_SIZE);
	//dprintf(777, "%s, %i\n",ft_buffer, ft_return);
	//dprintf(777, "%s, %i\n",dprintf_buffer, dprintf_return);
	return_match = ft_return == dprintf_return;
	output_match = strcmp(ft_buffer, dprintf_buffer) == 0;

	if (output_match == 0 || return_match == 0)
	{
		dprintf(fd_log, "return value      : printf  %d  , ft_printf %d\n", dprintf_return, ft_return);
		dprintf(fd_log, "ft_printf output  : %s\n", ft_buffer);
		dprintf(fd_log, "std printf output : %s\n", dprintf_buffer);
		dprintf(fd_log, "format            : %s.\n", format);
		dprintf(fd_log, "--------------------------------------------------\n");
	}
	ft_assert(return_match && output_match);
	return (1);
}
void print_title(char *format, ...)
{
	va_list arg;
	va_start(arg, format);
	printf("\n");
	vprintf(format, arg);
	fflush(stdout);
	printf("\n");
}
