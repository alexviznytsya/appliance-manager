/**
 * ApplicationManager.cpp
 * 
 * Appliance Manager
 *
 * Alex Viznytsya
 * 04/23/2018
 *
 */

#include <iostream>

#include "LinkedList.h"


void printHeader() {
    std::cout << std::endl;
    std::cout << "--------------------------------------------------------------" << std::endl;
    std::cout << "Appliance Manager" << std::endl;
    std::cout << "Alex Viznytsya" << std::endl;
    std::cout << "04/23/2018" << std::endl;
    std::cout << "--------------------------------------------------------------" << std::endl;
    std::cout << std::endl;
}

void printHelp() {
    std::cout << std::endl;
    std::cout << "l - List all appliances." << std::endl;
    std::cout << "0 ... 9 - Edit appliance." << std::endl;
    std::cout << "c - Create an appliance." << std::endl;
    std::cout << "p - Change price of current appliance." << std::endl;
    std::cout << "s - Save all appliances." << std::endl;
    std::cout << "q - Quit the appliance manager." << std::endl;
    std::cout << std::endl;
}


void createNewAppliance(LinkedList &ll) {
    int id = -1;
    int typeInt = -1;
    std::string manufacturer = "";
    double price = 0.00;
    std::string picture = "";
    std::cout << "Warning: old appliance file will be replaced by new one!" << std::endl;
    std::cout << "Please enter appliance id from 0 to 9: ";
    std::cin >> id;
    while(id < 0 || id > 9) {
        std::cout << "You have entered incorrect id number. Please try again: ";
        std::cin >> id;
    }
    AppliancePtr &ap = ll.getData(id);
    ap->id = id;
    std::cout << "Please enter appliance type: " << std::endl;
    std::cout << "    LAUNDRY_MACHINE = 0" << std::endl;
    std::cout << "    DISH_WASHER     = 1" << std::endl;
    std::cout << "    DRYER           = 2" << std::endl;
    std::cout << "                    : ";
    std::cin >> typeInt;
    while(typeInt < 0 || typeInt > 2) {
        std::cout << "You have entered incorrect id number. Please try again: ";
        std::cin >> typeInt;
    }
    ap->type = ApplianceType(typeInt);
    std::cout << "Please enter appliance manufacurer: ";
    std::cin >> manufacturer;
    ap->manufacturer = manufacturer;
    std::cout << "Please enter appliance price: ";
    std::cin >> price;
    while(price < 0) {
        std::cout << "You have entered incorrect id number. Please try again: ";
        std::cin >> price;
    }
    ap->price = price;
    ap->pictures.clear();
    std::cout << "Please enter path to appliance picture: ";
    std::cin >> picture;
    ap->pictures.push_back(picture);
    char picAnswer = 'n';
    while(true) {
        std::cout << "Do you want to add another appliance picture (Y/N): ";
        std::cin >> picAnswer;
        if(picAnswer == 'n' || picAnswer == 'N') {
            break;
        } else if(picAnswer == 'y' || picAnswer == 'Y'){
            std::cout << "Please enter path to appliance picture: ";
            std::cin >> picture;
            ap->pictures.push_back(picture);
        } else {
            std::cout << "You have entered incorrect answer." << std::endl;
            continue;
        }
    }
   
    std::cout << "New appliance file had been created." << std::endl;
    ap.saveFile();
}

void printAppliance(AppliancePtr &ap) {
    std::cout << "ID:           " << (*ap).id << std::endl;
    std::cout << "Type:         ";
    switch((*ap).type) {
        case ApplianceType::LAUNDRY_MACHINE:
            std::cout << "Laundry Machine";
            break;
        case ApplianceType::DISH_WASHER:
            std::cout << "Dish Washer";
            break;
        case ApplianceType::DRYER:
            std::cout << "Dryer";
            break;
        default:
            std::cout << "Unknown";
    }
    std::cout << std::endl;
    std::cout << "Manufacturer: " << (*ap).manufacturer << std::endl;
    std::cout << "Price:        " << (*ap).price << std::endl;
    std::cout << "Pictures:     " << (*ap).pictures[0] << std::endl;
    for(int i = 1; i < (*ap).pictures.size(); i++) {
        std::cout << "              " << (*ap).pictures[i] << std::endl;
    }
    std::cout << std::endl;
}

void printAllAppliances(LinkedList &ll) {
    std::cout << "List of all appliances:" << std::endl;
    for(int i = 0; i < ll.getSize(); i++) {
        printAppliance(ll.getData(i));
    }
}

void saveAllApplances(LinkedList &ll) {
    for(int i = 0; i < ll.getSize(); i++) {
        ll.getData(i).saveFile();
    }
    std::cout << "Memory data has been saved." << std::endl;
}

void changeAppliancePrice(LinkedList &ll, int sa) {
    double newPrice = 0.00;
    std::cout << "Please enter new appliance price: ";
    std::cin >> newPrice;
    AppliancePtr &ap = ll.getData(sa);
    ap->price = newPrice;
    std::cout << "Price has been successfully changed." << std::endl;
    std::cout << "New appliance data:" << std::endl;
    printAppliance(ap);
}

int main(int argc, char** argv) {
    
    char command = ' ';
    int selectedAppliance = -1;
    LinkedList appliancesLL(10);
    printHeader();

    
    std::cout << "Please enter command or h for help:" << std::endl;
    std::cout << "> ";
    std::cin >> command;
    while(command != 'q') {
        if(command >= '0' && command <= '9') {
            appliancesLL.getData(command - '0').openFile();
            selectedAppliance = command - '0';
            std::cout << "Current appliance has been set to: " << selectedAppliance;
            std::cout << std::endl;
        } else {
            switch(command) {
            case 'h':
                printHelp();
                break;
            case 'l':
                printAllAppliances(appliancesLL);
                break;
            case 'c':
                createNewAppliance(appliancesLL);
                break;
            case 'p':
                changeAppliancePrice(appliancesLL, selectedAppliance);
                break;
            case 's':
                saveAllApplances(appliancesLL);
                break;
            default:
                std::cout << "Error: Incorrect input. Please enter command again:" << std::endl;
            }
        }
        
        std::cout << "> ";
        std::cin >> command;
    }

    std::cout << std::endl;
    std::cout << "Thank you for using Appliance Manager." << std::endl;
    std::cout << "Exiting program ..." << std::endl;
    std::cout << std::endl;
    return 0;
}
