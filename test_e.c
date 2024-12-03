#include "test.h"
#include <stdarg.h>


extern int fd_log;
extern int ftstdout;
void test(char *format)
{
	
	int ft_return;	
	int dprintf_return;	
	reopen();
	ft_return = ft_printf(format);
	dprintf_return = dprintf(3, format);
	check(ft_return, dprintf_return, format);
}


int main()
{
	print_title("e :");
	
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

}

