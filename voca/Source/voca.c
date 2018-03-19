#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

//Especial Functions
char *TrimedString(char *input);
char *ReplaceSpecialChars(char *input);

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
int CountSubstring(char *input, char *subInput);
int CountWords(char *input);

//Index Functions
int NDex(char *input, char *search, int from);
int IndexOf(char *input, char *search);
int IndexOfFrom(char *input, char *search, int from);
int NDexOfSingleChar(char *input, char search, int from);
int IndexOfSingleChar(char *input, char search);
int IndexOfSingleCharFrom(char *input, char search, int from);
int LNDex(char *input, char *search, int from);
int LastIndexOf(char *input, char *search);
int LastIndexOfFrom(char *input, char *search, int from);
int LNDexOfSingleChar(char *input, char search, int from);
int LastIndexOfSingleChar(char *input, char search);
int LastIndexOfSingleCharFrom(char *input, char search, int from);

//Query Functions
int IsAlpha(char *input);
int IsDigit(char *input);
int IsAlphaDigit(char *input);
int IsUpperORLower(char *input, int flag);
int IsLowerCase(char *input);
int IsUpperCase(char *input);
int IsBlank(char *input);
int IsEmpty(char *input);
int IsNumeric(char *input);
int Includes(char *input, char *search);
int EndsWith(char *input, char *search);
int StartsWith(char *input, char *search);

//Manipulate Functions
char *Trim(char *input);
char *Padding(char *input, char *pattern, int amount, int flag);
char *PadLeft(char *input, char *pattern, int amount);
char *PadRight(char *input, char *pattern, int amount);

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

