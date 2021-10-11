//Nancy Mathew, ID: 1000873667
//CandyHouse.h
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

#ifndef _CANDYHOUSE_H
#define _CANDYHOUSE_H

class CandyHouse : public House
{
  public :
    CandyHouse(std::string Name, std::map<int,std::string>CandyRanking);
    std::string ringDoorbell(std::ostringstream &path);

    ~CandyHouse();
};
#endif
