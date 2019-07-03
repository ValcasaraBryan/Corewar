
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
	data->name = false;
	data->comment = false;
	data->line.line = NULL;
	data->line.current = 0;
	data->token = NULL;
	data->ins = NULL;
	data->ins_label = NULL;
	data->label = NULL;
	data->error.error = false;
	data->n_line = 1;
	data->index = 0;
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
			ft_fprintf(NO_FILE, S_ERR, OPEN, data.name_s);
			return (0);
		}
		if ((parsing_asm(&data)))
			if (!(write_file(&data, 0)))
			{
			ft_printf("token\t:\t%p\nins\t:\t%p\nlabel\t:\t%p\nn_label\t:\t%p\n", data.token, data.ins, data.ins_label, data.label);
				while (1);
				return (0);
			}
			ft_printf("token\t:\t%p\nins\t:\t%p\nlabel\t:\t%p\nn_label\t:\t%p\n", data.token, data.ins, data.ins_label, data.label);
		while (1);
	}
	return (0);
}
