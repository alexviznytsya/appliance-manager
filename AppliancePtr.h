/**
 * AppliancePtr.h
 *
 * Appliance Manager
 *
 * Alex Viznytsya
 * 04/23/2018
 *
 */

#pragma once
#include "Appliance.h"
#include <queue>

class AppliancePtr {
    private:
        Appliance *appliance;
        int id;
    
    protected:
        AppliancePtr(const AppliancePtr &ap);
        AppliancePtr &operator=(const AppliancePtr &ap);

    public:
        static std::queue<AppliancePtr*> openQueue;
        AppliancePtr(int i);
        ~AppliancePtr();
        Appliance &operator*();
        Appliance *operator->();
        void openFile();
        void saveFile();
};
