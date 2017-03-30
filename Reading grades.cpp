// Reading grades.cpp : Defines the entry point for the console application.


#include "stdafx.h"
#include <stdio.h>
#include "string.h"
#include "stdlib.h"


typedef struct
{
	int ID;
	char subject[40];
	int mark;
	char grade;
} record;

record records[100];
int nrecords = 0;

int readFile();
void writeFile();
void addToMark(int upgrade);

int main()
{

	int n = 0;
	n = readFile();
	addToMark(10);
	writeFile();

	return 0;

}

int readFile()
{

	int i;
	FILE *fptr;

	fptr = fopen("F:\\results.txt", "r");

	if (fptr == NULL)
	{
		printf("File could not be opened !!\n");
		return 0;
	}
	else
	{

		while (!feof(fptr))
		{
			fscanf(fptr, "%d\t%s\t%d\t%c\n", &records[nrecords].ID, records[nrecords].subject, &records[nrecords].mark, &records[nrecords].grade);
			nrecords++;
		}

		fclose(fptr);
		return nrecords;
	}
}

void writeFile()
{
	int i;
	FILE *fptr;

	fptr = fopen("F:\\results.txt", "w");

	if (fptr == NULL)
	{
		printf("File could not be opened !!\n");
		return;
	}
	else
	{

		for (i = 0; i<nrecords; i++)
		{
			fprintf(fptr, "%d\t%s\t%d\t%c\n", records[i].ID, records[i].subject, records[i].mark, records[i].grade);
		}

		fclose(fptr);
		return;
	}
}

void addToMark(int upgrade)
{
	int i;

	for (i = 0; i < nrecords; i++)
	{
		records[i].mark = records[i].mark + upgrade;
		if (records[i].mark > 100) records[i].mark = 100;
		if (records[i].mark >= 70)
		{
			records[i].grade = 'A';
		}
		else if (records[i].mark >= 60)
		{
			records[i].grade = 'B';
		}
		else if (records[i].mark >= 50)
		{
			records[i].grade = 'C';
		}
		else if (records[i].mark >= 40)
		{
			records[i].grade = 'D';
		}
		else
		{
			records[i].grade = 'E';
		}
	}
}