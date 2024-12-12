
#include "test.h"

#include <stdarg.h>

extern int fd_log;
extern int ftstdout;

void test(char *format, char *string)
{
	int ft_return;
	int dprintf_return;

	reopen();

	ft_return = ft_printf(format, string);
	dprintf_return  = dprintf(3, format, string);

	if (check(ft_return, dprintf_return, format))
	{

	}
}

void s_test(char *format)
{
	test(format, NULL);
	test(format, "");
	test(format, "0123456789");
}

int main(void)
{
	print_title("Conversion specifier: s");

	s_test("%s");
	s_test("%-20.20s");
	s_test("%-20.0s");
	s_test("%-0.20s");
	s_test("%-0.0s");
	s_test("%-0s");

	s_test("%+20.20s");
	s_test("%+20.0s");
	s_test("%+0.20s");
	s_test("%+0.0s");
	s_test("%+0s");

	s_test("% 20.20s");
	s_test("% 20.0s");
	s_test("%20.10s");
	s_test("% 0.20s");
	s_test("% 0.0s");
	s_test("% 0s");

	s_test("%+-20.20s");
	s_test("%+-20.0s");
	s_test("%+-0.20s");
	s_test("%+-0.0s");
	s_test("%+-0s");

	s_test("%+-#20.20s");
	s_test("%+-#20.0s");
	s_test("%+-#0.20s");
	s_test("%+-#0.0s");
	s_test("%+-#0s");
}
