#include <unistd.h>

#include "libft.h"
#include "libtc.h"

int	tc_keymove(void)
{
	union u_buffer	buffer_u;

	ft_bzero(buffer_u.buf, sizeof(buffer_u.buf));
	while (read(STDIN_FILENO, buffer_u.buf, sizeof(buffer_u.buf)))
		return (buffer_u.value);
	return (0);
}
