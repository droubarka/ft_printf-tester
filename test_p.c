#include "test.h"
#include <stdarg.h>
extern int ftstdout;
extern int fd_log;

extern int fd_log;
extern int ftstdout;
void test(char *format, void *p)
{
	int ft_return;	
	int dprintf_return;	
	reopen();

	ft_return = ft_printf(format,p);
	dprintf_return = dprintf(3,format, p);
	if (check(ft_return, dprintf_return, format) == 0)
	{

	}
}
void p_test (char *format)
{
	void *p1 = "";
	void *p2 = (void *) LLONG_MIN;
	void *p3 = (void *)(7);
	test(format, NULL);
	test(format,p1);
	test(format,p2);
	test(format,p3);
}
int main()
{
	print_title("p   :");
	p_test("%p");
	p_test("%-20.20p");
	p_test("%-20.0p");
	p_test("%-0.20p");
	p_test("%-0.0p");
	p_test("%-0p");
	p_test("%+010p");
	p_test("%-0+#40.20p");

	p_test("%+20.20p");
	p_test("%+20.0p");
	p_test("%+0.20p");
	p_test("%+0.0p");
	p_test("%+0p");

	p_test("% 20.20p");
	p_test("% 20.0p");
	p_test("% 0.20p");
	p_test("% 0.0p");
	p_test("% 0p");

	p_test("%+-20.20p");
	p_test("%+-20.0p");
	p_test("%+-0.20p");
	p_test("%+-0.0p");
	p_test("%+-0p");
	
	p_test("%+-#20.20p");
	p_test("%+-#20.0p");
	p_test("%+-#0.20p");
	p_test("%+-#0.0p");
	p_test("%+-#0p");
	return 0;
}

