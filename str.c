/**
 * initialize_strtok - Initializes the strtok process.
 * @str: The string to tokenize.
 * Return: The initialized string pointer.
 */
static char *initialize_strtok(char *str)
{
	static char *nxt;
	static int size;

	if (str != NULL)
	{
		nxt = str;
		size = strlen(str);
	}
	else if (size > 0)
	{
		nxt++;
		size--;
		str = nxt;
	}
	else
	{
		str = NULL;
	}

	return (str);
}

/**
 * handle_delimiters - Handles consecutive delimiters in the string.
 * @nxt: Pointer to the current position in the string.
 * @size: The remaining size of the string.
 * @delim: The delimiter string.
 */
static void handle_delimiters(char **nxt, int *size, const char *delim)
{
	int i = strspn(*nxt, delim);

	while (i > 1)
	{
		**nxt = '\0';
		(*nxt)++;
		(*size)--;
		i--;
	}
	if (i == 1)
	{
		**nxt = '\0';
		if (*size > 1)
		{
			(*nxt)--;
			(*size)++;
		}
	}
}

/**
 * advance_strtok - Advances the string pointer.
 * @nxt: Pointer to the current position in the string.
 * @size: The remaining size of the string.
 */
static void advance_strtok(char **nxt, int *size)
{
	(*nxt)++;
	(*size)--;
}

/**
 * _strtok - Split a string into tokens based on delimiters.
 * @str: The string to tokenize.
 * @delim: The delimiter string.
 * Return: A pointer to the next token found in the string, or NULL if no more tokens are found.
 */
char *_strtok(char *str, const char *delim)
{
	char *nxt;
	int size, i;

	str = initialize_strtok(str);
	if (str == NULL)
		return (NULL);
	nxt = str;
	size = strlen(str);

	while (*nxt)
	{
		handle_delimiters(&nxt, &size, delim);
		advance_strtok(&nxt, &size);
	}
	return (str);
}
