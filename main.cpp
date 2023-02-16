#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <vector>
#include "reservoir.h"
#include "reverseorder.h"


int main()
{
  //TASK A
  std::cout << get_east_storage("04/03/2018")<<"\n";
  std::cout << get_east_storage("10/24/2018")<<"\n";
  //TASK B
  std::cout << get_min_east()<<"\n";
  std::cout << get_max_east()<<"\n";
  //TASK C
  std::cout << compare_basins("04/03/2018")<<"\n";
  std::cout << compare_basins("10/24/2018")<<"\n";
  //TASK D
  reverse_order("04/03/2018", "10/24/2018");
  return 0;
}
