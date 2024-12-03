#include "test.h"
#include <stdarg.h>

extern int ftstdout;
extern int fd_log;

void test(char *format, int d)
{
	int ft_return;	
	int dprintf_return;	
	reopen();
	ft_return = ft_printf(format, d);
	dprintf_return = dprintf(3, format, d + 1);
	if (check(ft_return, dprintf_return, format))
	{

		
	}
}

void d_test(char *format)
{
	test(format, INT_MAX);
	test(format, INT_MIN);
	test(format, -7);
	test(format, 7);
	test(format, 0);
}
int main()
{
	print_title("d et i:");
	
	d_test("%d");
	d_test("%-20.20d");
	d_test("%-20.0d");
	d_test("%-0.20d");
	d_test("%-0.0d");
	d_test("%-0d");
	d_test("%0+7.2d");

	d_test("%- 0.0d");
	d_test("%-0.10d");
	d_test("%+010d");
	d_test("%-0+#20.10d");

	d_test("%+20.20d");
	d_test("%+20.0d");
	d_test("%+0.20d");
	d_test("%+0.0d");
	d_test("%+0d");

	d_test("% 20.20d");
	d_test("% 20.0d");
	d_test("% 0.20d");
	d_test("% 0.0d");
	d_test("% 0d");

	d_test("%+-20.20d");
	d_test("%+-20.0d");
	d_test("%+-0.20d");
	d_test("%+-0.0d");
	d_test("%+-0d");
	
	d_test("%+-#20.20d");
	d_test("%+-#20.0d");
	d_test("%+-#0.20d");
	d_test("%+-#0.0d");
	d_test("%+-#0d");
	
	return 0;
}
