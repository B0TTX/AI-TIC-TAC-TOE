#include "game.h"



Board::Board(int size)
	: size(size), board(size * size, ' ') {
		userToChar[1] = 'X';
		userToChar[2] = '0';
	}



void Board::display()
{
	int counter = 0;
	for(int i=0; i<size; i++)
	{
		for(int j=0; j<size; j++)
		{
			std::cout<<board[i * size + j]<<" ";
			counter++;
		}
		std::cout<<std::endl;
	}
}

Play::Play(int size) : Board(size) {}

void Play::select(int user)
{
	int loc;
	std::cout<<"Enter the location: ";
	std::cin>>loc;
	std::cout<<"Please enter user id: ";
	std::cin>>user;
	// int row = loc/size;
	// int col = loc%size;
	
	if(user == 1)
	{
		board[loc] = 'X';
	}
	else if(user == 2)
	{
		board[loc] = '0';
	}

	display();
}


bool Play::checkWinner(int user)
{
	// checking rows
	for(int i=0; i<9; i+=3)
	{
		if(board[i] == user &&
			board[i+1] == user &&
			board[i+2] == user)
		{
			return true;
		}
	}

	//checking columns

	for(int i=0; i<3; i++)
	{
		if(board[i] == user &&
			board[i+3] == user &&
			board[i+6] == user)
		{
			return true;
		}
	}

	//checking diagonals

	if(board[0] == user &&
		board[4] == user &&
		board[9] == user)
	{
		return true;
	}

	if(board[2] == user && 
		board[4] == user &&
		board[6] == user)
	{
		return true;
	}

	return false;
}

bool Play::checkUser1(int user)
{
	if(checkWinner(userToChar[user]) == 1)
	{
		return true;
	}
	return false;
}

bool Play::checkUser2(int user)
{
	if(checkWinner(userToChar[user]) == 1)
	{
		return true;
	}
	return false;
}

int Play::selectWinner(int user)
{
	int gameOver = false;
	int winner = 0;
	while(gameOver != true)
	{
		select(user);

		if(checkUser1(1))
		{
			winner = 1;
			gameOver = true;
		}
		if(checkUser2(2))
		{
			winner = 2;
			gameOver = true;
		}
	}
	return winner;
}




