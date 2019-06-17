
#include "asm.h"

void	init_data(t_data *data, char *av)
{
	int	i;

	i = -1;
	data->fd = -1;
	data->fd_file = -1;
	data->ret = -1;
	data->name_s = av;
	data->name_cor = NULL;
	data->quote = false;
	data->name_com = false;
	data->name_and_comment = 0;
	data->line.line = NULL;
	data->line.current = 0;
	data->line.n_line = 0;
	data->token = NULL;
	data->ins = NULL;
	data->ins_label = NULL;
	data->label = NULL;
	data->error.instruction = NULL;
	data->error.label = NULL;
	ft_bzero(data->header.prog_name, PROG_NAME_LENGTH);
	ft_bzero(data->header.comment, COMMENT_LENGTH);
	data->header.magic = COREWAR_EXEC_MAGIC;
}

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
		if (!(parsing_asm(&data)))
		{
			// ft_printf("Syntax error at token [TOKEN][%03d:%03d] %s \"%s\"\n", data.error.n_line, data.error.index, data.error.type, data.error.token);
		}
		else
		{
			if (!(write_file(&data, 0)))
				return (0);
			ft_printf(SUCCESS, data.name_cor);
		}
	}
	return (0);
}
