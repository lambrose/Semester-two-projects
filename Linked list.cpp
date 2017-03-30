// Linked list.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include "string.h"
#include "stdlib.h"

typedef struct result
{
	char firstName[50];
	char lastName[50];
	long id;
	char english, french, maths, philosophy;
	result *next;
} result;

result *first, *current, *last;

int readFile(char *fileName);

void printResult(result *aResult);

int main()
{
	char fileName[] = "F:\\results.txt";
	int i = 0;

	void initialiseResults();

	if (!readFile(fileName))
	{
		printf("File could not be opened !!\n");
		return 0;
	}

	current = first;

	printf("%12s%12s%6s%12s%12s%12s%12s\n", "Surname", "First Name", "ID", "Maths", "English", "French", "Philosophy");
	printf("     =======  ==========   ===       =====     =======      ======  ==========\n");

	while (current != NULL)
	{
		printResult(current);
		current = current->next;
	}

	return 0;
}

void printResult(result *aResult)
{
	printf("%12s%12s%6d%10c%11c%12c%10c\n", aResult->lastName, aResult->firstName, aResult->id, aResult->maths, aResult->english, aResult->french, aResult->philosophy);
}



int readFile(char *fileName)
{
	char line[200];
	FILE *fptr = fopen(fileName, "r");

	if (fptr == NULL)
	{
		printf("Error opening file ! \n");
		return 0;
	}

	
	fgets(line, 200, fptr);

	
	first = (result *)malloc(sizeof(result));
	first->next = NULL;
	current = first;

	fscanf(fptr, "%d\t%s\t%s\t%c\t%c\t%c\t%c\n", &first->id, first->firstName, first->lastName, &first->english, &first->maths, &first->french, &first->philosophy);

	while (!feof(fptr))
	{
		last = (result *)malloc(sizeof(result));
		current->next = last;
		current = last;
		current->next = NULL;
		fscanf(fptr, "%d\t%s\t%s\t%c\t%c\t%c\t%c\n", &current->id, current->firstName, current->lastName, &current->english, &current->maths, &current->french, &current->philosophy);
	}

	fclose(fptr);

	return 1;
}
