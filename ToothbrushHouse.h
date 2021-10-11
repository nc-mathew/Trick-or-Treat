//Nancy Mathew, ID: 1000873667
//ToothbrushHouse.h
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

#ifndef _TOOTHBRUSHHOUSE_H
#define _TOOTHBRUSHHOUSE_H
class ToothbrushHouse : public House
{
  public :
    ToothbrushHouse(std::string Name, std::map<int,std::string>CandyRanking);
    std::string ringDoorbell(std::ostringstream &path);

  ~ToothbrushHouse();

};
#endif
