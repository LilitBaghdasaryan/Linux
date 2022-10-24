#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <ctype.h>

int char_count(const char *s)
{
	 return strlen(s);
}

int word_count(const char *s)
{
	int words = 0;
	int i = 0;
	for(; i < strlen(s), !isalpha(s[i]) ; ++i);
	for(; i < strlen(s); ++i)
	{
		if(!isalpha(s[i]) && isalpha(s[i + 1]))
			words++;
	}
	if(isalpha(s[strlen(s - 1)]))
		words++;
	return words;
}
int line_count(const char *s)
{
	int lines = 0;
	for(int i = 0; i < strlen(s); ++i)
	{
		if(s[i] == '\n')
			lines++;
	}
	    return lines;
}

int main(int argc, char** argv)
{
	int lines = 0;
	int words = 0;
	int plines = 0;
	int pwords = 0;
	int pchars = 0;
	int chars = 0;
	if (argc == 1)
	{
		perror("No input file\n");
			return 1;
	}
    	int fd = open(argv[argc - 1], O_RDONLY);
	if (fd < 0)
	{
	 	perror("Can't open file\n");
		return 1;
	}
	char    buffer[256];
	ssize_t bytes;
	while ((bytes = read(fd, buffer, 256)) != 0)
	 {
		 lines += line_count(buffer);
		words += word_count(buffer);
		chars += char_count(buffer);
	 }
	if(argc == 2 || argc == 5)
	{
	    printf("%d %d %d ", lines, words, chars);
	    return 0;
	}
	for(int i = 1; i < argc - 1; i++)
	{
		if (!strcmp(argv[i], "-l"))
			plines++;
		if (!strcmp(argv[i], "-w"))
			pwords++;
		if (!strcmp(argv[i], "-c"))
			pchars++;
	}
	if (plines > 0)
		printf("%d ", lines);
	if (pwords > 0)
		printf("%d ", words);
	if(pchars > 0)
		printf("%d ", chars);
	printf("%s", "\n");
	return 0;

}
