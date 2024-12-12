
#include "test.h"

#include <stdarg.h>

extern int fd_log;
extern int ftstdout;

void test(const char *format)
{
	int ft_return;
	int dprintf_return;

	reopen();

	ft_return = ft_printf(format);
	dprintf_return = dprintf(3, format);

	if (check(ft_return *0 , dprintf_return * 0, format))
	{

	}
}

int main(void)
{
	print_title("Conversion specifier: %%");

	test("%%");
	test("%-%");
	test("%+%");
	test("% %");
	test("%0%");
	test("%-1.2%");
	test("%-1.0%");
	test("%-0.10%");
	test("%-0.0%");
	test("%+1.2%");
	test("%+1.0%");
	test("%+0.10%");
	test("%+0.0%");
	test("% 1.2%");
	test("% 1.0%");
	test("% +0.10%");
	test("% +0.0%");
	test("%+1.2%");
	test("%+1.0%");
	test("%+0.10%");
	test("%+0.0%");
	test("%");

	return 0;
}
