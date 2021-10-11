// House Class Template
//Nancy Mathew, ID: 1000873667, House.Cpp
#include "House.h"

House::House(std::string Name, std::map<int,std::string>CandyRanking)
	:houseName{Name}, CandyRankingMap{CandyRanking}
{
}

House::~House()
{
		std::cout << "HOUSE" << std::endl;
}

std::string House::ringDoorbell(std::ostringstream &path)
{
	return 0;
}
