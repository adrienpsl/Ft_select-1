
#include <unistd.h>
#include <termcap.h>

int	ft_tcoutput(int c)
{
	if (write(STDOUT_FILENO, &c, 1) != 1)
		return (-1);
	else
		return (c);
}
