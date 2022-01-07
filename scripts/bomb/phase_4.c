#include <stdio.h>

int     func4(int k)
{
        int     i;
        int     j;

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


int	main(void)
{
	int n = func4(9);
	printf("n is %d\n", n);

	return (0);
}
