#include <iostream>
#include <vector>
#include <fstream>

int main()
{
	std::ofstream output("test.txt");
	
	int pointer1 = 0;//point on the player_hand vector that wont be added to the CUE.
	int pointer2 = 1;//point on the player_hand vector that wont be added to the CUE.
	int MAX_CUES = 10;//Changes based on game type.
	int COMMUNITY_CARDS = 4;//Changes based on game type.
	
	std::vector<int> communityCards;
	communityCards.push_back(0);
	communityCards.push_back(1);
	communityCards.push_back(2);
	communityCards.push_back(3);
	communityCards.push_back(4);
	/*
	for(int pointer1 = 0; pointer1 < 6; ++pointer1)
	{
		for(int pointer2 = pointer1 + 1; pointer2 < 7; ++pointer2)
		{
			std::vector<int> vec;
			for(int i = 0; i < 7; ++i)
			{
				if(i != pointer1 && i != pointer2)
				{
					vec.push_back(i);
				}
			}
			std::cout << vec[0] << vec[1]<< vec[2] <<vec[3] << vec[4] << std::endl;
		}
	}*/
	int count = 0;
	for (int pointer1 = 0; pointer1 <= 2; ++pointer1)
	{
		for (int pointer2 = pointer1 + 1; pointer2 <= 3; ++pointer2)
		{
			for (int pointer3 = 4; pointer3 <= 7; ++pointer3)
			{
				for (int pointer4 = pointer3 + 1; pointer4 <= 8; ++pointer4)
				{
					std::vector<int> vec;
					for (int i = 0; i < 9; ++i)
					{
						if (i != pointer1 && i != pointer2 && i != pointer3 && i != pointer4)
						{
							vec.push_back(i);
							
						}
					}
					output << "Number of times run: "<< count << " " << vec[0] << vec[1]<< vec[2] <<vec[3] << vec[4] << std::endl;
					++count;
				}
			}
		}
	}
	
	
	
	return 0;
}



