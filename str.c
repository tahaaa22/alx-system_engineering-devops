
 * my_strtok - Tokenize a string.
 * @str: The string to be tokenized.
 * @delim: The delimiter characters.
 *
 * Return: A pointer to the next token, or NULL if no more tokens are found.
 */
char *my_strtok(char *str, const char *delim)
{
	static char *buffer;

	if (str != NULL)
		buffer = str;

	if (buffer == NULL || *buffer == '\0')
		return (NULL);

	/* Find the start of the next token */
	char *token_start = buffer;

	while (*token_start != '\0')
	{
		if (strchr(delim, *token_start) == NULL)
			break;
		token_start++;
	}

	if (*token_start == '\0')
	{
		buffer = NULL;
		return (NULL);
	}

	/* Find the end of the token */
	char *token_end = token_start + 1;

	while (*token_end != '\0')
	{
		if (strchr(delim, *token_end) != NULL)
			break;
		token_end++;
	}

	/* Null-terminate the token and update the buffer */
	if (*token_end != '\0')
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
