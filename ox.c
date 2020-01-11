#include<stdio.h>
void display(char arr[3][3]);
void player_move(char arr[3][3]);
void computer_move(char arr[3][3]);
int check(char arr[3][3]);

int main()
{
	char arr[3][3];
	char checkret;
	int flag=0;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			arr[i][j] =' ';
	display(arr);
	int f=0;
	for(int i=0;i<9;i++)
	{
		if(i%2==0)
		{
			player_move(arr);
			printf("\nUser :\n");
		}
		else{
				computer_move(arr);
				printf("\nComputer played  :\n");
		}
		display(arr);
		
		if(i>3)
			f=check(arr);
		if(f)
			return 0;
	}
	printf("Game Drawn");

	return 0;
}

void display(char arr[3][3])
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			printf("| %c ",arr[i][j]);
		}
		printf("|\n");
	}
}

void player_move(char arr[3][3])
{
	int i, j;
	int flag1=1;
	printf("\nEnter the 1 at any blank position :");
	while(flag1){
			printf("\nEnter row and column :");
			scanf("%d %d", &i, &j);
	
			if (arr[i][j] == ' ')
			{
				arr[i][j] = 'X';
				flag1=0;
			}
			else
				printf("Enter an empty and valid location");
		}
}

void computer_move(char arr[3][3])
{
	//horizontal
	for (int i = 0; i < 3; i++)
	{
		//for arr1
		if (arr[i][0] == arr[i][1] && arr[i][2]==' '&&arr[i][1]!=' '&& arr[i][0] != ' ')
		{
			//add computer move
			arr[i][2] = 'O';
			return;

		}
		else if (arr[i][0] == arr[i][2] && arr[i][1]==' '&&arr[i][0] != ' '&&arr[i][2] != ' ')
		{
			arr[i][1] = 'O';
			return;
		}
		else if (arr[i][1] == arr[i][2]  && arr[i][0]==' '&& arr[i][1] != ' '&& arr[i][2] != ' ')
		{
			arr[i][0] = 'O';
			return;
		}
	}

	//check vertical
	for (int i = 0; i < 3; i++)
	{
		if (arr[0][i] == arr[2][i] && arr[1][i]==' '&&arr[0][i]!=' '&&arr[2][i] != ' ')
		{
			arr[1][i] = 'O';
			return;
		}
		else if (arr[0][i] == arr[1][i] && arr[2][i]==' ' &&arr[0][i]!=' '&&arr[1][i]!=' ')
		{
			arr[2][i] = 'O';
			return;
		}
		else if (arr[1][i] == arr[2][i] && arr[0][i]==' ' && arr[1][i]!=' ' && arr[2][i] != ' ')
		{
			arr[0][i] = 'O';
			return;
		}

	}
	//check left diagonally
	if (arr[0][0] == arr[1][1] && arr[2][2]==' ' &&arr[0][0]!=' '&&arr[1][1]!=' ')
	{
		arr[2][2] = 'O';
		return;
	}
	else if (arr[0][0] == arr[2][2] && arr[1][1]==' ' &&arr[0][0]!=' '&&arr[2][2] != ' ')
	{
		arr[1][1] = 'O';
		return;
	}
	else if (arr[1][1] == arr[2][2]&&arr[0][0] == ' ' &&arr[1][1] != ' '&&arr[2][2] != ' ')
	{
		arr[0][0] = 'O';
		return;
	}

	//right diagonal
	if (arr[0][2] == arr[1][1] && arr[2][0]==' '&& arr[0][2] == ' '&& arr[1][1] != ' ')
	{
		arr[2][0] = 'O';
		return;
	}
	else if (arr[0][2] == arr[2][0] && arr[1][1]==' '&&arr[0][2]!=' '&&arr[2][0] != ' ')
	{
		arr[1][1] = 'O';
		return;
	}
	else if (arr[1][1] == arr[0][2] && arr[2][0]==' '&& arr[1][1]!=' '&& arr[0][2] != ' ')
	{
		arr[2][0] = 'O';
		return;
	}
	// random
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (arr[i][j] == ' ')
			{
				arr[i][j] = 'O';
				return;

			}
		}
	}
}

int check(char arr[3][3])
{
	//horizontal
	for (int i = 0; i < 3; i++)
	{
		if ((arr[i][0] ==arr[i][1] && arr[i][1] == arr[i][2] ))
		{
			if(arr[i][0]=='X')
			{
				printf("user win");
				//flag=1;
				return 1;
			}
			else if(arr[i][0]=='O')
			{
				printf("Computer win");
				
				return 1;
			}
		}
	}

	

	//vertical
	for (int i = 0; i < 3; i++)
	{
		if ((arr[0][i] == arr[1][i] && arr[1][i]==arr[2][i]))
		{
			if(arr[0][i]=='X')
			{
				printf("user win");
				//flag=1;
				return 1;
			}
			else if(arr[0][i]=='O')
			{
				printf("Computer win");
				//flag=1;
				return 1;
			}
		}
	}

	

	//diagonal
	if (arr[0][0] == 'X' && arr[1][1] == 'X' && arr[2][2] == 'X')
	{
		printf("\nUser wins");
		//flag=1;
		return 1;
	}
	if (arr[0][0] == 'O' && arr[1][1] == 'O' && arr[2][2] == 'O')
	{
		printf("\nComputer wins");
		//flag=1;
		return 1;
	}

	//diagonal
	if (arr[0][2] == 'X' && arr[1][1] == 'X' && arr[2][0] == 'X')
	{
		printf("\nUser wins");
		//flag=1;
		return 1;
	}
	if (arr[0][2] == 'O' && arr[1][1] == 'O' && arr[2][0] == 'O')
	{
		printf("\nComputer wins");
		//flag=1;
		return 1;
	}
	return 0;
}
//C:\Program Files (x86)\Common Files\Oracle\Java\javapath;C:\Program Files (x86)\Java\jdk1.8.0_181\bin