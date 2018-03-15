#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

//Base functions
char *TrimedString(char *input);
char **Split(char *input);
//int CountWords(char *input); on hold


//Case functions
char *ULCase(char *input, int lowerOrUpper);
char *UpperCase(char *input);
char *LowerCase(char *input);
char *SwapCase(char *input);
char *TitleCase(char *input);
char *SnakeCase(char *input);
char *KebabCase(char *input);
char *CDPitalize(char *input, int flag);
char *Capitalize(char *input);
char *Decapitalize(char *input);


//Chop Functions
char CharAt(char *input, int index);
int CodePointAt(char *input, int index);
char FirstOrLast(char *input, int flag);
char First(char *input);
char Last(char *input);
char *FirstOrLastPlus(char *input, int amount, int flag);
char *FirstPlus(char *input, int amount);
char *LastPlus(char *input, int amount);

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


char *TitleCase(char *input)
{
	char **splitedInput = Split(input);
	int amountOfWords = 0, totalLength = 0;
	char *key = "bspxd";

	for(int i = 0; ;i++)
	{
		if(strcmp(splitedInput[i], key) == 0)
		{
			break;
		}

		splitedInput[i] = LowerCase(splitedInput[i]);
		splitedInput[i][0] = toupper(splitedInput[i][0]);
		amountOfWords++;
		totalLength += strlen(splitedInput[i]);
	}

	char* result = malloc(sizeof(char)*(totalLength+amountOfWords+1));

	for(int i = 0; ;i++)
	{
		if(strcmp(splitedInput[i], key) == 0)
		{
			break;
		}

		for(int j = 0; j < strlen(splitedInput[i]); j++)
		{
			result[strlen(result)] = splitedInput[i][j];

			if((j+1)==strlen(splitedInput[i]))
			{
				result[strlen(result)] = ' ';
			}
		}
	}

	result[strlen(result)] = '\0';

	return result;
}

char *SnakeCase(char *input)
{
	input = TrimedString(input);
	
	for(int i = 0; i<strlen(input); i++)
	{
		if(isspace(input[i]) > 0)
		{
			input[i] = '_';
		}
	}

	return input;
}

char *KebabCase(char *input)
{
	input = TrimedString(input);
	
	for(int i = 0; i<strlen(input); i++)
	{
		if(isspace(input[i]) > 0)
		{
			input[i] = '-';
		}
	}

	return input;
}

char *CDPitalize(char *input, int flag)
{
	input = LowerCase(input);
	
	if(flag == 0)
	{
		input[0] = toupper(input[0]);
	}
	else
	{
		input[0] = tolower(input[0]);
	}

	return input;
}

char *Capitalize(char *input)
{
	input = CDPitalize(input, 0);
	return input;
}

char *Decapitalize(char *input)
{
	input = CDPitalize(input, 1);
	return input;
}

char CharAt(char *input, int index)
{
	if(index>strlen(input))
	{
		return '\0';
	}

	return input[index];
}


int CodePointAt(char *input, int index)
{
	if(index>strlen(input))
	{
		return -1;
	}

	return (int) input[index];
}

char FirstOrLast(char *input, int flag)
{
	if(flag == 0)
	{
		return input[0];
	}

	return strlen(input) > 0 ? input[strlen(input-1)] : '\0';
}

char First(char *input)
{
	return FirstOrLast(input, 0);
}
char Last(char *input)
{
	return FirstOrLast(input, 1);
}

char *FirstOrLastPlus(char *input, int amount, int flag)
{
		char *result = malloc(sizeof(char)*(amount+1));
		int i = flag == 0 ? 0 : strlen(input) - amount;

		while(1)
		{
			result[strlen(result)] =  input[flag == 0 ? i++ : i++];

			if(--amount == 0)
			{
				break;
			}
		}

		result[strlen(result)] = '\0';

		return result;
}

char *FirstPlus(char *input, int amount)
{
	return FirstOrLastPlus(input, amount, 0);
}

char *LastPlus(char *input, int amount)
{
	return FirstOrLastPlus(input, amount, 1);
}
