#include <stdio.h>
#include <string.h>

/**
 * find_token_start - Find the start of the next token.
 * @buffer: The buffer to search.
 * @delim: The delimiter characters.
 *
 * Return: A pointer to the start of the next token.
 */
char *find_token_start(char *buffer, const char *delim)
{
	while (*buffer)
	{
		if (!strchr(delim, *buffer))
			break;
		buffer++;
	}

	return (buffer);
}

/**
 * find_token_end - Find the end of the current token.
 * @token_start: The start of the current token.
 * @delim: The delimiter characters.
 *
 * Return: A pointer to the end of the current token.
 */
char *find_token_end(char *token_start, const char *delim)
{
	char *token_end = token_start + 1;

	while (*token_end)
	{
		if (strchr(delim, *token_end))
			break;
		token_end++;
	}

	return (token_end);
}

/**
 * my_strtok - Tokenize a string.
 * @str: The string to be tokenized.
 * @delim: The delimiter characters.
 *
 * Return: A pointer to the next token, or NULL if no more tokens are found.
 */
char *my_strtok(char *str, const char *delim)
{
	static char *buffer;

	if (str)
		buffer = str;

	if (!buffer || !(*buffer))
		return (NULL);

	char *token_start = find_token_start(buffer, delim);

	if (!(*token_start))
	{
		buffer = NULL;
		return (NULL);
	}

	char *token_end = find_token_end(token_start, delim);

	if (*token_end)
	{
		*token_end = '\0';
		buffer = token_end + 1;
	}
	else
	{
		buffer = NULL;
	}

	return (token_start);
}
