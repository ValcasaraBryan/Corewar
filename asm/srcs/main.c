
#include "asm.h"

int		main(int argc, char **argv)
{
	t_data	data;

	if (argc == 1)
		ft_printf("Usage: ./asm <sourcefile.s>\n");
	else
	{
		init_data(&data, argv[argc - 1]);
		if ((data.fd = open(data.name_s, O_RDONLY)) == -1)
		{
			ft_fprintf(NO_FILE, S_ERR, data.name_s);
			return (0);
		}
		// unsigned char buf;
		// int	ret;
		// int	i;
// 
	// i = 1;
		// while ((ret = read(data.fd, &buf, 1)) > 0)
		// {
			// ft_printf("%02x", buf);
			// i++;
		// }
		if (!(parsing_asm(&data)))
		{
			ft_printf("error\n");
			// ft_printf("Syntax error at token [TOKEN][%03d:%03d] %s \"%s\"\n", data.error.n_line, data.error.index, data.error.type, data.error.token);
			return (0);
		}
		// else
		// {
			// ft_printf("MAIN :\n");
			// ft_printf("name    : |%s|\n", data.name);
			// ft_printf("comment : |%s|\n", data.comment);
			print_list(&data);
			// ft_printf(SUCCESS, data.name_cor);
			// while (1);
			// return (1);
		// }
		// erase_all(&data);
		// sleep(2);
	}
	return (0);
}
