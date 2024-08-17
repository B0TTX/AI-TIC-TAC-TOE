#include <iostream>
#include <vector>
#include <unordered_map>


class Board
{

	public:
		int size;
		std::vector<char> board;
		std::unordered_map<int, char> userToChar;
		Board(int size);
		void display();


		//void fill(int board[][], int size);
};

class Play : public Board 
{
	private:
		std::string opt;

	public:
		Play(int size);
		void select(int user);
		bool checkWinner(int user);
		bool checkUser1(int user);
		bool checkUser2(int user);
		int selectWinner(int user);
};
