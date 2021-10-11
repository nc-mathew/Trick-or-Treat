// House class header file template
//Nancy Mathew, ID: 1000873667, House.h
/* add the necessary includes */
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <thread>
#include <chrono>
#include <mutex>
#include <map>

/* add an include guard named _HOUSE_  */
#ifndef _HOUSE_H
#define _HOUSE_H

class House
{
	public :
		/* create the prototype for the constructor based on House.cpp */
		House(std::string Name, std::map<int,std::string>CandyRanking);
		/* create the prototype for ringDoorbell() based on House.cpp */
		virtual std::string ringDoorbell(std::ostringstream &path) = 0;

		virtual ~House();

	protected :
		std::string houseName;
		/* declare a mutex named door */
		std::mutex Door;
		/* declare a map named CandyRankingMap of type int,string */
		std::map<int, std::string> CandyRankingMap;
};
#endif
