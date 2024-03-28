#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define LINELEN (80)

int main(int argc, char *argv[]);
char *mygets(char *buf, int len);

int main(int argc, char *argv[])
{
	char str1[LINELEN + 1];
	char str2[LINELEN + 1];

	if (argc != 2)
	    return -1;
	/*
	char first[] ="./";
	strcat(first,argv[1]);
	*/
        
	while (1)
	{
		if (mygets(str1, LINELEN) == NULL)
			break;
		if (mygets(str2, LINELEN) == NULL)
			break;
		
		int rc = fork();
		
		if(rc<0) {
		    fprintf(stderr, "fork failed\n");
                    exit(1);
                } else if (rc == 0) {
                    char* argExe[] = {argv[1], str1, str2, NULL};
                   
                   
                   
                   char cwd[LINELEN];

			    strcat(cwd, "./");
			    strcat(cwd, argv[1]);
                   
                    int eC = execvp(cwd,argExe);
      
                    if(eC < 0)
                    {
                      return -2;
                      break;
                    }
		} else {
                      int status;
                      wait(&status);
                      if (WIFEXITED(status)) {
                          printf("Child process return value %d\n", WEXITSTATUS(status));
                      }
                }
		fflush(stdout);
	}
	return 0;
}


char *mygets(char *buf, int len)
{
	char *retval;

	retval = fgets(buf, len, stdin);
	buf[len] = '\0';
	if (buf[strlen(buf) - 1] == 10) /* trim \r */
		buf[strlen(buf) - 1] = '\0';
	else if (retval) while (getchar() != '\n'); /* get to eol */

	return retval;
}
