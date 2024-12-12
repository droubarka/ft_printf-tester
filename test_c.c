
#include "test.h"

#include <fcntl.h>
#include <stdarg.h>

extern int fd_log;
extern int ftstdout;

void test(char *format, char c)
{
	int ft_return;
	int dprintf_return;

	reopen();

	ft_return = ft_printf(format, c);
	dprintf_return = dprintf(3, format, c);

	if (check(ft_return, dprintf_return, format))
	{

	}
}

void test_c(char *format)
{
	test(format, -'A');
	test(format, 0);
	test(format, 'A');
}

int main(void)
{
	print_title("Conversion specifier: c");

	test_c("%-10c");
	test_c("%-+78.0c");
	test_c("%-+0.0c");
	test_c("%-+0.4c");
	test_c("%+78.0c");
	test_c("%+0.0c");
	test_c("%+0.4c");
	test_c("% 78.0c");
	test_c("% 0.0c");
	test_c("% 0.4c");
	test_c("%- 78.0c");
	test_c("%- 0.0c");
	test_c("%- 0.4c");

	return 0;
}
