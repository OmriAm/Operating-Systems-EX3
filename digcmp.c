#include <string.h>
#include <stdio.h>

int digcmp(const char *str1, const char *str2);
int countDigitsInString(const char *s);
int main(int argc, char *argv[]);

int digcmp(const char *str1, const char *str2)
{
	int val1,val2;

	val1 = countDigitsInString(str1);
	val2 = countDigitsInString(str2);
	
	if (val1 > val2)
		return 1;
	if (val2 > val1)
		return 2;
	return 0;
}
int countDigitsInString(const char *s)
{
	int c=0,j;
    
    for(j = 0; s[j] != '\0'; j++)
    {
        if(s[j]=='0' || s[j]=='1'|| s[j]=='2'||
        s[j]=='3'|| s[j]=='4'|| s[j]=='5'||
        s[j]=='6'|| s[j]=='7'|| s[j]=='8'|| s[j]=='9')
        c++;
    }
    return c;
}
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		return -1;
	}
	return digcmp(argv[1], argv[2]);
}
