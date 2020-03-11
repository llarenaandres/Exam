#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int numOfSides(void);
int numOfRolls(void);
int rollDie(int i, int sides);
void printFrequency(int rolls, int outcome[], int freq[]);

int main(void)
{
	int sides = 0;
	int rolls = 0;
	int i, j, count, temp;
	int outcome[100];
	int freq[100];
	srand(time(NULL));

	sides = numOfSides();
	rolls = numOfRolls();

	for(i=0; i<rolls; ++i)
	{
		outcome[i] = 0;
	}

	printf("\nArray elements after rolling the die: \n");

	for(i=0; i<rolls; ++i)
	{
		outcome[i] = rollDie(i, sides);
		printf("outcome[%d] = %d\n", i, outcome[i]);
		freq[i] = -1;
	}
	for(i=0; i<rolls; ++i)
	{
		for(j= i+1; j<rolls; ++j)
		{
			if(outcome[i] > outcome[j])
			{
				temp = outcome[i];
				outcome[i] = outcome[j];
				outcome[j] = temp;
			}
		}
	}
	for(i=0; i<rolls; i++)
	{
		count = 1;
		
		for(j= i+1; j<rolls; j++)
		{
			if(outcome[i] == outcome[j])
			{
				count++;
				freq[j]= 0;
			}
		}
			if(freq[i] != 0)

			{
				freq[i]= count;
			}
	}
	
	printf("\nThe number of times you rolled a: \n");
	printFrequency(rolls, &outcome[0], &freq[0]);

	return 0;
}
int numOfSides(void)
{
	int sides;
	printf("\nEnter the number of sides for your die: ");
	scanf(" %d", &sides);
	while(sides < 1 || sides >20)
	{
		printf("Enter the number of sides for your die: ");
		scanf(" %d", &sides);
	}

	return sides;
}
int numOfRolls(void)
{
	int rolls;
	printf("\nEnter the number of rolls: ");
	scanf(" %d", &rolls);
	while(rolls < 1)
	{
		printf("Enter the number of rolls: ");
		scanf(" %d", &rolls);
	}

	return rolls;
}
int rollDie(int i, int sides)
{
	int outcome[i];
	outcome[i] = (rand()%(sides))+1;

	return outcome[i];
}
void printFrequency(int rolls, int outcome[], int freq[])
{
	int i;
	for(i= 0; i<rolls; ++i)
	{
		if(freq[i] !=0)
		{
			printf(" %d= %d\n\n", outcome[i], freq[i]);
		}
	}
}

			
