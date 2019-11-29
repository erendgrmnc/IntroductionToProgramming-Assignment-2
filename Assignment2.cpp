

#include "iostream" //in-out library
#include "time.h"//for random function
#include "algorithm"//for sorting algorithm

using namespace std;

int main() {

	srand(time(NULL)); // parameter of seed

	int randletter; //This a integer need to declare a random letter.
	int i, j; //for getting every row and column one by one.
	char  matrixelements; //elements (letters) of matrix.

	const int row = 5;//row range.
	const int col = 10;//column range.

	char matrix[row][col];//Matrix.

	for (i = 0; i < row; i++)//For every row 0-4.
	{
		for (j = 0; j < col; j++)//For every column 0-9.
		{
			randletter = rand() % 26;//generates a random integer.
			
			if (j % 2 == 1) // if column number is odd,It will be lowercase letter. 
			{
				matrixelements = 'a' + randletter;	//adding the integer it created to decide a letter a-z.
			}

			else // if column number is even,It will be uppercase letter.
			{
				matrixelements = 'A' + randletter; //adding the integer it created to decide a letter A-Z.
			}
			
			for (int controlrow = 0; controlrow < row; controlrow++) //Creates another matrices row for controlling if there is repated letter.
			{
				for (int controlcol = 0; controlcol < col; controlcol++) //Creates another matrices column for controlling if there is repated letter.
				{
					if (matrix[controlrow][controlcol] == matrixelements)//If there is a same letter in matrix :
					{
						if (j % 2 == 0 )//If column number is an even number replace it with a lowercase letter.
						{
							randletter = rand() % 26;
							matrixelements = 'a' + randletter;
						}

						else {
							randletter = rand() % 26;//If column number is an odd number replace it with a uppercase letter.
							matrixelements = 'A' + randletter;
						}
						controlrow = 0;
						controlcol = 0;
					}

				}
			}
			
			matrix[i][j] = { matrixelements };// non arrayed non repated matrix.
		}
	}

		cout << "********** Non Arrayed Matrix *********** " << endl;
		for (int i = 0; i < row; i++)//printing the non arrayed non repated matrix.
		{
			for (int j = 0; j < col; j++)
			{
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}

		sort(&matrix[0][0], &matrix[0][0] + 5 * 10);//Sorting matrix according to the alphabet.

		cout << "********** Arrayed Matrix *********** " << endl;
		for (int i = 0; i < row; i++)//printing the  arrayed non repated matrix.
		{
			for (int j = 0; j < col; j++)
			{
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}

		system("pause");
		return 0;
	}

