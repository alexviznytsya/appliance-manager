/**
 * Appliance.h
 *
 * Appliance Manager
 *
 * Alex Viznytsya
 * 04/23/2018
 *
 */

#pragma once
#include <string>
#include <fstream>
#include <vector>

enum ApplianceType : int {LAUNDRY_MACHINE = 0, DISH_WASHER, DRYER};

class Appliance {
    friend class AppliancePtr;

    protected:
        Appliance(std::string fn);
        Appliance(const Appliance &a);
        Appliance &operator=(const Appliance &a);
        void saveData();
        
    public:
        int id;
        ApplianceType type;
        std::string manufacturer;
        double price;
        std::vector<std::string> pictures;
        ~Appliance();
};
