#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	char	*mem;

	mem = ft_strdup("memory");
	ft_printf("%s %s %s\n", "un", "deux", "trois");
	printf("Hello %d world\n", 54536457);
	// printf("ptr=%p\n", mem);
	free(mem);

	return (0);
}
