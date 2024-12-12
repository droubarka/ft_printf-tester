
#include "test.h"

#include <stdarg.h>

extern int fd_log;
extern int ftstdout;

void test(char *format, long long d)
{
	int ft_return;
	int dprintf_return;

	reopen();

	ft_return = ft_printf(format, d);
	dprintf_return = dprintf(3, format, d);

	if (check(ft_return, dprintf_return, format))
	{

	}
}

void u_test(char *format)
{
	test(format, LONG_MAX);
	test(format, LONG_MIN);
	test(format, 0);
}

int main(void)
{
	print_title("Conversion specifier: u");

	u_test("%u");
	u_test("%-20.20u");
	u_test("%-20.0u");
	u_test("%-0.20u");
	u_test("%-0.0u");
	u_test("%-0u");

	u_test("%+20.20u");
	u_test("%+20.0u");
	u_test("%+0.20u");
	u_test("%+0.0u");
	u_test("%+0u");

	u_test("% 20.20u");
	u_test("% 20.0u");
	u_test("% 0.20u");
	u_test("% 0.0u");
	u_test("% 0u");

	u_test("%+-20.20u");
	u_test("%+-20.0u");
	u_test("%+-0.20u");
	u_test("%+-0.0u");
	u_test("%+-0u");

	u_test("%+-#20.20u");
	u_test("%+-#20.0u");
	u_test("%+-#0.20u");
	u_test("%+-#0.0u");
	u_test("%+-#0u");

	return 0;
}
