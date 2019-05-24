
#include "asm.h"

int		main(int argc, char **argv)
{
	t_data	data;

	if (argc == 1)
		ft_printf("Usage: ./asm <sourcefile.s>\n");
	else
	{
		init_data(&data, argv[argc - 1]);
		if (!(parsing_asm(&data)))
		{
			ft_printf("error\n");
			// ft_printf("Syntax error at token [TOKEN][%03d:%03d] %s \"%s\"\n", data.error.n_line, data.error.index, data.error.type, data.error.token);
			return (0);
		}
		else
		{
			// ft_printf("name    : |%s|\n", data.name);
			// ft_printf("comment : |%s|\n", data.comment);
			print_list(&data);
			ft_printf(SUCCESS, data.name_cor);
			return (1);
		}
		// erase_all(&data);
		// sleep(2);
	}
	return (0);
}
