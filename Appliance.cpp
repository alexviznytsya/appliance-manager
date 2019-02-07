/**
 * Appliance.cpp
 * 
 * Appliance Manager
 * 
 * Alex Viznytsya
 * 04/23/2018
 * 
*/

#include "Appliance.h"

Appliance::Appliance(std::string fn) {
    std::ifstream file(fn);
    std::string line;
    std::getline(file, line);
    this->id = std::stoi(line);
    std::getline(file, line);
    this->type = ApplianceType(std::stoi(line));
    std::getline(file, line);
    this->manufacturer = line;
    std::getline(file, line);
    this->price = std::stod(line);
    while(file.good()) {
        std::getline(file, line);
        if(line.length() > 0) {
            (this->pictures).push_back(line);
        }
    }
    file.close();
}

Appliance::~Appliance() {
    this->saveData();
}

void Appliance::saveData() {
    std::string fn = "./Appliances/" + std::to_string(this->id) + ".txt";
    std::remove(fn.c_str());
    std::ofstream file(fn);
    file << std::to_string(this->id) + "\n";
    file << std::to_string(this->type) + "\n";
    file << this->manufacturer + "\n";
    file << std::to_string(this->price) + "\n";
    for(int i = 0; i < (this->pictures).size(); i++) {
        file << (this->pictures)[i] + "\n";
    }
    file.close();
}
