#include "test.h"
#include <stdarg.h>


extern int fd_log;
extern int ftstdout;
void test(char *format, long long x)
{
	
	int ft_return;	
	int dprintf_return;	
	reopen();
	ft_return = ft_printf(format, x);
	dprintf_return = dprintf(3, format, x);
	if (check(ft_return, dprintf_return, format))
	{

	}
}

void x_test(char *format)
{
	test(format, LONG_MAX);
	test(format, UINT_MAX);
	test(format, LONG_MIN);	
	test(format, UINT_MAX);	
	test(format, 0);	

}
int main()
{
	print_title("x :");
	
	x_test("%x");

	x_test("%-0.20x");
	x_test("%-0.0x");
	x_test("%-0x ");

	x_test("%+20.20x");
	x_test("%+20.0x ");
	x_test("%+0.20x");
	x_test("%+0.0x");
	x_test("%+0x ");

	x_test("% 20.20x");
	x_test("% 20.0x");
	x_test("% 0.20x");
	x_test("% 0.0x");
	x_test("% 0x " );

	x_test("%+-20.20x");
	x_test("%+-20.0x");
	x_test("%+-0.20x");
	x_test("%+-0.0x");
	x_test("%+-0x");
	
	x_test("%+-#20.20x");
	x_test("%+-#20.0x");
	x_test("%+-#0.20x");
	x_test("%+-#0.0x");
	x_test("%+-#0x");

	dprintf(777, "\nX :\n");
	
	x_test("%X");
	x_test("%-20.20X");
	x_test("%-20.0X");
	x_test("%-0.20X");
	x_test("%-0.0X");
	x_test("%-0x ");

	x_test("%+20.20X");
	x_test("%+20.0x ");
	x_test("%+0.20X");
	x_test("%+0.0X");
	x_test("%+0x ");

	x_test("% 20.20X");
	x_test("% 20.0X");
	x_test("% 0.20X");
	x_test("% 0.0X");
	x_test("% 0x " );

	x_test("%+-20.20X");
	x_test("%+-20.0X");
	x_test("%+-0.20X");
	x_test("%+-0.0X");
	x_test("%+-0X");
	
	x_test("%+-#20.20X");
	x_test("%+-#20.0X");
	x_test("%+-#0.20X");
	x_test("%+-#0.0X");
	x_test("%+-#0X");
}

