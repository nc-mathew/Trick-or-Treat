//Nancy Mathew, ID: 1000873667
//CandyHouse.cpp
#include "CandyHouse.h"
#include "House.h"


CandyHouse::CandyHouse(std::string Name, std::map<int,std::string>CandyRanking)
	: House(Name, CandyRanking)
{
}

CandyHouse::~CandyHouse()
{
    std::cout << "CANDYHOUSE" << std::endl;
}

std::string CandyHouse::ringDoorbell(std::ostringstream &path)
{
	/* lock the door mutex */
	Door.lock();
	path << "+";
	/* put this_thread to sleep for 3 seconds */
	std::this_thread::sleep_for(std::chrono::seconds(3));
	//Pick a candy from the CandyRankingMap
	int candy = rand() % (CandyRankingMap.size()) + 1;

	/* unlock the door mutex */
	Door.unlock();

	return CandyRankingMap[candy];
}
