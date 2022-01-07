#include <stdio.h>

FILE	*infile = 0;
int	num_input_strings = 0;
char	input_strings[480];
int	node1 = 0xfd;


int	blank_line(char *line)
{
	char	c;

	c = *line;
	while (1)
	{
		if (c == '\0')
			return (1);
		c = *line;
		line = line + 1;
		if (c = ' ')
			break ;
		c = *line;
	}
	return (0);
}


char	*skip(void)
{
	char	*in;
	int	r;

	do
	{
		in = fgets(input_strings + num_input_strings * 0x50, 0x50, infile);
		if (in == 0)
			return (0);
		r = blank_line(in);
	} while (r != 0)
	return (in);
}


char	*read_line(void)
{
	int	sk;
	char	*env;
	char	*curr_input;
	int	i = 0;

	sk = skip();
	if (sk == 0)
	{
		if (infile != stdin)
		{
			env = getenv("GRADE_BOMB");
			if (env == 0)
				exit(0);
			infile = stdin;
			sk = skip();
			if (sk == 0)
			{
				printf("Error: Premature EOF on stdin\n");
				explode_bomb();
			}
		}
	}

	curr_input = input_strings + (num_input_strings * 0x50);
	while (curr_input[i] != '\0')
		i++;
	if (i == 0x50)
	{
		printf("Error: Input line too long\n");
		explode_bomb();
	}
	curr_input[i] = '\0';
	num_input_strings++;
	return (curr_input);
}

void	phase_defused(void)
{
	int	cmp;
	int	n;
	char	s[80];

	if (num_input_strings == 6)
	{
		cmp = sscanf(input_strings + 240, "%d %s", n, s);
		if (cmp == 2)
		{
			cmp = strings_not_equal(s, "austinpowers");
			if (cmp == 0)
			{
				printf("Curses, you've found the secret phase!\n");
				printf("But finding it and solving it are quite different...\n");
				secret_phase();
			}
		}
		printf("Congratulations! You've defused the bomb!\n");
	}
	return ;
}

void	phase_1(char *input)
{
	int n;

	n = strings_not_equal(input, "Public speaking is very easy.");
	if (n != 0)
		explode_bomb();
	return ;
}

void	phase_2(char *input)
{
	int	c;
	int	a[7];

	read_six_numbers(input, a + 1);
	if (a[1] != 1)
		explode_bomb();
	c = 1;
	while (c < 6)
	{
		if (a[c + 1] != (c + 1) * a[c])
			explode_bomb();
		c++;
	}
	return ;
}

void	phase_3(char *input)
{
	int		n;
	unsigned int	i;
	char		c;
	char		check;
	unsigned int	j;

	n = sscanf(input, "%d %c %d", &i, &check, &j);
	if (n < 3)
		explode_bomb();
	switch(i)
	{
		case 0:
			c = 'q';
			if (j != 777)
				explode_bomb();
		break ;
		case 1:
			c = 'b';
			if (j != 214)
				explode_bomb();
		break ;
		case 2:
			c = 'b';
			if (j != 755)
				explode_bomb();
		break ;
		case 3:
			c = 'k';
			if (j != 251)
				explode_bomb();
		break ;
		case 4:
			c = 'o';
			if (j != 160)
				explode_bomb();
		break ;
		case 5:
			c = 't';
			if (j != 458)
				explode_bomb();
		break ;
		case 6:
			c = 'v';
			if (j != 780)
				explode_bomb();
		break ;
		case 7:
			c = 'b';
			if (j != 524)
				explode_bomb();
		break ;
		default:
			c = 'x';
			explode_bomb();
	}
	if (c != check)
		explode_bomb();
	return ;

}

int	func4(int k)
{
	int	i;
	int	j;

	if (k < 2)
		j = 1;
	else
	{
		i = func4(k - 1);
		j = func4(k - 2);
		j = i + j;
	}
	return (j);
}

void	phase_4(char *input)
{
	int	n;
	int	k;

	n = sscanf(input, "%d", &k);
	if (n != 1 || k < 1)
		explode_bomb();
	n = func4(k);					// func4 must return 55
	if (n != 55)
		explode_bomb();
	return ;
}

void	phase_5(char *input)
{
	int	l;
	char	local_c[6];
	char	str[] = "isrveawhobpnutfg";

	l = string_length(input);
	if (l != 6)
		explode_bomb();
	l = 0;
	while (l < 6)
	{
		local_c[l] = str[(input[l] & 0xf)];
		l++;
	}
	l = strings_not_equal(local_c, "giants");
	if (l != 0)
		explode_bomb();
	return ;
}

void	phase_6(char *input)
{
	int	numbers[6];
	int	*ptrarray[6];
	int	i = 0;
	int	j = 0;
	int	*nd = &node1;
	int	*int_ptr1;
	int	*int_ptr2;

	read_six_numbers(input, numbers);
	while (i < 6)
	{
		j = i;
		if (numbers[i] - 1 > 5)				// Numbers between 1 and 6 (no negatives either)
			explode_bomb();
		while (j < 6)
		{
			if (numbers[i] == numbers[j])		// Can't have the same number twice
				explode_bomb();
			j++;
		}
		i++;
	}

	i = 0;
	while (i < 6)
	{
		j = 1;
		int_ptr1 = nd;
		if (numbers[i] > 1)
		{
			while (j < numbers[i])
			{
				int_ptr1 = (int *)*(int_ptr1 + 8);
				j++;
			}
		}
		ptrarray[i] = int_ptr1;
		i++;
	}

	i = 1;
	int_ptr1 = ptrarray[0];
	while (i < 6)
	{
		int_ptr2 = ptrarray[i];
		int_ptr1[2] = (int)int_ptr2;
		int_ptr2 = int_ptr1;
		i++;
	}

	int_ptr2[2] = 0;
	i = 0;
	while (i < 5)
	{
		if (*(numbers[0]) < *(int *)numbers[0][2])
			explode_bomb();
		numbers[0] = (int *)numbers[0][2];
		i++;
	}
	return ;
}



int	main(int argc, char **argv)
{
	char	*input;

	if (argc != 1)
	{
		if (argc != 2)
		{
			printf("Usage: %s [<input_file>]\n", argv[0]);
			exit(8);
		}
		infile = fopen(argv[1], "r");
		if (infile == 0)
		{
			printf("%s: Error: Couldn't open %s\n", argv[0], argv[1]);
			exit(8);
		}
	}

	initialize_bomb();
	printf("Welcome this is my little bomb !!!! You have 6 stages with\n");
	printf("only one life good luck !! Have a nice day!\n");

	input = read_line();
	phase_1(input);
	phase_defused();
	printf("Phase 1 defused. How about the next one?\n");
	
	input = read_line();
	phase_2(input);
	phase_defused();
	printf("That's number 2. Keep going!\n");

	input = read_line();
	phase_3(input);
	phase_defused();
	printf("Halfway there!\n");

	input = read_line();
	phase_4(input);
	phase_defused();
	printf("So you got that one. Try this one.\n");

	input = read_line();
	phase_5(input);
	phase_defused();
	printf("Good work! On to the next...\n");

	input = read_line();
	phase_6(input);
	phase_defused();
	return (0);
}
