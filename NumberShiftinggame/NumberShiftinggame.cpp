// NumberShiftinggame.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void setMatrix(int Matrix[4][4])  //any changes made to 2D matrix here
                                  //will also get reflected in main
{                                 
	int pool[15] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	int maxIndex = 14;
	srand(time(NULL));    //changes the random generating alogrithm
	for (int i = 0; i <= 3; i++)
	{
		for (int j = 0; j <= 3; j++)
		{
			if (maxIndex >= 0)
			{
				int random_index = (rand() % (maxIndex + 1)); // crux 
				Matrix[i][j] = pool[random_index];
				pool[random_index] = pool[maxIndex];
				maxIndex--;
			}
			else // condition not true for last element
			{
				Matrix[i][j] = 0;

			}
		}
	}
}

void showMatrix(int Matrix[4][4])
{
	printf("\n---------------------\n"); 
	for (int i = 0; i <= 3; i++)
	{
		for (int j = 0; j <= 3; j++)
		{
			if (Matrix[i][j] != 0)
			{
				printf(" %-2d  ", Matrix[i][j]);

			}
			else
			{
				printf(" ");




			}
		}

		printf("\n---------------------\n");



	}







}



int main()
{
	int Matrix[4][4];
	setMatrix(Matrix); // not Matrix[4][4] for calling
	showMatrix(Matrix);

    return 0;
}

