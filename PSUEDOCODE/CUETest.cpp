#include <iostream>
#include <vector>

int main()
{
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
	}
	
	return 0;
}