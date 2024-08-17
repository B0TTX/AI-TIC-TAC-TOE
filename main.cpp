#include "game.h"

int main()
{
	int size=0;
	int user;
	std::cout<<"Enter the size of the board ";
	std::cin>>size;
	Play play(size);
	play.display();
	int ans = play.selectWinner(user);
	std::cout<<"THE GAME IS WON BY USER: " <<ans<<std::endl;
}