#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <vector>

void reverse_order(std::string date1, std::string date2){
    std::vector <std::string> days;
    std::vector <double> basin;
    
    std::ifstream file("Current_Reservoir_Levels.tsv");
    if (file.fail()) {
    std::cerr << "File cannot be opened for reading." << "\n";
    exit(1); 
}

    std::string junk;
    std::getline(file, junk);
    double eastSt, eastEl, westSt, westEl;
    std::string dates;

    while(file >> dates >> eastSt >> eastEl >> westSt >> westEl){
        if(dates >= date1 && dates <= date2){
            days.push_back(dates);
            basin.push_back(westEl);
        }
        file.ignore(INT_MAX, '\n');
    }

    for(int i = days.size(); i > -1; i--){
        std::cout << days[i]<< " " << basin[i]<< "\n";
    }
  

}