#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

//Base functions
char *TrimedString(char *input);


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
char *Slice(char *input, int start);
char *SliceTo(char *input, int start, int end);
char *SubStr(char *input, int start);
char *SubStrAmount(char *input, int start, int end);
char *SubString(char *input, int start);
char *SubStringTo(char *input, int start, int end);
char *Prune(char *input, int length);

//Count Functions
int Count(char *input);

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
	char *result = malloc(sizeof(char)*(strlen(input)+1));
	
	for(int i = 0; i<strlen(input); i++)
	{
		if(i==0 || (i>0 && isalpha(input[i]) && isspace(input[i-1])))
		{
			result[i] = toupper(input[i]);
		}
		else
		{
			result[i] = tolower(input[i]);
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

char *Slice(char *input, int start)
{
	char *result = malloc(sizeof(char)*strlen(input) - (start < 0 ? strlen(input) + start : start) + 1);
	start = start < 0 ? strlen(input) + start : start;

	while(1)
	{
		if(input[start] == '\0')
		{
			break;
		}

		result[strlen(result)] = input[start++];
	}

	return result;
}

char *SliceTo(char *input, int start, int end)
{
	char *result = malloc(sizeof(char)*end-start+1);

	for(int i = 0; start < end; i++, start++)
	{
		result[strlen(result)] = input[start];
	}

	result[strlen(result)] = '\0';
	return result;
}

char *SubStr(char *input, int start)
{
	char *result = malloc(sizeof(char) * (strlen(input) - start + 1));

	for(int i = start; i < strlen(input); i++)
	{
		result[strlen(result)] = input[i];
	}

	result[strlen(result)] = '\0';
	return result;
}


char *SubStrAmount(char *input, int start, int end)
{
	char *result = malloc(sizeof(char) * (strlen(input) - start + 1));

	for(int i = start; i < start+end; i++)
	{
		result[strlen(result)] = input[i];
	}

	result[strlen(result)] = '\0';
	return result;
}

char *SubString(char *input, int start)
{
	char *result = malloc(sizeof(char) * (strlen(input) - start + 1));

	for(int i = start; i < strlen(input); i++)
	{
		result[strlen(result)] = input[i];
	}

	return result;
}

char *SubStringTo(char *input, int start, int end)
{
	char *result = malloc(sizeof(char) * (strlen(input) - start - end + 1));

	for(int i = start + 1; i <= end; i++)
	{
		result[strlen(result)] = input[i];
	}

	return result;
}

char *Prune(char *input, int length)
{
	char *trimedInput = TrimedString(input);
	int amountOfWords = 0, wordsThatFit = 0, totalLength = 0;

	for(int i = 0; i<strlen(trimedInput); i++)
	{
		if(isspace(trimedInput[i]) || i == strlen(trimedInput)-1)
		{
			amountOfWords++;
		}
	}

	int *stringLengths = malloc(sizeof(int) * amountOfWords);
	int lengthIndex = 0, spaceCounter = 0;
	
	for(int i = 0; i<amountOfWords; i++)
	{
		stringLengths[i] = 0;
	}

	for(int i = 0; i<strlen(trimedInput); i++)
	{
		if(isspace(trimedInput[i]) > 0)
		{
			lengthIndex++;
			continue;
		}

		stringLengths[lengthIndex] += 1;
	}
	
	for(int i = 0; i<amountOfWords; i++)
	{

		totalLength = totalLength + i + stringLengths[i];	
		wordsThatFit++;

		if(totalLength + stringLengths[i+1] >= length )
		{
			break;
		}

	}

	char *result = malloc(sizeof(char)*(length+1));

	if(length > stringLengths[0])
	{
		for(int i = 0; i<strlen(trimedInput); i++)
		{
			if(isspace(trimedInput[i]))
			{
				wordsThatFit--;
			}

			if(wordsThatFit == 0 || i>totalLength)
			{
				break;
			}

			result[strlen(result)] = trimedInput[i];
		}
	}

	while(strlen(result)<length && length>2)
	{
		result[strlen(result)] = '.';
	}

	result[strlen(result)] = '\0';

	return result;	
}

int Count(char *input)
{
	return strlen(input);
}
