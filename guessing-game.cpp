#include <iostream>
#include <cstdlib>
#include <ctime>


int main()
{
	//declaring round limit
	const int roundLimit=5;

	std::cout<<"Guess the random number"<<std::endl;
	//random seed, target set
	srand(time(0));
	int targetNo = rand()%100 +1;

	for (int i=0;i<roundLimit;i++)
	{
		
		int userGuess=0;
		std::cin>>userGuess;
		//checking for good input
		while (!std::cin.good())
		{
			std::cout<<"Not an Int, please enter again"<<std::endl;
			std::cin.clear();
			std::cin.ignore(INT8_MAX, '\n');
			std::cin>>userGuess;

		}
		//appropriate output messages
		if(userGuess>targetNo)
		{
			if(i<roundLimit-1)//if not last round- no need to tell the player this
				std::cout<<"Guess Lower"<<std::endl;

		}else if(userGuess<targetNo)
		{
			if(i<roundLimit-1)
				std::cout<<"Guess Higher"<<std::endl;
		}else
		{	//win-exit application
			std::cout<<"You Win"<<std::endl;
			return 0;
		}
	}
	std::cout<<"You Lose"<<std::endl;
	std::cout<<"The number is "<<targetNo<<std::endl;
	return 0;
}