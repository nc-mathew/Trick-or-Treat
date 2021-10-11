// Coding Assignment 5 Template
//Nancy Mathew, ID: 1000873667, Code6 Assignment with candy and toothbrush houses
/* Add the needed includes */
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <thread>
#include <chrono>
#include <mutex>
#include <map>

//using namespace std;

#include "House.h"
#include "TrickOrTreater.h"
#include "CandyHouse.h"
#include "ToothbrushHouse.h"

void get_command_line_params(int argc, char *argv[], std::string& TOTfile, std::string& Housefile, std::string& Candyfile)
{
	/* if argc is 4, then put argv[1] in TOTfile, argv[2] in Housefile and argv[3] in Candyfile
	/* else throw an invalid_argument with the message shown in the output */
	int i;
	std::string cla;
	int totFile = 0, houseFile = 0, candyFile = 0;

	for (i = 1; i < argc; i++)
	{
		if(argc == 4)
		{
			TOTfile = argv[1];
			Housefile = argv[2];
			Candyfile = argv[3];
		}
	}

	if (!(totFile && houseFile && candyFile))
	{
		throw std::invalid_argument("\nMissing command line parameters - Usage : TOTFILE= HOUSEFILE= CANDYFILE =\n");
	}
}

int main(int argc, char *argv[])
{
	std::string TOTFilename, HouseFilename, CandyFilename;

	/* create a map named CandyRankingMap of type int,string */
	std::map<int, std::string> CandyRankingMap;

	std::string CandyLine;
	char CandyLineA[50] = {};
	std::string CandyName;
	int CandyRanking;
	char *CandyPtr = NULL;

	/* create a vector named Houses of type pointers to House */
	std::vector<House*> Houses;
	std::string HouseLine;

	/* create a vector named TOTs of type TrickOrTreater */
	std::vector<TrickOrTreater> TOTs;
	std::string TotLine;

	/* declare an ostringstream named HouseHeading */
	std::ostringstream HouseHeading;
	srand(time(NULL));

	/* create a try-catch block for function get_command_line_params */
	try
	{
		get_command_line_params(argc, argv, TOTFilename, HouseFilename, CandyFilename);
	}
	catch(std::invalid_argument& say)
	{
		std::cerr << "Exception: " << say.what() << std::endl;
	}
	/* open all three files from command line for reading - use TOTFH, HouseFH and CandyFH */
	std::ifstream TOTFH{"TOT.txt"};
	std::ifstream HouseFH{"HOUSES.txt"};
	std::ifstream CandyFH{"CANDY.txt"};

	while (getline(CandyFH, CandyLine))
	{
		strcpy(CandyLineA, CandyLine.c_str());
		CandyPtr = strtok(CandyLineA, "|");
		CandyName = CandyPtr;
		CandyPtr = strtok(NULL, "|");
		CandyRanking = atoi(CandyPtr);
		/* call insert() and make_pair() with CandyRanking and CandyName */
		CandyRankingMap.insert(make_pair(CandyRanking, CandyName));
	}
	/* Close the Candy file - CandyFH */
	CandyFH.close();

	HouseHeading << "          ";

	while (getline(HouseFH, HouseLine))
	{
		/* in one line - use new to allocate a House object that is constructed by    */
		/* passing HouseLine and CandyRankingMap and push_back the object into Houses */
		//Houses.push_back(new House(HouseLine, CandyRankingMap));
		int pick_num = rand() % 2;

		if(pick_num == 0)
		{
			Houses.push_back(new CandyHouse(HouseLine, CandyRankingMap));
		}
		else
		{
			Houses.push_back(new ToothbrushHouse(HouseLine, CandyRankingMap));
		}

		HouseHeading << HouseLine;
		for (int i = 0; i < 11 - HouseLine.length(); i++)
			HouseHeading << " ";

	}
	HouseHeading << std::endl << std::endl;
	/* Close the House file - HouseFH */
	HouseFH.close();
	/* Create all of the Trick or Treaters */
	while(getline(TOTFH, TotLine))
	{
		TOTs.push_back(TrickOrTreater{TotLine, Houses});
	}
	/* Close the TOT file - TOTFH */
	TOTFH.close();
	/* Start all of the trick or treaters using a range based for loop over vector TOT */
	/* call function startThread() for each iterator for each pass through the loop */

	for(auto& it : TOTs)
	{
		it.startThread();
	}
	while (TrickOrTreater::ImDone != TOTs.size() )
	{
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		std::cout << HouseHeading.str();


    for (auto& it : TOTs) /* range based for loop over TOTs */
		{
			std::cout << it.getPath()/* call getPath() for iterator */ << it.getName()/* call getName() for iterator */ << std::endl;
    }
		std::this_thread::sleep_for(std::chrono::milliseconds(5));/* put this_thread to sleep for 5 milliseconds */
  }

	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	std::cout << HouseHeading.str();

	for (auto& it : TOTs)/* range based for loop over TOTs */
	{
		std::cout << it.getPath()/* call getPath() for iterator */ << it.getName()/* call getName() for iterator */ << std::endl;
	}

	for (auto& it : TOTs)// range based for loop over TOTs
	{
		std::cout << it;
	}

	for (auto& it : TOTs) //range based for loop over TOTs
	{
		it.joinThread(); // Call function joinThread() for iterator
	}

	for (auto& it : Houses) //range based for loop over Houses
	{
		delete it; // use delete for iterator to return dynamically allocated memory
	}

	return 0;
}
