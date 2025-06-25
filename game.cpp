#include<iostream>
using namespace std;

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
char p1marker, p2marker;
char choice,playagain;
bool p1win, p2win;
string p1name, p2name;
void displayboard();
void markerchoice();
void player1move();
void player2move();
void winner();


int main()
{
	do {
		int moveno = 1, p1moveno = 1;
		cout << "TIC TAC TOE\n";
		cout << "Enter player 1 name: ";
		cin >> p1name;
		cout << "Enter player 2 name: ";
		cin >> p2name;
		displayboard();
		markerchoice();
		while (p1win == false && p2win == false && moveno <= 5)
		{
			cout << p1name << " move no: " << moveno << endl;
			player1move();
			if (p1win || p2win)
			{
				displayboard();
				cout << p1name << " wins\n";
				break;
			}
			if (p1win == false && p2win == false && p1moveno == 5) {
				cout << "GAME DRAW!\n";
				break;
			}
			p1moveno++;
			cout << p2name << " move no: " << moveno << endl;
			player2move();
			if (p1win || p2win)
			{
				displayboard();
				cout << p2name << " wins\n";
				break;
			}
			moveno++;
		}
		cout << "do you want to play again? (y/n): ";
		cin >> playagain;
	} while (playagain == 'y' || playagain == 'Y');

	return 0;
}
void displayboard()
{
	cout << "BOARD\n";
	cout << "  " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
	cout << "  ----------" << endl;
	cout << "  " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
	cout << "  ----------" << endl;
	cout << "  " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}
void markerchoice()
{
	cout << p1name << ", choose your marker (X or O): ";
	cin >> p1marker;
	if (p1marker == 'X' || p1marker == 'x')
	{
		p2marker = 'O';
	}
	else if (p1marker == 'O' || p1marker == 'o')
	{
		p2marker = 'X';
	}
	else
	{
		cout << "Invalid marker choice. Default markers assigned.\n" << p1name << " = X\n " << p2name << " = 0" << endl;
		p1marker = 'X';
		p2marker = '0';
	}
}
void player1move()
{
	displayboard();
	cout << " choose your position (1-9): ";
	cin >> choice;
	if (choice < '1' || choice > '9')
	{
		do {
			cout << "Invalid choice. Please choose a number between 1 and 9." << endl;
			cin >> choice;
		} while (choice < '1' || choice > '9');
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == choice)
			{
				board[i][j] = p1marker;
				winner();
				return;
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] != choice) {}
		}
	}
	cout << "Position already taken. Please choose another position." << endl;
	player1move();
}
void player2move()
{
	displayboard();
	cout << " choose your position (1-9): ";
	cin >> choice;
	if (choice < '1' || choice > '9') {
		do {
			cout << "Invalid choice. Please choose a number between 1 and 9." << endl;
			cin >> choice;
		} while (choice < '1' || choice > '9');
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == choice)
			{
				board[i][j] = p2marker;
				winner();
				return;
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] != choice)
			{
			}
		}
	}
	cout << "Position already taken. Please choose another position." << endl;
	player2move();
}
void winner()
{
	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
		{
			if (board[i][0] == 'X' || board[i][0] == 'x')
			{
				if (p1marker == 'X' || p1marker == 'x')
				{
					p1win = true;
				}
				else
				{
					p2win = true;
				}
				return;
			}
			if (board[i][0] == 'O' || board[i][0] == 'o')
			{
				if (p1marker == 'O' || p1marker == 'o')
				{
					p1win = true;
				}
				else
				{
					p2win = true;
				}
				return;
			}
		}
		for (int j = 0; j < 3; j++)
		{
			if (board[0][j] == board[1][j] && board[1][j] == board[2][j])
			{
				if (board[0][j] == 'X' || board[0][j] == 'x')
				{
					if (p1marker == 'X' || p1marker == 'x')
					{
						p1win = true;
					}
					else
					{
						p2win = true;
					}
					return;
				}
				else if (board[0][j] == 'O' || board[0][j] == 'o')
				{
					if (p1marker == 'O' || p1marker == 'o')
					{
						p1win = true;
					}
					else
					{
						p2win = true;
					}
					return;
				}
			}
		}
		if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
		{
			if (board[0][0] == 'X' || board[0][0] == 'x')

			{
				if (p1marker == 'X' || p1marker == 'x')
				{
					p1win = true;
				}
				else
				{
					p2win = true;
				}
				return;
			}
			else if (board[0][0] == 'O' || board[0][0] == 'o')
			{
				if (p1marker == 'O' || p1marker == 'o')
				{
					p1win = true;
				}
				else
				{
					p2win = true;
				}
				return;
			}
		}
		if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
		{
			if (board[0][2] == 'X' || board[0][2] == 'x')
			{
				if (p1marker == 'X' || p1marker == 'x')
				{
					p1win = true;
				}
				else
				{
					p2win = true;
				}
				return;
			}
			else if (board[0][2] == 'O' || board[0][2] == 'o')
			{
				if (p1marker == 'O' || p1marker == 'o')
				{
					p1win = true;
				}
				else
				{
					p2win = true;
				}
				return;
			}
		}
	}
}