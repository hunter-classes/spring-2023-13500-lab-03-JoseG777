#pragma once
#include <string>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <vector>

double get_east_storage(std::string date);

double get_min_east();

double get_max_east();

std::string compare_basins(std::string date);
