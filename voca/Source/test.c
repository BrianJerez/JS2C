#include <stdio.h>
#include "voca.h"

int main(void)
{
	printf("%d\n", LastIndexOf("we have a mission", "mission"));
	printf("%d\n", LastIndexOfSingleChar("we have a mission", 'a'));
	return 0;
}
