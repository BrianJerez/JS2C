#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char *TrimedString(char *input);

char *TrimedString(char *input)
{
	int AmountOfSpaces = 0;
	
	for(int i = 0; i < strlen(input); i++)
	{
		if(isalpha(input[i]) == 0 && input[i] != ' ')
		{
			AmountOfSpaces++;
		}

		if(input[i] == ' ' && input[i-1] == ' ')
		{
			AmountOfSpaces++;
		}
	}

	char *result = malloc(strlen(input) + 1 - AmountOfSpaces);
	char resultIndex = 0;

	for(int i = 0; i<strlen(input); i++)
	{
		if(isalpha(input[i]) == 0 && input[i] != ' ')
		{
			continue;
		}

		if(resultIndex != 0 && (i+1)<strlen(input) && input[i] == ' ' && isalpha(input[i+1]) > 0)
		{
			result[resultIndex++] = input[i];
		}
		else if(isalpha(input[i]))
		{
			result[resultIndex++] = input[i];
		}
	}

	result[resultIndex] = '\0';

	return result;
}
