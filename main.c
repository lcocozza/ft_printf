#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	char	*mem;

	mem = ft_strdup("memory");
	ft_printf("Hello %c world\n", 'c');
	// printf("ptr=%p\n", mem);
	free(mem);

	return (0);
}
