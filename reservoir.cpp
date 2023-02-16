#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <climits>

double get_east_storage(std::string date){
    std::ifstream file("Current_Reservoir_Levels.tsv");
    if (file.fail()) {
    std::cerr << "File cannot be opened for reading." << "\n";
    exit(1); 
}

    std::string junk;
    std::getline(file, junk);
    std::string dates;
    double eastSt;

    while(file >> dates >> eastSt){
        if(date == dates){
            return eastSt;
        }
        file.ignore(INT_MAX, '\n');
    }
    return 0;
}

double get_min_east(){
    std::ifstream file("Current_Reservoir_Levels.tsv");
    if (file.fail()) {
    std::cerr << "File cannot be opened for reading." << "\n";
    exit(1); 
}

    std::string junk;
    std::getline(file, junk);
    std::string dates;
    double eastSt;
    double minEast = 10000000;

    while(file >> dates >> eastSt){
        if(eastSt < minEast){
            minEast = eastSt;
        }
        file.ignore(INT_MAX, '\n');
    }
    return minEast;
}

double get_max_east(){
    std::ifstream file("Current_Reservoir_Levels.tsv");
    if (file.fail()) {
    std::cerr << "File cannot be opened for reading." << "\n";
    exit(1); 
}

    std::string junk;
    std::getline(file, junk);
    std::string dates;
    double eastSt;
    double maxEast = 0;

    while(file >> dates >> eastSt){
        if(eastSt > maxEast){
            maxEast = eastSt;
        }
        file.ignore(INT_MAX, '\n');
    }
    return maxEast;
}

std::string compare_basins(std::string date){
    std::ifstream file("Current_Reservoir_Levels.tsv");
    if (file.fail()) {
    std::cerr << "File cannot be opened for reading." << "\n";
    exit(1); 
}

    std::string junk;
    std::getline(file, junk);
    std::string dates;
    double eastSt, eastEl, westSt, westEl;

    while(file >> dates >> eastSt >> eastEl >> westSt >> westEl){
        if(date == dates){
            if(eastEl > westEl){
                return "East";
            }
            else if(westEl > eastEl){
                return "West";
            }
            else{
                return "Equal";
            }
        }
        file.ignore(INT_MAX, '\n');
    }
    return 0;

}
