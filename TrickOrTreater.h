// Treat or Tricker class header file template
//Nancy Mathew, ID: 1000873667, TrickOrTreater.h

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

#include "House.h"
/* add an include guard called _TOT_H */
#ifndef _TOT_H
#define _TOT_H

class TrickOrTreater
{
	/* create friend function prototype */
	friend std::ostream& operator<<(std::ostream& output, TrickOrTreater &TOT);

	public :
		/* create the prototype for the constructor based on TrickOrTreater.cpp */
		TrickOrTreater(std::string Name, std::vector<House*>List);
		std::string getName();
		void startThread();
		void joinThread();
		void GoTrickOrTreating();
		void Walk(int);
		std::string getPath();
		static int ImDone;


	private :
		std::string name;
		std::ostringstream path;
		std::thread *TOTThreadPtr = nullptr;
		/* declare a map named Bucket of type string,int */
		std::map<std::string, int> Bucket;
		/* declare a vector name ListOfHouses of type pointer to House */
		std::vector<House*> ListOfHouses;
};
#endif
