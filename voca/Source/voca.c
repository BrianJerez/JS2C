#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//Base functions
char *TrimedString(char *input);
char **Split(char *input);

//Case functions
char *ULCase(char *input, int lowerOrUpper);
char *UpperCase(char *input);
char *LowerCase(char *input);
char *SwapCase(char *input);

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

char **Split(char *input)
{
	char *trimedArray= TrimedString(input);
	int amountOfWords = 1;
	int greatestWord = 0, actualWordLength = 0;

	for(int i = 0; i<strlen(trimedArray); i++)
	{
		if(trimedArray[i] == ' ')
		{
			if(greatestWord < actualWordLength)
			{
				greatestWord = actualWordLength;
				actualWordLength = 0;
			}

			amountOfWords++;
		}
		else if(i == (strlen(trimedArray) - 1) && isalpha(trimedArray[i]) == 0)
		{
			amountOfWords++;
		}

		actualWordLength++;
	}

	char result[amountOfWords][greatestWord+1];
	char resultIndex = 0;
	char tempArray[greatestWord+1];

	for(int i = 0; i<strlen(trimedArray); i++)
	{
		if(isalpha(trimedArray[i]) > 0)
		{
			tempArray[strlen(tempArray)] = trimedArray[i];
		}

		if(trimedArray[i] == ' ' || i == strlen(trimedArray) - 1)
		{
			tempArray[strlen(tempArray)] = '\0';
			strcpy(result[resultIndex++], tempArray);
			memset(tempArray, 0, sizeof tempArray);
		}
	}

	char **fixedResult = (char**)malloc(sizeof(char*)*amountOfWords);
	
	for(int i = 0; i<amountOfWords+1; i++)
	{
		fixedResult[i] = strdup(result[i]);
	}

	strcpy(fixedResult[amountOfWords], "bspxd");

	return fixedResult;
}


char *ULCase(char *input, int lowerOrUpper)
{
	char *trimedArray = TrimedString(input);
	char *result = malloc(sizeof(char) * strlen(trimedArray) + 1);

	for(int i = 0; i<strlen(trimedArray); i++)
	{
		if(lowerOrUpper == 0)
		{
			result[i] = tolower(trimedArray[i]);
		}
		else
		{
			result[i] = toupper(trimedArray[i]);
		}

	}

	result[strlen(result)] = '\0';

	return result;

}

char *UpperCase(char *input)
{
	return ULCase(input, 1);
}

char *LowerCase(char *input)
{
	return ULCase(input, 0);
}

char *SwapCase(char *input)
{
	char *trimedArray = TrimedString(input);
	char *result = malloc(sizeof(char) * (strlen(trimedArray)+1));

	for(int i = 0; i<strlen(trimedArray); i++)
	{
		if(trimedArray[i] == toupper(trimedArray[i]))
		{
			result[i] = tolower(trimedArray[i]);
		}
		else if(trimedArray[i] == tolower(trimedArray[i]))
		{
			result[i] = toupper(trimedArray[i]);
		}
	}

	return result;
}
