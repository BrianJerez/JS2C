//Case Functions
char *ULCase(char *input, int lowerOrUpper);
char *UpperCase(char *input);
char *LowerCase(char *input);
char *SwapCase(char *input);
char *TitleCase(char *input);
char *SnakeCase(char *input);
char *KebabCase(char *input);
char *Capitalize(char *input);
char *Decapitalize(char *input);


//Chop Functions
char CharAt(char *input, int index);
int CodePointAt(char *input, int index);
char First(char *input);
char Last(char *input);
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
int IndexOf(char *input, char *search);
int IndexOfFrom(char *input, char *search, int from);
int IndexOfSingleChar(char *input, char search);
int IndexOfSingleCharFrom(char *input, char search, int from);
int LastIndexOf(char *input, char *search);
int LastIndexOfFrom(char *input, char search, int from);
int LastIndexOfSingleChar(char *input, char search);
int LastIndexOfSingleCharFrom(char *input, char search, int from);

//Query Functions
int IsAlpha(char *input);
int IsDigit(char *input);
int IsAlphaDigit(char *input);
int IsLowerCase(char *input);
int IsUpperCase(char *input);
int IsBlank(char *input);
int IsEmpty(char *input);
int IsNumeric(char *input);
int Includes(char *input, char *search);
int EndsWith(char *input, char *search);
int StartsWith(char *input, char *search);

//Manipulable Functions
char *Reverse(char *input);
char *Trim(char *input);
char *TrimLeft(char *input);
char *TrimRight(char *input);
char *PadLeft(char *input, char *pattern, int amount);
char *PadRight(char *input, char *pattern, int amount);
char *Replace(char *input, char *match, char *replace);
char *Splice(char *input, int start, int end);
