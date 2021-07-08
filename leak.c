
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

__attribute__((destructor))
void	destructor(void)
{
	int status;
	status = system("leaks push_swap &> leaksout");
	if (status)
	{
		write(2, "leak!!!\n", 8);
		system("cat leaksout >/dev/stderr");
		exit(1);
	}
	else
	{
		system("rm leaksout");
		printf("no leaks\n");
	}
}