char *ReplaceSpecialChars(char *input)
{
	char *result = malloc(sizeof(char)*(strlen(input) + 1));

	for(int i = 0; i<strlen(input); i++)
	{
		if(isalpha(input[i]) == 0)
		{
			result[strlen(result)] = ' ';
		}
		else
		{
			result[strlen(result)] = input[i];
		}
	}

	result[strlen(result)] = '\0';

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

int CountSubstring(char *input, char *subInput)
{
	char *trimedInput = TrimedString(input);
	int repetitions = 0, charCoincidences = 0;
	
	for(int i = 0; i<strlen(input); i++)
	{
		if(input[i] == subInput[charCoincidences])
		{
			charCoincidences++;
		}
		else
		{
			charCoincidences = 0;
		}

		if(charCoincidences == strlen(subInput))
		{
			charCoincidences = 0;
			repetitions++;
		}


	}

	return repetitions;
}

int CountWords(char *input)
{
	int amountOfWords = 0;
	char *firstSwap = TrimedString(ReplaceSpecialChars(input));
	puts(firstSwap);

	for(int i = 0; i<strlen(firstSwap); i++)
	{
		if(isspace(firstSwap[i]))
		{
			amountOfWords++;
		}
	}

	return ++amountOfWords;
}


int NDex(char *input, char *search, int from)
{
	int count = 0;
	
	for(int i = from; i<strlen(input); i++)
	{
			if(input[i] == search[count])
			{
				count++;
			}
			else
			{
				count = 0;
			}

			if(count == strlen(search))
			{
				return i - count + 1;
			}
	}

	return -1;
}

int IndexOf(char *input, char *search)
{
	return NDex(input, search, 0);
}

int IndexOfFrom(char *input, char *search, int from)
{
	return NDex(input, search, from);
}

int NDexOfSingleChar(char *input, char search, int from)
{
	for(int i = from; i<strlen(input); i++)
	{
		if(input[i] == search)
		{
			return i;
		}
	}

	return -1;
}


int IndexOfSingleChar(char *input, char search)
{
	return NDexOfSingleChar(input, search, 0);
}

int IndexOfSingleCharFrom(char *input, char search, int from)
{
	return NDexOfSingleChar(input, search, from);
}

int LNDex(char *input, char *search, int from)
{
	int lastPosition = -1, searchIndex = 0;
	for(int i = from; i<strlen(input); i++)
	{
		if(input[i] == search[searchIndex] && searchIndex == 0)
		{
			lastPosition = i;
			searchIndex++;
		}
		else if(input[i] == search[searchIndex])
		{
			searchIndex++;
		}
		else if(input[i] != search[searchIndex])
		{
			searchIndex = 0;
		}
	}

	return lastPosition;
}


int LastIndexOf(char *input, char *search)
{
	return LNDex(input, search, 0);
}
int LastIndexOfFrom(char *input, char *search, int from)
{
	return LNDex(input, search, from);
}


int LastIndexOfSingleChar(char *input, char search)
{
	char *modifiedSearch = malloc(sizeof(char) * 2);
	modifiedSearch[strlen(modifiedSearch)] = search;
	modifiedSearch[strlen(modifiedSearch)] = '\0';
	return LNDex(input, modifiedSearch, 0);
}

int LastIndexOfSingleCharFrom(char *input, char search, int from)
{
	char *modifiedSearch = malloc(sizeof(char) * 2);
	modifiedSearch[strlen(modifiedSearch)] = search;
	modifiedSearch[strlen(modifiedSearch)] = '\0';
	return LNDex(input, modifiedSearch, from);
}

int IsAlpha(char *input)
{
	int invalidChars = 0;

	for(int i = 0; i<strlen(input); i++)
	{
		if(isalpha(input[i]) > 0 && isdigit(input[i]) == 0)
		{
			continue;
		}

		invalidChars++;
	}

	return invalidChars > 0 ? 0 : 1;
}

int IsDigit(char *input)
{
	int invalidChars = 0;

	for(int i = 0; i<strlen(input); i++)
	{
		if(isalpha(input[i]) == 0 && isdigit(input[i]) > 0)
		{
			continue;
		}

		invalidChars++;
	}

	return invalidChars > 0 ? 0 : 1;
}

int IsAlphaDigit(char *input)
{
	int invalidChars = 0;

	for(int i = 0; i<strlen(input); i++)
	{
		if(isalnum(input[i]))
		{
			continue;
		}

		invalidChars++;
	}

	return invalidChars > 0 && invalidChars != 0 ? 1 : 0;
}

int IsUpperOrLower(char *input, int flag)
{
	int invalidChars = 0;

	for(int i = 0; i<strlen(input); i++)
	{
		if(flag == 0 && input[i] == toupper(input[i]))
		{
			invalidChars++;
			break;
		}
		
		if(flag == 1 && input[i] == tolower(input[i]))
		{
			invalidChars++;
			break;
		}

		if(flag == 2 && input[i] != ' ')
		{
			invalidChars++;
			break;
		}

		if(flag == 3)
		{
			invalidChars++;
			break;
		}
	}

	return invalidChars > 0 ? 0 : 1;
}

int IsLowerCase(char *input)
{
	return IsUpperOrLower(input, 0);
}

int IsUpperCase(char *input)
{
	return IsUpperOrLower(input, 1);
}

int IsBlank(char *input)
{
	return IsUpperOrLower(input, 2);
}

int IsEmpty(char *input)
{	
	return IsUpperOrLower(input, 2);
}

int IsNumeric(char *input)
{
	int validChars = 0;

	for(int i = 0; i<strlen(input); i++)
	{
		if(isdigit(input[i]))
		{
			validChars++;
			continue;
		}

		if(input[i] == '.' && (i == 0 || (isdigit(input[i-1]) && isdigit(input[i+1]))))
		{
			validChars++;
			continue;
		}

		if((input[i] == '+' || input[i] == '-') && i == 0)
		{
			validChars++;
		}
	}

	return validChars == strlen(input) ? 1 : 0;
}

int Includes(char *input, char *search)
{
	int result = 0, coincidences = 0, searchIndex = 0;

	for(int i = 0; i<strlen(input); i++)
	{
		if(input[i] == search[searchIndex])
		{
			searchIndex++;
		}
		else
		{
			searchIndex = 0;
		}

		if(searchIndex == strlen(search))
		{
			result++;
			break;
		}
	}

	return result;
}

int EndsWith(char *input, char *search)
{
	int indexSearch = 0, coincidences = 0;

	for(int i = strlen(input)-strlen(search); i<strlen(input); i++)
	{
		if(input[i] == search[indexSearch])
		{
			indexSearch++;
		}
		else
		{
			break;
		}
	}

	return indexSearch == strlen(search) ? 1 : 0;
}

int StartsWith(char *input, char *search)
{
	int indexSearch = 0, coincidences = 0;

	for(int i = 0; i<strlen(search); i++)
	{
		if(input[i] == search[indexSearch])
		{
			indexSearch++;
		}
		else
		{
			break;
		}
	}

	return indexSearch == strlen(search) ? 1 : 0;
}

char *Trim(char *input)
{
	return TrimedString(input);
}

char *Padding(char *input, char *pattern, int amount, int flag)
{
	char *result = malloc(sizeof(char)* (amount + strlen(input) + 1));
	int patternIndex = 0;

	while(flag > 0 ? 0 : amount>strlen(result))
	{
		result[strlen(result)] = pattern[patternIndex++];

		if(patternIndex == strlen(pattern))
		{
			patternIndex = 0;
		}
	}

	strcpy(flag > 0 ? result : result + strlen(result), input);
	
	while(flag > 0 ? strlen(result) < amount + strlen(input) + 1 : 0)
	{
		result[strlen(result)] = pattern[patternIndex++];

		if(patternIndex == strlen(pattern))
		{
			patternIndex = 0;
		}
	}

	return result;
}

char *PadLeft(char *input, char *pattern, int amount)
{
	return Padding(input, pattern, amount, 0);
}

char *PadRight(char *input, char *pattern, int amount)
{
	return Padding(input, pattern, amount, 1);
}
