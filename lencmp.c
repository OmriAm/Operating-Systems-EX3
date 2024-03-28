#include <string.h>
#include <stdio.h>

int lencmp(const char *str1, const char *str2);
int main(int argc, char *argv[]);

int lencmp(const char *str1, const char *str2)
{
	int val;
	val = strlen(str1) - strlen(str2);
	if (val < 0)
		return 1;
	if (val > 0)
		return 2;
	return 0;
}

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		return -1;
	}
	return lencmp(argv[1], argv[2]);
}
