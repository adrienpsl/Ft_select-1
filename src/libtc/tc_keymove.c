#include <unistd.h>

#include "libft.h"
#include "libtc.h"

int	tc_keymove(void)
{
	union u_buffer	buffer_u;

	ft_bzero(buffer_u.buf, sizeof(buffer_u.buf));
	while (read(STDIN_FILENO, buffer_u.buf, sizeof(buffer_u.buf)))
	{
		switch (buffer_u.value)
		{
			case del:
				return (del);
			case up:
				return (up);
			case down:
				return (down);
			case left:
				return (left);
			case right:
				return (right);
			case space:
				return (space);
			case newline:
				return (newline);
		}
		ft_bzero(buffer_u.buf, sizeof(buffer_u.buf));
	}
	return (0);
}
