/**
 * AppliancePtr.cpp
 *
 * Appliance Manager
 *
 * Alex Viznytsya
 * 04/23/2018
 *
 */

#include "AppliancePtr.h"

std::queue<AppliancePtr*> AppliancePtr::openQueue;

AppliancePtr::AppliancePtr(int i) : id{i}, appliance{nullptr} {
}

AppliancePtr::~AppliancePtr() {
    if(this->appliance != nullptr) {
        delete appliance;
    }
}

void AppliancePtr::openFile() {
    if(this->appliance == nullptr) {
        if(AppliancePtr::openQueue.size() >= 3) {
            delete AppliancePtr::openQueue.front()->appliance;
            AppliancePtr::openQueue.front()->appliance = nullptr;
            AppliancePtr::openQueue.pop();
        }
        this->appliance = new Appliance("./Appliances/" + std::to_string(this->id) + ".txt");
        AppliancePtr::openQueue.push(this);
    }
}

void AppliancePtr::saveFile() {
    if(this->appliance != nullptr) {
        this->appliance->saveData();
    }
}

Appliance &AppliancePtr::operator*() {
    this->openFile();
    return *(this->appliance);
}

Appliance *AppliancePtr::operator->() {
    this->openFile();
    return this->appliance;
}
