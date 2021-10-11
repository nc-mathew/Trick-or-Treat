// Trick or Treater Class Template
//Nancy Mathew, ID: 1000873667, TrickOrTreater.cpp
#include "TrickOrTreater.h"


int TrickOrTreater::ImDone = 0;

TrickOrTreater::TrickOrTreater(std::string Name, std::vector<House*>List)
	: name{Name}, ListOfHouses{List}
{
}

void TrickOrTreater::Walk(int speed)
{
    for (int i = 0; i < 10; ++i)
	{
		path << '.';
		/* put this_thread to sleep for speed milliseconds */
		std::this_thread::sleep_for(std::chrono::milliseconds(speed));
  }
}


void TrickOrTreater::GoTrickOrTreating()
{
	int speed = 0;

	for(auto it : ListOfHouses)/* range based for loop over ListOfHouses */
	{
		speed = rand()%500 + 1;   // speed is between 1 and 500
		/* call function Walk and pass it speed */
		Walk(speed);
		Bucket[it->ringDoorbell(path)]++;
	}
	// Increment ImDone because this thread is done trick or treating
	TrickOrTreater::ImDone++;
}

std::string TrickOrTreater::getName()
{
	return name;
}

void TrickOrTreater::startThread()
{
	TOTThreadPtr = new std::thread(&TrickOrTreater::GoTrickOrTreating, this);
}

void TrickOrTreater::joinThread()
{
	this->TOTThreadPtr->join();
	delete this->TOTThreadPtr;
}

std::string TrickOrTreater::getPath()
{
	return path.str();/* return the string version of ostringstream path */
}

std::ostream& operator<<(std::ostream& output, TrickOrTreater &TOT)/* add both parameters */
{
	output << TOT.name << "'s - ";

	/* create a range based for loop using TOT.Bucket    */
	for(auto& it : TOT.Bucket)
	{
	 	output << it.second << " " << it.first << ", ";
	}
	/* use the insertion operator to write the map element to output */
	output << "\n";
	
	return output;
}
