#include "asm.h"

int		asm_main(int argc, char **argv)
{
	t_data	data;

	if (argc == 1)
		ft_printf("Usage: ./asm <sourcefile.s>\n");
	else
	{
		init_data(&data, argv[argc - 1]);
		if (!(parsing_asm(&data)))
		{
			// ft_printf("Syntax error at token [TOKEN][%03d:%03d] %s \"%s\"\n", data.error.n_line, data.error.index, data.error.type, data.error.token);
			return (0);
		}
		else
		{
			ft_printf("name    : |%s|\n", data.name);
			ft_printf("comment : |%s|\n", data.comment);
			print_list(&data);
			ft_printf(SUCCESS, data.name_cor);
			return (1);
		}
		// erase_all(&data);
		// sleep(2);
	}
	return (0);
}

int		main(void)
{
	char **test;
	int	ret;
	
	test = (char **)malloc(sizeof(char *) * (2 + 1));
	test[0] = ft_strdup("asm");
	test[1] = (char *)malloc(sizeof(char) * 100);
	ft_strcpy(test[1], "../asm/test_1.s");
	ret = asm_main(2, test);
	if (ret == 1)
		ft_printf("OK\n");
	else
		ft_printf("NOT ! NOT ! NOT!\n");
	ft_printf("---------------------------------------------------------------------\n");
	ft_strcpy(test[1], "../asm/test_2.s");
	ret = asm_main(2, test);
	if (ret == 1)
		ft_printf("OK\n");
	else
		ft_printf("NOT ! NOT ! NOT!\n");
	ft_printf("---------------------------------------------------------------------\n");
	ft_strcpy(test[1], "../asm/test_3.s");
	ret = asm_main(2, test);
	if (ret == 1)
		ft_printf("OK\n");
	else
		ft_printf("NOT ! NOT ! NOT!\n");
	ft_printf("---------------------------------------------------------------------\n");
	
	ft_strcpy(test[1], "../asm/test_4.s");
	ret = asm_main(2, test);
	if (ret == 0)
		ft_printf("OK\n");
	else
		ft_printf("NOT ! NOT ! NOT!\n");
	ft_printf("---------------------------------------------------------------------\n");
	
	ft_strcpy(test[1], "../asm/test_5.s");
	ret = asm_main(2, test);
	if (ret == 0)
		ft_printf("OK\n");
	else
		ft_printf("NOT ! NOT ! NOT!\n");
	ft_printf("---------------------------------------------------------------------\n");
	
	ft_strcpy(test[1], "../asm/test_6.s");
	ret = asm_main(2, test);
	if (ret == 1)
		ft_printf("OK\n");
	else
		ft_printf("NOT ! NOT ! NOT!\n");
	ft_printf("---------------------------------------------------------------------\n");
	ft_strcpy(test[1], "../asm/test_7.s");
	ret = asm_main(2, test);
	if (ret == 1)
		ft_printf("OK\n");
	else
		ft_printf("NOT ! NOT ! NOT!\n");
	ft_printf("---------------------------------------------------------------------\n");
	return (0);
}
