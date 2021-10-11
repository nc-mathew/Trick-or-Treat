//Nancy Mathew, ID: 1000873667
//ToothbrushHouse.cpp

#include "ToothbrushHouse.h"
#include "House.h"

ToothbrushHouse::ToothbrushHouse(std::string Name, std::map<int,std::string>CandyRanking)
	: House(Name, CandyRanking)
{
}

ToothbrushHouse::~ToothbrushHouse()
{
    std::cout << "TOOTHBRUSHHOUSE" << std::endl;
}

std::string ToothbrushHouse::ringDoorbell(std::ostringstream &path)
{
	/* lock the door mutex */
	Door.lock();
	path << "-";
	/* put this_thread to sleep for 3 seconds */
	std::this_thread::sleep_for(std::chrono::seconds(3));
	//Pick a candy from the CandyRankingMap
	//int toothbrush = rand() % (CandyRankingMap.size()) + 1;
	/* unlock the door mutex */
	Door.unlock();

	return "TOOTHBRUSH";
}
