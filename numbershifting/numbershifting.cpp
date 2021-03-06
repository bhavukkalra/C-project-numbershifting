
#include "stdafx.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h> // for _getch()
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define ESC 0




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

/*void showMatrix(int Matrix[4][4]) // my function mistake??
{
	printf("\n-----------------------\n");
	for (int i = 0; i <= 3; i++)
	{
		for (int j = 0; j <= 3; j++)
		{
			if (Matrix[i][j] != 0)
			{
				printf(" %-2d  |", Matrix[i][j]); //at least two spaces for each
			}									  //-2 for alignment	
			else
			{
				printf("   "); // SYMMETRY IS IMPORTANT 
			}                     // OTHERWISE MALFUNCTIONING ON SCREEN   
		}                    
		printf("\n-----------------------\n");
		//if (i != 3)
			//printf("|");
		
	}
}
*/

void showMatrix(int Matrix[][4]) {
	int i, j;
	printf("\n-------------------------\n|");
	for (i = 0; i <= 3; i++) {
		for (j = 0; j <= 3; j++) {
			if (Matrix[i][j] != 0)
				printf(" %-2d | ", Matrix[i][j]);
			else
				printf("    | ");
		}
		printf("\n-------------------------\n");
		if (i != 3)
			printf("|");

	}
}

int readKey()

{
	char c;
	c = _getch();
	if(c == 224) // used for ESC validation
	c = _getch();  //why other arrows work
	switch (c)
	{
	case 72:
		return UP;
		break;
	case 27:
		return ESC;
		break;
	case 80:
		return DOWN;
		break;
	case 75:
		return LEFT;
		break;
	case 77:
		return RIGHT;
	default:
		return 5;
	}
}

int checkWin(int Matrix[4][4])
{
	int checker = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			checker < 15 ? checker++ : checker = 0;
			if (Matrix[i][j] != checker)
			{
				return 0;
			}
		}
	}
	return 1;
}

void swap(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int shiftRIGHT(int Matrix[4][4])
{
	int i,j,zeroFound = 0;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (Matrix[i][j] == 0)
			{
				zeroFound = 1;
				break;
			}
		}
	if (zeroFound == 1) // special condition to break out of 
		break;          // outer loop
	}
	if (j == 0)
		return 0; // border case(shifting not possible)
	else
	{
		//swap(&Matrix[i][j], &Matrix[i][j - 1]);
		int temp = Matrix[i][j];
		Matrix[i][j] = Matrix[i][j - 1];
		Matrix[i][j - 1] = temp;
		return 1;
	}

}

int shiftLEFT(int Matrix[4][4])
{
	int i, j, zeroFound = 0;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (Matrix[i][j] == 0)
			{
				zeroFound = 1;
				break;
			}
		}
		if (zeroFound == 1) // special condition to break out of 
			break;          // outer loop
	}
	if (j == 3)
		return 0; // border case(shifting not possible)
	else
	{
		//swap(&Matrix[i][j], &Matrix[i][j + 1]);
		int temp = Matrix[i][j];
		Matrix[i][j] = Matrix[i][j + 1];
		Matrix[i][j + 1] = temp;
		return 1;
	}


}

int shiftUP(int Matrix[4][4])
{
	int i, j, zeroFound = 0;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (Matrix[i][j] == 0)
			{
				zeroFound = 1;
				break;
			}
		}
		if (zeroFound == 1) // special condition to break out of 
			break;          // outer loop
	}
	if (i == 3)
		return 0; // border case(shifting not possible)
	else
	{
		//swap(&Matrix[i][j], &Matrix[i + 1][j]);
		int temp = Matrix[i][j];
		Matrix[i][j] = Matrix[i+1][j];
		Matrix[i+1][j] = temp;
		return 1;
	}


}

int shiftDOWN(int Matrix[4][4])
{
	int i, j, zeroFound = 0;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (Matrix[i][j] == 0)
			{
				zeroFound = 1;
				break;
			}
		}
		if (zeroFound == 1) // special condition to break out of 
			break;          // outer loop
	}
	if (i == 0)
		return 0; // border case(shifting not possible)
	else
	{
		//swap(&Matrix[i][j], &Matrix[i - 1][j]);
		int temp = Matrix[i][j];
		Matrix[i][j] = Matrix[i - 1][j];
		Matrix[i - 1][j] = temp;
		return 1;
	}


}
/*
int main()
{
	int Matrix[4][4], move = 500;
	setMatrix(Matrix);
	while (move) {
		printf("\nMove Remaining: %d", move);
		showMatrix(Matrix);
		if (checkWin(Matrix)) {
			printf("\nCongratulation you win in %d moves", 500 - move);
			printf("\nPress any key to exit...");
			_getch();
			exit(0);
		}
		switch (readKey())
		{
		case ESC:
			exit(0);
		case UP:
			if (!shiftUP(Matrix))
				move++;
			break;
		case DOWN:
			if (!shiftDOWN(Matrix))
				move++;
			break;
		case LEFT:
			if (!shiftLEFT(Matrix))
				move++;
			break;
		case RIGHT:
			if (!shiftRIGHT(Matrix))
				move++;
			break;
		default:
			move++;
		}
		system("cls");
		move--;
	}
//	_getch();


}

*/

int main()
{
	int Matrix[4][4],moves = 10;
	setMatrix(Matrix); // not Matrix[4][4] for calling
	//showMatrix(Matrix);
	while (moves)
	{
		printf("moves remianing %d", moves);
		showMatrix(Matrix);
		
		if (checkWin(Matrix))
		{
			printf("you won in %d moves", 500 - moves);
			printf("press any key to exit...");
			_getch();
			exit(0);
		}
		switch (readKey())
		{
		case ESC:
			exit(0);
		case UP:
			if(!shiftUP(Matrix)) // VERY POWERFULL
				moves++;
			break;
		case DOWN:
			if (!shiftDOWN(Matrix)) // VERY POWERFULL
				moves++;
			break;
		case LEFT:
			if (!shiftLEFT(Matrix)) // VERY POWERFULL
				moves++;
			break;
		case RIGHT:
			if (!shiftRIGHT(Matrix)) // VERY POWERFULL 
				moves++;
			break;
		default:
			moves++;
		}
		moves--;
		system("cls");  // clear whole screen	
	}
}

