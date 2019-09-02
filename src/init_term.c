
#include <stdlib.h>
#include <unistd.h>
#include <termcap.h>

#include "libft.h"

int	init_term(void)
{
	char	*term_type;

	if (!(term_type = ft_getenv("TERM")))
	{
		ft_dprintf(STDERR_FILENO, "TERM environnement variable not defined.\n");
		return (1);
	}
	if (tgetent(NULL, term_type) != 1)
	{
		ft_dprintf(STDERR_FILENO, "Terminfo error.\n");
		return (1);
	}
	return (0);
}
