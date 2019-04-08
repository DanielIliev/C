#include <stdio.h>
#include <stdlib.h>

#define ARRLEN(x) (sizeof(x) / sizeof((x)[0]))

void create(FILE *fp);
void read();
int checkSeparator();

struct dictionary {
	int id;
	char word[20];
	int count;
};

struct dictionary elements[5000];

int main(void)
{
	FILE *fp = NULL;
	fp = fopen("test.txt", "r");
	create(fp);
	return 0;
}

void create(FILE *fp) {
	char c;
	char separators[] = {'.', ',', '?', '!', ':', ';', '/', '\0', EOF};
	char *buffer;
    size_t bufsize = 32;
    size_t characters;

    buffer = (char *)malloc(bufsize * sizeof(char));
    if( buffer == NULL)
    {
        perror("Unable to allocate buffer");
        exit(1);
    }
	while ((buffer = getline(&line, &len, fp)) != -1) {
        printf("%s", line);
    }
	/*do
	{
		if (looped > 0)
		{
			for (int i = 0; i < ARRLEN(line); i++)
			{
				for (int k = 0; k < ARRLEN(separators); k++)
				{
					if (line[i] == separators[k])
					{
						printf("Separator\n");
					}
				}
			}	
		}
		looped++;
	} while (fgets(line, sizeof(line), fp));*/
	read();
}

void read() {

}