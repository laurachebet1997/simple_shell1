#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

void type_prompt();
void read_command(char cmd[], char *par[]);

int main()
{
	char cmd[100], command[100], *parameters[5], *envp[] = {(char *) "PATH=/bin", 0};
	/*parameters = '\0';*/


	/*envp[] = {(char *) "PATH=/bin", 0};*/
	while (1)
		{
			type_prompt();
			read_command(command, parameters);
			if(fork() != 0)
				{
					wait(NULL);
				}else{
				strcpy(cmd, "/bin/");
				strcat(cmd, command);
				execve(cmd, parameters, envp);
			}
		if(strcmp(command, "exit")==0)
			{
				break;
			}
	}
	return 0;
}
void type_prompt()
{
	static int first_time = 1;
	if (first_time)
		{
			const char *CLEAR_SCREEN_ANSI = "\\($)";
			write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
			first_time = 0;
		}
	printf("shell@practice:#");
}
void read_command(char cmd[], char *par[])
{
	char line[1024];
	int count=0;
	int i=0;
	int j=0;
	char arr[100], *pch;

	for( ;; )
		{
			int c = fgetc(stdin);
			line[count++] = (char) c;
			if (c == '\n')
				break;
			}
		if (count == 1){
			return;
		}
			pch = strtok(line, "\n");
			while (pch != NULL){
				arr[i++] = *(strdup(pch));
				pch = strtok(NULL, "\n");
			}
		strcpy(cmd, arr);
		for(j=0; j<i; j++)
			{
				*(par[j]) = arr[j];
				*(par+i) = 0;
			}
	}

